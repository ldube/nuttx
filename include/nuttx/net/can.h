/****************************************************************************
 * include/nuttx/net/can.h
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: 2007, 2009-2012, 2015 Gregory Nutt. All
 * rights reserved.
 * SPDX-FileCopyrightText: 2001-2003, Adam Dunkels. All rights reserved.
 * SPDX-FileContributor: Gregory Nutt <gnutt@nuttx.org>
 * SPDX-FileContributor: Adam Dunkels <adam@dunkels.com>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote
 *    products derived from this software without specific prior
 *    written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

#ifndef __INCLUDE_NUTTX_NET_CAN_H
#define __INCLUDE_NUTTX_NET_CAN_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include <nuttx/can.h>
#include <nuttx/net/netconfig.h>
#include <stdint.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#ifdef CONFIG_NET_CAN_CANFD
#  define NET_CAN_PKTSIZE sizeof(struct canfd_frame)
#else
#  define NET_CAN_PKTSIZE sizeof(struct can_frame)
#endif

/****************************************************************************
 * Public Types
 ****************************************************************************/

/* The structure holding the CAN statistics that are gathered if
 * CONFIG_NET_STATISTICS is defined.
 */

#ifdef CONFIG_NET_STATISTICS
struct can_stats_s
{
  net_stats_t drop;       /* Number of dropped CAN frames */
  net_stats_t recv;       /* Number of received CAN frames */
  net_stats_t sent;       /* Number of sent CAN frames */
};
#endif

/****************************************************************************
 * Public Data
 ****************************************************************************/

#ifdef CONFIG_NET_CAN_CANFD

/* Lookup tables convert can_dlc <-> payload len */

extern const uint8_t g_can_dlc_to_len[16];
extern const uint8_t g_len_to_can_dlc[65];

#endif

#ifdef __cplusplus
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Name: can_input
 *
 * Description:
 *   Handle incoming CAN frame input
 *
 *   This function provides the interface between CAN device drivers and
 *   SocketCAN logic.  All frames that are received should be provided to
 *   can_input() prior to other routing.
 *
 * Input Parameters:
 *   dev - The device driver structure containing the received packet
 *
 * Returned Value:
 *   OK    The packet has been processed  and can be deleted
 *   ERROR There is a matching connection, but could not dispatch the packet
 *         yet.  Useful when a packet arrives before a recv call is in
 *         place.
 *
 * Assumptions:
 *   Called from the CAN device diver with the network locked.
 *
 ****************************************************************************/

struct net_driver_s; /* Forward reference */
int can_input(FAR struct net_driver_s *dev);

#undef EXTERN
#ifdef __cplusplus
}
#endif

#endif /* __INCLUDE_NUTTX_NET_CAN_H */
