# Copyright 2024 NXP
# NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
# accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
# activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
# comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
# terms, then you may not retain, install, activate or otherwise use the software.

import SDL
import utime as time
import usys as sys
import lvgl as lv
import lodepng as png
import ustruct
import fs_driver

lv.init()
SDL.init(w=800,h=480)

# Register SDL display driver.
disp_buf1 = lv.disp_draw_buf_t()
buf1_1 = bytearray(800*10)
disp_buf1.init(buf1_1, None, len(buf1_1)//4)
disp_drv = lv.disp_drv_t()
disp_drv.init()
disp_drv.draw_buf = disp_buf1
disp_drv.flush_cb = SDL.monitor_flush
disp_drv.hor_res = 800
disp_drv.ver_res = 480
disp_drv.register()

# Regsiter SDL mouse driver
indev_drv = lv.indev_drv_t()
indev_drv.init()
indev_drv.type = lv.INDEV_TYPE.POINTER
indev_drv.read_cb = SDL.mouse_read
indev_drv.register()

fs_drv = lv.fs_drv_t()
fs_driver.fs_register(fs_drv, 'Z')

# Below: Taken from https://github.com/lvgl/lv_binding_micropython/blob/master/driver/js/imagetools.py#L22-L94

COLOR_SIZE = lv.color_t.__SIZE__
COLOR_IS_SWAPPED = hasattr(lv.color_t().ch,'green_h')

class lodepng_error(RuntimeError):
    def __init__(self, err):
        if type(err) is int:
            super().__init__(png.error_text(err))
        else:
            super().__init__(err)

# Parse PNG file header
# Taken from https://github.com/shibukawa/imagesize_py/blob/ffef30c1a4715c5acf90e8945ceb77f4a2ed2d45/imagesize.py#L63-L85

def get_png_info(decoder, src, header):
    # Only handle variable image types

    if lv.img.src_get_type(src) != lv.img.SRC.VARIABLE:
        return lv.RES.INV

    data = lv.img_dsc_t.__cast__(src).data
    if data == None:
        return lv.RES.INV

    png_header = bytes(data.__dereference__(24))

    if png_header.startswith(b'\211PNG\r\n\032\n'):
        if png_header[12:16] == b'IHDR':
            start = 16
        # Maybe this is for an older PNG version.
        else:
            start = 8
        try:
            width, height = ustruct.unpack(">LL", png_header[start:start+8])
        except ustruct.error:
            return lv.RES.INV
    else:
        return lv.RES.INV

    header.always_zero = 0
    header.w = width
    header.h = height
    header.cf = lv.img.CF.TRUE_COLOR_ALPHA

    return lv.RES.OK

def convert_rgba8888_to_bgra8888(img_view):
    for i in range(0, len(img_view), lv.color_t.__SIZE__):
        ch = lv.color_t.__cast__(img_view[i:i]).ch
        ch.red, ch.blue = ch.blue, ch.red

# Read and parse PNG file

def open_png(decoder, dsc):
    img_dsc = lv.img_dsc_t.__cast__(dsc.src)
    png_data = img_dsc.data
    png_size = img_dsc.data_size
    png_decoded = png.C_Pointer()
    png_width = png.C_Pointer()
    png_height = png.C_Pointer()
    error = png.decode32(png_decoded, png_width, png_height, png_data, png_size)
    if error:
        raise lodepng_error(error)
    img_size = png_width.int_val * png_height.int_val * 4
    img_data = png_decoded.ptr_val
    img_view = img_data.__dereference__(img_size)

    if COLOR_SIZE == 4:
        convert_rgba8888_to_bgra8888(img_view)
    else:
        raise lodepng_error("Error: Color mode not supported yet!")

    dsc.img_data = img_data
    return lv.RES.OK

# Above: Taken from https://github.com/lvgl/lv_binding_micropython/blob/master/driver/js/imagetools.py#L22-L94

decoder = lv.img.decoder_create()
decoder.info_cb = get_png_info
decoder.open_cb = open_png

def anim_x_cb(obj, v):
    obj.set_x(v)

def anim_y_cb(obj, v):
    obj.set_y(v)

def anim_width_cb(obj, v):
    obj.set_width(v)

def anim_height_cb(obj, v):
    obj.set_height(v)

def anim_img_zoom_cb(obj, v):
    obj.set_zoom(v)

def anim_img_rotate_cb(obj, v):
    obj.set_angle(v)

global_font_cache = {}
def test_font(font_family, font_size):
    global global_font_cache
    if font_family + str(font_size) in global_font_cache:
        return global_font_cache[font_family + str(font_size)]
    if font_size % 2:
        candidates = [
            (font_family, font_size),
            (font_family, font_size-font_size%2),
            (font_family, font_size+font_size%2),
            ("montserrat", font_size-font_size%2),
            ("montserrat", font_size+font_size%2),
            ("montserrat", 16)
        ]
    else:
        candidates = [
            (font_family, font_size),
            ("montserrat", font_size),
            ("montserrat", 16)
        ]
    for (family, size) in candidates:
        try:
            if eval(f'lv.font_{family}_{size}'):
                global_font_cache[font_family + str(font_size)] = eval(f'lv.font_{family}_{size}')
                if family != font_family or size != font_size:
                    print(f'WARNING: lv.font_{family}_{size} is used!')
                return eval(f'lv.font_{family}_{size}')
        except AttributeError:
            try:
                load_font = lv.font_load(f"Z:MicroPython/lv_font_{family}_{size}.fnt")
                global_font_cache[font_family + str(font_size)] = load_font
                return load_font
            except:
                if family == font_family and size == font_size:
                    print(f'WARNING: lv.font_{family}_{size} is NOT supported!')

global_image_cache = {}
def load_image(file):
    global global_image_cache
    if file in global_image_cache:
        return global_image_cache[file]
    try:
        with open(file,'rb') as f:
            data = f.read()
    except:
        print(f'Could not open {file}')
        sys.exit()

    img = lv.img_dsc_t({
        'data_size': len(data),
        'data': data
    })
    global_image_cache[file] = img
    return img

def calendar_event_handler(e,obj):
    code = e.get_code()

    if code == lv.EVENT.VALUE_CHANGED:
        source = e.get_current_target()
        date = lv.calendar_date_t()
        if source.get_pressed_date(date) == lv.RES.OK:
            source.set_highlighted_dates([date], 1)

def spinbox_increment_event_cb(e, obj):
    code = e.get_code()
    if code == lv.EVENT.SHORT_CLICKED or code == lv.EVENT.LONG_PRESSED_REPEAT:
        obj.increment()
def spinbox_decrement_event_cb(e, obj):
    code = e.get_code()
    if code == lv.EVENT.SHORT_CLICKED or code == lv.EVENT.LONG_PRESSED_REPEAT:
        obj.decrement()

def digital_clock_cb(timer, obj, current_time, show_second, use_ampm):
    hour = int(current_time[0])
    minute = int(current_time[1])
    second = int(current_time[2])
    ampm = current_time[3]
    second = second + 1
    if second == 60:
        second = 0
        minute = minute + 1
        if minute == 60:
            minute = 0
            hour = hour + 1
            if use_ampm:
                if hour == 12:
                    if ampm == 'AM':
                        ampm = 'PM'
                    elif ampm == 'PM':
                        ampm = 'AM'
                if hour > 12:
                    hour = hour % 12
    hour = hour % 24
    if use_ampm:
        if show_second:
            obj.set_text("%d:%02d:%02d %s" %(hour, minute, second, ampm))
        else:
            obj.set_text("%d:%02d %s" %(hour, minute, ampm))
    else:
        if show_second:
            obj.set_text("%d:%02d:%02d" %(hour, minute, second))
        else:
            obj.set_text("%d:%02d" %(hour, minute))
    current_time[0] = hour
    current_time[1] = minute
    current_time[2] = second
    current_time[3] = ampm

def analog_clock_cb(timer, obj):
    datetime = time.localtime()
    hour = datetime[3]
    if hour >= 12: hour = hour - 12
    obj.set_time(hour, datetime[4], datetime[5])

def datetext_event_handler(e, obj):
    code = e.get_code()
    target = e.get_target()
    if code == lv.EVENT.FOCUSED:
        if obj is None:
            bg = lv.layer_top()
            bg.add_flag(lv.obj.FLAG.CLICKABLE)
            obj = lv.calendar(bg)
            scr = target.get_screen()
            scr_height = scr.get_height()
            scr_width = scr.get_width()
            obj.set_size(int(scr_width * 0.8), int(scr_height * 0.8))
            datestring = target.get_text()
            year = int(datestring.split('/')[0])
            month = int(datestring.split('/')[1])
            day = int(datestring.split('/')[2])
            obj.set_showed_date(year, month)
            highlighted_days=[lv.calendar_date_t({'year':year, 'month':month, 'day':day})]
            obj.set_highlighted_dates(highlighted_days, 1)
            obj.align(lv.ALIGN.CENTER, 0, 0)
            lv.calendar_header_arrow(obj)
            obj.add_event_cb(lambda e: datetext_calendar_event_handler(e, target), lv.EVENT.ALL, None)
            scr.update_layout()

def datetext_calendar_event_handler(e, obj):
    code = e.get_code()
    target = e.get_current_target()
    if code == lv.EVENT.VALUE_CHANGED:
        date = lv.calendar_date_t()
        if target.get_pressed_date(date) == lv.RES.OK:
            obj.set_text(f"{date.year}/{date.month}/{date.day}")
            bg = lv.layer_top()
            bg.clear_flag(lv.obj.FLAG.CLICKABLE)
            bg.set_style_bg_opa(lv.OPA.TRANSP, 0)
            target.delete()

def ta_event_cb(e,kb):
    code = e.get_code()
    ta = e.get_target()
    if code == lv.EVENT.FOCUSED:
        kb.set_textarea(ta)
        kb.move_foreground()
        kb.clear_flag(lv.obj.FLAG.HIDDEN)

    if code == lv.EVENT.DEFOCUSED:
        kb.set_textarea(None)
        kb.move_background()
        kb.add_flag(lv.obj.FLAG.HIDDEN)

# Create MainScreen
MainScreen = lv.obj()
g_kb_MainScreen = lv.keyboard(MainScreen)
g_kb_MainScreen.add_event_cb(lambda e: ta_event_cb(e, g_kb_MainScreen), lv.EVENT.ALL, None)
g_kb_MainScreen.add_flag(lv.obj.FLAG.HIDDEN)
g_kb_MainScreen.set_style_text_font(test_font("SourceHanSerifSC_Regular", 18), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen.set_size(800, 480)
MainScreen.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for MainScreen, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen.set_style_bg_color(lv.color_hex(0x000000), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create MainScreen_contFooter
MainScreen_contFooter = lv.obj(MainScreen)
MainScreen_contFooter.set_pos(0, 380)
MainScreen_contFooter.set_size(800, 100)
MainScreen_contFooter.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for MainScreen_contFooter, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_contFooter.set_style_border_width(1, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contFooter.set_style_border_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contFooter.set_style_border_color(lv.color_hex(0x2195f6), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contFooter.set_style_border_side(lv.BORDER_SIDE.FULL, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contFooter.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contFooter.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contFooter.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contFooter.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contFooter.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contFooter.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contFooter.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
# Create MainScreen_imgSyringe
MainScreen_imgSyringe = lv.img(MainScreen_contFooter)
MainScreen_imgSyringe.set_src("B:MicroPython/_syringe2_512_alpha_400x100.bin")
MainScreen_imgSyringe.add_flag(lv.obj.FLAG.CLICKABLE)
MainScreen_imgSyringe.set_pivot(50,50)
MainScreen_imgSyringe.set_angle(0)
MainScreen_imgSyringe.set_pos(400, 0)
MainScreen_imgSyringe.set_size(400, 100)
# Set style for MainScreen_imgSyringe, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_imgSyringe.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create MainScreen_labelDrug
MainScreen_labelDrug = lv.label(MainScreen_contFooter)
MainScreen_labelDrug.set_text("DrugName-manufacture")
MainScreen_labelDrug.set_long_mode(lv.label.LONG.WRAP)
MainScreen_labelDrug.set_width(lv.pct(100))
MainScreen_labelDrug.set_pos(0, 0)
MainScreen_labelDrug.set_size(400, 30)
# Set style for MainScreen_labelDrug, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_labelDrug.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelDrug.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelDrug.set_style_text_color(lv.color_hex(0xffff00), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelDrug.set_style_text_font(test_font("Amiko_Regular", 21), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelDrug.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelDrug.set_style_text_letter_space(1, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelDrug.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelDrug.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelDrug.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelDrug.set_style_pad_top(5, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelDrug.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelDrug.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelDrug.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelDrug.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create MainScreen_labelSyringe
MainScreen_labelSyringe = lv.label(MainScreen_contFooter)
MainScreen_labelSyringe.set_text("SyringeName-manufacture")
MainScreen_labelSyringe.set_long_mode(lv.label.LONG.WRAP)
MainScreen_labelSyringe.set_width(lv.pct(100))
MainScreen_labelSyringe.set_pos(0, 30)
MainScreen_labelSyringe.set_size(400, 30)
# Set style for MainScreen_labelSyringe, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_labelSyringe.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelSyringe.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelSyringe.set_style_text_color(lv.color_hex(0x00fff5), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelSyringe.set_style_text_font(test_font("Amiko_Regular", 21), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelSyringe.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelSyringe.set_style_text_letter_space(1, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelSyringe.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelSyringe.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelSyringe.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelSyringe.set_style_pad_top(5, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelSyringe.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelSyringe.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelSyringe.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelSyringe.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create MainScreen_labelDiameter
MainScreen_labelDiameter = lv.label(MainScreen_contFooter)
MainScreen_labelDiameter.set_text("Dia:99.9 mm")
MainScreen_labelDiameter.set_long_mode(lv.label.LONG.WRAP)
MainScreen_labelDiameter.set_width(lv.pct(100))
MainScreen_labelDiameter.set_pos(0, 60)
MainScreen_labelDiameter.set_size(400, 30)
# Set style for MainScreen_labelDiameter, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_labelDiameter.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelDiameter.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelDiameter.set_style_text_color(lv.color_hex(0xff0000), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelDiameter.set_style_text_font(test_font("Amiko_Regular", 21), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelDiameter.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelDiameter.set_style_text_letter_space(1, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelDiameter.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelDiameter.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelDiameter.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelDiameter.set_style_pad_top(5, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelDiameter.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelDiameter.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelDiameter.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelDiameter.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create MainScreen_barSyringeLevel
MainScreen_barSyringeLevel = lv.bar(MainScreen_contFooter)
MainScreen_barSyringeLevel.set_style_anim_time(1000, 0)
MainScreen_barSyringeLevel.set_mode(lv.bar.MODE.NORMAL)
MainScreen_barSyringeLevel.set_range(0, 100)
MainScreen_barSyringeLevel.set_value(50, lv.ANIM.OFF)
MainScreen_barSyringeLevel.set_pos(552, 24)
MainScreen_barSyringeLevel.set_size(177, 50)
# Set style for MainScreen_barSyringeLevel, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_barSyringeLevel.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_barSyringeLevel.set_style_radius(10, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_barSyringeLevel.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
# Set style for MainScreen_barSyringeLevel, Part: lv.PART.INDICATOR, State: lv.STATE.DEFAULT.
MainScreen_barSyringeLevel.set_style_bg_opa(151, lv.PART.INDICATOR|lv.STATE.DEFAULT)
MainScreen_barSyringeLevel.set_style_bg_color(lv.color_hex(0xb400ff), lv.PART.INDICATOR|lv.STATE.DEFAULT)
MainScreen_barSyringeLevel.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.INDICATOR|lv.STATE.DEFAULT)
MainScreen_barSyringeLevel.set_style_radius(10, lv.PART.INDICATOR|lv.STATE.DEFAULT)

# Create MainScreen_labelSyringeInfo
MainScreen_labelSyringeInfo = lv.label(MainScreen_contFooter)
MainScreen_labelSyringeInfo.set_text("Injecting")
MainScreen_labelSyringeInfo.set_long_mode(lv.label.LONG.WRAP)
MainScreen_labelSyringeInfo.set_width(lv.pct(100))
MainScreen_labelSyringeInfo.set_pos(450, 75)
MainScreen_labelSyringeInfo.set_size(100, 20)
# Set style for MainScreen_labelSyringeInfo, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_labelSyringeInfo.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelSyringeInfo.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelSyringeInfo.set_style_text_color(lv.color_hex(0xf00000), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelSyringeInfo.set_style_text_font(test_font("arial", 17), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelSyringeInfo.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelSyringeInfo.set_style_text_letter_space(1, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelSyringeInfo.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelSyringeInfo.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelSyringeInfo.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelSyringeInfo.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelSyringeInfo.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelSyringeInfo.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelSyringeInfo.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelSyringeInfo.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create MainScreen_imgForbidden
MainScreen_imgForbidden = lv.img(MainScreen_contFooter)
MainScreen_imgForbidden.set_src("B:MicroPython/_forbidden_64_alpha_64x64.bin")
MainScreen_imgForbidden.add_flag(lv.obj.FLAG.CLICKABLE)
MainScreen_imgForbidden.set_pivot(50,50)
MainScreen_imgForbidden.set_angle(0)
MainScreen_imgForbidden.set_pos(732, 16)
MainScreen_imgForbidden.set_size(64, 64)
# Set style for MainScreen_imgForbidden, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_imgForbidden.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create MainScreen_imgDroplet
MainScreen_imgDroplet = lv.img(MainScreen_contFooter)
MainScreen_imgDroplet.set_src("B:MicroPython/_droplet_32_alpha_32x32.bin")
MainScreen_imgDroplet.add_flag(lv.obj.FLAG.CLICKABLE)
MainScreen_imgDroplet.set_pivot(50,50)
MainScreen_imgDroplet.set_angle(0)
MainScreen_imgDroplet.set_pos(397, 53)
MainScreen_imgDroplet.set_size(32, 32)
# Set style for MainScreen_imgDroplet, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_imgDroplet.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create MainScreen_contHeader
MainScreen_contHeader = lv.obj(MainScreen)
MainScreen_contHeader.set_pos(0, 0)
MainScreen_contHeader.set_size(800, 80)
MainScreen_contHeader.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for MainScreen_contHeader, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_contHeader.set_style_border_width(1, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contHeader.set_style_border_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contHeader.set_style_border_color(lv.color_hex(0x2195f6), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contHeader.set_style_border_side(lv.BORDER_SIDE.FULL, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contHeader.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contHeader.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contHeader.set_style_bg_color(lv.color_hex(0x000000), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contHeader.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contHeader.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contHeader.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contHeader.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contHeader.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contHeader.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
# Create MainScreen_digital_clock
MainScreen_digital_clock_time = [int(11), int(57), int(03), "AM"]
MainScreen_digital_clock = lv.dclock(MainScreen_contHeader, "11:57:03 AM")
MainScreen_digital_clock_timer = lv.timer_create_basic()
MainScreen_digital_clock_timer.set_period(1000)
MainScreen_digital_clock_timer.set_cb(lambda src: digital_clock_cb(MainScreen_digital_clock_timer, MainScreen_digital_clock, MainScreen_digital_clock_time, True, True ))
MainScreen_digital_clock.set_pos(5, 40)
MainScreen_digital_clock.set_size(130, 36)
# Set style for MainScreen_digital_clock, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_digital_clock.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_digital_clock.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_digital_clock.set_style_text_font(test_font("montserratMedium", 19), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_digital_clock.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_digital_clock.set_style_text_letter_space(1, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_digital_clock.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_digital_clock.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_digital_clock.set_style_pad_top(7, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_digital_clock.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_digital_clock.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_digital_clock.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_digital_clock.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create MainScreen_datetext
MainScreen_datetext = lv.label(MainScreen_contHeader)
MainScreen_datetext.set_text("2024/05/05")
MainScreen_datetext.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
MainScreen_datetext.add_flag(lv.obj.FLAG.CLICKABLE)
MainScreen_datetext_calendar = None
MainScreen_datetext.add_event_cb(lambda e: datetext_event_handler(e, MainScreen_datetext_calendar), lv.EVENT.ALL, None)
MainScreen_datetext.set_pos(5, 0)
MainScreen_datetext.set_size(130, 36)
# Set style for MainScreen_datetext, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_datetext.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_datetext.set_style_text_font(test_font("montserratMedium", 18), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_datetext.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_datetext.set_style_text_letter_space(1, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_datetext.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_datetext.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_datetext.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_datetext.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_datetext.set_style_pad_top(7, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_datetext.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_datetext.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_datetext.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create MainScreen_labelAlarmNut
MainScreen_labelAlarmNut = lv.label(MainScreen_contHeader)
MainScreen_labelAlarmNut.set_text("Nut Released")
MainScreen_labelAlarmNut.set_long_mode(lv.label.LONG.WRAP)
MainScreen_labelAlarmNut.set_width(lv.pct(100))
MainScreen_labelAlarmNut.set_pos(191, 19)
MainScreen_labelAlarmNut.set_size(112, 40)
# Set style for MainScreen_labelAlarmNut, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_labelAlarmNut.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelAlarmNut.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelAlarmNut.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelAlarmNut.set_style_text_font(test_font("Alatsi_Regular", 18), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelAlarmNut.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelAlarmNut.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelAlarmNut.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelAlarmNut.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelAlarmNut.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelAlarmNut.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelAlarmNut.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelAlarmNut.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelAlarmNut.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelAlarmNut.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create MainScreen_labelAlarmPlunger
MainScreen_labelAlarmPlunger = lv.label(MainScreen_contHeader)
MainScreen_labelAlarmPlunger.set_text("Plunger Released")
MainScreen_labelAlarmPlunger.set_long_mode(lv.label.LONG.WRAP)
MainScreen_labelAlarmPlunger.set_width(lv.pct(100))
MainScreen_labelAlarmPlunger.set_pos(324, 19)
MainScreen_labelAlarmPlunger.set_size(112, 40)
# Set style for MainScreen_labelAlarmPlunger, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_labelAlarmPlunger.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelAlarmPlunger.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelAlarmPlunger.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelAlarmPlunger.set_style_text_font(test_font("Alatsi_Regular", 18), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelAlarmPlunger.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelAlarmPlunger.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelAlarmPlunger.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelAlarmPlunger.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelAlarmPlunger.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelAlarmPlunger.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelAlarmPlunger.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelAlarmPlunger.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelAlarmPlunger.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelAlarmPlunger.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create MainScreen_imgNetwork
MainScreen_imgNetwork = lv.img(MainScreen_contHeader)
MainScreen_imgNetwork.set_src("B:MicroPython/_network_64_alpha_64x64.bin")
MainScreen_imgNetwork.add_flag(lv.obj.FLAG.CLICKABLE)
MainScreen_imgNetwork.set_pivot(50,50)
MainScreen_imgNetwork.set_angle(0)
MainScreen_imgNetwork.set_pos(665, 6)
MainScreen_imgNetwork.set_size(64, 64)
# Set style for MainScreen_imgNetwork, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_imgNetwork.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create MainScreen_imgSerialPort
MainScreen_imgSerialPort = lv.img(MainScreen_contHeader)
MainScreen_imgSerialPort.set_src("B:MicroPython/_Serial_64_alpha_64x64.bin")
MainScreen_imgSerialPort.add_flag(lv.obj.FLAG.CLICKABLE)
MainScreen_imgSerialPort.set_pivot(50,50)
MainScreen_imgSerialPort.set_angle(0)
MainScreen_imgSerialPort.set_pos(579, 6)
MainScreen_imgSerialPort.set_size(64, 64)
# Set style for MainScreen_imgSerialPort, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_imgSerialPort.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create MainScreen_imgUsbPort
MainScreen_imgUsbPort = lv.img(MainScreen_contHeader)
MainScreen_imgUsbPort.set_src("B:MicroPython/_usb_64_alpha_64x64.bin")
MainScreen_imgUsbPort.add_flag(lv.obj.FLAG.CLICKABLE)
MainScreen_imgUsbPort.set_pivot(50,50)
MainScreen_imgUsbPort.set_angle(0)
MainScreen_imgUsbPort.set_pos(493, 6)
MainScreen_imgUsbPort.set_size(64, 64)
# Set style for MainScreen_imgUsbPort, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_imgUsbPort.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create MainScreen_barBatteryLevel
MainScreen_barBatteryLevel = lv.bar(MainScreen_contHeader)
MainScreen_barBatteryLevel.set_style_anim_time(1000, 0)
MainScreen_barBatteryLevel.set_mode(lv.bar.MODE.NORMAL)
MainScreen_barBatteryLevel.set_range(0, 4)
MainScreen_barBatteryLevel.set_value(2, lv.ANIM.OFF)
MainScreen_barBatteryLevel.set_pos(751, 5)
MainScreen_barBatteryLevel.set_size(38, 64)
# Set style for MainScreen_barBatteryLevel, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_barBatteryLevel.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_barBatteryLevel.set_style_radius(10, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_barBatteryLevel.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_barBatteryLevel.set_style_bg_img_src("B:MicroPython/_batterybg_64_38x64.bin", lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_barBatteryLevel.set_style_bg_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
# Set style for MainScreen_barBatteryLevel, Part: lv.PART.INDICATOR, State: lv.STATE.DEFAULT.
MainScreen_barBatteryLevel.set_style_bg_opa(0, lv.PART.INDICATOR|lv.STATE.DEFAULT)
MainScreen_barBatteryLevel.set_style_radius(10, lv.PART.INDICATOR|lv.STATE.DEFAULT)
MainScreen_barBatteryLevel.set_style_bg_img_src("B:MicroPython/_battery_64_38x64.bin", lv.PART.INDICATOR|lv.STATE.DEFAULT)
MainScreen_barBatteryLevel.set_style_bg_img_opa(255, lv.PART.INDICATOR|lv.STATE.DEFAULT)

# Create MainScreen_contMain
MainScreen_contMain = lv.obj(MainScreen)
MainScreen_contMain.set_pos(0, 80)
MainScreen_contMain.set_size(800, 300)
MainScreen_contMain.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for MainScreen_contMain, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_contMain.set_style_border_width(1, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contMain.set_style_border_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contMain.set_style_border_color(lv.color_hex(0x2195f6), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contMain.set_style_border_side(lv.BORDER_SIDE.FULL, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contMain.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contMain.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contMain.set_style_bg_color(lv.color_hex(0x000000), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contMain.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contMain.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contMain.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contMain.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contMain.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contMain.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
# Create MainScreen_barOcclusionLevel
MainScreen_barOcclusionLevel = lv.bar(MainScreen_contMain)
MainScreen_barOcclusionLevel.set_style_anim_time(1000, 0)
MainScreen_barOcclusionLevel.set_mode(lv.bar.MODE.NORMAL)
MainScreen_barOcclusionLevel.set_range(0, 11)
MainScreen_barOcclusionLevel.set_value(4, lv.ANIM.OFF)
MainScreen_barOcclusionLevel.set_pos(754, 6)
MainScreen_barOcclusionLevel.set_size(25, 132)
# Set style for MainScreen_barOcclusionLevel, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_barOcclusionLevel.set_style_bg_opa(60, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_barOcclusionLevel.set_style_bg_color(lv.color_hex(0x2195f6), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_barOcclusionLevel.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_barOcclusionLevel.set_style_radius(10, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_barOcclusionLevel.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_barOcclusionLevel.set_style_bg_img_src("B:MicroPython/_ledbar_empty_25x132.bin", lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_barOcclusionLevel.set_style_bg_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
# Set style for MainScreen_barOcclusionLevel, Part: lv.PART.INDICATOR, State: lv.STATE.DEFAULT.
MainScreen_barOcclusionLevel.set_style_bg_opa(255, lv.PART.INDICATOR|lv.STATE.DEFAULT)
MainScreen_barOcclusionLevel.set_style_bg_color(lv.color_hex(0x2195f6), lv.PART.INDICATOR|lv.STATE.DEFAULT)
MainScreen_barOcclusionLevel.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.INDICATOR|lv.STATE.DEFAULT)
MainScreen_barOcclusionLevel.set_style_radius(10, lv.PART.INDICATOR|lv.STATE.DEFAULT)
MainScreen_barOcclusionLevel.set_style_bg_img_src("B:MicroPython/_ledbar_full_25x132.bin", lv.PART.INDICATOR|lv.STATE.DEFAULT)
MainScreen_barOcclusionLevel.set_style_bg_img_opa(255, lv.PART.INDICATOR|lv.STATE.DEFAULT)

# Create MainScreen_label_1
MainScreen_label_1 = lv.label(MainScreen_contMain)
MainScreen_label_1.set_text("Mode:\n")
MainScreen_label_1.set_long_mode(lv.label.LONG.WRAP)
MainScreen_label_1.set_width(lv.pct(100))
MainScreen_label_1.set_pos(5, 4)
MainScreen_label_1.set_size(100, 35)
# Set style for MainScreen_label_1, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_label_1.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_1.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_1.set_style_text_color(lv.color_hex(0xebff00), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_1.set_style_text_font(test_font("Acme_Regular", 30), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_1.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_1.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_1.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_1.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_1.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_1.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_1.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_1.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_1.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_1.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create MainScreen_labelInjectionMode
MainScreen_labelInjectionMode = lv.label(MainScreen_contMain)
MainScreen_labelInjectionMode.set_text("Volume / Mass / Dosage\n")
MainScreen_labelInjectionMode.set_long_mode(lv.label.LONG.WRAP)
MainScreen_labelInjectionMode.set_width(lv.pct(100))
MainScreen_labelInjectionMode.set_pos(121, 3)
MainScreen_labelInjectionMode.set_size(400, 35)
# Set style for MainScreen_labelInjectionMode, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_labelInjectionMode.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelInjectionMode.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelInjectionMode.set_style_text_color(lv.color_hex(0xebff00), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelInjectionMode.set_style_text_font(test_font("arial", 33), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelInjectionMode.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelInjectionMode.set_style_text_letter_space(1, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelInjectionMode.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelInjectionMode.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelInjectionMode.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelInjectionMode.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelInjectionMode.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelInjectionMode.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelInjectionMode.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelInjectionMode.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create MainScreen_label_2
MainScreen_label_2 = lv.label(MainScreen_contMain)
MainScreen_label_2.set_text("Rate:\n")
MainScreen_label_2.set_long_mode(lv.label.LONG.WRAP)
MainScreen_label_2.set_width(lv.pct(100))
MainScreen_label_2.set_pos(5, 45)
MainScreen_label_2.set_size(100, 35)
# Set style for MainScreen_label_2, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_label_2.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_2.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_2.set_style_text_color(lv.color_hex(0xff0027), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_2.set_style_text_font(test_font("Acme_Regular", 30), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_2.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_2.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_2.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_2.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_2.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_2.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_2.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_2.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_2.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_2.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create MainScreen_labelInjectionRate
MainScreen_labelInjectionRate = lv.label(MainScreen_contMain)
MainScreen_labelInjectionRate.set_text("100.0 ml/min\n\n")
MainScreen_labelInjectionRate.set_long_mode(lv.label.LONG.WRAP)
MainScreen_labelInjectionRate.set_width(lv.pct(100))
MainScreen_labelInjectionRate.set_pos(121, 44)
MainScreen_labelInjectionRate.set_size(400, 35)
# Set style for MainScreen_labelInjectionRate, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_labelInjectionRate.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelInjectionRate.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelInjectionRate.set_style_text_color(lv.color_hex(0xff0027), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelInjectionRate.set_style_text_font(test_font("arial", 35), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelInjectionRate.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelInjectionRate.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelInjectionRate.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelInjectionRate.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelInjectionRate.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelInjectionRate.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelInjectionRate.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelInjectionRate.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelInjectionRate.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelInjectionRate.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create MainScreen_label_Error
MainScreen_label_Error = lv.label(MainScreen_contMain)
MainScreen_label_Error.set_text("Plunger Sensor Error")
MainScreen_label_Error.set_long_mode(lv.label.LONG.WRAP)
MainScreen_label_Error.set_width(lv.pct(100))
MainScreen_label_Error.set_pos(250, 270)
MainScreen_label_Error.set_size(300, 30)
# Set style for MainScreen_label_Error, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_label_Error.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_Error.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_Error.set_style_text_color(lv.color_hex(0xff0027), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_Error.set_style_text_font(test_font("arial", 25), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_Error.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_Error.set_style_text_letter_space(1, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_Error.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_Error.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_Error.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_Error.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_Error.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_Error.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_Error.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_Error.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create MainScreen_labelInjectedVolume
MainScreen_labelInjectedVolume = lv.label(MainScreen_contMain)
MainScreen_labelInjectedVolume.set_text("100.1 ml")
MainScreen_labelInjectedVolume.set_long_mode(lv.label.LONG.WRAP)
MainScreen_labelInjectedVolume.set_width(lv.pct(100))
MainScreen_labelInjectedVolume.set_pos(0, 94)
MainScreen_labelInjectedVolume.set_size(411, 92)
# Set style for MainScreen_labelInjectedVolume, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_labelInjectedVolume.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelInjectedVolume.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelInjectedVolume.set_style_text_color(lv.color_hex(0xff6500), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelInjectedVolume.set_style_text_font(test_font("arial", 100), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelInjectedVolume.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelInjectedVolume.set_style_text_letter_space(1, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelInjectedVolume.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelInjectedVolume.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelInjectedVolume.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelInjectedVolume.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelInjectedVolume.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelInjectedVolume.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelInjectedVolume.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelInjectedVolume.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create MainScreen_label_3
MainScreen_label_3 = lv.label(MainScreen_contMain)
MainScreen_label_3.set_text("Patient Weight:")
MainScreen_label_3.set_long_mode(lv.label.LONG.WRAP)
MainScreen_label_3.set_width(lv.pct(100))
MainScreen_label_3.set_pos(18, 195)
MainScreen_label_3.set_size(166, 22)
# Set style for MainScreen_label_3, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_label_3.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_3.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_3.set_style_text_color(lv.color_hex(0x2195F6), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_3.set_style_text_font(test_font("Acme_Regular", 20), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_3.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_3.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_3.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_3.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_3.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_3.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_3.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_3.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_3.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_3.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create MainScreen_label_4
MainScreen_label_4 = lv.label(MainScreen_contMain)
MainScreen_label_4.set_text("Total:")
MainScreen_label_4.set_long_mode(lv.label.LONG.WRAP)
MainScreen_label_4.set_width(lv.pct(100))
MainScreen_label_4.set_pos(18, 225)
MainScreen_label_4.set_size(65, 19)
# Set style for MainScreen_label_4, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_label_4.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_4.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_4.set_style_text_color(lv.color_hex(0x2195F6), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_4.set_style_text_font(test_font("Acme_Regular", 20), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_4.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_4.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_4.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_4.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_4.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_4.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_4.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_4.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_4.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_4.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create MainScreen_label_5
MainScreen_label_5 = lv.label(MainScreen_contMain)
MainScreen_label_5.set_text("Rem:")
MainScreen_label_5.set_long_mode(lv.label.LONG.WRAP)
MainScreen_label_5.set_width(lv.pct(100))
MainScreen_label_5.set_pos(391, 195)
MainScreen_label_5.set_size(52, 19)
# Set style for MainScreen_label_5, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_label_5.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_5.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_5.set_style_text_color(lv.color_hex(0x2195F6), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_5.set_style_text_font(test_font("Acme_Regular", 20), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_5.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_5.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_5.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_5.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_5.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_5.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_5.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_5.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_5.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_5.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create MainScreen_label_6
MainScreen_label_6 = lv.label(MainScreen_contMain)
MainScreen_label_6.set_text("Time Left:")
MainScreen_label_6.set_long_mode(lv.label.LONG.WRAP)
MainScreen_label_6.set_width(lv.pct(100))
MainScreen_label_6.set_pos(391, 225)
MainScreen_label_6.set_size(110, 19)
# Set style for MainScreen_label_6, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_label_6.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_6.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_6.set_style_text_color(lv.color_hex(0x2195F6), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_6.set_style_text_font(test_font("Acme_Regular", 20), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_6.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_6.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_6.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_6.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_6.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_6.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_6.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_6.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_6.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_6.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create MainScreen_labelTimeLeft
MainScreen_labelTimeLeft = lv.label(MainScreen_contMain)
MainScreen_labelTimeLeft.set_text("00:09:53")
MainScreen_labelTimeLeft.set_long_mode(lv.label.LONG.WRAP)
MainScreen_labelTimeLeft.set_width(lv.pct(100))
MainScreen_labelTimeLeft.set_pos(510, 225)
MainScreen_labelTimeLeft.set_size(110, 19)
# Set style for MainScreen_labelTimeLeft, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_labelTimeLeft.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelTimeLeft.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelTimeLeft.set_style_text_color(lv.color_hex(0x2195F6), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelTimeLeft.set_style_text_font(test_font("Acme_Regular", 22), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelTimeLeft.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelTimeLeft.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelTimeLeft.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelTimeLeft.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelTimeLeft.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelTimeLeft.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelTimeLeft.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelTimeLeft.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelTimeLeft.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelTimeLeft.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create MainScreen_labelRemVolume
MainScreen_labelRemVolume = lv.label(MainScreen_contMain)
MainScreen_labelRemVolume.set_text("180.0 ml")
MainScreen_labelRemVolume.set_long_mode(lv.label.LONG.WRAP)
MainScreen_labelRemVolume.set_width(lv.pct(100))
MainScreen_labelRemVolume.set_pos(449, 195)
MainScreen_labelRemVolume.set_size(100, 19)
# Set style for MainScreen_labelRemVolume, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_labelRemVolume.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelRemVolume.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelRemVolume.set_style_text_color(lv.color_hex(0x2195F6), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelRemVolume.set_style_text_font(test_font("Acme_Regular", 22), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelRemVolume.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelRemVolume.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelRemVolume.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelRemVolume.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelRemVolume.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelRemVolume.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelRemVolume.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelRemVolume.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelRemVolume.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelRemVolume.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create MainScreen_labelPatientKg
MainScreen_labelPatientKg = lv.label(MainScreen_contMain)
MainScreen_labelPatientKg.set_text("120 kg")
MainScreen_labelPatientKg.set_long_mode(lv.label.LONG.WRAP)
MainScreen_labelPatientKg.set_width(lv.pct(100))
MainScreen_labelPatientKg.set_pos(190, 195)
MainScreen_labelPatientKg.set_size(76, 22)
# Set style for MainScreen_labelPatientKg, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_labelPatientKg.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelPatientKg.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelPatientKg.set_style_text_color(lv.color_hex(0x2195F6), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelPatientKg.set_style_text_font(test_font("Acme_Regular", 22), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelPatientKg.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelPatientKg.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelPatientKg.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelPatientKg.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelPatientKg.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelPatientKg.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelPatientKg.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelPatientKg.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelPatientKg.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelPatientKg.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create MainScreen_labelTotalVolume
MainScreen_labelTotalVolume = lv.label(MainScreen_contMain)
MainScreen_labelTotalVolume.set_text("180.0 ml")
MainScreen_labelTotalVolume.set_long_mode(lv.label.LONG.WRAP)
MainScreen_labelTotalVolume.set_width(lv.pct(100))
MainScreen_labelTotalVolume.set_pos(88, 225)
MainScreen_labelTotalVolume.set_size(100, 19)
# Set style for MainScreen_labelTotalVolume, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_labelTotalVolume.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelTotalVolume.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelTotalVolume.set_style_text_color(lv.color_hex(0x2195F6), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelTotalVolume.set_style_text_font(test_font("Acme_Regular", 22), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelTotalVolume.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelTotalVolume.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelTotalVolume.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelTotalVolume.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelTotalVolume.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelTotalVolume.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelTotalVolume.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelTotalVolume.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelTotalVolume.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_labelTotalVolume.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create MainScreen_btnGoSetting
MainScreen_btnGoSetting = lv.btn(MainScreen_contMain)
MainScreen_btnGoSetting_label = lv.label(MainScreen_btnGoSetting)
MainScreen_btnGoSetting_label.set_text("")
MainScreen_btnGoSetting_label.set_long_mode(lv.label.LONG.WRAP)
MainScreen_btnGoSetting_label.set_width(lv.pct(100))
MainScreen_btnGoSetting_label.align(lv.ALIGN.CENTER, 0, 0)
MainScreen_btnGoSetting.set_style_pad_all(0, lv.STATE.DEFAULT)
MainScreen_btnGoSetting.set_pos(728, 247)
MainScreen_btnGoSetting.set_size(58, 44)
# Set style for MainScreen_btnGoSetting, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_btnGoSetting.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnGoSetting.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnGoSetting.set_style_radius(5, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnGoSetting.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnGoSetting.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnGoSetting.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnGoSetting.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnGoSetting.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create MainScreen_contSetting
MainScreen_contSetting = lv.obj(MainScreen)
MainScreen_contSetting.set_pos(800, 80)
MainScreen_contSetting.set_size(800, 300)
MainScreen_contSetting.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for MainScreen_contSetting, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_contSetting.set_style_border_width(1, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contSetting.set_style_border_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contSetting.set_style_border_color(lv.color_hex(0x2195f6), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contSetting.set_style_border_side(lv.BORDER_SIDE.FULL, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contSetting.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contSetting.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contSetting.set_style_bg_color(lv.color_hex(0x000000), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contSetting.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contSetting.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contSetting.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contSetting.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contSetting.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contSetting.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
# Create MainScreen_btnGoMain
MainScreen_btnGoMain = lv.btn(MainScreen_contSetting)
MainScreen_btnGoMain_label = lv.label(MainScreen_btnGoMain)
MainScreen_btnGoMain_label.set_text("")
MainScreen_btnGoMain_label.set_long_mode(lv.label.LONG.WRAP)
MainScreen_btnGoMain_label.set_width(lv.pct(100))
MainScreen_btnGoMain_label.align(lv.ALIGN.CENTER, 0, 0)
MainScreen_btnGoMain.set_style_pad_all(0, lv.STATE.DEFAULT)
MainScreen_btnGoMain.set_pos(732, 247)
MainScreen_btnGoMain.set_size(58, 44)
# Set style for MainScreen_btnGoMain, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_btnGoMain.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnGoMain.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnGoMain.set_style_radius(5, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnGoMain.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnGoMain.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnGoMain.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnGoMain.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnGoMain.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create MainScreen_label_7
MainScreen_label_7 = lv.label(MainScreen_contSetting)
MainScreen_label_7.set_text("Syringe")
MainScreen_label_7.set_long_mode(lv.label.LONG.WRAP)
MainScreen_label_7.set_width(lv.pct(100))
MainScreen_label_7.set_pos(25, 105)
MainScreen_label_7.set_size(100, 50)
# Set style for MainScreen_label_7, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_label_7.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_7.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_7.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_7.set_style_text_font(test_font("Acme_Regular", 26), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_7.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_7.set_style_text_letter_space(1, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_7.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_7.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_7.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_7.set_style_pad_top(10, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_7.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_7.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_7.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_7.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create MainScreen_label_9
MainScreen_label_9 = lv.label(MainScreen_contSetting)
MainScreen_label_9.set_text("Drug")
MainScreen_label_9.set_long_mode(lv.label.LONG.WRAP)
MainScreen_label_9.set_width(lv.pct(100))
MainScreen_label_9.set_pos(155, 105)
MainScreen_label_9.set_size(100, 50)
# Set style for MainScreen_label_9, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_label_9.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_9.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_9.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_9.set_style_text_font(test_font("Acme_Regular", 25), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_9.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_9.set_style_text_letter_space(1, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_9.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_9.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_9.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_9.set_style_pad_top(10, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_9.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_9.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_9.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_9.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create MainScreen_label_10
MainScreen_label_10 = lv.label(MainScreen_contSetting)
MainScreen_label_10.set_text("Mode")
MainScreen_label_10.set_long_mode(lv.label.LONG.WRAP)
MainScreen_label_10.set_width(lv.pct(100))
MainScreen_label_10.set_pos(285, 105)
MainScreen_label_10.set_size(100, 50)
# Set style for MainScreen_label_10, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_label_10.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_10.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_10.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_10.set_style_text_font(test_font("Acme_Regular", 28), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_10.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_10.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_10.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_10.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_10.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_10.set_style_pad_top(10, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_10.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_10.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_10.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_10.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create MainScreen_label_11
MainScreen_label_11 = lv.label(MainScreen_contSetting)
MainScreen_label_11.set_text("OCC. Pressure")
MainScreen_label_11.set_long_mode(lv.label.LONG.WRAP)
MainScreen_label_11.set_width(lv.pct(100))
MainScreen_label_11.set_pos(415, 105)
MainScreen_label_11.set_size(100, 50)
# Set style for MainScreen_label_11, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_label_11.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_11.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_11.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_11.set_style_text_font(test_font("Acme_Regular", 22), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_11.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_11.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_11.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_11.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_11.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_11.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_11.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_11.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_11.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_11.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create MainScreen_label_12
MainScreen_label_12 = lv.label(MainScreen_contSetting)
MainScreen_label_12.set_text("KVO")
MainScreen_label_12.set_long_mode(lv.label.LONG.WRAP)
MainScreen_label_12.set_width(lv.pct(100))
MainScreen_label_12.set_pos(545, 105)
MainScreen_label_12.set_size(100, 50)
# Set style for MainScreen_label_12, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_label_12.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_12.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_12.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_12.set_style_text_font(test_font("Acme_Regular", 28), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_12.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_12.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_12.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_12.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_12.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_12.set_style_pad_top(11, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_12.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_12.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_12.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_12.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create MainScreen_label_13
MainScreen_label_13 = lv.label(MainScreen_contSetting)
MainScreen_label_13.set_text("Intermittent Infusion")
MainScreen_label_13.set_long_mode(lv.label.LONG.WRAP)
MainScreen_label_13.set_width(lv.pct(100))
MainScreen_label_13.set_pos(668, 110)
MainScreen_label_13.set_size(115, 50)
# Set style for MainScreen_label_13, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_label_13.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_13.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_13.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_13.set_style_text_font(test_font("Acme_Regular", 22), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_13.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_13.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_13.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_13.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_13.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_13.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_13.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_13.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_13.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_13.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create MainScreen_label_8
MainScreen_label_8 = lv.label(MainScreen_contSetting)
MainScreen_label_8.set_text("Rhythmic Infusion")
MainScreen_label_8.set_long_mode(lv.label.LONG.WRAP)
MainScreen_label_8.set_width(lv.pct(100))
MainScreen_label_8.set_pos(25, 250)
MainScreen_label_8.set_size(100, 50)
# Set style for MainScreen_label_8, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_label_8.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_8.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_8.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_8.set_style_text_font(test_font("Acme_Regular", 24), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_8.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_8.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_8.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_8.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_8.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_8.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_8.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_8.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_8.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_8.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create MainScreen_label_14
MainScreen_label_14 = lv.label(MainScreen_contSetting)
MainScreen_label_14.set_text("Nurse Call")
MainScreen_label_14.set_long_mode(lv.label.LONG.WRAP)
MainScreen_label_14.set_width(lv.pct(100))
MainScreen_label_14.set_pos(155, 250)
MainScreen_label_14.set_size(100, 50)
# Set style for MainScreen_label_14, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_label_14.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_14.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_14.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_14.set_style_text_font(test_font("Acme_Regular", 25), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_14.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_14.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_14.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_14.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_14.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_14.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_14.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_14.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_14.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_14.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create MainScreen_label_15
MainScreen_label_15 = lv.label(MainScreen_contSetting)
MainScreen_label_15.set_text("Bolus")
MainScreen_label_15.set_long_mode(lv.label.LONG.WRAP)
MainScreen_label_15.set_width(lv.pct(100))
MainScreen_label_15.set_pos(285, 250)
MainScreen_label_15.set_size(100, 50)
# Set style for MainScreen_label_15, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_label_15.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_15.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_15.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_15.set_style_text_font(test_font("Acme_Regular", 24), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_15.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_15.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_15.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_15.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_15.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_15.set_style_pad_top(11, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_15.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_15.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_15.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_15.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create MainScreen_label_16
MainScreen_label_16 = lv.label(MainScreen_contSetting)
MainScreen_label_16.set_text("Purge")
MainScreen_label_16.set_long_mode(lv.label.LONG.WRAP)
MainScreen_label_16.set_width(lv.pct(100))
MainScreen_label_16.set_pos(415, 250)
MainScreen_label_16.set_size(100, 50)
# Set style for MainScreen_label_16, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_label_16.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_16.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_16.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_16.set_style_text_font(test_font("Acme_Regular", 24), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_16.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_16.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_16.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_16.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_16.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_16.set_style_pad_top(11, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_16.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_16.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_16.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_16.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create MainScreen_label_17
MainScreen_label_17 = lv.label(MainScreen_contSetting)
MainScreen_label_17.set_text("Setting")
MainScreen_label_17.set_long_mode(lv.label.LONG.WRAP)
MainScreen_label_17.set_width(lv.pct(100))
MainScreen_label_17.set_pos(544, 249)
MainScreen_label_17.set_size(100, 50)
# Set style for MainScreen_label_17, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_label_17.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_17.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_17.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_17.set_style_text_font(test_font("Acme_Regular", 24), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_17.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_17.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_17.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_17.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_17.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_17.set_style_pad_top(11, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_17.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_17.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_17.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_label_17.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create MainScreen_btnMenuSyringe
MainScreen_btnMenuSyringe = lv.btn(MainScreen_contSetting)
MainScreen_btnMenuSyringe_label = lv.label(MainScreen_btnMenuSyringe)
MainScreen_btnMenuSyringe_label.set_text("")
MainScreen_btnMenuSyringe_label.set_long_mode(lv.label.LONG.WRAP)
MainScreen_btnMenuSyringe_label.set_width(lv.pct(100))
MainScreen_btnMenuSyringe_label.align(lv.ALIGN.CENTER, 0, 0)
MainScreen_btnMenuSyringe.set_style_pad_all(0, lv.STATE.DEFAULT)
MainScreen_btnMenuSyringe.set_pos(25, 5)
MainScreen_btnMenuSyringe.set_size(100, 100)
# Set style for MainScreen_btnMenuSyringe, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_btnMenuSyringe.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuSyringe.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuSyringe.set_style_radius(5, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuSyringe.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuSyringe.set_style_bg_img_src("B:MicroPython/_Syringe_100_100x100.bin", lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuSyringe.set_style_bg_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuSyringe.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuSyringe.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuSyringe.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuSyringe.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
# Set style for MainScreen_btnMenuSyringe, Part: lv.PART.MAIN, State: lv.STATE.FOCUSED.
MainScreen_btnMenuSyringe.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuSyringe.set_style_bg_color(lv.color_hex(0x2195f6), lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuSyringe.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuSyringe.set_style_border_width(0, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuSyringe.set_style_radius(5, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuSyringe.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuSyringe.set_style_bg_img_src("B:MicroPython/_Syringe_100_100x100.bin", lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuSyringe.set_style_bg_img_opa(255, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuSyringe.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuSyringe.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuSyringe.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.FOCUSED)

# Create MainScreen_btnMenuDrug
MainScreen_btnMenuDrug = lv.btn(MainScreen_contSetting)
MainScreen_btnMenuDrug_label = lv.label(MainScreen_btnMenuDrug)
MainScreen_btnMenuDrug_label.set_text("")
MainScreen_btnMenuDrug_label.set_long_mode(lv.label.LONG.WRAP)
MainScreen_btnMenuDrug_label.set_width(lv.pct(100))
MainScreen_btnMenuDrug_label.align(lv.ALIGN.CENTER, 0, 0)
MainScreen_btnMenuDrug.set_style_pad_all(0, lv.STATE.DEFAULT)
MainScreen_btnMenuDrug.set_pos(155, 5)
MainScreen_btnMenuDrug.set_size(100, 100)
# Set style for MainScreen_btnMenuDrug, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_btnMenuDrug.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuDrug.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuDrug.set_style_radius(5, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuDrug.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuDrug.set_style_bg_img_src("B:MicroPython/_Syringe_100_100x100.bin", lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuDrug.set_style_bg_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuDrug.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuDrug.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuDrug.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuDrug.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
# Set style for MainScreen_btnMenuDrug, Part: lv.PART.MAIN, State: lv.STATE.FOCUSED.
MainScreen_btnMenuDrug.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuDrug.set_style_bg_color(lv.color_hex(0x2195f6), lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuDrug.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuDrug.set_style_border_width(0, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuDrug.set_style_radius(5, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuDrug.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuDrug.set_style_bg_img_src("B:MicroPython/_Syringe_100_100x100.bin", lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuDrug.set_style_bg_img_opa(255, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuDrug.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuDrug.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuDrug.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.FOCUSED)

# Create MainScreen_btnMenuMode
MainScreen_btnMenuMode = lv.btn(MainScreen_contSetting)
MainScreen_btnMenuMode_label = lv.label(MainScreen_btnMenuMode)
MainScreen_btnMenuMode_label.set_text("")
MainScreen_btnMenuMode_label.set_long_mode(lv.label.LONG.WRAP)
MainScreen_btnMenuMode_label.set_width(lv.pct(100))
MainScreen_btnMenuMode_label.align(lv.ALIGN.CENTER, 0, 0)
MainScreen_btnMenuMode.set_style_pad_all(0, lv.STATE.DEFAULT)
MainScreen_btnMenuMode.set_pos(285, 5)
MainScreen_btnMenuMode.set_size(100, 100)
# Set style for MainScreen_btnMenuMode, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_btnMenuMode.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuMode.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuMode.set_style_radius(5, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuMode.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuMode.set_style_bg_img_src("B:MicroPython/_Syringe_100_100x100.bin", lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuMode.set_style_bg_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuMode.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuMode.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuMode.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuMode.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
# Set style for MainScreen_btnMenuMode, Part: lv.PART.MAIN, State: lv.STATE.FOCUSED.
MainScreen_btnMenuMode.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuMode.set_style_bg_color(lv.color_hex(0x2195f6), lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuMode.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuMode.set_style_border_width(0, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuMode.set_style_radius(5, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuMode.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuMode.set_style_bg_img_src("B:MicroPython/_Syringe_100_100x100.bin", lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuMode.set_style_bg_img_opa(255, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuMode.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuMode.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuMode.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.FOCUSED)

# Create MainScreen_btnMenuOCC
MainScreen_btnMenuOCC = lv.btn(MainScreen_contSetting)
MainScreen_btnMenuOCC_label = lv.label(MainScreen_btnMenuOCC)
MainScreen_btnMenuOCC_label.set_text("")
MainScreen_btnMenuOCC_label.set_long_mode(lv.label.LONG.WRAP)
MainScreen_btnMenuOCC_label.set_width(lv.pct(100))
MainScreen_btnMenuOCC_label.align(lv.ALIGN.CENTER, 0, 0)
MainScreen_btnMenuOCC.set_style_pad_all(0, lv.STATE.DEFAULT)
MainScreen_btnMenuOCC.set_pos(415, 5)
MainScreen_btnMenuOCC.set_size(100, 100)
# Set style for MainScreen_btnMenuOCC, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_btnMenuOCC.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuOCC.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuOCC.set_style_radius(5, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuOCC.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuOCC.set_style_bg_img_src("B:MicroPython/_Syringe_100_100x100.bin", lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuOCC.set_style_bg_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuOCC.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuOCC.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuOCC.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuOCC.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
# Set style for MainScreen_btnMenuOCC, Part: lv.PART.MAIN, State: lv.STATE.FOCUSED.
MainScreen_btnMenuOCC.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuOCC.set_style_bg_color(lv.color_hex(0x2195f6), lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuOCC.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuOCC.set_style_border_width(0, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuOCC.set_style_radius(5, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuOCC.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuOCC.set_style_bg_img_src("B:MicroPython/_Syringe_100_100x100.bin", lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuOCC.set_style_bg_img_opa(255, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuOCC.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuOCC.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuOCC.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.FOCUSED)

# Create MainScreen_btnMenuKVO
MainScreen_btnMenuKVO = lv.btn(MainScreen_contSetting)
MainScreen_btnMenuKVO_label = lv.label(MainScreen_btnMenuKVO)
MainScreen_btnMenuKVO_label.set_text("")
MainScreen_btnMenuKVO_label.set_long_mode(lv.label.LONG.WRAP)
MainScreen_btnMenuKVO_label.set_width(lv.pct(100))
MainScreen_btnMenuKVO_label.align(lv.ALIGN.CENTER, 0, 0)
MainScreen_btnMenuKVO.set_style_pad_all(0, lv.STATE.DEFAULT)
MainScreen_btnMenuKVO.set_pos(545, 5)
MainScreen_btnMenuKVO.set_size(100, 100)
# Set style for MainScreen_btnMenuKVO, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_btnMenuKVO.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuKVO.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuKVO.set_style_radius(5, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuKVO.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuKVO.set_style_bg_img_src("B:MicroPython/_Syringe_100_100x100.bin", lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuKVO.set_style_bg_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuKVO.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuKVO.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuKVO.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuKVO.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
# Set style for MainScreen_btnMenuKVO, Part: lv.PART.MAIN, State: lv.STATE.FOCUSED.
MainScreen_btnMenuKVO.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuKVO.set_style_bg_color(lv.color_hex(0x2195f6), lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuKVO.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuKVO.set_style_border_width(0, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuKVO.set_style_radius(5, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuKVO.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuKVO.set_style_bg_img_src("B:MicroPython/_Syringe_100_100x100.bin", lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuKVO.set_style_bg_img_opa(255, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuKVO.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuKVO.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuKVO.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.FOCUSED)

# Create MainScreen_btnMenuIntInf
MainScreen_btnMenuIntInf = lv.btn(MainScreen_contSetting)
MainScreen_btnMenuIntInf_label = lv.label(MainScreen_btnMenuIntInf)
MainScreen_btnMenuIntInf_label.set_text("")
MainScreen_btnMenuIntInf_label.set_long_mode(lv.label.LONG.WRAP)
MainScreen_btnMenuIntInf_label.set_width(lv.pct(100))
MainScreen_btnMenuIntInf_label.align(lv.ALIGN.CENTER, 0, 0)
MainScreen_btnMenuIntInf.set_style_pad_all(0, lv.STATE.DEFAULT)
MainScreen_btnMenuIntInf.set_pos(675, 5)
MainScreen_btnMenuIntInf.set_size(100, 100)
# Set style for MainScreen_btnMenuIntInf, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_btnMenuIntInf.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuIntInf.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuIntInf.set_style_radius(5, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuIntInf.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuIntInf.set_style_bg_img_src("B:MicroPython/_Syringe_100_100x100.bin", lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuIntInf.set_style_bg_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuIntInf.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuIntInf.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuIntInf.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuIntInf.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
# Set style for MainScreen_btnMenuIntInf, Part: lv.PART.MAIN, State: lv.STATE.FOCUSED.
MainScreen_btnMenuIntInf.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuIntInf.set_style_bg_color(lv.color_hex(0x2195f6), lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuIntInf.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuIntInf.set_style_border_width(0, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuIntInf.set_style_radius(5, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuIntInf.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuIntInf.set_style_bg_img_src("B:MicroPython/_Syringe_100_100x100.bin", lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuIntInf.set_style_bg_img_opa(255, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuIntInf.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuIntInf.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuIntInf.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.FOCUSED)

# Create MainScreen_btnMenuRhyInf
MainScreen_btnMenuRhyInf = lv.btn(MainScreen_contSetting)
MainScreen_btnMenuRhyInf_label = lv.label(MainScreen_btnMenuRhyInf)
MainScreen_btnMenuRhyInf_label.set_text("")
MainScreen_btnMenuRhyInf_label.set_long_mode(lv.label.LONG.WRAP)
MainScreen_btnMenuRhyInf_label.set_width(lv.pct(100))
MainScreen_btnMenuRhyInf_label.align(lv.ALIGN.CENTER, 0, 0)
MainScreen_btnMenuRhyInf.set_style_pad_all(0, lv.STATE.DEFAULT)
MainScreen_btnMenuRhyInf.set_pos(25, 150)
MainScreen_btnMenuRhyInf.set_size(100, 100)
# Set style for MainScreen_btnMenuRhyInf, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_btnMenuRhyInf.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuRhyInf.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuRhyInf.set_style_radius(5, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuRhyInf.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuRhyInf.set_style_bg_img_src("B:MicroPython/_Syringe_100_100x100.bin", lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuRhyInf.set_style_bg_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuRhyInf.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuRhyInf.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuRhyInf.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuRhyInf.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
# Set style for MainScreen_btnMenuRhyInf, Part: lv.PART.MAIN, State: lv.STATE.FOCUSED.
MainScreen_btnMenuRhyInf.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuRhyInf.set_style_bg_color(lv.color_hex(0x2195f6), lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuRhyInf.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuRhyInf.set_style_border_width(0, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuRhyInf.set_style_radius(5, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuRhyInf.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuRhyInf.set_style_bg_img_src("B:MicroPython/_Syringe_100_100x100.bin", lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuRhyInf.set_style_bg_img_opa(255, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuRhyInf.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuRhyInf.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuRhyInf.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.FOCUSED)

# Create MainScreen_btnMenuNurseCall
MainScreen_btnMenuNurseCall = lv.btn(MainScreen_contSetting)
MainScreen_btnMenuNurseCall_label = lv.label(MainScreen_btnMenuNurseCall)
MainScreen_btnMenuNurseCall_label.set_text("")
MainScreen_btnMenuNurseCall_label.set_long_mode(lv.label.LONG.WRAP)
MainScreen_btnMenuNurseCall_label.set_width(lv.pct(100))
MainScreen_btnMenuNurseCall_label.align(lv.ALIGN.CENTER, 0, 0)
MainScreen_btnMenuNurseCall.set_style_pad_all(0, lv.STATE.DEFAULT)
MainScreen_btnMenuNurseCall.set_pos(155, 150)
MainScreen_btnMenuNurseCall.set_size(100, 100)
# Set style for MainScreen_btnMenuNurseCall, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_btnMenuNurseCall.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuNurseCall.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuNurseCall.set_style_radius(5, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuNurseCall.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuNurseCall.set_style_bg_img_src("B:MicroPython/_Nurse_100_100x100.bin", lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuNurseCall.set_style_bg_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuNurseCall.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuNurseCall.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuNurseCall.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuNurseCall.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
# Set style for MainScreen_btnMenuNurseCall, Part: lv.PART.MAIN, State: lv.STATE.FOCUSED.
MainScreen_btnMenuNurseCall.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuNurseCall.set_style_bg_color(lv.color_hex(0x2195f6), lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuNurseCall.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuNurseCall.set_style_border_width(0, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuNurseCall.set_style_radius(5, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuNurseCall.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuNurseCall.set_style_bg_img_src("B:MicroPython/_Nurse_100_100x100.bin", lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuNurseCall.set_style_bg_img_opa(255, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuNurseCall.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuNurseCall.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuNurseCall.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.FOCUSED)

# Create MainScreen_btnMenuBolus
MainScreen_btnMenuBolus = lv.btn(MainScreen_contSetting)
MainScreen_btnMenuBolus_label = lv.label(MainScreen_btnMenuBolus)
MainScreen_btnMenuBolus_label.set_text("")
MainScreen_btnMenuBolus_label.set_long_mode(lv.label.LONG.WRAP)
MainScreen_btnMenuBolus_label.set_width(lv.pct(100))
MainScreen_btnMenuBolus_label.align(lv.ALIGN.CENTER, 0, 0)
MainScreen_btnMenuBolus.set_style_pad_all(0, lv.STATE.DEFAULT)
MainScreen_btnMenuBolus.set_pos(285, 150)
MainScreen_btnMenuBolus.set_size(100, 100)
# Set style for MainScreen_btnMenuBolus, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_btnMenuBolus.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuBolus.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuBolus.set_style_radius(5, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuBolus.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuBolus.set_style_bg_img_src("B:MicroPython/_Bolus_100_100x100.bin", lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuBolus.set_style_bg_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuBolus.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuBolus.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuBolus.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuBolus.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
# Set style for MainScreen_btnMenuBolus, Part: lv.PART.MAIN, State: lv.STATE.FOCUSED.
MainScreen_btnMenuBolus.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuBolus.set_style_bg_color(lv.color_hex(0x2195f6), lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuBolus.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuBolus.set_style_border_width(0, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuBolus.set_style_radius(5, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuBolus.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuBolus.set_style_bg_img_src("B:MicroPython/_Bolus_100_100x100.bin", lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuBolus.set_style_bg_img_opa(255, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuBolus.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuBolus.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuBolus.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.FOCUSED)

# Create MainScreen_btnMenuPurge
MainScreen_btnMenuPurge = lv.btn(MainScreen_contSetting)
MainScreen_btnMenuPurge_label = lv.label(MainScreen_btnMenuPurge)
MainScreen_btnMenuPurge_label.set_text("")
MainScreen_btnMenuPurge_label.set_long_mode(lv.label.LONG.WRAP)
MainScreen_btnMenuPurge_label.set_width(lv.pct(100))
MainScreen_btnMenuPurge_label.align(lv.ALIGN.CENTER, 0, 0)
MainScreen_btnMenuPurge.set_style_pad_all(0, lv.STATE.DEFAULT)
MainScreen_btnMenuPurge.set_pos(415, 150)
MainScreen_btnMenuPurge.set_size(100, 100)
# Set style for MainScreen_btnMenuPurge, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_btnMenuPurge.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuPurge.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuPurge.set_style_radius(5, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuPurge.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuPurge.set_style_bg_img_src("B:MicroPython/_Purge_100_100x100.bin", lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuPurge.set_style_bg_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuPurge.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuPurge.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuPurge.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuPurge.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
# Set style for MainScreen_btnMenuPurge, Part: lv.PART.MAIN, State: lv.STATE.FOCUSED.
MainScreen_btnMenuPurge.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuPurge.set_style_bg_color(lv.color_hex(0x2195f6), lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuPurge.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuPurge.set_style_border_width(0, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuPurge.set_style_radius(5, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuPurge.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuPurge.set_style_bg_img_src("B:MicroPython/_Purge_100_100x100.bin", lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuPurge.set_style_bg_img_opa(255, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuPurge.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuPurge.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuPurge.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.FOCUSED)

# Create MainScreen_btnMenuSetting
MainScreen_btnMenuSetting = lv.btn(MainScreen_contSetting)
MainScreen_btnMenuSetting_label = lv.label(MainScreen_btnMenuSetting)
MainScreen_btnMenuSetting_label.set_text("")
MainScreen_btnMenuSetting_label.set_long_mode(lv.label.LONG.WRAP)
MainScreen_btnMenuSetting_label.set_width(lv.pct(100))
MainScreen_btnMenuSetting_label.align(lv.ALIGN.CENTER, 0, 0)
MainScreen_btnMenuSetting.set_style_pad_all(0, lv.STATE.DEFAULT)
MainScreen_btnMenuSetting.set_pos(545, 150)
MainScreen_btnMenuSetting.set_size(100, 100)
# Set style for MainScreen_btnMenuSetting, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_btnMenuSetting.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuSetting.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuSetting.set_style_radius(5, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuSetting.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuSetting.set_style_bg_img_src("B:MicroPython/_Setting_100_100x100.bin", lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuSetting.set_style_bg_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuSetting.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuSetting.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuSetting.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnMenuSetting.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
# Set style for MainScreen_btnMenuSetting, Part: lv.PART.MAIN, State: lv.STATE.FOCUSED.
MainScreen_btnMenuSetting.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuSetting.set_style_bg_color(lv.color_hex(0x2195f6), lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuSetting.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuSetting.set_style_border_width(0, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuSetting.set_style_radius(5, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuSetting.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuSetting.set_style_bg_img_src("B:MicroPython/_Setting_100_100x100.bin", lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuSetting.set_style_bg_img_opa(255, lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuSetting.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuSetting.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.FOCUSED)
MainScreen_btnMenuSetting.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.FOCUSED)

# Create MainScreen_contSyringe
MainScreen_contSyringe = lv.obj(MainScreen)
MainScreen_contSyringe.set_pos(800, 80)
MainScreen_contSyringe.set_size(800, 300)
MainScreen_contSyringe.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for MainScreen_contSyringe, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_contSyringe.set_style_border_width(1, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contSyringe.set_style_border_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contSyringe.set_style_border_color(lv.color_hex(0x2195f6), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contSyringe.set_style_border_side(lv.BORDER_SIDE.FULL, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contSyringe.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contSyringe.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contSyringe.set_style_bg_color(lv.color_hex(0x000000), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contSyringe.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contSyringe.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contSyringe.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contSyringe.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contSyringe.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_contSyringe.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
# Create MainScreen_btnGoSettingSyringe
MainScreen_btnGoSettingSyringe = lv.btn(MainScreen_contSyringe)
MainScreen_btnGoSettingSyringe_label = lv.label(MainScreen_btnGoSettingSyringe)
MainScreen_btnGoSettingSyringe_label.set_text("")
MainScreen_btnGoSettingSyringe_label.set_long_mode(lv.label.LONG.WRAP)
MainScreen_btnGoSettingSyringe_label.set_width(lv.pct(100))
MainScreen_btnGoSettingSyringe_label.align(lv.ALIGN.CENTER, 0, 0)
MainScreen_btnGoSettingSyringe.set_style_pad_all(0, lv.STATE.DEFAULT)
MainScreen_btnGoSettingSyringe.set_pos(732, 247)
MainScreen_btnGoSettingSyringe.set_size(58, 44)
# Set style for MainScreen_btnGoSettingSyringe, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
MainScreen_btnGoSettingSyringe.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnGoSettingSyringe.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnGoSettingSyringe.set_style_radius(5, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnGoSettingSyringe.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnGoSettingSyringe.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnGoSettingSyringe.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnGoSettingSyringe.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
MainScreen_btnGoSettingSyringe.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)

MainScreen.update_layout()

def MainScreen_event_handler(e):
    code = e.get_code()
    if (code == lv.EVENT.SCREEN_LOADED):
        #Write animation: MainScreen_imgDroplet move_x
        MainScreen_imgDroplet_anim_move_x = lv.anim_t()
        MainScreen_imgDroplet_anim_move_x.init()
        MainScreen_imgDroplet_anim_move_x.set_var(MainScreen_imgDroplet)
        MainScreen_imgDroplet_anim_move_x.set_time(1500)
        MainScreen_imgDroplet_anim_move_x.set_delay(100)
        MainScreen_imgDroplet_anim_move_x.set_custom_exec_cb(lambda e,val: anim_x_cb(MainScreen_imgDroplet,val))
        MainScreen_imgDroplet_anim_move_x.set_values(MainScreen_imgDroplet.get_x(), 397)
        MainScreen_imgDroplet_anim_move_x.set_path_cb(lv.anim_t.path_ease_in)
        MainScreen_imgDroplet_anim_move_x.set_repeat_count(lv.ANIM_REPEAT.INFINITE)
        MainScreen_imgDroplet_anim_move_x.set_repeat_delay(200)
        MainScreen_imgDroplet_anim_move_x.set_playback_time(0)
        MainScreen_imgDroplet_anim_move_x.set_playback_delay(0)
        MainScreen_imgDroplet_anim_move_x.start()
        #Write animation: MainScreen_imgDroplet move_y
        MainScreen_imgDroplet_anim_move_y = lv.anim_t()
        MainScreen_imgDroplet_anim_move_y.init()
        MainScreen_imgDroplet_anim_move_y.set_var(MainScreen_imgDroplet)
        MainScreen_imgDroplet_anim_move_y.set_time(1500)
        MainScreen_imgDroplet_anim_move_y.set_delay(100)
        MainScreen_imgDroplet_anim_move_y.set_custom_exec_cb(lambda e,val: anim_y_cb(MainScreen_imgDroplet,val))
        MainScreen_imgDroplet_anim_move_y.set_values(MainScreen_imgDroplet.get_y(), 100)
        MainScreen_imgDroplet_anim_move_y.set_path_cb(lv.anim_t.path_ease_in)
        MainScreen_imgDroplet_anim_move_y.set_repeat_count(lv.ANIM_REPEAT.INFINITE)
        MainScreen_imgDroplet_anim_move_y.set_repeat_delay(200)
        MainScreen_imgDroplet_anim_move_y.set_playback_time(0)
        MainScreen_imgDroplet_anim_move_y.set_playback_delay(0)
        MainScreen_imgDroplet_anim_move_y.start()
        MainScreen_btnGoSetting.clear_flag(lv.obj.FLAG.CLICK_FOCUSABLE)
        MainScreen_btnGoMain.clear_flag(lv.obj.FLAG.CLICK_FOCUSABLE)
        MainScreen_datetext.clear_flag(lv.obj.FLAG.CLICK_FOCUSABLE)
        MainScreen_barOcclusionLevel.set_style_radius(0, lv.PART.MAIN)
        MainScreen_barBatteryLevel.set_style_radius(0, lv.PART.MAIN)

MainScreen.add_event_cb(lambda e: MainScreen_event_handler(e), lv.EVENT.ALL, None)

def MainScreen_imgDroplet_event_handler(e):
    code = e.get_code()

MainScreen_imgDroplet.add_event_cb(lambda e: MainScreen_imgDroplet_event_handler(e), lv.EVENT.ALL, None)

def MainScreen_btnGoSetting_event_handler(e):
    code = e.get_code()
    if (code == lv.EVENT.CLICKED):
        #Write animation: MainScreen_contSetting move_x
        MainScreen_contSetting_anim_move_x = lv.anim_t()
        MainScreen_contSetting_anim_move_x.init()
        MainScreen_contSetting_anim_move_x.set_var(MainScreen_contSetting)
        MainScreen_contSetting_anim_move_x.set_time(200)
        MainScreen_contSetting_anim_move_x.set_delay(0)
        MainScreen_contSetting_anim_move_x.set_custom_exec_cb(lambda e,val: anim_x_cb(MainScreen_contSetting,val))
        MainScreen_contSetting_anim_move_x.set_values(MainScreen_contSetting.get_x(), 0)
        MainScreen_contSetting_anim_move_x.set_path_cb(lv.anim_t.path_linear)
        MainScreen_contSetting_anim_move_x.set_repeat_count(0)
        MainScreen_contSetting_anim_move_x.set_repeat_delay(0)
        MainScreen_contSetting_anim_move_x.set_playback_time(0)
        MainScreen_contSetting_anim_move_x.set_playback_delay(0)
        MainScreen_contSetting_anim_move_x.start()
        #Write animation: MainScreen_contSetting move_y
        MainScreen_contSetting_anim_move_y = lv.anim_t()
        MainScreen_contSetting_anim_move_y.init()
        MainScreen_contSetting_anim_move_y.set_var(MainScreen_contSetting)
        MainScreen_contSetting_anim_move_y.set_time(200)
        MainScreen_contSetting_anim_move_y.set_delay(0)
        MainScreen_contSetting_anim_move_y.set_custom_exec_cb(lambda e,val: anim_y_cb(MainScreen_contSetting,val))
        MainScreen_contSetting_anim_move_y.set_values(MainScreen_contSetting.get_y(), 80)
        MainScreen_contSetting_anim_move_y.set_path_cb(lv.anim_t.path_linear)
        MainScreen_contSetting_anim_move_y.set_repeat_count(0)
        MainScreen_contSetting_anim_move_y.set_repeat_delay(0)
        MainScreen_contSetting_anim_move_y.set_playback_time(0)
        MainScreen_contSetting_anim_move_y.set_playback_delay(0)
        MainScreen_contSetting_anim_move_y.start()
        #Write animation: MainScreen_contMain move_x
        MainScreen_contMain_anim_move_x = lv.anim_t()
        MainScreen_contMain_anim_move_x.init()
        MainScreen_contMain_anim_move_x.set_var(MainScreen_contMain)
        MainScreen_contMain_anim_move_x.set_time(200)
        MainScreen_contMain_anim_move_x.set_delay(0)
        MainScreen_contMain_anim_move_x.set_custom_exec_cb(lambda e,val: anim_x_cb(MainScreen_contMain,val))
        MainScreen_contMain_anim_move_x.set_values(MainScreen_contMain.get_x(), -800)
        MainScreen_contMain_anim_move_x.set_path_cb(lv.anim_t.path_linear)
        MainScreen_contMain_anim_move_x.set_repeat_count(0)
        MainScreen_contMain_anim_move_x.set_repeat_delay(0)
        MainScreen_contMain_anim_move_x.set_playback_time(0)
        MainScreen_contMain_anim_move_x.set_playback_delay(0)
        MainScreen_contMain_anim_move_x.start()
        #Write animation: MainScreen_contMain move_y
        MainScreen_contMain_anim_move_y = lv.anim_t()
        MainScreen_contMain_anim_move_y.init()
        MainScreen_contMain_anim_move_y.set_var(MainScreen_contMain)
        MainScreen_contMain_anim_move_y.set_time(200)
        MainScreen_contMain_anim_move_y.set_delay(0)
        MainScreen_contMain_anim_move_y.set_custom_exec_cb(lambda e,val: anim_y_cb(MainScreen_contMain,val))
        MainScreen_contMain_anim_move_y.set_values(MainScreen_contMain.get_y(), 80)
        MainScreen_contMain_anim_move_y.set_path_cb(lv.anim_t.path_linear)
        MainScreen_contMain_anim_move_y.set_repeat_count(0)
        MainScreen_contMain_anim_move_y.set_repeat_delay(0)
        MainScreen_contMain_anim_move_y.set_playback_time(0)
        MainScreen_contMain_anim_move_y.set_playback_delay(0)
        MainScreen_contMain_anim_move_y.start()

MainScreen_btnGoSetting.add_event_cb(lambda e: MainScreen_btnGoSetting_event_handler(e), lv.EVENT.ALL, None)

def MainScreen_btnGoMain_event_handler(e):
    code = e.get_code()
    if (code == lv.EVENT.CLICKED):
        #Write animation: MainScreen_contSetting move_x
        MainScreen_contSetting_anim_move_x = lv.anim_t()
        MainScreen_contSetting_anim_move_x.init()
        MainScreen_contSetting_anim_move_x.set_var(MainScreen_contSetting)
        MainScreen_contSetting_anim_move_x.set_time(200)
        MainScreen_contSetting_anim_move_x.set_delay(0)
        MainScreen_contSetting_anim_move_x.set_custom_exec_cb(lambda e,val: anim_x_cb(MainScreen_contSetting,val))
        MainScreen_contSetting_anim_move_x.set_values(MainScreen_contSetting.get_x(), 800)
        MainScreen_contSetting_anim_move_x.set_path_cb(lv.anim_t.path_linear)
        MainScreen_contSetting_anim_move_x.set_repeat_count(0)
        MainScreen_contSetting_anim_move_x.set_repeat_delay(0)
        MainScreen_contSetting_anim_move_x.set_playback_time(0)
        MainScreen_contSetting_anim_move_x.set_playback_delay(0)
        MainScreen_contSetting_anim_move_x.start()
        #Write animation: MainScreen_contSetting move_y
        MainScreen_contSetting_anim_move_y = lv.anim_t()
        MainScreen_contSetting_anim_move_y.init()
        MainScreen_contSetting_anim_move_y.set_var(MainScreen_contSetting)
        MainScreen_contSetting_anim_move_y.set_time(200)
        MainScreen_contSetting_anim_move_y.set_delay(0)
        MainScreen_contSetting_anim_move_y.set_custom_exec_cb(lambda e,val: anim_y_cb(MainScreen_contSetting,val))
        MainScreen_contSetting_anim_move_y.set_values(MainScreen_contSetting.get_y(), 80)
        MainScreen_contSetting_anim_move_y.set_path_cb(lv.anim_t.path_linear)
        MainScreen_contSetting_anim_move_y.set_repeat_count(0)
        MainScreen_contSetting_anim_move_y.set_repeat_delay(0)
        MainScreen_contSetting_anim_move_y.set_playback_time(0)
        MainScreen_contSetting_anim_move_y.set_playback_delay(0)
        MainScreen_contSetting_anim_move_y.start()
        #Write animation: MainScreen_contMain move_x
        MainScreen_contMain_anim_move_x = lv.anim_t()
        MainScreen_contMain_anim_move_x.init()
        MainScreen_contMain_anim_move_x.set_var(MainScreen_contMain)
        MainScreen_contMain_anim_move_x.set_time(200)
        MainScreen_contMain_anim_move_x.set_delay(0)
        MainScreen_contMain_anim_move_x.set_custom_exec_cb(lambda e,val: anim_x_cb(MainScreen_contMain,val))
        MainScreen_contMain_anim_move_x.set_values(MainScreen_contMain.get_x(), 0)
        MainScreen_contMain_anim_move_x.set_path_cb(lv.anim_t.path_linear)
        MainScreen_contMain_anim_move_x.set_repeat_count(0)
        MainScreen_contMain_anim_move_x.set_repeat_delay(0)
        MainScreen_contMain_anim_move_x.set_playback_time(0)
        MainScreen_contMain_anim_move_x.set_playback_delay(0)
        MainScreen_contMain_anim_move_x.start()
        #Write animation: MainScreen_contMain move_y
        MainScreen_contMain_anim_move_y = lv.anim_t()
        MainScreen_contMain_anim_move_y.init()
        MainScreen_contMain_anim_move_y.set_var(MainScreen_contMain)
        MainScreen_contMain_anim_move_y.set_time(200)
        MainScreen_contMain_anim_move_y.set_delay(0)
        MainScreen_contMain_anim_move_y.set_custom_exec_cb(lambda e,val: anim_y_cb(MainScreen_contMain,val))
        MainScreen_contMain_anim_move_y.set_values(MainScreen_contMain.get_y(), 80)
        MainScreen_contMain_anim_move_y.set_path_cb(lv.anim_t.path_linear)
        MainScreen_contMain_anim_move_y.set_repeat_count(0)
        MainScreen_contMain_anim_move_y.set_repeat_delay(0)
        MainScreen_contMain_anim_move_y.set_playback_time(0)
        MainScreen_contMain_anim_move_y.set_playback_delay(0)
        MainScreen_contMain_anim_move_y.start()

MainScreen_btnGoMain.add_event_cb(lambda e: MainScreen_btnGoMain_event_handler(e), lv.EVENT.ALL, None)

def MainScreen_btnMenuSyringe_event_handler(e):
    code = e.get_code()
    if (code == lv.EVENT.CLICKED):
        #Write animation: MainScreen_contSetting move_x
        MainScreen_contSetting_anim_move_x = lv.anim_t()
        MainScreen_contSetting_anim_move_x.init()
        MainScreen_contSetting_anim_move_x.set_var(MainScreen_contSetting)
        MainScreen_contSetting_anim_move_x.set_time(200)
        MainScreen_contSetting_anim_move_x.set_delay(0)
        MainScreen_contSetting_anim_move_x.set_custom_exec_cb(lambda e,val: anim_x_cb(MainScreen_contSetting,val))
        MainScreen_contSetting_anim_move_x.set_values(MainScreen_contSetting.get_x(), 800)
        MainScreen_contSetting_anim_move_x.set_path_cb(lv.anim_t.path_linear)
        MainScreen_contSetting_anim_move_x.set_repeat_count(0)
        MainScreen_contSetting_anim_move_x.set_repeat_delay(0)
        MainScreen_contSetting_anim_move_x.set_playback_time(0)
        MainScreen_contSetting_anim_move_x.set_playback_delay(0)
        MainScreen_contSetting_anim_move_x.start()
        #Write animation: MainScreen_contSetting move_y
        MainScreen_contSetting_anim_move_y = lv.anim_t()
        MainScreen_contSetting_anim_move_y.init()
        MainScreen_contSetting_anim_move_y.set_var(MainScreen_contSetting)
        MainScreen_contSetting_anim_move_y.set_time(200)
        MainScreen_contSetting_anim_move_y.set_delay(0)
        MainScreen_contSetting_anim_move_y.set_custom_exec_cb(lambda e,val: anim_y_cb(MainScreen_contSetting,val))
        MainScreen_contSetting_anim_move_y.set_values(MainScreen_contSetting.get_y(), 80)
        MainScreen_contSetting_anim_move_y.set_path_cb(lv.anim_t.path_linear)
        MainScreen_contSetting_anim_move_y.set_repeat_count(0)
        MainScreen_contSetting_anim_move_y.set_repeat_delay(0)
        MainScreen_contSetting_anim_move_y.set_playback_time(0)
        MainScreen_contSetting_anim_move_y.set_playback_delay(0)
        MainScreen_contSetting_anim_move_y.start()
        #Write animation: MainScreen_contSyringe move_x
        MainScreen_contSyringe_anim_move_x = lv.anim_t()
        MainScreen_contSyringe_anim_move_x.init()
        MainScreen_contSyringe_anim_move_x.set_var(MainScreen_contSyringe)
        MainScreen_contSyringe_anim_move_x.set_time(200)
        MainScreen_contSyringe_anim_move_x.set_delay(0)
        MainScreen_contSyringe_anim_move_x.set_custom_exec_cb(lambda e,val: anim_x_cb(MainScreen_contSyringe,val))
        MainScreen_contSyringe_anim_move_x.set_values(MainScreen_contSyringe.get_x(), 0)
        MainScreen_contSyringe_anim_move_x.set_path_cb(lv.anim_t.path_linear)
        MainScreen_contSyringe_anim_move_x.set_repeat_count(0)
        MainScreen_contSyringe_anim_move_x.set_repeat_delay(0)
        MainScreen_contSyringe_anim_move_x.set_playback_time(0)
        MainScreen_contSyringe_anim_move_x.set_playback_delay(0)
        MainScreen_contSyringe_anim_move_x.start()
        #Write animation: MainScreen_contSyringe move_y
        MainScreen_contSyringe_anim_move_y = lv.anim_t()
        MainScreen_contSyringe_anim_move_y.init()
        MainScreen_contSyringe_anim_move_y.set_var(MainScreen_contSyringe)
        MainScreen_contSyringe_anim_move_y.set_time(200)
        MainScreen_contSyringe_anim_move_y.set_delay(0)
        MainScreen_contSyringe_anim_move_y.set_custom_exec_cb(lambda e,val: anim_y_cb(MainScreen_contSyringe,val))
        MainScreen_contSyringe_anim_move_y.set_values(MainScreen_contSyringe.get_y(), 80)
        MainScreen_contSyringe_anim_move_y.set_path_cb(lv.anim_t.path_linear)
        MainScreen_contSyringe_anim_move_y.set_repeat_count(0)
        MainScreen_contSyringe_anim_move_y.set_repeat_delay(0)
        MainScreen_contSyringe_anim_move_y.set_playback_time(0)
        MainScreen_contSyringe_anim_move_y.set_playback_delay(0)
        MainScreen_contSyringe_anim_move_y.start()

MainScreen_btnMenuSyringe.add_event_cb(lambda e: MainScreen_btnMenuSyringe_event_handler(e), lv.EVENT.ALL, None)

def MainScreen_btnGoSettingSyringe_event_handler(e):
    code = e.get_code()
    if (code == lv.EVENT.CLICKED):
        #Write animation: MainScreen_contSetting move_x
        MainScreen_contSetting_anim_move_x = lv.anim_t()
        MainScreen_contSetting_anim_move_x.init()
        MainScreen_contSetting_anim_move_x.set_var(MainScreen_contSetting)
        MainScreen_contSetting_anim_move_x.set_time(200)
        MainScreen_contSetting_anim_move_x.set_delay(0)
        MainScreen_contSetting_anim_move_x.set_custom_exec_cb(lambda e,val: anim_x_cb(MainScreen_contSetting,val))
        MainScreen_contSetting_anim_move_x.set_values(MainScreen_contSetting.get_x(), 0)
        MainScreen_contSetting_anim_move_x.set_path_cb(lv.anim_t.path_linear)
        MainScreen_contSetting_anim_move_x.set_repeat_count(0)
        MainScreen_contSetting_anim_move_x.set_repeat_delay(0)
        MainScreen_contSetting_anim_move_x.set_playback_time(0)
        MainScreen_contSetting_anim_move_x.set_playback_delay(0)
        MainScreen_contSetting_anim_move_x.start()
        #Write animation: MainScreen_contSetting move_y
        MainScreen_contSetting_anim_move_y = lv.anim_t()
        MainScreen_contSetting_anim_move_y.init()
        MainScreen_contSetting_anim_move_y.set_var(MainScreen_contSetting)
        MainScreen_contSetting_anim_move_y.set_time(200)
        MainScreen_contSetting_anim_move_y.set_delay(0)
        MainScreen_contSetting_anim_move_y.set_custom_exec_cb(lambda e,val: anim_y_cb(MainScreen_contSetting,val))
        MainScreen_contSetting_anim_move_y.set_values(MainScreen_contSetting.get_y(), 80)
        MainScreen_contSetting_anim_move_y.set_path_cb(lv.anim_t.path_linear)
        MainScreen_contSetting_anim_move_y.set_repeat_count(0)
        MainScreen_contSetting_anim_move_y.set_repeat_delay(0)
        MainScreen_contSetting_anim_move_y.set_playback_time(0)
        MainScreen_contSetting_anim_move_y.set_playback_delay(0)
        MainScreen_contSetting_anim_move_y.start()
        #Write animation: MainScreen_contSyringe move_x
        MainScreen_contSyringe_anim_move_x = lv.anim_t()
        MainScreen_contSyringe_anim_move_x.init()
        MainScreen_contSyringe_anim_move_x.set_var(MainScreen_contSyringe)
        MainScreen_contSyringe_anim_move_x.set_time(200)
        MainScreen_contSyringe_anim_move_x.set_delay(0)
        MainScreen_contSyringe_anim_move_x.set_custom_exec_cb(lambda e,val: anim_x_cb(MainScreen_contSyringe,val))
        MainScreen_contSyringe_anim_move_x.set_values(MainScreen_contSyringe.get_x(), 800)
        MainScreen_contSyringe_anim_move_x.set_path_cb(lv.anim_t.path_linear)
        MainScreen_contSyringe_anim_move_x.set_repeat_count(0)
        MainScreen_contSyringe_anim_move_x.set_repeat_delay(0)
        MainScreen_contSyringe_anim_move_x.set_playback_time(0)
        MainScreen_contSyringe_anim_move_x.set_playback_delay(0)
        MainScreen_contSyringe_anim_move_x.start()
        #Write animation: MainScreen_contSyringe move_y
        MainScreen_contSyringe_anim_move_y = lv.anim_t()
        MainScreen_contSyringe_anim_move_y.init()
        MainScreen_contSyringe_anim_move_y.set_var(MainScreen_contSyringe)
        MainScreen_contSyringe_anim_move_y.set_time(200)
        MainScreen_contSyringe_anim_move_y.set_delay(0)
        MainScreen_contSyringe_anim_move_y.set_custom_exec_cb(lambda e,val: anim_y_cb(MainScreen_contSyringe,val))
        MainScreen_contSyringe_anim_move_y.set_values(MainScreen_contSyringe.get_y(), 80)
        MainScreen_contSyringe_anim_move_y.set_path_cb(lv.anim_t.path_linear)
        MainScreen_contSyringe_anim_move_y.set_repeat_count(0)
        MainScreen_contSyringe_anim_move_y.set_repeat_delay(0)
        MainScreen_contSyringe_anim_move_y.set_playback_time(0)
        MainScreen_contSyringe_anim_move_y.set_playback_delay(0)
        MainScreen_contSyringe_anim_move_y.start()

MainScreen_btnGoSettingSyringe.add_event_cb(lambda e: MainScreen_btnGoSettingSyringe_event_handler(e), lv.EVENT.ALL, None)

# content from custom.py

# Load the default screen
lv.scr_load(MainScreen)

while SDL.check():
    time.sleep_ms(5)

