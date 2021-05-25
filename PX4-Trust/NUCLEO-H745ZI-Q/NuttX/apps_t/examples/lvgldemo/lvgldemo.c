/****************************************************************************
 * apps/examples/lvgldemo/lvgldemo.c
 *
 *   Copyright (C) 2019 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <sys/boardctl.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <time.h>
#include <debug.h>

#include <lvgl/lvgl.h>

#include "fbdev.h"
#include "lcddev.h"

#if defined(CONFIG_INPUT_TOUCHSCREEN) || defined(CONFIG_INPUT_MOUSE)
#include "tp.h"
#include "tp_cal.h"
#endif

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Should we perform board-specific driver initialization?  There are two
 * ways that board initialization can occur:  1) automatically via
 * board_late_initialize() during bootupif CONFIG_BOARD_LATE_INITIALIZE
 * or 2).
 * via a call to boardctl() if the interface is enabled
 * (CONFIG_LIB_BOARDCTL=y).
 * If this task is running as an NSH built-in application, then that
 * initialization has probably already been performed otherwise we do it
 * here.
 */

#undef NEED_BOARDINIT

#if defined(CONFIG_LIB_BOARDCTL) && !defined(CONFIG_NSH_ARCHINIT)
#  define NEED_BOARDINIT 1
#endif

#define DISPLAY_BUFFER_SIZE (CONFIG_LV_HOR_RES * \
                              CONFIG_EXAMPLES_LVGLDEMO_BUFF_SIZE)

/****************************************************************************
 * Public Functions Prototypes
 ****************************************************************************/

void lv_demo_benchmark(void);
void lv_demo_printer(void);
void lv_demo_stress(void);
void lv_demo_widgets(void);

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: monitor_cb
 *
 * Description:
 *   Monitoring callback from lvgl every time the screen is flushed.
 *
 ****************************************************************************/

static void monitor_cb(lv_disp_drv_t * disp_drv, uint32_t time, uint32_t px)
{
  ginfo("%" PRIu32 " px refreshed in %" PRIu32 " ms\n", px, time);
}

/****************************************************************************
 * Private Data
 ****************************************************************************/

static lv_color_t buffer1[DISPLAY_BUFFER_SIZE];

#ifdef CONFIG_EXAMPLES_LVGLDEMO_DOUBLE_BUFFERING
static lv_color_t buffer2[DISPLAY_BUFFER_SIZE];
#else
# define buffer2 NULL
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: main or lvgldemo_main
 *
 * Description:
 *
 * Input Parameters:
 *   Standard argc and argv
 *
 * Returned Value:
 *   Zero on success; a positive, non-zero value on failure.
 *
 ****************************************************************************/

int main(int argc, FAR char *argv[])
{
  lv_disp_drv_t disp_drv;
  lv_disp_buf_t disp_buf;

#if defined(CONFIG_INPUT_TOUCHSCREEN) || defined(CONFIG_INPUT_MOUSE)
#ifndef CONFIG_EXAMPLES_LVGLDEMO_CALIBRATE
  lv_point_t p[4];

  /* top left */

  p[0].x = 0;
  p[0].y = 0;

  /* top right */

  p[1].x = LV_HOR_RES;
  p[1].y = 0;

  /* bottom left */

  p[2].x = 0;
  p[2].y = LV_VER_RES;

  /* bottom right */

  p[3].x = LV_HOR_RES;
  p[3].y = LV_VER_RES;
#endif
#endif

#ifdef NEED_BOARDINIT
  /* Perform board-specific driver initialization */

  boardctl(BOARDIOC_INIT, 0);

#ifdef CONFIG_BOARDCTL_FINALINIT
  /* Perform architecture-specific final-initialization (if configured) */

  boardctl(BOARDIOC_FINALINIT, 0);
#endif
#endif

  /* LVGL initialization */

  lv_init();

  /* Basic LVGL display driver initialization */

  lv_disp_buf_init(&disp_buf, buffer1, buffer2, DISPLAY_BUFFER_SIZE);
  lv_disp_drv_init(&disp_drv);
  disp_drv.buffer = &disp_buf;
  disp_drv.monitor_cb = monitor_cb;

  /* Display interface initialization */

  if (fbdev_init(&disp_drv) != EXIT_SUCCESS)
    {
      /* Failed to use framebuffer falling back to lcd driver */

      if (lcddev_init(&disp_drv) != EXIT_SUCCESS)
        {
          /* No possible drivers left, fail */

          return EXIT_FAILURE;
        }
    }

  lv_disp_drv_register(&disp_drv);

#if defined(CONFIG_INPUT_TOUCHSCREEN) || defined(CONFIG_INPUT_MOUSE)
  /* Touchpad Initialization */

  tp_init();
  lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;

  /* This function will be called periodically (by the library) to get the
   * mouse position and state.
   */

  indev_drv.read_cb = tp_read;
  lv_indev_drv_register(&indev_drv);
#endif

#if defined(CONFIG_EXAMPLES_LVGLDEMO_BENCHMARK)
  lv_demo_benchmark();
#elif defined(CONFIG_EXAMPLES_LVGLDEMO_PRINTER)
  lv_demo_printer();
#elif defined(CONFIG_EXAMPLES_LVGLDEMO_STRESS)
  lv_demo_stress();
#elif defined(CONFIG_EXAMPLES_LVGLDEMO_WIDGETS)
  lv_demo_widgets();
#endif

#if defined(CONFIG_INPUT_TOUCHSCREEN) || defined(CONFIG_INPUT_MOUSE)
  /* Start TP calibration */

#ifdef CONFIG_EXAMPLES_LVGLDEMO_CALIBRATE
  tp_cal_create();
#else
  tp_set_cal_values(p, p + 1, p + 2, p + 3);
#endif
#endif

  /* Handle LVGL tasks */

  while (1)
    {
      lv_task_handler();
      usleep(10000);
    }

  return EXIT_SUCCESS;
}
