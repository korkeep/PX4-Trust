/****************************************************************************
 * examples/poll/poll_internal.h
 *
 *   Copyright (C) 2008, 2009, 2014, 2020 Gregory Nutt. All rights reserved.
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

#ifndef __EXAMPLES_POLL_POLL_INTERNAL_H
#define __EXAMPLES_POLL_POLL_INTERNAL_H

/****************************************************************************
 * Compilation Switches
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <pthread.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Here are all of the configuration settings that must be met to have TCP/IP
 * poll/select support.  This kind of looks like overkill.
 *
 * CONFIG_NET                  - Network support must be enabled
 * CONFIG_NET_TCP              - Only support on TCP (because read-ahead
 *                               buffering s not yet support for UDP)
 */

#if defined(CONFIG_NET) && defined(CONFIG_NET_TCP)
#  define HAVE_NETPOLL 1
#else
#  undef HAVE_NETPOLL
#endif

#define FIFO_PATH1 "/dev/fifo0"
#define FIFO_PATH2 "/dev/fifo1"

#define POLL_LISTENER_DELAY   2000   /* 2 seconds */
#define SELECT_LISTENER_DELAY 4      /* 4 seconds */
#define NET_LISTENER_DELAY    3      /* 3 seconds */
#define WRITER_DELAY          6      /* 6 seconds */

#define LISTENER_PORT         5471

/****************************************************************************
 * Public Types
 ****************************************************************************/

/****************************************************************************
 * Public Data
 ****************************************************************************/

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

extern void *poll_listener(pthread_addr_t pvarg);
extern void *select_listener(pthread_addr_t pvarg);

#ifdef HAVE_NETPOLL
extern void *net_listener(pthread_addr_t pvarg);
extern void *net_reader(pthread_addr_t pvarg);
#endif
#endif /* __EXAMPLES_POLL_POLL_INTERNAL_H */
