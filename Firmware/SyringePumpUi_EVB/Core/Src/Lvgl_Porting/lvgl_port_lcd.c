/*
 * lcd.c
 *
 *  Created on: 23 Dec 2021
 *      Author: Ahmet Alperen Bulut / github.com/ahmetalperenbulut
 */


/*********************
 *      INCLUDES
 *********************/
//#include "stm32h745i_discovery.h"
//#include "stm32h745i_discovery_lcd.h

#include "stm32h7xx_hal.h"
#include "lvgl/lvgl.h"
#include <stdlib.h>
#include "lvgl_port_lcd.h"
#include "dma2d.h"
#include "ltdc.h"
/*********************
 *      DEFINES
 *********************/
//#define LCD_INSTANCE				(0)
#define LVGL_BUFFER_ADDR_AT_SDRAM	(0xC00BB810)
#define LVGL_BUFFER_2_ADDR_AT_SDRAM (0xC0177020)

static LV_ATTRIBUTE_MEM_ALIGN lv_color_t fbuf[2][LCD_HOR_RES * 64];


/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void disp_flush(lv_disp_drv_t *drv, const lv_area_t *area,lv_color_t *color_p);
static void disp_flush_complete(DMA2D_HandleTypeDef *hdma2d);

static void disp_clean_dcache(lv_disp_drv_t *drv);
static uint8_t CopyImageToLcdFrameBuffer(void *pSrc, void *pDst, uint32_t xSize,
		uint32_t ySize);

/**********************
 *  STATIC VARIABLES
 **********************/

static lv_disp_t *display = NULL;
static lv_disp_drv_t disp_drv;
static lv_disp_draw_buf_t disp_buf;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/**
 * Initialize LCD
 */

void LCD_init()
{
	/* There is only one display on STM32 */
	if (display != NULL)
		abort();

	/* Initialize the LCD */
	HAL_GPIO_WritePin(LCD_BL_GPIO_Port, LCD_BL_Pin, GPIO_PIN_RESET);//enable Backlight

	lv_disp_draw_buf_init(&disp_buf, (void*)LVGL_BUFFER_ADDR_AT_SDRAM,
			(void*)LVGL_BUFFER_2_ADDR_AT_SDRAM,
			LCD_HOR_RES * LCD_VER_RES); /*Initialize the display buffer*/

//		lv_disp_draw_buf_init(&disp_buf, (void*)fbuf[0],
//			(void*)fbuf[1],
//			LCD_HOR_RES * 64); /*Initialize the display buffer*/

//	lv_disp_draw_buf_init(&disp_buf, (void*)LVGL_BUFFER_ADDR_AT_SDRAM,
//			(void*)LVGL_BUFFER_2_ADDR_AT_SDRAM,
//			LCD_HOR_RES * 64); /*Initialize the display buffer*/


	lv_disp_drv_init(&disp_drv);

	/*Set up the functions to access to your display*/

	/*Set the resolution of the display*/
	disp_drv.hor_res = LCD_HOR_RES;
	disp_drv.ver_res = LCD_VER_RES;

	/*Used to copy the buffer's content to the display*/
	disp_drv.flush_cb = disp_flush;
	disp_drv.full_refresh=1;
	disp_drv.clean_dcache_cb = disp_clean_dcache;

	hdma2d.XferCpltCallback=disp_flush_complete;
	/*Set a display buffer*/
	disp_drv.draw_buf = &disp_buf;

	/*Finally register the driver*/
	display = lv_disp_drv_register(&disp_drv);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/* Flush the content of the internal buffer the specific area on the display
 * You can use DMA or any hardware acceleration to do this operation in the background but
 * 'lv_disp_flush_ready()' has to be called when finished*/
static void disp_flush(lv_disp_drv_t *drv, const lv_area_t *area,
		lv_color_t *color_p)
{
	/*Return if the area is out the screen*/
////	if (area->x2 < 0)
////		return;
////	if (area->y2 < 0)
////		return;
////	if (area->x1 > LCD_HOR_RES - 1)
////		return;
////	if (area->y1 > LCD_VER_RES - 1)
////		return;
//	//BSP_LED_Toggle(LED2);
	SCB_CleanInvalidateDCache();
	SCB_InvalidateICache();

//	  lv_coord_t width = lv_area_get_width(area);
//	  lv_coord_t height = lv_area_get_height(area);
//
//	  DMA2D->CR = 0x0U << DMA2D_CR_MODE_Pos;
//	  DMA2D->FGPFCCR = DMA2D_INPUT_RGB565;
//	  DMA2D->FGMAR = (uint32_t)color_p;
//	  DMA2D->FGOR = 0;
//	  DMA2D->OPFCCR = DMA2D_OUTPUT_RGB565;
//	  DMA2D->OMAR = hltdc.LayerCfg[0].FBStartAdress + 2 * \
//	                (area->y1 * LCD_HOR_RES + area->x1);
//	  DMA2D->OOR = LCD_HOR_RES - width;
//	  DMA2D->NLR = (width << DMA2D_NLR_PL_Pos) | (height << DMA2D_NLR_NL_Pos);
//	  DMA2D->IFCR = 0x3FU;
//	  DMA2D->CR |= DMA2D_CR_TCIE;
//	  DMA2D->CR |= DMA2D_CR_START;

/* LTDC copy*/
	HAL_LTDC_SetAddress(&hltdc, color_p, 0);
	/*DMA2D*/
//	uint32_t address =
//			hltdc.LayerCfg[0].FBStartAdress
//					+ (((LCD_HOR_RES * area->y1) + area->x1)* 2);
//	CopyImageToLcdFrameBuffer((void*) color_p, (void*) address,
//			lv_area_get_width(area), lv_area_get_height(area));

	lv_disp_flush_ready(&disp_drv);
	return;
}

static void disp_clean_dcache(lv_disp_drv_t *drv)
{
	SCB_CleanInvalidateDCache();
}
static void disp_flush_complete(DMA2D_HandleTypeDef *hdma2d)
{
	lv_disp_flush_ready(&disp_drv);
}
/**
 * @brief  Copy to LCD frame buffer area centered in WVGA resolution.
 * The area of copy is of size in ARGB8888.
 * @param  pSrc: Pointer to source buffer : source image buffer start here
 * @param  pDst: Pointer to destination buffer LCD frame buffer center area start here
 * @param  xSize: Buffer width
 * @param  ySize: Buffer height
 * @retval LCD Status : BSP_ERROR_NONE or BSP_ERROR_BUS_DMA_FAILURE
 */
static uint8_t CopyImageToLcdFrameBuffer(void *pSrc, void *pDst, uint32_t xSize,
		uint32_t ySize)
{
	HAL_StatusTypeDef hal_status = HAL_OK;
	uint8_t lcd_status;

	/* Configure the DMA2D Mode, Color Mode and output offset */
	hdma2d.Instance = DMA2D;
	hdma2d.Init.Mode = DMA2D_M2M;
	hdma2d.Init.ColorMode = DMA2D_OUTPUT_RGB565; /* Output color out of PFC */
	hdma2d.Init.OutputOffset = LCD_HOR_RES - xSize;
	hdma2d.Init.AlphaInverted = DMA2D_REGULAR_ALPHA; /* No Output Alpha Inversion*/
	hdma2d.Init.RedBlueSwap = DMA2D_RB_REGULAR; /* No Output Red & Blue swap */
	hdma2d.XferCpltCallback=disp_flush_complete;

	/* Output offset in pixels == nb of pixels to be added at end of line to come to the  */
	/* first pixel of the next line : on the output side of the DMA2D computation         */


	/* DMA2D Initialization */
	if (HAL_DMA2D_Init(&hdma2d) == HAL_OK)
	{
		if (HAL_DMA2D_Start_IT(&hdma2d, (uint32_t) pSrc, (uint32_t) pDst,
				xSize, ySize) == HAL_OK)
		{
//			/* Polling For DMA transfer */
//			hal_status = HAL_DMA2D_PollForTransfer(&hdma2d, 20);
//			if (hal_status == HAL_OK)
//			{
//				/* return good status on exit */
//				lcd_status = 0;
//			}
//			else
//			{
//				lcd_status = -107;
//			}
		}
	}

	return (lcd_status);
}
