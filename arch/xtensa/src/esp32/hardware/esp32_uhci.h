/****************************************************************************
 * arch/xtensa/src/esp32/hardware/esp32_uhci.h
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

#ifndef __ARCH_XTENSA_SRC_ESP32_HARDWARE_ESP32_UHCI_H
#define __ARCH_XTENSA_SRC_ESP32_HARDWARE_ESP32_UHCI_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include "esp32_soc.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define REG_UHCI_BASE(i)         (DR_REG_UHCI0_BASE - (i) * 0x8000)

/* UHCI_CONF0_REG register */

#define UHCI_CONF0_REG(i) (REG_UHCI_BASE(i) + 0x0)

/* UHCI_UART_RX_BRK_EOF_EN : RW; bitpos: [23]; default: 0;
 * Set this bit to enable to use brk char as the end of a data frame.
 */

#define UHCI_UART_RX_BRK_EOF_EN    (BIT(23))
#define UHCI_UART_RX_BRK_EOF_EN_M  (UHCI_UART_RX_BRK_EOF_EN_V << UHCI_UART_RX_BRK_EOF_EN_S)
#define UHCI_UART_RX_BRK_EOF_EN_V  0x00000001
#define UHCI_UART_RX_BRK_EOF_EN_S  23

/* UHCI_CLK_EN : RW; bitpos: [22]; default: 0;
 * Set this bit to enable clock-gating for read or write registers.
 */

#define UHCI_CLK_EN    (BIT(22))
#define UHCI_CLK_EN_M  (UHCI_CLK_EN_V << UHCI_CLK_EN_S)
#define UHCI_CLK_EN_V  0x00000001
#define UHCI_CLK_EN_S  22

/* UHCI_ENCODE_CRC_EN : RW; bitpos: [21]; default: 1;
 * Set this bit to enable crc calculation for data frame when bit6 in the
 * head packet is 1.
 */

#define UHCI_ENCODE_CRC_EN    (BIT(21))
#define UHCI_ENCODE_CRC_EN_M  (UHCI_ENCODE_CRC_EN_V << UHCI_ENCODE_CRC_EN_S)
#define UHCI_ENCODE_CRC_EN_V  0x00000001
#define UHCI_ENCODE_CRC_EN_S  21

/* UHCI_LEN_EOF_EN : RW; bitpos: [20]; default: 1;
 * Set this bit to enable to use packet_len in packet head  when the
 * received data is equal to packet_len  this means the end of a data frame.
 */

#define UHCI_LEN_EOF_EN    (BIT(20))
#define UHCI_LEN_EOF_EN_M  (UHCI_LEN_EOF_EN_V << UHCI_LEN_EOF_EN_S)
#define UHCI_LEN_EOF_EN_V  0x00000001
#define UHCI_LEN_EOF_EN_S  20

/* UHCI_UART_IDLE_EOF_EN : RW; bitpos: [19]; default: 0;
 * Set this bit to enable to use idle time  when the idle time after data
 * frame is satisfied  this means the end of a data frame.
 */

#define UHCI_UART_IDLE_EOF_EN    (BIT(19))
#define UHCI_UART_IDLE_EOF_EN_M  (UHCI_UART_IDLE_EOF_EN_V << UHCI_UART_IDLE_EOF_EN_S)
#define UHCI_UART_IDLE_EOF_EN_V  0x00000001
#define UHCI_UART_IDLE_EOF_EN_S  19

/* UHCI_CRC_REC_EN : RW; bitpos: [18]; default: 1;
 * Set this bit to enable receiver''s ability of crc calculation  when
 * crc_en bit in head packet is 1 then there will be crc bytes after
 * data_frame
 */

#define UHCI_CRC_REC_EN    (BIT(18))
#define UHCI_CRC_REC_EN_M  (UHCI_CRC_REC_EN_V << UHCI_CRC_REC_EN_S)
#define UHCI_CRC_REC_EN_V  0x00000001
#define UHCI_CRC_REC_EN_S  18

/* UHCI_HEAD_EN : RW; bitpos: [17]; default: 1;
 * Set this bit to enable to use head packet  before the data frame.
 */

#define UHCI_HEAD_EN    (BIT(17))
#define UHCI_HEAD_EN_M  (UHCI_HEAD_EN_V << UHCI_HEAD_EN_S)
#define UHCI_HEAD_EN_V  0x00000001
#define UHCI_HEAD_EN_S  17

/* UHCI_SEPER_EN : RW; bitpos: [16]; default: 1;
 * Set this bit to use special char to separate the data frame.
 */

#define UHCI_SEPER_EN    (BIT(16))
#define UHCI_SEPER_EN_M  (UHCI_SEPER_EN_V << UHCI_SEPER_EN_S)
#define UHCI_SEPER_EN_V  0x00000001
#define UHCI_SEPER_EN_S  16

/* UHCI_MEM_TRANS_EN : RW; bitpos: [15]; default: 0; */

#define UHCI_MEM_TRANS_EN    (BIT(15))
#define UHCI_MEM_TRANS_EN_M  (UHCI_MEM_TRANS_EN_V << UHCI_MEM_TRANS_EN_S)
#define UHCI_MEM_TRANS_EN_V  0x00000001
#define UHCI_MEM_TRANS_EN_S  15

/* UHCI_OUT_DATA_BURST_EN : RW; bitpos: [14]; default: 0;
 * Set this bit to enable DMA burst MODE
 */

#define UHCI_OUT_DATA_BURST_EN    (BIT(14))
#define UHCI_OUT_DATA_BURST_EN_M  (UHCI_OUT_DATA_BURST_EN_V << UHCI_OUT_DATA_BURST_EN_S)
#define UHCI_OUT_DATA_BURST_EN_V  0x00000001
#define UHCI_OUT_DATA_BURST_EN_S  14

/* UHCI_INDSCR_BURST_EN : RW; bitpos: [13]; default: 0;
 * Set this bit to enable DMA out links to use burst mode.
 */

#define UHCI_INDSCR_BURST_EN    (BIT(13))
#define UHCI_INDSCR_BURST_EN_M  (UHCI_INDSCR_BURST_EN_V << UHCI_INDSCR_BURST_EN_S)
#define UHCI_INDSCR_BURST_EN_V  0x00000001
#define UHCI_INDSCR_BURST_EN_S  13

/* UHCI_OUTDSCR_BURST_EN : RW; bitpos: [12]; default: 0;
 * Set this bit to enable DMA in links to use burst mode.
 */

#define UHCI_OUTDSCR_BURST_EN    (BIT(12))
#define UHCI_OUTDSCR_BURST_EN_M  (UHCI_OUTDSCR_BURST_EN_V << UHCI_OUTDSCR_BURST_EN_S)
#define UHCI_OUTDSCR_BURST_EN_V  0x00000001
#define UHCI_OUTDSCR_BURST_EN_S  12

/* UHCI_UART2_CE : RW; bitpos: [11]; default: 0;
 * Set this bit to use UART2 to transmit or receive data.
 */

#define UHCI_UART2_CE    (BIT(11))
#define UHCI_UART2_CE_M  (UHCI_UART2_CE_V << UHCI_UART2_CE_S)
#define UHCI_UART2_CE_V  0x00000001
#define UHCI_UART2_CE_S  11

/* UHCI_UART1_CE : RW; bitpos: [10]; default: 0;
 * Set this bit to use UART1 to transmit or receive data.
 */

#define UHCI_UART1_CE    (BIT(10))
#define UHCI_UART1_CE_M  (UHCI_UART1_CE_V << UHCI_UART1_CE_S)
#define UHCI_UART1_CE_V  0x00000001
#define UHCI_UART1_CE_S  10

/* UHCI_UART0_CE : RW; bitpos: [9]; default: 0;
 * Set this bit to use UART to transmit or receive data.
 */

#define UHCI_UART0_CE    (BIT(9))
#define UHCI_UART0_CE_M  (UHCI_UART0_CE_V << UHCI_UART0_CE_S)
#define UHCI_UART0_CE_V  0x00000001
#define UHCI_UART0_CE_S  9

/* UHCI_OUT_EOF_MODE : RW; bitpos: [8]; default: 1;
 * Set this bit to produce eof after DMA pops all data  clear this bit to
 * produce eof after DMA pushes all data
 */

#define UHCI_OUT_EOF_MODE    (BIT(8))
#define UHCI_OUT_EOF_MODE_M  (UHCI_OUT_EOF_MODE_V << UHCI_OUT_EOF_MODE_S)
#define UHCI_OUT_EOF_MODE_V  0x00000001
#define UHCI_OUT_EOF_MODE_S  8

/* UHCI_OUT_NO_RESTART_CLR : RW; bitpos: [7]; default: 0;
 * don't use
 */

#define UHCI_OUT_NO_RESTART_CLR    (BIT(7))
#define UHCI_OUT_NO_RESTART_CLR_M  (UHCI_OUT_NO_RESTART_CLR_V << UHCI_OUT_NO_RESTART_CLR_S)
#define UHCI_OUT_NO_RESTART_CLR_V  0x00000001
#define UHCI_OUT_NO_RESTART_CLR_S  7

/* UHCI_OUT_AUTO_WRBACK : RW; bitpos: [6]; default: 0;
 * when in link's length is 0  go on to use the next in link automatically.
 */

#define UHCI_OUT_AUTO_WRBACK    (BIT(6))
#define UHCI_OUT_AUTO_WRBACK_M  (UHCI_OUT_AUTO_WRBACK_V << UHCI_OUT_AUTO_WRBACK_S)
#define UHCI_OUT_AUTO_WRBACK_V  0x00000001
#define UHCI_OUT_AUTO_WRBACK_S  6

/* UHCI_OUT_LOOP_TEST : RW; bitpos: [5]; default: 0;
 * Set this bit to enable loop test for out links.
 */

#define UHCI_OUT_LOOP_TEST    (BIT(5))
#define UHCI_OUT_LOOP_TEST_M  (UHCI_OUT_LOOP_TEST_V << UHCI_OUT_LOOP_TEST_S)
#define UHCI_OUT_LOOP_TEST_V  0x00000001
#define UHCI_OUT_LOOP_TEST_S  5

/* UHCI_IN_LOOP_TEST : RW; bitpos: [4]; default: 0;
 * Set this bit to enable loop test for in links.
 */

#define UHCI_IN_LOOP_TEST    (BIT(4))
#define UHCI_IN_LOOP_TEST_M  (UHCI_IN_LOOP_TEST_V << UHCI_IN_LOOP_TEST_S)
#define UHCI_IN_LOOP_TEST_V  0x00000001
#define UHCI_IN_LOOP_TEST_S  4

/* UHCI_AHBM_RST : RW; bitpos: [3]; default: 0;
 * Set this bit to reset dma  ahb interface.
 */

#define UHCI_AHBM_RST    (BIT(3))
#define UHCI_AHBM_RST_M  (UHCI_AHBM_RST_V << UHCI_AHBM_RST_S)
#define UHCI_AHBM_RST_V  0x00000001
#define UHCI_AHBM_RST_S  3

/* UHCI_AHBM_FIFO_RST : RW; bitpos: [2]; default: 0;
 * Set this bit to reset dma ahb fifo.
 */

#define UHCI_AHBM_FIFO_RST    (BIT(2))
#define UHCI_AHBM_FIFO_RST_M  (UHCI_AHBM_FIFO_RST_V << UHCI_AHBM_FIFO_RST_S)
#define UHCI_AHBM_FIFO_RST_V  0x00000001
#define UHCI_AHBM_FIFO_RST_S  2

/* UHCI_OUT_RST : RW; bitpos: [1]; default: 0;
 * Set this bit to reset out link operations.
 */

#define UHCI_OUT_RST    (BIT(1))
#define UHCI_OUT_RST_M  (UHCI_OUT_RST_V << UHCI_OUT_RST_S)
#define UHCI_OUT_RST_V  0x00000001
#define UHCI_OUT_RST_S  1

/* UHCI_IN_RST : RW; bitpos: [0]; default: 0;
 * Set this bit to reset in link operations.
 */

#define UHCI_IN_RST    (BIT(0))
#define UHCI_IN_RST_M  (UHCI_IN_RST_V << UHCI_IN_RST_S)
#define UHCI_IN_RST_V  0x00000001
#define UHCI_IN_RST_S  0

/* UHCI_INT_RAW_REG register */

#define UHCI_INT_RAW_REG(i) (REG_UHCI_BASE(i) + 0x4)

/* UHCI_DMA_INFIFO_FULL_WM_INT_RAW : R; bitpos: [16]; default: 0; */

#define UHCI_DMA_INFIFO_FULL_WM_INT_RAW    (BIT(16))
#define UHCI_DMA_INFIFO_FULL_WM_INT_RAW_M  (UHCI_DMA_INFIFO_FULL_WM_INT_RAW_V << UHCI_DMA_INFIFO_FULL_WM_INT_RAW_S)
#define UHCI_DMA_INFIFO_FULL_WM_INT_RAW_V  0x00000001
#define UHCI_DMA_INFIFO_FULL_WM_INT_RAW_S  16

/* UHCI_SEND_A_Q_INT_RAW : R; bitpos: [15]; default: 0;
 * When use always_send registers to send a series of short packets it will
 * produce this interrupt when dma has send the short packet.
 */

#define UHCI_SEND_A_Q_INT_RAW    (BIT(15))
#define UHCI_SEND_A_Q_INT_RAW_M  (UHCI_SEND_A_Q_INT_RAW_V << UHCI_SEND_A_Q_INT_RAW_S)
#define UHCI_SEND_A_Q_INT_RAW_V  0x00000001
#define UHCI_SEND_A_Q_INT_RAW_S  15

/* UHCI_SEND_S_Q_INT_RAW : R; bitpos: [14]; default: 0;
 * When use single send registers to send a short packets it will produce
 * this interrupt when dma has send the short packet.
 */

#define UHCI_SEND_S_Q_INT_RAW    (BIT(14))
#define UHCI_SEND_S_Q_INT_RAW_M  (UHCI_SEND_S_Q_INT_RAW_V << UHCI_SEND_S_Q_INT_RAW_S)
#define UHCI_SEND_S_Q_INT_RAW_V  0x00000001
#define UHCI_SEND_S_Q_INT_RAW_S  14

/* UHCI_OUT_TOTAL_EOF_INT_RAW : R; bitpos: [13]; default: 0;
 * When all data have been send  it will produce uhci_out_total_eof_int
 * interrupt.
 */

#define UHCI_OUT_TOTAL_EOF_INT_RAW    (BIT(13))
#define UHCI_OUT_TOTAL_EOF_INT_RAW_M  (UHCI_OUT_TOTAL_EOF_INT_RAW_V << UHCI_OUT_TOTAL_EOF_INT_RAW_S)
#define UHCI_OUT_TOTAL_EOF_INT_RAW_V  0x00000001
#define UHCI_OUT_TOTAL_EOF_INT_RAW_S  13

/* UHCI_OUTLINK_EOF_ERR_INT_RAW : R; bitpos: [12]; default: 0;
 * when there are some errors about eof in outlink descriptor  it will
 * produce uhci_outlink_eof_err_int interrupt.
 */

#define UHCI_OUTLINK_EOF_ERR_INT_RAW    (BIT(12))
#define UHCI_OUTLINK_EOF_ERR_INT_RAW_M  (UHCI_OUTLINK_EOF_ERR_INT_RAW_V << UHCI_OUTLINK_EOF_ERR_INT_RAW_S)
#define UHCI_OUTLINK_EOF_ERR_INT_RAW_V  0x00000001
#define UHCI_OUTLINK_EOF_ERR_INT_RAW_S  12

/* UHCI_IN_DSCR_EMPTY_INT_RAW : R; bitpos: [11]; default: 0;
 * when there are not enough in links for DMA it will produce
 * uhci_in_dscr_err_int interrupt.
 */

#define UHCI_IN_DSCR_EMPTY_INT_RAW    (BIT(11))
#define UHCI_IN_DSCR_EMPTY_INT_RAW_M  (UHCI_IN_DSCR_EMPTY_INT_RAW_V << UHCI_IN_DSCR_EMPTY_INT_RAW_S)
#define UHCI_IN_DSCR_EMPTY_INT_RAW_V  0x00000001
#define UHCI_IN_DSCR_EMPTY_INT_RAW_S  11

/* UHCI_OUT_DSCR_ERR_INT_RAW : R; bitpos: [10]; default: 0;
 * when there are some errors about the in link descriptor  it will produce
 * uhci_out_dscr_err_int interrupt.
 */

#define UHCI_OUT_DSCR_ERR_INT_RAW    (BIT(10))
#define UHCI_OUT_DSCR_ERR_INT_RAW_M  (UHCI_OUT_DSCR_ERR_INT_RAW_V << UHCI_OUT_DSCR_ERR_INT_RAW_S)
#define UHCI_OUT_DSCR_ERR_INT_RAW_V  0x00000001
#define UHCI_OUT_DSCR_ERR_INT_RAW_S  10

/* UHCI_IN_DSCR_ERR_INT_RAW : R; bitpos: [9]; default: 0;
 * when there are some errors about the out link descriptor  it will produce
 * uhci_in_dscr_err_int interrupt.
 */

#define UHCI_IN_DSCR_ERR_INT_RAW    (BIT(9))
#define UHCI_IN_DSCR_ERR_INT_RAW_M  (UHCI_IN_DSCR_ERR_INT_RAW_V << UHCI_IN_DSCR_ERR_INT_RAW_S)
#define UHCI_IN_DSCR_ERR_INT_RAW_V  0x00000001
#define UHCI_IN_DSCR_ERR_INT_RAW_S  9

/* UHCI_OUT_EOF_INT_RAW : R; bitpos: [8]; default: 0;
 * when the current descriptor's eof bit is 1  it will produce
 * uhci_out_eof_int interrupt.
 */

#define UHCI_OUT_EOF_INT_RAW    (BIT(8))
#define UHCI_OUT_EOF_INT_RAW_M  (UHCI_OUT_EOF_INT_RAW_V << UHCI_OUT_EOF_INT_RAW_S)
#define UHCI_OUT_EOF_INT_RAW_V  0x00000001
#define UHCI_OUT_EOF_INT_RAW_S  8

/* UHCI_OUT_DONE_INT_RAW : R; bitpos: [7]; default: 0;
 * when a out link descriptor is completed  it will produce
 * uhci_out_done_int interrupt.
 */

#define UHCI_OUT_DONE_INT_RAW    (BIT(7))
#define UHCI_OUT_DONE_INT_RAW_M  (UHCI_OUT_DONE_INT_RAW_V << UHCI_OUT_DONE_INT_RAW_S)
#define UHCI_OUT_DONE_INT_RAW_V  0x00000001
#define UHCI_OUT_DONE_INT_RAW_S  7

/* UHCI_IN_ERR_EOF_INT_RAW : R; bitpos: [6]; default: 0;
 * when there are some errors about eof in in link descriptor  it will
 * produce uhci_in_err_eof_int interrupt.
 */

#define UHCI_IN_ERR_EOF_INT_RAW    (BIT(6))
#define UHCI_IN_ERR_EOF_INT_RAW_M  (UHCI_IN_ERR_EOF_INT_RAW_V << UHCI_IN_ERR_EOF_INT_RAW_S)
#define UHCI_IN_ERR_EOF_INT_RAW_V  0x00000001
#define UHCI_IN_ERR_EOF_INT_RAW_S  6

/* UHCI_IN_SUC_EOF_INT_RAW : R; bitpos: [5]; default: 0;
 * when a data packet has been received  it will produce uhci_in_suc_eof_int
 * interrupt.
 */

#define UHCI_IN_SUC_EOF_INT_RAW    (BIT(5))
#define UHCI_IN_SUC_EOF_INT_RAW_M  (UHCI_IN_SUC_EOF_INT_RAW_V << UHCI_IN_SUC_EOF_INT_RAW_S)
#define UHCI_IN_SUC_EOF_INT_RAW_V  0x00000001
#define UHCI_IN_SUC_EOF_INT_RAW_S  5

/* UHCI_IN_DONE_INT_RAW : R; bitpos: [4]; default: 0;
 * when a in link descriptor has been completed it will produce
 * uhci_in_done_int interrupt.
 */

#define UHCI_IN_DONE_INT_RAW    (BIT(4))
#define UHCI_IN_DONE_INT_RAW_M  (UHCI_IN_DONE_INT_RAW_V << UHCI_IN_DONE_INT_RAW_S)
#define UHCI_IN_DONE_INT_RAW_V  0x00000001
#define UHCI_IN_DONE_INT_RAW_S  4

/* UHCI_TX_HUNG_INT_RAW : R; bitpos: [3]; default: 0;
 * when DMA takes a lot of time to read a data from RAM  it will produce
 * uhci_tx_hung_int interrupt.
 */

#define UHCI_TX_HUNG_INT_RAW    (BIT(3))
#define UHCI_TX_HUNG_INT_RAW_M  (UHCI_TX_HUNG_INT_RAW_V << UHCI_TX_HUNG_INT_RAW_S)
#define UHCI_TX_HUNG_INT_RAW_V  0x00000001
#define UHCI_TX_HUNG_INT_RAW_S  3

/* UHCI_RX_HUNG_INT_RAW : R; bitpos: [2]; default: 0;
 * when DMA takes a lot of time to receive a data   it will produce
 * uhci_rx_hung_int interrupt.
 */

#define UHCI_RX_HUNG_INT_RAW    (BIT(2))
#define UHCI_RX_HUNG_INT_RAW_M  (UHCI_RX_HUNG_INT_RAW_V << UHCI_RX_HUNG_INT_RAW_S)
#define UHCI_RX_HUNG_INT_RAW_V  0x00000001
#define UHCI_RX_HUNG_INT_RAW_S  2

/* UHCI_TX_START_INT_RAW : R; bitpos: [1]; default: 0;
 * when DMA detects a separator char it will produce uhci_tx_start_int
 * interrupt.
 */

#define UHCI_TX_START_INT_RAW    (BIT(1))
#define UHCI_TX_START_INT_RAW_M  (UHCI_TX_START_INT_RAW_V << UHCI_TX_START_INT_RAW_S)
#define UHCI_TX_START_INT_RAW_V  0x00000001
#define UHCI_TX_START_INT_RAW_S  1

/* UHCI_RX_START_INT_RAW : R; bitpos: [0]; default: 0;
 * when a separator char has been send  it will produce uhci_rx_start_int
 * interrupt.
 */

#define UHCI_RX_START_INT_RAW    (BIT(0))
#define UHCI_RX_START_INT_RAW_M  (UHCI_RX_START_INT_RAW_V << UHCI_RX_START_INT_RAW_S)
#define UHCI_RX_START_INT_RAW_V  0x00000001
#define UHCI_RX_START_INT_RAW_S  0

/* UHCI_INT_ST_REG register */

#define UHCI_INT_ST_REG(i) (REG_UHCI_BASE(i) + 0x8)

/* UHCI_DMA_INFIFO_FULL_WM_INT_ST : R; bitpos: [16]; default: 0; */

#define UHCI_DMA_INFIFO_FULL_WM_INT_ST    (BIT(16))
#define UHCI_DMA_INFIFO_FULL_WM_INT_ST_M  (UHCI_DMA_INFIFO_FULL_WM_INT_ST_V << UHCI_DMA_INFIFO_FULL_WM_INT_ST_S)
#define UHCI_DMA_INFIFO_FULL_WM_INT_ST_V  0x00000001
#define UHCI_DMA_INFIFO_FULL_WM_INT_ST_S  16

/* UHCI_SEND_A_Q_INT_ST : R; bitpos: [15]; default: 0; */

#define UHCI_SEND_A_Q_INT_ST    (BIT(15))
#define UHCI_SEND_A_Q_INT_ST_M  (UHCI_SEND_A_Q_INT_ST_V << UHCI_SEND_A_Q_INT_ST_S)
#define UHCI_SEND_A_Q_INT_ST_V  0x00000001
#define UHCI_SEND_A_Q_INT_ST_S  15

/* UHCI_SEND_S_Q_INT_ST : R; bitpos: [14]; default: 0; */

#define UHCI_SEND_S_Q_INT_ST    (BIT(14))
#define UHCI_SEND_S_Q_INT_ST_M  (UHCI_SEND_S_Q_INT_ST_V << UHCI_SEND_S_Q_INT_ST_S)
#define UHCI_SEND_S_Q_INT_ST_V  0x00000001
#define UHCI_SEND_S_Q_INT_ST_S  14

/* UHCI_OUT_TOTAL_EOF_INT_ST : R; bitpos: [13]; default: 0; */

#define UHCI_OUT_TOTAL_EOF_INT_ST    (BIT(13))
#define UHCI_OUT_TOTAL_EOF_INT_ST_M  (UHCI_OUT_TOTAL_EOF_INT_ST_V << UHCI_OUT_TOTAL_EOF_INT_ST_S)
#define UHCI_OUT_TOTAL_EOF_INT_ST_V  0x00000001
#define UHCI_OUT_TOTAL_EOF_INT_ST_S  13

/* UHCI_OUTLINK_EOF_ERR_INT_ST : R; bitpos: [12]; default: 0; */

#define UHCI_OUTLINK_EOF_ERR_INT_ST    (BIT(12))
#define UHCI_OUTLINK_EOF_ERR_INT_ST_M  (UHCI_OUTLINK_EOF_ERR_INT_ST_V << UHCI_OUTLINK_EOF_ERR_INT_ST_S)
#define UHCI_OUTLINK_EOF_ERR_INT_ST_V  0x00000001
#define UHCI_OUTLINK_EOF_ERR_INT_ST_S  12

/* UHCI_IN_DSCR_EMPTY_INT_ST : R; bitpos: [11]; default: 0; */

#define UHCI_IN_DSCR_EMPTY_INT_ST    (BIT(11))
#define UHCI_IN_DSCR_EMPTY_INT_ST_M  (UHCI_IN_DSCR_EMPTY_INT_ST_V << UHCI_IN_DSCR_EMPTY_INT_ST_S)
#define UHCI_IN_DSCR_EMPTY_INT_ST_V  0x00000001
#define UHCI_IN_DSCR_EMPTY_INT_ST_S  11

/* UHCI_OUT_DSCR_ERR_INT_ST : R; bitpos: [10]; default: 0; */

#define UHCI_OUT_DSCR_ERR_INT_ST    (BIT(10))
#define UHCI_OUT_DSCR_ERR_INT_ST_M  (UHCI_OUT_DSCR_ERR_INT_ST_V << UHCI_OUT_DSCR_ERR_INT_ST_S)
#define UHCI_OUT_DSCR_ERR_INT_ST_V  0x00000001
#define UHCI_OUT_DSCR_ERR_INT_ST_S  10

/* UHCI_IN_DSCR_ERR_INT_ST : R; bitpos: [9]; default: 0; */

#define UHCI_IN_DSCR_ERR_INT_ST    (BIT(9))
#define UHCI_IN_DSCR_ERR_INT_ST_M  (UHCI_IN_DSCR_ERR_INT_ST_V << UHCI_IN_DSCR_ERR_INT_ST_S)
#define UHCI_IN_DSCR_ERR_INT_ST_V  0x00000001
#define UHCI_IN_DSCR_ERR_INT_ST_S  9

/* UHCI_OUT_EOF_INT_ST : R; bitpos: [8]; default: 0; */

#define UHCI_OUT_EOF_INT_ST    (BIT(8))
#define UHCI_OUT_EOF_INT_ST_M  (UHCI_OUT_EOF_INT_ST_V << UHCI_OUT_EOF_INT_ST_S)
#define UHCI_OUT_EOF_INT_ST_V  0x00000001
#define UHCI_OUT_EOF_INT_ST_S  8

/* UHCI_OUT_DONE_INT_ST : R; bitpos: [7]; default: 0; */

#define UHCI_OUT_DONE_INT_ST    (BIT(7))
#define UHCI_OUT_DONE_INT_ST_M  (UHCI_OUT_DONE_INT_ST_V << UHCI_OUT_DONE_INT_ST_S)
#define UHCI_OUT_DONE_INT_ST_V  0x00000001
#define UHCI_OUT_DONE_INT_ST_S  7

/* UHCI_IN_ERR_EOF_INT_ST : R; bitpos: [6]; default: 0; */

#define UHCI_IN_ERR_EOF_INT_ST    (BIT(6))
#define UHCI_IN_ERR_EOF_INT_ST_M  (UHCI_IN_ERR_EOF_INT_ST_V << UHCI_IN_ERR_EOF_INT_ST_S)
#define UHCI_IN_ERR_EOF_INT_ST_V  0x00000001
#define UHCI_IN_ERR_EOF_INT_ST_S  6

/* UHCI_IN_SUC_EOF_INT_ST : R; bitpos: [5]; default: 0; */

#define UHCI_IN_SUC_EOF_INT_ST    (BIT(5))
#define UHCI_IN_SUC_EOF_INT_ST_M  (UHCI_IN_SUC_EOF_INT_ST_V << UHCI_IN_SUC_EOF_INT_ST_S)
#define UHCI_IN_SUC_EOF_INT_ST_V  0x00000001
#define UHCI_IN_SUC_EOF_INT_ST_S  5

/* UHCI_IN_DONE_INT_ST : R; bitpos: [4]; default: 0; */

#define UHCI_IN_DONE_INT_ST    (BIT(4))
#define UHCI_IN_DONE_INT_ST_M  (UHCI_IN_DONE_INT_ST_V << UHCI_IN_DONE_INT_ST_S)
#define UHCI_IN_DONE_INT_ST_V  0x00000001
#define UHCI_IN_DONE_INT_ST_S  4

/* UHCI_TX_HUNG_INT_ST : R; bitpos: [3]; default: 0; */

#define UHCI_TX_HUNG_INT_ST    (BIT(3))
#define UHCI_TX_HUNG_INT_ST_M  (UHCI_TX_HUNG_INT_ST_V << UHCI_TX_HUNG_INT_ST_S)
#define UHCI_TX_HUNG_INT_ST_V  0x00000001
#define UHCI_TX_HUNG_INT_ST_S  3

/* UHCI_RX_HUNG_INT_ST : R; bitpos: [2]; default: 0; */

#define UHCI_RX_HUNG_INT_ST    (BIT(2))
#define UHCI_RX_HUNG_INT_ST_M  (UHCI_RX_HUNG_INT_ST_V << UHCI_RX_HUNG_INT_ST_S)
#define UHCI_RX_HUNG_INT_ST_V  0x00000001
#define UHCI_RX_HUNG_INT_ST_S  2

/* UHCI_TX_START_INT_ST : R; bitpos: [1]; default: 0; */

#define UHCI_TX_START_INT_ST    (BIT(1))
#define UHCI_TX_START_INT_ST_M  (UHCI_TX_START_INT_ST_V << UHCI_TX_START_INT_ST_S)
#define UHCI_TX_START_INT_ST_V  0x00000001
#define UHCI_TX_START_INT_ST_S  1

/* UHCI_RX_START_INT_ST : R; bitpos: [0]; default: 0; */

#define UHCI_RX_START_INT_ST    (BIT(0))
#define UHCI_RX_START_INT_ST_M  (UHCI_RX_START_INT_ST_V << UHCI_RX_START_INT_ST_S)
#define UHCI_RX_START_INT_ST_V  0x00000001
#define UHCI_RX_START_INT_ST_S  0

/* UHCI_INT_ENA_REG register */

#define UHCI_INT_ENA_REG(i) (REG_UHCI_BASE(i) + 0xc)

/* UHCI_DMA_INFIFO_FULL_WM_INT_ENA : RW; bitpos: [16]; default: 0; */

#define UHCI_DMA_INFIFO_FULL_WM_INT_ENA    (BIT(16))
#define UHCI_DMA_INFIFO_FULL_WM_INT_ENA_M  (UHCI_DMA_INFIFO_FULL_WM_INT_ENA_V << UHCI_DMA_INFIFO_FULL_WM_INT_ENA_S)
#define UHCI_DMA_INFIFO_FULL_WM_INT_ENA_V  0x00000001
#define UHCI_DMA_INFIFO_FULL_WM_INT_ENA_S  16

/* UHCI_SEND_A_Q_INT_ENA : RW; bitpos: [15]; default: 0; */

#define UHCI_SEND_A_Q_INT_ENA    (BIT(15))
#define UHCI_SEND_A_Q_INT_ENA_M  (UHCI_SEND_A_Q_INT_ENA_V << UHCI_SEND_A_Q_INT_ENA_S)
#define UHCI_SEND_A_Q_INT_ENA_V  0x00000001
#define UHCI_SEND_A_Q_INT_ENA_S  15

/* UHCI_SEND_S_Q_INT_ENA : RW; bitpos: [14]; default: 0; */

#define UHCI_SEND_S_Q_INT_ENA    (BIT(14))
#define UHCI_SEND_S_Q_INT_ENA_M  (UHCI_SEND_S_Q_INT_ENA_V << UHCI_SEND_S_Q_INT_ENA_S)
#define UHCI_SEND_S_Q_INT_ENA_V  0x00000001
#define UHCI_SEND_S_Q_INT_ENA_S  14

/* UHCI_OUT_TOTAL_EOF_INT_ENA : RW; bitpos: [13]; default: 0; */

#define UHCI_OUT_TOTAL_EOF_INT_ENA    (BIT(13))
#define UHCI_OUT_TOTAL_EOF_INT_ENA_M  (UHCI_OUT_TOTAL_EOF_INT_ENA_V << UHCI_OUT_TOTAL_EOF_INT_ENA_S)
#define UHCI_OUT_TOTAL_EOF_INT_ENA_V  0x00000001
#define UHCI_OUT_TOTAL_EOF_INT_ENA_S  13

/* UHCI_OUTLINK_EOF_ERR_INT_ENA : RW; bitpos: [12]; default: 0; */

#define UHCI_OUTLINK_EOF_ERR_INT_ENA    (BIT(12))
#define UHCI_OUTLINK_EOF_ERR_INT_ENA_M  (UHCI_OUTLINK_EOF_ERR_INT_ENA_V << UHCI_OUTLINK_EOF_ERR_INT_ENA_S)
#define UHCI_OUTLINK_EOF_ERR_INT_ENA_V  0x00000001
#define UHCI_OUTLINK_EOF_ERR_INT_ENA_S  12

/* UHCI_IN_DSCR_EMPTY_INT_ENA : RW; bitpos: [11]; default: 0; */

#define UHCI_IN_DSCR_EMPTY_INT_ENA    (BIT(11))
#define UHCI_IN_DSCR_EMPTY_INT_ENA_M  (UHCI_IN_DSCR_EMPTY_INT_ENA_V << UHCI_IN_DSCR_EMPTY_INT_ENA_S)
#define UHCI_IN_DSCR_EMPTY_INT_ENA_V  0x00000001
#define UHCI_IN_DSCR_EMPTY_INT_ENA_S  11

/* UHCI_OUT_DSCR_ERR_INT_ENA : RW; bitpos: [10]; default: 0; */

#define UHCI_OUT_DSCR_ERR_INT_ENA    (BIT(10))
#define UHCI_OUT_DSCR_ERR_INT_ENA_M  (UHCI_OUT_DSCR_ERR_INT_ENA_V << UHCI_OUT_DSCR_ERR_INT_ENA_S)
#define UHCI_OUT_DSCR_ERR_INT_ENA_V  0x00000001
#define UHCI_OUT_DSCR_ERR_INT_ENA_S  10

/* UHCI_IN_DSCR_ERR_INT_ENA : RW; bitpos: [9]; default: 0; */

#define UHCI_IN_DSCR_ERR_INT_ENA    (BIT(9))
#define UHCI_IN_DSCR_ERR_INT_ENA_M  (UHCI_IN_DSCR_ERR_INT_ENA_V << UHCI_IN_DSCR_ERR_INT_ENA_S)
#define UHCI_IN_DSCR_ERR_INT_ENA_V  0x00000001
#define UHCI_IN_DSCR_ERR_INT_ENA_S  9

/* UHCI_OUT_EOF_INT_ENA : RW; bitpos: [8]; default: 0; */

#define UHCI_OUT_EOF_INT_ENA    (BIT(8))
#define UHCI_OUT_EOF_INT_ENA_M  (UHCI_OUT_EOF_INT_ENA_V << UHCI_OUT_EOF_INT_ENA_S)
#define UHCI_OUT_EOF_INT_ENA_V  0x00000001
#define UHCI_OUT_EOF_INT_ENA_S  8

/* UHCI_OUT_DONE_INT_ENA : RW; bitpos: [7]; default: 0; */

#define UHCI_OUT_DONE_INT_ENA    (BIT(7))
#define UHCI_OUT_DONE_INT_ENA_M  (UHCI_OUT_DONE_INT_ENA_V << UHCI_OUT_DONE_INT_ENA_S)
#define UHCI_OUT_DONE_INT_ENA_V  0x00000001
#define UHCI_OUT_DONE_INT_ENA_S  7

/* UHCI_IN_ERR_EOF_INT_ENA : RW; bitpos: [6]; default: 0; */

#define UHCI_IN_ERR_EOF_INT_ENA    (BIT(6))
#define UHCI_IN_ERR_EOF_INT_ENA_M  (UHCI_IN_ERR_EOF_INT_ENA_V << UHCI_IN_ERR_EOF_INT_ENA_S)
#define UHCI_IN_ERR_EOF_INT_ENA_V  0x00000001
#define UHCI_IN_ERR_EOF_INT_ENA_S  6

/* UHCI_IN_SUC_EOF_INT_ENA : RW; bitpos: [5]; default: 0; */

#define UHCI_IN_SUC_EOF_INT_ENA    (BIT(5))
#define UHCI_IN_SUC_EOF_INT_ENA_M  (UHCI_IN_SUC_EOF_INT_ENA_V << UHCI_IN_SUC_EOF_INT_ENA_S)
#define UHCI_IN_SUC_EOF_INT_ENA_V  0x00000001
#define UHCI_IN_SUC_EOF_INT_ENA_S  5

/* UHCI_IN_DONE_INT_ENA : RW; bitpos: [4]; default: 0; */

#define UHCI_IN_DONE_INT_ENA    (BIT(4))
#define UHCI_IN_DONE_INT_ENA_M  (UHCI_IN_DONE_INT_ENA_V << UHCI_IN_DONE_INT_ENA_S)
#define UHCI_IN_DONE_INT_ENA_V  0x00000001
#define UHCI_IN_DONE_INT_ENA_S  4

/* UHCI_TX_HUNG_INT_ENA : RW; bitpos: [3]; default: 0; */

#define UHCI_TX_HUNG_INT_ENA    (BIT(3))
#define UHCI_TX_HUNG_INT_ENA_M  (UHCI_TX_HUNG_INT_ENA_V << UHCI_TX_HUNG_INT_ENA_S)
#define UHCI_TX_HUNG_INT_ENA_V  0x00000001
#define UHCI_TX_HUNG_INT_ENA_S  3

/* UHCI_RX_HUNG_INT_ENA : RW; bitpos: [2]; default: 0; */

#define UHCI_RX_HUNG_INT_ENA    (BIT(2))
#define UHCI_RX_HUNG_INT_ENA_M  (UHCI_RX_HUNG_INT_ENA_V << UHCI_RX_HUNG_INT_ENA_S)
#define UHCI_RX_HUNG_INT_ENA_V  0x00000001
#define UHCI_RX_HUNG_INT_ENA_S  2

/* UHCI_TX_START_INT_ENA : RW; bitpos: [1]; default: 0; */

#define UHCI_TX_START_INT_ENA    (BIT(1))
#define UHCI_TX_START_INT_ENA_M  (UHCI_TX_START_INT_ENA_V << UHCI_TX_START_INT_ENA_S)
#define UHCI_TX_START_INT_ENA_V  0x00000001
#define UHCI_TX_START_INT_ENA_S  1

/* UHCI_RX_START_INT_ENA : RW; bitpos: [0]; default: 0; */

#define UHCI_RX_START_INT_ENA    (BIT(0))
#define UHCI_RX_START_INT_ENA_M  (UHCI_RX_START_INT_ENA_V << UHCI_RX_START_INT_ENA_S)
#define UHCI_RX_START_INT_ENA_V  0x00000001
#define UHCI_RX_START_INT_ENA_S  0

/* UHCI_INT_CLR_REG register */

#define UHCI_INT_CLR_REG(i) (REG_UHCI_BASE(i) + 0x10)

/* UHCI_DMA_INFIFO_FULL_WM_INT_CLR : W; bitpos: [16]; default: 0; */

#define UHCI_DMA_INFIFO_FULL_WM_INT_CLR    (BIT(16))
#define UHCI_DMA_INFIFO_FULL_WM_INT_CLR_M  (UHCI_DMA_INFIFO_FULL_WM_INT_CLR_V << UHCI_DMA_INFIFO_FULL_WM_INT_CLR_S)
#define UHCI_DMA_INFIFO_FULL_WM_INT_CLR_V  0x00000001
#define UHCI_DMA_INFIFO_FULL_WM_INT_CLR_S  16

/* UHCI_SEND_A_Q_INT_CLR : W; bitpos: [15]; default: 0; */

#define UHCI_SEND_A_Q_INT_CLR    (BIT(15))
#define UHCI_SEND_A_Q_INT_CLR_M  (UHCI_SEND_A_Q_INT_CLR_V << UHCI_SEND_A_Q_INT_CLR_S)
#define UHCI_SEND_A_Q_INT_CLR_V  0x00000001
#define UHCI_SEND_A_Q_INT_CLR_S  15

/* UHCI_SEND_S_Q_INT_CLR : W; bitpos: [14]; default: 0; */

#define UHCI_SEND_S_Q_INT_CLR    (BIT(14))
#define UHCI_SEND_S_Q_INT_CLR_M  (UHCI_SEND_S_Q_INT_CLR_V << UHCI_SEND_S_Q_INT_CLR_S)
#define UHCI_SEND_S_Q_INT_CLR_V  0x00000001
#define UHCI_SEND_S_Q_INT_CLR_S  14

/* UHCI_OUT_TOTAL_EOF_INT_CLR : W; bitpos: [13]; default: 0; */

#define UHCI_OUT_TOTAL_EOF_INT_CLR    (BIT(13))
#define UHCI_OUT_TOTAL_EOF_INT_CLR_M  (UHCI_OUT_TOTAL_EOF_INT_CLR_V << UHCI_OUT_TOTAL_EOF_INT_CLR_S)
#define UHCI_OUT_TOTAL_EOF_INT_CLR_V  0x00000001
#define UHCI_OUT_TOTAL_EOF_INT_CLR_S  13

/* UHCI_OUTLINK_EOF_ERR_INT_CLR : W; bitpos: [12]; default: 0; */

#define UHCI_OUTLINK_EOF_ERR_INT_CLR    (BIT(12))
#define UHCI_OUTLINK_EOF_ERR_INT_CLR_M  (UHCI_OUTLINK_EOF_ERR_INT_CLR_V << UHCI_OUTLINK_EOF_ERR_INT_CLR_S)
#define UHCI_OUTLINK_EOF_ERR_INT_CLR_V  0x00000001
#define UHCI_OUTLINK_EOF_ERR_INT_CLR_S  12

/* UHCI_IN_DSCR_EMPTY_INT_CLR : W; bitpos: [11]; default: 0; */

#define UHCI_IN_DSCR_EMPTY_INT_CLR    (BIT(11))
#define UHCI_IN_DSCR_EMPTY_INT_CLR_M  (UHCI_IN_DSCR_EMPTY_INT_CLR_V << UHCI_IN_DSCR_EMPTY_INT_CLR_S)
#define UHCI_IN_DSCR_EMPTY_INT_CLR_V  0x00000001
#define UHCI_IN_DSCR_EMPTY_INT_CLR_S  11

/* UHCI_OUT_DSCR_ERR_INT_CLR : W; bitpos: [10]; default: 0; */

#define UHCI_OUT_DSCR_ERR_INT_CLR    (BIT(10))
#define UHCI_OUT_DSCR_ERR_INT_CLR_M  (UHCI_OUT_DSCR_ERR_INT_CLR_V << UHCI_OUT_DSCR_ERR_INT_CLR_S)
#define UHCI_OUT_DSCR_ERR_INT_CLR_V  0x00000001
#define UHCI_OUT_DSCR_ERR_INT_CLR_S  10

/* UHCI_IN_DSCR_ERR_INT_CLR : W; bitpos: [9]; default: 0; */

#define UHCI_IN_DSCR_ERR_INT_CLR    (BIT(9))
#define UHCI_IN_DSCR_ERR_INT_CLR_M  (UHCI_IN_DSCR_ERR_INT_CLR_V << UHCI_IN_DSCR_ERR_INT_CLR_S)
#define UHCI_IN_DSCR_ERR_INT_CLR_V  0x00000001
#define UHCI_IN_DSCR_ERR_INT_CLR_S  9

/* UHCI_OUT_EOF_INT_CLR : W; bitpos: [8]; default: 0; */

#define UHCI_OUT_EOF_INT_CLR    (BIT(8))
#define UHCI_OUT_EOF_INT_CLR_M  (UHCI_OUT_EOF_INT_CLR_V << UHCI_OUT_EOF_INT_CLR_S)
#define UHCI_OUT_EOF_INT_CLR_V  0x00000001
#define UHCI_OUT_EOF_INT_CLR_S  8

/* UHCI_OUT_DONE_INT_CLR : W; bitpos: [7]; default: 0; */

#define UHCI_OUT_DONE_INT_CLR    (BIT(7))
#define UHCI_OUT_DONE_INT_CLR_M  (UHCI_OUT_DONE_INT_CLR_V << UHCI_OUT_DONE_INT_CLR_S)
#define UHCI_OUT_DONE_INT_CLR_V  0x00000001
#define UHCI_OUT_DONE_INT_CLR_S  7

/* UHCI_IN_ERR_EOF_INT_CLR : W; bitpos: [6]; default: 0; */

#define UHCI_IN_ERR_EOF_INT_CLR    (BIT(6))
#define UHCI_IN_ERR_EOF_INT_CLR_M  (UHCI_IN_ERR_EOF_INT_CLR_V << UHCI_IN_ERR_EOF_INT_CLR_S)
#define UHCI_IN_ERR_EOF_INT_CLR_V  0x00000001
#define UHCI_IN_ERR_EOF_INT_CLR_S  6

/* UHCI_IN_SUC_EOF_INT_CLR : W; bitpos: [5]; default: 0; */

#define UHCI_IN_SUC_EOF_INT_CLR    (BIT(5))
#define UHCI_IN_SUC_EOF_INT_CLR_M  (UHCI_IN_SUC_EOF_INT_CLR_V << UHCI_IN_SUC_EOF_INT_CLR_S)
#define UHCI_IN_SUC_EOF_INT_CLR_V  0x00000001
#define UHCI_IN_SUC_EOF_INT_CLR_S  5

/* UHCI_IN_DONE_INT_CLR : W; bitpos: [4]; default: 0; */

#define UHCI_IN_DONE_INT_CLR    (BIT(4))
#define UHCI_IN_DONE_INT_CLR_M  (UHCI_IN_DONE_INT_CLR_V << UHCI_IN_DONE_INT_CLR_S)
#define UHCI_IN_DONE_INT_CLR_V  0x00000001
#define UHCI_IN_DONE_INT_CLR_S  4

/* UHCI_TX_HUNG_INT_CLR : W; bitpos: [3]; default: 0; */

#define UHCI_TX_HUNG_INT_CLR    (BIT(3))
#define UHCI_TX_HUNG_INT_CLR_M  (UHCI_TX_HUNG_INT_CLR_V << UHCI_TX_HUNG_INT_CLR_S)
#define UHCI_TX_HUNG_INT_CLR_V  0x00000001
#define UHCI_TX_HUNG_INT_CLR_S  3

/* UHCI_RX_HUNG_INT_CLR : W; bitpos: [2]; default: 0; */

#define UHCI_RX_HUNG_INT_CLR    (BIT(2))
#define UHCI_RX_HUNG_INT_CLR_M  (UHCI_RX_HUNG_INT_CLR_V << UHCI_RX_HUNG_INT_CLR_S)
#define UHCI_RX_HUNG_INT_CLR_V  0x00000001
#define UHCI_RX_HUNG_INT_CLR_S  2

/* UHCI_TX_START_INT_CLR : W; bitpos: [1]; default: 0; */

#define UHCI_TX_START_INT_CLR    (BIT(1))
#define UHCI_TX_START_INT_CLR_M  (UHCI_TX_START_INT_CLR_V << UHCI_TX_START_INT_CLR_S)
#define UHCI_TX_START_INT_CLR_V  0x00000001
#define UHCI_TX_START_INT_CLR_S  1

/* UHCI_RX_START_INT_CLR : W; bitpos: [0]; default: 0; */

#define UHCI_RX_START_INT_CLR    (BIT(0))
#define UHCI_RX_START_INT_CLR_M  (UHCI_RX_START_INT_CLR_V << UHCI_RX_START_INT_CLR_S)
#define UHCI_RX_START_INT_CLR_V  0x00000001
#define UHCI_RX_START_INT_CLR_S  0

/* UHCI_DMA_OUT_STATUS_REG register */

#define UHCI_DMA_OUT_STATUS_REG(i) (REG_UHCI_BASE(i) + 0x14)

/* UHCI_OUT_EMPTY : R; bitpos: [1]; default: 1;
 * 1:DMA in link descriptor's fifo is empty.
 */

#define UHCI_OUT_EMPTY    (BIT(1))
#define UHCI_OUT_EMPTY_M  (UHCI_OUT_EMPTY_V << UHCI_OUT_EMPTY_S)
#define UHCI_OUT_EMPTY_V  0x00000001
#define UHCI_OUT_EMPTY_S  1

/* UHCI_OUT_FULL : R; bitpos: [0]; default: 0;
 * 1:DMA out link descriptor's fifo is full.
 */

#define UHCI_OUT_FULL    (BIT(0))
#define UHCI_OUT_FULL_M  (UHCI_OUT_FULL_V << UHCI_OUT_FULL_S)
#define UHCI_OUT_FULL_V  0x00000001
#define UHCI_OUT_FULL_S  0

/* UHCI_DMA_OUT_PUSH_REG register */

#define UHCI_DMA_OUT_PUSH_REG(i) (REG_UHCI_BASE(i) + 0x18)

/* UHCI_OUTFIFO_PUSH : RW; bitpos: [16]; default: 0;
 * Set this bit to push data in out link descriptor's fifo.
 */

#define UHCI_OUTFIFO_PUSH    (BIT(16))
#define UHCI_OUTFIFO_PUSH_M  (UHCI_OUTFIFO_PUSH_V << UHCI_OUTFIFO_PUSH_S)
#define UHCI_OUTFIFO_PUSH_V  0x00000001
#define UHCI_OUTFIFO_PUSH_S  16

/* UHCI_OUTFIFO_WDATA : RW; bitpos: [8:0]; default: 0;
 * This is the data need to be pushed into out link descriptor's fifo.
 */

#define UHCI_OUTFIFO_WDATA    0x000001FF
#define UHCI_OUTFIFO_WDATA_M  (UHCI_OUTFIFO_WDATA_V << UHCI_OUTFIFO_WDATA_S)
#define UHCI_OUTFIFO_WDATA_V  0x000001FF
#define UHCI_OUTFIFO_WDATA_S  0

/* UHCI_DMA_IN_STATUS_REG register */

#define UHCI_DMA_IN_STATUS_REG(i) (REG_UHCI_BASE(i) + 0x1c)

/* UHCI_RX_ERR_CAUSE : R; bitpos: [6:4]; default: 0;
 * This register stores the errors caused in out link descriptor's data
 * packet.
 */

#define UHCI_RX_ERR_CAUSE    0x00000007
#define UHCI_RX_ERR_CAUSE_M  (UHCI_RX_ERR_CAUSE_V << UHCI_RX_ERR_CAUSE_S)
#define UHCI_RX_ERR_CAUSE_V  0x00000007
#define UHCI_RX_ERR_CAUSE_S  4

/* UHCI_IN_EMPTY : R; bitpos: [1]; default: 1; */

#define UHCI_IN_EMPTY    (BIT(1))
#define UHCI_IN_EMPTY_M  (UHCI_IN_EMPTY_V << UHCI_IN_EMPTY_S)
#define UHCI_IN_EMPTY_V  0x00000001
#define UHCI_IN_EMPTY_S  1

/* UHCI_IN_FULL : R; bitpos: [0]; default: 0; */

#define UHCI_IN_FULL    (BIT(0))
#define UHCI_IN_FULL_M  (UHCI_IN_FULL_V << UHCI_IN_FULL_S)
#define UHCI_IN_FULL_V  0x00000001
#define UHCI_IN_FULL_S  0

/* UHCI_DMA_IN_POP_REG register */

#define UHCI_DMA_IN_POP_REG(i) (REG_UHCI_BASE(i) + 0x20)

/* UHCI_INFIFO_POP : RW; bitpos: [16]; default: 0;
 * Set this bit to pop data in in link descriptor's fifo.
 */

#define UHCI_INFIFO_POP    (BIT(16))
#define UHCI_INFIFO_POP_M  (UHCI_INFIFO_POP_V << UHCI_INFIFO_POP_S)
#define UHCI_INFIFO_POP_V  0x00000001
#define UHCI_INFIFO_POP_S  16

/* UHCI_INFIFO_RDATA : R; bitpos: [11:0]; default: 0;
 * This register stores the data pop from in link descriptor's fifo.
 */

#define UHCI_INFIFO_RDATA    0x00000FFF
#define UHCI_INFIFO_RDATA_M  (UHCI_INFIFO_RDATA_V << UHCI_INFIFO_RDATA_S)
#define UHCI_INFIFO_RDATA_V  0x00000FFF
#define UHCI_INFIFO_RDATA_S  0

/* UHCI_DMA_OUT_LINK_REG register */

#define UHCI_DMA_OUT_LINK_REG(i) (REG_UHCI_BASE(i) + 0x24)

/* UHCI_OUTLINK_PARK : R; bitpos: [31]; default: 0;
 * 1£º the out link descriptor's fsm is in idle state. 0:the out link
 * descriptor's fsm is working.
 */

#define UHCI_OUTLINK_PARK    (BIT(31))
#define UHCI_OUTLINK_PARK_M  (UHCI_OUTLINK_PARK_V << UHCI_OUTLINK_PARK_S)
#define UHCI_OUTLINK_PARK_V  0x00000001
#define UHCI_OUTLINK_PARK_S  31

/* UHCI_OUTLINK_RESTART : RW; bitpos: [30]; default: 0;
 * Set this bit to mount on new out link descriptors
 */

#define UHCI_OUTLINK_RESTART    (BIT(30))
#define UHCI_OUTLINK_RESTART_M  (UHCI_OUTLINK_RESTART_V << UHCI_OUTLINK_RESTART_S)
#define UHCI_OUTLINK_RESTART_V  0x00000001
#define UHCI_OUTLINK_RESTART_S  30

/* UHCI_OUTLINK_START : RW; bitpos: [29]; default: 0;
 * Set this bit to start dealing with the out link descriptors.
 */

#define UHCI_OUTLINK_START    (BIT(29))
#define UHCI_OUTLINK_START_M  (UHCI_OUTLINK_START_V << UHCI_OUTLINK_START_S)
#define UHCI_OUTLINK_START_V  0x00000001
#define UHCI_OUTLINK_START_S  29

/* UHCI_OUTLINK_STOP : RW; bitpos: [28]; default: 0;
 * Set this bit to stop dealing with the out link descriptors.
 */

#define UHCI_OUTLINK_STOP    (BIT(28))
#define UHCI_OUTLINK_STOP_M  (UHCI_OUTLINK_STOP_V << UHCI_OUTLINK_STOP_S)
#define UHCI_OUTLINK_STOP_V  0x00000001
#define UHCI_OUTLINK_STOP_S  28

/* UHCI_OUTLINK_ADDR : RW; bitpos: [19:0]; default: 0;
 * This register stores the least 20 bits of the first out link descriptor's
 * address.
 */

#define UHCI_OUTLINK_ADDR    0x000FFFFF
#define UHCI_OUTLINK_ADDR_M  (UHCI_OUTLINK_ADDR_V << UHCI_OUTLINK_ADDR_S)
#define UHCI_OUTLINK_ADDR_V  0x000FFFFF
#define UHCI_OUTLINK_ADDR_S  0

/* UHCI_DMA_IN_LINK_REG register */

#define UHCI_DMA_IN_LINK_REG(i) (REG_UHCI_BASE(i) + 0x28)

/* UHCI_INLINK_PARK : R; bitpos: [31]; default: 0;
 * 1:the in link descriptor's fsm is in idle state.   0:the in link
 * descriptor's fsm is working
 */

#define UHCI_INLINK_PARK    (BIT(31))
#define UHCI_INLINK_PARK_M  (UHCI_INLINK_PARK_V << UHCI_INLINK_PARK_S)
#define UHCI_INLINK_PARK_V  0x00000001
#define UHCI_INLINK_PARK_S  31

/* UHCI_INLINK_RESTART : RW; bitpos: [30]; default: 0;
 * Set this bit to mount on new in link descriptors
 */

#define UHCI_INLINK_RESTART    (BIT(30))
#define UHCI_INLINK_RESTART_M  (UHCI_INLINK_RESTART_V << UHCI_INLINK_RESTART_S)
#define UHCI_INLINK_RESTART_V  0x00000001
#define UHCI_INLINK_RESTART_S  30

/* UHCI_INLINK_START : RW; bitpos: [29]; default: 0;
 * Set this bit to start dealing with the in link descriptors.
 */

#define UHCI_INLINK_START    (BIT(29))
#define UHCI_INLINK_START_M  (UHCI_INLINK_START_V << UHCI_INLINK_START_S)
#define UHCI_INLINK_START_V  0x00000001
#define UHCI_INLINK_START_S  29

/* UHCI_INLINK_STOP : RW; bitpos: [28]; default: 0;
 * Set this bit to stop dealing with the in link descriptors.
 */

#define UHCI_INLINK_STOP    (BIT(28))
#define UHCI_INLINK_STOP_M  (UHCI_INLINK_STOP_V << UHCI_INLINK_STOP_S)
#define UHCI_INLINK_STOP_V  0x00000001
#define UHCI_INLINK_STOP_S  28

/* UHCI_INLINK_AUTO_RET : RW; bitpos: [20]; default: 1;
 * 1:when a packet is wrong in link descriptor returns to the descriptor
 * which is lately used.
 */

#define UHCI_INLINK_AUTO_RET    (BIT(20))
#define UHCI_INLINK_AUTO_RET_M  (UHCI_INLINK_AUTO_RET_V << UHCI_INLINK_AUTO_RET_S)
#define UHCI_INLINK_AUTO_RET_V  0x00000001
#define UHCI_INLINK_AUTO_RET_S  20

/* UHCI_INLINK_ADDR : RW; bitpos: [19:0]; default: 0;
 * This register stores the least 20 bits of the first in link descriptor's
 * address.
 */

#define UHCI_INLINK_ADDR    0x000FFFFF
#define UHCI_INLINK_ADDR_M  (UHCI_INLINK_ADDR_V << UHCI_INLINK_ADDR_S)
#define UHCI_INLINK_ADDR_V  0x000FFFFF
#define UHCI_INLINK_ADDR_S  0

/* UHCI_CONF1_REG register */

#define UHCI_CONF1_REG(i) (REG_UHCI_BASE(i) + 0x2c)

/* UHCI_DMA_INFIFO_FULL_THRS : RW; bitpos: [20:9]; default: 0;
 * when data amount in link descriptor's fifo is more than this register
 * value  it will produce uhci_dma_infifo_full_wm_int interrupt.
 */

#define UHCI_DMA_INFIFO_FULL_THRS    0x00000FFF
#define UHCI_DMA_INFIFO_FULL_THRS_M  (UHCI_DMA_INFIFO_FULL_THRS_V << UHCI_DMA_INFIFO_FULL_THRS_S)
#define UHCI_DMA_INFIFO_FULL_THRS_V  0x00000FFF
#define UHCI_DMA_INFIFO_FULL_THRS_S  9

/* UHCI_SW_START : RW; bitpos: [8]; default: 0;
 * Set this bit to start inserting the packet header.
 */

#define UHCI_SW_START    (BIT(8))
#define UHCI_SW_START_M  (UHCI_SW_START_V << UHCI_SW_START_S)
#define UHCI_SW_START_V  0x00000001
#define UHCI_SW_START_S  8

/* UHCI_WAIT_SW_START : RW; bitpos: [7]; default: 0;
 * Set this bit to enable software way to add packet header.
 */

#define UHCI_WAIT_SW_START    (BIT(7))
#define UHCI_WAIT_SW_START_M  (UHCI_WAIT_SW_START_V << UHCI_WAIT_SW_START_S)
#define UHCI_WAIT_SW_START_V  0x00000001
#define UHCI_WAIT_SW_START_S  7

/* UHCI_CHECK_OWNER : RW; bitpos: [6]; default: 0;
 * Set this bit to check the owner bit in link descriptor.
 */

#define UHCI_CHECK_OWNER    (BIT(6))
#define UHCI_CHECK_OWNER_M  (UHCI_CHECK_OWNER_V << UHCI_CHECK_OWNER_S)
#define UHCI_CHECK_OWNER_V  0x00000001
#define UHCI_CHECK_OWNER_S  6

/* UHCI_TX_ACK_NUM_RE : RW; bitpos: [5]; default: 1;
 * Set this bit to enable hardware replace ack num in packet header
 * automatically.
 */

#define UHCI_TX_ACK_NUM_RE    (BIT(5))
#define UHCI_TX_ACK_NUM_RE_M  (UHCI_TX_ACK_NUM_RE_V << UHCI_TX_ACK_NUM_RE_S)
#define UHCI_TX_ACK_NUM_RE_V  0x00000001
#define UHCI_TX_ACK_NUM_RE_S  5

/* UHCI_TX_CHECK_SUM_RE : RW; bitpos: [4]; default: 1;
 * Set this bit to enable hardware replace check_sum in packet header
 * automatically.
 */

#define UHCI_TX_CHECK_SUM_RE    (BIT(4))
#define UHCI_TX_CHECK_SUM_RE_M  (UHCI_TX_CHECK_SUM_RE_V << UHCI_TX_CHECK_SUM_RE_S)
#define UHCI_TX_CHECK_SUM_RE_V  0x00000001
#define UHCI_TX_CHECK_SUM_RE_S  4

/* UHCI_SAVE_HEAD : RW; bitpos: [3]; default: 0;
 * Set this bit to save packet header .
 */

#define UHCI_SAVE_HEAD    (BIT(3))
#define UHCI_SAVE_HEAD_M  (UHCI_SAVE_HEAD_V << UHCI_SAVE_HEAD_S)
#define UHCI_SAVE_HEAD_V  0x00000001
#define UHCI_SAVE_HEAD_S  3

/* UHCI_CRC_DISABLE : RW; bitpos: [2]; default: 0;
 * Set this bit to disable crc calculation.
 */

#define UHCI_CRC_DISABLE    (BIT(2))
#define UHCI_CRC_DISABLE_M  (UHCI_CRC_DISABLE_V << UHCI_CRC_DISABLE_S)
#define UHCI_CRC_DISABLE_V  0x00000001
#define UHCI_CRC_DISABLE_S  2

/* UHCI_CHECK_SEQ_EN : RW; bitpos: [1]; default: 1;
 * Set this bit to enable decoder to check seq num in packet header.
 */

#define UHCI_CHECK_SEQ_EN    (BIT(1))
#define UHCI_CHECK_SEQ_EN_M  (UHCI_CHECK_SEQ_EN_V << UHCI_CHECK_SEQ_EN_S)
#define UHCI_CHECK_SEQ_EN_V  0x00000001
#define UHCI_CHECK_SEQ_EN_S  1

/* UHCI_CHECK_SUM_EN : RW; bitpos: [0]; default: 1;
 * Set this bit to enable decoder to check  check_sum in packet header.
 */

#define UHCI_CHECK_SUM_EN    (BIT(0))
#define UHCI_CHECK_SUM_EN_M  (UHCI_CHECK_SUM_EN_V << UHCI_CHECK_SUM_EN_S)
#define UHCI_CHECK_SUM_EN_V  0x00000001
#define UHCI_CHECK_SUM_EN_S  0

/* UHCI_STATE0_REG register */

#define UHCI_STATE0_REG(i) (REG_UHCI_BASE(i) + 0x30)

/* UHCI_STATE0 : R; bitpos: [31:0]; default: 0; */

#define UHCI_STATE0    0xFFFFFFFF
#define UHCI_STATE0_M  (UHCI_STATE0_V << UHCI_STATE0_S)
#define UHCI_STATE0_V  0xFFFFFFFF
#define UHCI_STATE0_S  0

/* UHCI_STATE1_REG register */

#define UHCI_STATE1_REG(i) (REG_UHCI_BASE(i) + 0x34)

/* UHCI_STATE1 : R; bitpos: [31:0]; default: 0; */

#define UHCI_STATE1    0xFFFFFFFF
#define UHCI_STATE1_M  (UHCI_STATE1_V << UHCI_STATE1_S)
#define UHCI_STATE1_V  0xFFFFFFFF
#define UHCI_STATE1_S  0

/* UHCI_DMA_OUT_EOF_DES_ADDR_REG register */

#define UHCI_DMA_OUT_EOF_DES_ADDR_REG(i) (REG_UHCI_BASE(i) + 0x38)

/* UHCI_OUT_EOF_DES_ADDR : R; bitpos: [31:0]; default: 0;
 * This register stores the address of out link descriptoir when eof bit in
 * this descriptor is 1.
 */

#define UHCI_OUT_EOF_DES_ADDR    0xFFFFFFFF
#define UHCI_OUT_EOF_DES_ADDR_M  (UHCI_OUT_EOF_DES_ADDR_V << UHCI_OUT_EOF_DES_ADDR_S)
#define UHCI_OUT_EOF_DES_ADDR_V  0xFFFFFFFF
#define UHCI_OUT_EOF_DES_ADDR_S  0

/* UHCI_DMA_IN_SUC_EOF_DES_ADDR_REG register */

#define UHCI_DMA_IN_SUC_EOF_DES_ADDR_REG(i) (REG_UHCI_BASE(i) + 0x3c)

/* UHCI_IN_SUC_EOF_DES_ADDR : R; bitpos: [31:0]; default: 0;
 * This register stores the address of in link descriptor when eof bit in
 * this descriptor is 1.
 */

#define UHCI_IN_SUC_EOF_DES_ADDR    0xFFFFFFFF
#define UHCI_IN_SUC_EOF_DES_ADDR_M  (UHCI_IN_SUC_EOF_DES_ADDR_V << UHCI_IN_SUC_EOF_DES_ADDR_S)
#define UHCI_IN_SUC_EOF_DES_ADDR_V  0xFFFFFFFF
#define UHCI_IN_SUC_EOF_DES_ADDR_S  0

/* UHCI_DMA_IN_ERR_EOF_DES_ADDR_REG register */

#define UHCI_DMA_IN_ERR_EOF_DES_ADDR_REG(i) (REG_UHCI_BASE(i) + 0x40)

/* UHCI_IN_ERR_EOF_DES_ADDR : R; bitpos: [31:0]; default: 0;
 * This register stores the address of in link descriptor when there are
 * some errors in this descriptor.
 */

#define UHCI_IN_ERR_EOF_DES_ADDR    0xFFFFFFFF
#define UHCI_IN_ERR_EOF_DES_ADDR_M  (UHCI_IN_ERR_EOF_DES_ADDR_V << UHCI_IN_ERR_EOF_DES_ADDR_S)
#define UHCI_IN_ERR_EOF_DES_ADDR_V  0xFFFFFFFF
#define UHCI_IN_ERR_EOF_DES_ADDR_S  0

/* UHCI_DMA_OUT_EOF_BFR_DES_ADDR_REG register */

#define UHCI_DMA_OUT_EOF_BFR_DES_ADDR_REG(i) (REG_UHCI_BASE(i) + 0x44)

/* UHCI_OUT_EOF_BFR_DES_ADDR : R; bitpos: [31:0]; default: 0;
 * This register stores the address of out link descriptor when there are
 * some errors in this descriptor.
 */

#define UHCI_OUT_EOF_BFR_DES_ADDR    0xFFFFFFFF
#define UHCI_OUT_EOF_BFR_DES_ADDR_M  (UHCI_OUT_EOF_BFR_DES_ADDR_V << UHCI_OUT_EOF_BFR_DES_ADDR_S)
#define UHCI_OUT_EOF_BFR_DES_ADDR_V  0xFFFFFFFF
#define UHCI_OUT_EOF_BFR_DES_ADDR_S  0

/* UHCI_AHB_TEST_REG register */

#define UHCI_AHB_TEST_REG(i) (REG_UHCI_BASE(i) + 0x48)

/* UHCI_AHB_TESTADDR : RW; bitpos: [5:4]; default: 0;
 * The two bits represent ahb bus address bit[20:19]
 */

#define UHCI_AHB_TESTADDR    0x00000003
#define UHCI_AHB_TESTADDR_M  (UHCI_AHB_TESTADDR_V << UHCI_AHB_TESTADDR_S)
#define UHCI_AHB_TESTADDR_V  0x00000003
#define UHCI_AHB_TESTADDR_S  4

/* UHCI_AHB_TESTMODE : RW; bitpos: [2:0]; default: 0;
 * bit2 is ahb bus test enable ,bit1 is used to choose write(1) or read(0)
 * mode. bit0 is used to choose test only once(1) or continue(0)
 */

#define UHCI_AHB_TESTMODE    0x00000007
#define UHCI_AHB_TESTMODE_M  (UHCI_AHB_TESTMODE_V << UHCI_AHB_TESTMODE_S)
#define UHCI_AHB_TESTMODE_V  0x00000007
#define UHCI_AHB_TESTMODE_S  0

/* UHCI_DMA_IN_DSCR_REG register */

#define UHCI_DMA_IN_DSCR_REG(i) (REG_UHCI_BASE(i) + 0x4c)

/* UHCI_INLINK_DSCR : R; bitpos: [31:0]; default: 0;
 * The content of current in link descriptor's third dword
 */

#define UHCI_INLINK_DSCR    0xFFFFFFFF
#define UHCI_INLINK_DSCR_M  (UHCI_INLINK_DSCR_V << UHCI_INLINK_DSCR_S)
#define UHCI_INLINK_DSCR_V  0xFFFFFFFF
#define UHCI_INLINK_DSCR_S  0

/* UHCI_DMA_IN_DSCR_BF0_REG register */

#define UHCI_DMA_IN_DSCR_BF0_REG(i) (REG_UHCI_BASE(i) + 0x50)

/* UHCI_INLINK_DSCR_BF0 : R; bitpos: [31:0]; default: 0;
 * The content of current in link descriptor's first dword
 */

#define UHCI_INLINK_DSCR_BF0    0xFFFFFFFF
#define UHCI_INLINK_DSCR_BF0_M  (UHCI_INLINK_DSCR_BF0_V << UHCI_INLINK_DSCR_BF0_S)
#define UHCI_INLINK_DSCR_BF0_V  0xFFFFFFFF
#define UHCI_INLINK_DSCR_BF0_S  0

/* UHCI_DMA_IN_DSCR_BF1_REG register */

#define UHCI_DMA_IN_DSCR_BF1_REG(i) (REG_UHCI_BASE(i) + 0x54)

/* UHCI_INLINK_DSCR_BF1 : R; bitpos: [31:0]; default: 0;
 * The content of current in link descriptor's second dword
 */

#define UHCI_INLINK_DSCR_BF1    0xFFFFFFFF
#define UHCI_INLINK_DSCR_BF1_M  (UHCI_INLINK_DSCR_BF1_V << UHCI_INLINK_DSCR_BF1_S)
#define UHCI_INLINK_DSCR_BF1_V  0xFFFFFFFF
#define UHCI_INLINK_DSCR_BF1_S  0

/* UHCI_DMA_OUT_DSCR_REG register */

#define UHCI_DMA_OUT_DSCR_REG(i) (REG_UHCI_BASE(i) + 0x58)

/* UHCI_OUTLINK_DSCR : R; bitpos: [31:0]; default: 0;
 * The content of current out link descriptor's third dword
 */

#define UHCI_OUTLINK_DSCR    0xFFFFFFFF
#define UHCI_OUTLINK_DSCR_M  (UHCI_OUTLINK_DSCR_V << UHCI_OUTLINK_DSCR_S)
#define UHCI_OUTLINK_DSCR_V  0xFFFFFFFF
#define UHCI_OUTLINK_DSCR_S  0

/* UHCI_DMA_OUT_DSCR_BF0_REG register */

#define UHCI_DMA_OUT_DSCR_BF0_REG(i) (REG_UHCI_BASE(i) + 0x5c)

/* UHCI_OUTLINK_DSCR_BF0 : R; bitpos: [31:0]; default: 0;
 * The content of current out link descriptor's first dword
 */

#define UHCI_OUTLINK_DSCR_BF0    0xFFFFFFFF
#define UHCI_OUTLINK_DSCR_BF0_M  (UHCI_OUTLINK_DSCR_BF0_V << UHCI_OUTLINK_DSCR_BF0_S)
#define UHCI_OUTLINK_DSCR_BF0_V  0xFFFFFFFF
#define UHCI_OUTLINK_DSCR_BF0_S  0

/* UHCI_DMA_OUT_DSCR_BF1_REG register */

#define UHCI_DMA_OUT_DSCR_BF1_REG(i) (REG_UHCI_BASE(i) + 0x60)

/* UHCI_OUTLINK_DSCR_BF1 : R; bitpos: [31:0]; default: 0;
 * The content of current out link descriptor's second dword
 */

#define UHCI_OUTLINK_DSCR_BF1    0xFFFFFFFF
#define UHCI_OUTLINK_DSCR_BF1_M  (UHCI_OUTLINK_DSCR_BF1_V << UHCI_OUTLINK_DSCR_BF1_S)
#define UHCI_OUTLINK_DSCR_BF1_V  0xFFFFFFFF
#define UHCI_OUTLINK_DSCR_BF1_S  0

/* UHCI_ESCAPE_CONF_REG register */

#define UHCI_ESCAPE_CONF_REG(i) (REG_UHCI_BASE(i) + 0x64)

/* UHCI_RX_13_ESC_EN : RW; bitpos: [7]; default: 0;
 * Set this bit to enable  flow control char 0x13 replace when DMA sends
 * data.
 */

#define UHCI_RX_13_ESC_EN    (BIT(7))
#define UHCI_RX_13_ESC_EN_M  (UHCI_RX_13_ESC_EN_V << UHCI_RX_13_ESC_EN_S)
#define UHCI_RX_13_ESC_EN_V  0x00000001
#define UHCI_RX_13_ESC_EN_S  7

/* UHCI_RX_11_ESC_EN : RW; bitpos: [6]; default: 0;
 * Set this bit to enable  flow control char 0x11 replace when DMA sends
 * data.
 */

#define UHCI_RX_11_ESC_EN    (BIT(6))
#define UHCI_RX_11_ESC_EN_M  (UHCI_RX_11_ESC_EN_V << UHCI_RX_11_ESC_EN_S)
#define UHCI_RX_11_ESC_EN_V  0x00000001
#define UHCI_RX_11_ESC_EN_S  6

/* UHCI_RX_DB_ESC_EN : RW; bitpos: [5]; default: 1;
 * Set this bit to enable  0xdb char replace when DMA sends data.
 */

#define UHCI_RX_DB_ESC_EN    (BIT(5))
#define UHCI_RX_DB_ESC_EN_M  (UHCI_RX_DB_ESC_EN_V << UHCI_RX_DB_ESC_EN_S)
#define UHCI_RX_DB_ESC_EN_V  0x00000001
#define UHCI_RX_DB_ESC_EN_S  5

/* UHCI_RX_C0_ESC_EN : RW; bitpos: [4]; default: 1;
 * Set this bit to enable  0xc0 char replace when DMA sends data.
 */

#define UHCI_RX_C0_ESC_EN    (BIT(4))
#define UHCI_RX_C0_ESC_EN_M  (UHCI_RX_C0_ESC_EN_V << UHCI_RX_C0_ESC_EN_S)
#define UHCI_RX_C0_ESC_EN_V  0x00000001
#define UHCI_RX_C0_ESC_EN_S  4

/* UHCI_TX_13_ESC_EN : RW; bitpos: [3]; default: 0;
 * Set this bit to enable flow control char 0x13 decode when DMA receives
 * data.
 */

#define UHCI_TX_13_ESC_EN    (BIT(3))
#define UHCI_TX_13_ESC_EN_M  (UHCI_TX_13_ESC_EN_V << UHCI_TX_13_ESC_EN_S)
#define UHCI_TX_13_ESC_EN_V  0x00000001
#define UHCI_TX_13_ESC_EN_S  3

/* UHCI_TX_11_ESC_EN : RW; bitpos: [2]; default: 0;
 * Set this bit to enable  flow control char 0x11 decode when DMA receives
 * data.
 */

#define UHCI_TX_11_ESC_EN    (BIT(2))
#define UHCI_TX_11_ESC_EN_M  (UHCI_TX_11_ESC_EN_V << UHCI_TX_11_ESC_EN_S)
#define UHCI_TX_11_ESC_EN_V  0x00000001
#define UHCI_TX_11_ESC_EN_S  2

/* UHCI_TX_DB_ESC_EN : RW; bitpos: [1]; default: 1;
 * Set this bit to enable  0xdb char decode when DMA receives data.
 */

#define UHCI_TX_DB_ESC_EN    (BIT(1))
#define UHCI_TX_DB_ESC_EN_M  (UHCI_TX_DB_ESC_EN_V << UHCI_TX_DB_ESC_EN_S)
#define UHCI_TX_DB_ESC_EN_V  0x00000001
#define UHCI_TX_DB_ESC_EN_S  1

/* UHCI_TX_C0_ESC_EN : RW; bitpos: [0]; default: 1;
 * Set this bit to enable  0xc0 char decode when DMA receives data.
 */

#define UHCI_TX_C0_ESC_EN    (BIT(0))
#define UHCI_TX_C0_ESC_EN_M  (UHCI_TX_C0_ESC_EN_V << UHCI_TX_C0_ESC_EN_S)
#define UHCI_TX_C0_ESC_EN_V  0x00000001
#define UHCI_TX_C0_ESC_EN_S  0

/* UHCI_HUNG_CONF_REG register */

#define UHCI_HUNG_CONF_REG(i) (REG_UHCI_BASE(i) + 0x68)

/* UHCI_RXFIFO_TIMEOUT_ENA : RW; bitpos: [23]; default: 1;
 * This is the enable bit for DMA  send data timeout
 */

#define UHCI_RXFIFO_TIMEOUT_ENA    (BIT(23))
#define UHCI_RXFIFO_TIMEOUT_ENA_M  (UHCI_RXFIFO_TIMEOUT_ENA_V << UHCI_RXFIFO_TIMEOUT_ENA_S)
#define UHCI_RXFIFO_TIMEOUT_ENA_V  0x00000001
#define UHCI_RXFIFO_TIMEOUT_ENA_S  23

/* UHCI_RXFIFO_TIMEOUT_SHIFT : RW; bitpos: [22:20]; default: 0;
 * The tick count is cleared when its value
 * >=(17'd8000>>reg_rxfifo_timeout_shift)
 */

#define UHCI_RXFIFO_TIMEOUT_SHIFT    0x00000007
#define UHCI_RXFIFO_TIMEOUT_SHIFT_M  (UHCI_RXFIFO_TIMEOUT_SHIFT_V << UHCI_RXFIFO_TIMEOUT_SHIFT_S)
#define UHCI_RXFIFO_TIMEOUT_SHIFT_V  0x00000007
#define UHCI_RXFIFO_TIMEOUT_SHIFT_S  20

/* UHCI_RXFIFO_TIMEOUT : RW; bitpos: [19:12]; default: 16;
 * This register stores the timeout value.when DMA takes more time than this
 * register value to read a data from RAM  it will produce  uhci_rx_hung_int
 * interrupt.
 */

#define UHCI_RXFIFO_TIMEOUT    0x000000FF
#define UHCI_RXFIFO_TIMEOUT_M  (UHCI_RXFIFO_TIMEOUT_V << UHCI_RXFIFO_TIMEOUT_S)
#define UHCI_RXFIFO_TIMEOUT_V  0x000000FF
#define UHCI_RXFIFO_TIMEOUT_S  12

/* UHCI_TXFIFO_TIMEOUT_ENA : RW; bitpos: [11]; default: 1;
 * The enable bit for txfifo receive data  timeout
 */

#define UHCI_TXFIFO_TIMEOUT_ENA    (BIT(11))
#define UHCI_TXFIFO_TIMEOUT_ENA_M  (UHCI_TXFIFO_TIMEOUT_ENA_V << UHCI_TXFIFO_TIMEOUT_ENA_S)
#define UHCI_TXFIFO_TIMEOUT_ENA_V  0x00000001
#define UHCI_TXFIFO_TIMEOUT_ENA_S  11

/* UHCI_TXFIFO_TIMEOUT_SHIFT : RW; bitpos: [10:8]; default: 0;
 * The tick count is cleared when its value
 * >=(17'd8000>>reg_txfifo_timeout_shift)
 */

#define UHCI_TXFIFO_TIMEOUT_SHIFT    0x00000007
#define UHCI_TXFIFO_TIMEOUT_SHIFT_M  (UHCI_TXFIFO_TIMEOUT_SHIFT_V << UHCI_TXFIFO_TIMEOUT_SHIFT_S)
#define UHCI_TXFIFO_TIMEOUT_SHIFT_V  0x00000007
#define UHCI_TXFIFO_TIMEOUT_SHIFT_S  8

/* UHCI_TXFIFO_TIMEOUT : RW; bitpos: [7:0]; default: 16;
 * This register stores the timeout value.when DMA takes more time than this
 * register value to receive a data  it will produce  uhci_tx_hung_int
 * interrupt.
 */

#define UHCI_TXFIFO_TIMEOUT    0x000000FF
#define UHCI_TXFIFO_TIMEOUT_M  (UHCI_TXFIFO_TIMEOUT_V << UHCI_TXFIFO_TIMEOUT_S)
#define UHCI_TXFIFO_TIMEOUT_V  0x000000FF
#define UHCI_TXFIFO_TIMEOUT_S  0

/* UHCI_ACK_NUM_REG register */

#define UHCI_ACK_NUM_REG(i) (REG_UHCI_BASE(i) + 0x6c)

/* UHCI_RX_HEAD_REG register */

#define UHCI_RX_HEAD_REG(i) (REG_UHCI_BASE(i) + 0x70)

/* UHCI_RX_HEAD : R; bitpos: [31:0]; default: 0;
 * This register stores the packet header received by DMA
 */

#define UHCI_RX_HEAD    0xFFFFFFFF
#define UHCI_RX_HEAD_M  (UHCI_RX_HEAD_V << UHCI_RX_HEAD_S)
#define UHCI_RX_HEAD_V  0xFFFFFFFF
#define UHCI_RX_HEAD_S  0

/* UHCI_QUICK_SENT_REG register */

#define UHCI_QUICK_SENT_REG(i) (REG_UHCI_BASE(i) + 0x74)

/* UHCI_ALWAYS_SEND_EN : RW; bitpos: [7]; default: 0;
 * Set this bit to enable continuously send the same short packet
 */

#define UHCI_ALWAYS_SEND_EN    (BIT(7))
#define UHCI_ALWAYS_SEND_EN_M  (UHCI_ALWAYS_SEND_EN_V << UHCI_ALWAYS_SEND_EN_S)
#define UHCI_ALWAYS_SEND_EN_V  0x00000001
#define UHCI_ALWAYS_SEND_EN_S  7

/* UHCI_ALWAYS_SEND_NUM : RW; bitpos: [6:4]; default: 0;
 * The bits are used to choose which short packet
 */

#define UHCI_ALWAYS_SEND_NUM    0x00000007
#define UHCI_ALWAYS_SEND_NUM_M  (UHCI_ALWAYS_SEND_NUM_V << UHCI_ALWAYS_SEND_NUM_S)
#define UHCI_ALWAYS_SEND_NUM_V  0x00000007
#define UHCI_ALWAYS_SEND_NUM_S  4

/* UHCI_SINGLE_SEND_EN : RW; bitpos: [3]; default: 0;
 * Set this bit to enable  send a short packet
 */

#define UHCI_SINGLE_SEND_EN    (BIT(3))
#define UHCI_SINGLE_SEND_EN_M  (UHCI_SINGLE_SEND_EN_V << UHCI_SINGLE_SEND_EN_S)
#define UHCI_SINGLE_SEND_EN_V  0x00000001
#define UHCI_SINGLE_SEND_EN_S  3

/* UHCI_SINGLE_SEND_NUM : RW; bitpos: [2:0]; default: 0;
 * The bits are used to choose which short packet
 */

#define UHCI_SINGLE_SEND_NUM    0x00000007
#define UHCI_SINGLE_SEND_NUM_M  (UHCI_SINGLE_SEND_NUM_V << UHCI_SINGLE_SEND_NUM_S)
#define UHCI_SINGLE_SEND_NUM_V  0x00000007
#define UHCI_SINGLE_SEND_NUM_S  0

/* UHCI_Q0_WORD0_REG register */

#define UHCI_Q0_WORD0_REG(i) (REG_UHCI_BASE(i) + 0x78)

/* UHCI_SEND_Q0_WORD0 : RW; bitpos: [31:0]; default: 0;
 * This register stores the content of short packet's first dword
 */

#define UHCI_SEND_Q0_WORD0    0xFFFFFFFF
#define UHCI_SEND_Q0_WORD0_M  (UHCI_SEND_Q0_WORD0_V << UHCI_SEND_Q0_WORD0_S)
#define UHCI_SEND_Q0_WORD0_V  0xFFFFFFFF
#define UHCI_SEND_Q0_WORD0_S  0

/* UHCI_Q0_WORD1_REG register */

#define UHCI_Q0_WORD1_REG(i) (REG_UHCI_BASE(i) + 0x7c)

/* UHCI_SEND_Q0_WORD1 : RW; bitpos: [31:0]; default: 0;
 * This register stores the content of short packet's second dword
 */

#define UHCI_SEND_Q0_WORD1    0xFFFFFFFF
#define UHCI_SEND_Q0_WORD1_M  (UHCI_SEND_Q0_WORD1_V << UHCI_SEND_Q0_WORD1_S)
#define UHCI_SEND_Q0_WORD1_V  0xFFFFFFFF
#define UHCI_SEND_Q0_WORD1_S  0

/* UHCI_Q1_WORD0_REG register */

#define UHCI_Q1_WORD0_REG(i) (REG_UHCI_BASE(i) + 0x80)

/* UHCI_SEND_Q1_WORD0 : RW; bitpos: [31:0]; default: 0;
 * This register stores the content of short packet's first dword
 */

#define UHCI_SEND_Q1_WORD0    0xFFFFFFFF
#define UHCI_SEND_Q1_WORD0_M  (UHCI_SEND_Q1_WORD0_V << UHCI_SEND_Q1_WORD0_S)
#define UHCI_SEND_Q1_WORD0_V  0xFFFFFFFF
#define UHCI_SEND_Q1_WORD0_S  0

/* UHCI_Q1_WORD1_REG register */

#define UHCI_Q1_WORD1_REG(i) (REG_UHCI_BASE(i) + 0x84)

/* UHCI_SEND_Q1_WORD1 : RW; bitpos: [31:0]; default: 0;
 * This register stores the content of short packet's second dword
 */

#define UHCI_SEND_Q1_WORD1    0xFFFFFFFF
#define UHCI_SEND_Q1_WORD1_M  (UHCI_SEND_Q1_WORD1_V << UHCI_SEND_Q1_WORD1_S)
#define UHCI_SEND_Q1_WORD1_V  0xFFFFFFFF
#define UHCI_SEND_Q1_WORD1_S  0

/* UHCI_Q2_WORD0_REG register */

#define UHCI_Q2_WORD0_REG(i) (REG_UHCI_BASE(i) + 0x88)

/* UHCI_SEND_Q2_WORD0 : RW; bitpos: [31:0]; default: 0;
 * This register stores the content of short packet's first dword
 */

#define UHCI_SEND_Q2_WORD0    0xFFFFFFFF
#define UHCI_SEND_Q2_WORD0_M  (UHCI_SEND_Q2_WORD0_V << UHCI_SEND_Q2_WORD0_S)
#define UHCI_SEND_Q2_WORD0_V  0xFFFFFFFF
#define UHCI_SEND_Q2_WORD0_S  0

/* UHCI_Q2_WORD1_REG register */

#define UHCI_Q2_WORD1_REG(i) (REG_UHCI_BASE(i) + 0x8c)

/* UHCI_SEND_Q2_WORD1 : RW; bitpos: [31:0]; default: 0;
 * This register stores the content of short packet's second dword
 */

#define UHCI_SEND_Q2_WORD1    0xFFFFFFFF
#define UHCI_SEND_Q2_WORD1_M  (UHCI_SEND_Q2_WORD1_V << UHCI_SEND_Q2_WORD1_S)
#define UHCI_SEND_Q2_WORD1_V  0xFFFFFFFF
#define UHCI_SEND_Q2_WORD1_S  0

/* UHCI_Q3_WORD0_REG register */

#define UHCI_Q3_WORD0_REG(i) (REG_UHCI_BASE(i) + 0x90)

/* UHCI_SEND_Q3_WORD0 : RW; bitpos: [31:0]; default: 0;
 * This register stores the content of short packet's first dword
 */

#define UHCI_SEND_Q3_WORD0    0xFFFFFFFF
#define UHCI_SEND_Q3_WORD0_M  (UHCI_SEND_Q3_WORD0_V << UHCI_SEND_Q3_WORD0_S)
#define UHCI_SEND_Q3_WORD0_V  0xFFFFFFFF
#define UHCI_SEND_Q3_WORD0_S  0

/* UHCI_Q3_WORD1_REG register */

#define UHCI_Q3_WORD1_REG(i) (REG_UHCI_BASE(i) + 0x94)

/* UHCI_SEND_Q3_WORD1 : RW; bitpos: [31:0]; default: 0;
 * This register stores the content of short packet's second dword
 */

#define UHCI_SEND_Q3_WORD1    0xFFFFFFFF
#define UHCI_SEND_Q3_WORD1_M  (UHCI_SEND_Q3_WORD1_V << UHCI_SEND_Q3_WORD1_S)
#define UHCI_SEND_Q3_WORD1_V  0xFFFFFFFF
#define UHCI_SEND_Q3_WORD1_S  0

/* UHCI_Q4_WORD0_REG register */

#define UHCI_Q4_WORD0_REG(i) (REG_UHCI_BASE(i) + 0x98)

/* UHCI_SEND_Q4_WORD0 : RW; bitpos: [31:0]; default: 0;
 * This register stores the content of short packet's first dword
 */

#define UHCI_SEND_Q4_WORD0    0xFFFFFFFF
#define UHCI_SEND_Q4_WORD0_M  (UHCI_SEND_Q4_WORD0_V << UHCI_SEND_Q4_WORD0_S)
#define UHCI_SEND_Q4_WORD0_V  0xFFFFFFFF
#define UHCI_SEND_Q4_WORD0_S  0

/* UHCI_Q4_WORD1_REG register */

#define UHCI_Q4_WORD1_REG(i) (REG_UHCI_BASE(i) + 0x9c)

/* UHCI_SEND_Q4_WORD1 : RW; bitpos: [31:0]; default: 0;
 * This register stores the content of short packet's second dword
 */

#define UHCI_SEND_Q4_WORD1    0xFFFFFFFF
#define UHCI_SEND_Q4_WORD1_M  (UHCI_SEND_Q4_WORD1_V << UHCI_SEND_Q4_WORD1_S)
#define UHCI_SEND_Q4_WORD1_V  0xFFFFFFFF
#define UHCI_SEND_Q4_WORD1_S  0

/* UHCI_Q5_WORD0_REG register */

#define UHCI_Q5_WORD0_REG(i) (REG_UHCI_BASE(i) + 0xa0)

/* UHCI_SEND_Q5_WORD0 : RW; bitpos: [31:0]; default: 0;
 * This register stores the content of short packet's first dword
 */

#define UHCI_SEND_Q5_WORD0    0xFFFFFFFF
#define UHCI_SEND_Q5_WORD0_M  (UHCI_SEND_Q5_WORD0_V << UHCI_SEND_Q5_WORD0_S)
#define UHCI_SEND_Q5_WORD0_V  0xFFFFFFFF
#define UHCI_SEND_Q5_WORD0_S  0

/* UHCI_Q5_WORD1_REG register */

#define UHCI_Q5_WORD1_REG(i) (REG_UHCI_BASE(i) + 0xa4)

/* UHCI_SEND_Q5_WORD1 : RW; bitpos: [31:0]; default: 0;
 * This register stores the content of short packet's second dword
 */

#define UHCI_SEND_Q5_WORD1    0xFFFFFFFF
#define UHCI_SEND_Q5_WORD1_M  (UHCI_SEND_Q5_WORD1_V << UHCI_SEND_Q5_WORD1_S)
#define UHCI_SEND_Q5_WORD1_V  0xFFFFFFFF
#define UHCI_SEND_Q5_WORD1_S  0

/* UHCI_Q6_WORD0_REG register */

#define UHCI_Q6_WORD0_REG(i) (REG_UHCI_BASE(i) + 0xa8)

/* UHCI_SEND_Q6_WORD0 : RW; bitpos: [31:0]; default: 0;
 * This register stores the content of short packet's first dword
 */

#define UHCI_SEND_Q6_WORD0    0xFFFFFFFF
#define UHCI_SEND_Q6_WORD0_M  (UHCI_SEND_Q6_WORD0_V << UHCI_SEND_Q6_WORD0_S)
#define UHCI_SEND_Q6_WORD0_V  0xFFFFFFFF
#define UHCI_SEND_Q6_WORD0_S  0

/* UHCI_Q6_WORD1_REG register */

#define UHCI_Q6_WORD1_REG(i) (REG_UHCI_BASE(i) + 0xac)

/* UHCI_SEND_Q6_WORD1 : RW; bitpos: [31:0]; default: 0;
 * This register stores the content of short packet's second dword
 */

#define UHCI_SEND_Q6_WORD1    0xFFFFFFFF
#define UHCI_SEND_Q6_WORD1_M  (UHCI_SEND_Q6_WORD1_V << UHCI_SEND_Q6_WORD1_S)
#define UHCI_SEND_Q6_WORD1_V  0xFFFFFFFF
#define UHCI_SEND_Q6_WORD1_S  0

/* UHCI_ESC_CONF0_REG register */

#define UHCI_ESC_CONF0_REG(i) (REG_UHCI_BASE(i) + 0xb0)

/* UHCI_SEPER_ESC_CHAR1 : RW; bitpos: [23:16]; default: 220;
 * This register stores the second char used to replace separator char in
 * data . 0xdc 0xdb replace 0xc0 by default.
 */

#define UHCI_SEPER_ESC_CHAR1    0x000000FF
#define UHCI_SEPER_ESC_CHAR1_M  (UHCI_SEPER_ESC_CHAR1_V << UHCI_SEPER_ESC_CHAR1_S)
#define UHCI_SEPER_ESC_CHAR1_V  0x000000FF
#define UHCI_SEPER_ESC_CHAR1_S  16

/* UHCI_SEPER_ESC_CHAR0 : RW; bitpos: [15:8]; default: 219;
 * This register stores thee first char used to replace separator char in
 * data.
 */

#define UHCI_SEPER_ESC_CHAR0    0x000000FF
#define UHCI_SEPER_ESC_CHAR0_M  (UHCI_SEPER_ESC_CHAR0_V << UHCI_SEPER_ESC_CHAR0_S)
#define UHCI_SEPER_ESC_CHAR0_V  0x000000FF
#define UHCI_SEPER_ESC_CHAR0_S  8

/* UHCI_SEPER_CHAR : RW; bitpos: [7:0]; default: 192;
 * This register stores the separator char  separator char is used to
 * separate the data frame.
 */

#define UHCI_SEPER_CHAR    0x000000FF
#define UHCI_SEPER_CHAR_M  (UHCI_SEPER_CHAR_V << UHCI_SEPER_CHAR_S)
#define UHCI_SEPER_CHAR_V  0x000000FF
#define UHCI_SEPER_CHAR_S  0

/* UHCI_ESC_CONF1_REG register */

#define UHCI_ESC_CONF1_REG(i) (REG_UHCI_BASE(i) + 0xb4)

/* UHCI_ESC_SEQ0_CHAR1 : RW; bitpos: [23:16]; default: 221;
 * This register stores the second char used to replace the reg_esc_seq0 in
 * data
 */

#define UHCI_ESC_SEQ0_CHAR1    0x000000FF
#define UHCI_ESC_SEQ0_CHAR1_M  (UHCI_ESC_SEQ0_CHAR1_V << UHCI_ESC_SEQ0_CHAR1_S)
#define UHCI_ESC_SEQ0_CHAR1_V  0x000000FF
#define UHCI_ESC_SEQ0_CHAR1_S  16

/* UHCI_ESC_SEQ0_CHAR0 : RW; bitpos: [15:8]; default: 219;
 * This register stores the first char used to replace reg_esc_seq0 in data.
 */

#define UHCI_ESC_SEQ0_CHAR0    0x000000FF
#define UHCI_ESC_SEQ0_CHAR0_M  (UHCI_ESC_SEQ0_CHAR0_V << UHCI_ESC_SEQ0_CHAR0_S)
#define UHCI_ESC_SEQ0_CHAR0_V  0x000000FF
#define UHCI_ESC_SEQ0_CHAR0_S  8

/* UHCI_ESC_SEQ0 : RW; bitpos: [7:0]; default: 219;
 * This register stores the first substitute char used to replace the
 * separator char.
 */

#define UHCI_ESC_SEQ0    0x000000FF
#define UHCI_ESC_SEQ0_M  (UHCI_ESC_SEQ0_V << UHCI_ESC_SEQ0_S)
#define UHCI_ESC_SEQ0_V  0x000000FF
#define UHCI_ESC_SEQ0_S  0

/* UHCI_ESC_CONF2_REG register */

#define UHCI_ESC_CONF2_REG(i) (REG_UHCI_BASE(i) + 0xb8)

/* UHCI_ESC_SEQ1_CHAR1 : RW; bitpos: [23:16]; default: 222;
 * This register stores the second char used to replace the reg_esc_seq1 in
 * data.
 */

#define UHCI_ESC_SEQ1_CHAR1    0x000000FF
#define UHCI_ESC_SEQ1_CHAR1_M  (UHCI_ESC_SEQ1_CHAR1_V << UHCI_ESC_SEQ1_CHAR1_S)
#define UHCI_ESC_SEQ1_CHAR1_V  0x000000FF
#define UHCI_ESC_SEQ1_CHAR1_S  16

/* UHCI_ESC_SEQ1_CHAR0 : RW; bitpos: [15:8]; default: 219;
 * This register stores the first char used to replace the reg_esc_seq1 in
 * data.
 */

#define UHCI_ESC_SEQ1_CHAR0    0x000000FF
#define UHCI_ESC_SEQ1_CHAR0_M  (UHCI_ESC_SEQ1_CHAR0_V << UHCI_ESC_SEQ1_CHAR0_S)
#define UHCI_ESC_SEQ1_CHAR0_V  0x000000FF
#define UHCI_ESC_SEQ1_CHAR0_S  8

/* UHCI_ESC_SEQ1 : RW; bitpos: [7:0]; default: 17;
 * This register stores the flow control char to turn on the flow_control
 */

#define UHCI_ESC_SEQ1    0x000000FF
#define UHCI_ESC_SEQ1_M  (UHCI_ESC_SEQ1_V << UHCI_ESC_SEQ1_S)
#define UHCI_ESC_SEQ1_V  0x000000FF
#define UHCI_ESC_SEQ1_S  0

/* UHCI_ESC_CONF3_REG register */

#define UHCI_ESC_CONF3_REG(i) (REG_UHCI_BASE(i) + 0xbc)

/* UHCI_ESC_SEQ2_CHAR1 : RW; bitpos: [23:16]; default: 223;
 * This register stores  the second char used to replace the reg_esc_seq2 in
 * data.
 */

#define UHCI_ESC_SEQ2_CHAR1    0x000000FF
#define UHCI_ESC_SEQ2_CHAR1_M  (UHCI_ESC_SEQ2_CHAR1_V << UHCI_ESC_SEQ2_CHAR1_S)
#define UHCI_ESC_SEQ2_CHAR1_V  0x000000FF
#define UHCI_ESC_SEQ2_CHAR1_S  16

/* UHCI_ESC_SEQ2_CHAR0 : RW; bitpos: [15:8]; default: 219;
 * This register stores the first char used to replace the reg_esc_seq2 in
 * data.
 */

#define UHCI_ESC_SEQ2_CHAR0    0x000000FF
#define UHCI_ESC_SEQ2_CHAR0_M  (UHCI_ESC_SEQ2_CHAR0_V << UHCI_ESC_SEQ2_CHAR0_S)
#define UHCI_ESC_SEQ2_CHAR0_V  0x000000FF
#define UHCI_ESC_SEQ2_CHAR0_S  8

/* UHCI_ESC_SEQ2 : RW; bitpos: [7:0]; default: 19;
 * This register stores the flow_control char to turn off the flow_control
 */

#define UHCI_ESC_SEQ2    0x000000FF
#define UHCI_ESC_SEQ2_M  (UHCI_ESC_SEQ2_V << UHCI_ESC_SEQ2_S)
#define UHCI_ESC_SEQ2_V  0x000000FF
#define UHCI_ESC_SEQ2_S  0

/* UHCI_PKT_THRES_REG register */

#define UHCI_PKT_THRES_REG(i) (REG_UHCI_BASE(i) + 0xc0)

/* UHCI_PKT_THRS : RW; bitpos: [12:0]; default: 128;
 * when the amount of packet payload is greater than this value the process
 * of receiving data is done.
 */

#define UHCI_PKT_THRS    0x00001FFF
#define UHCI_PKT_THRS_M  (UHCI_PKT_THRS_V << UHCI_PKT_THRS_S)
#define UHCI_PKT_THRS_V  0x00001FFF
#define UHCI_PKT_THRS_S  0

/* UHCI_DATE_REG register */

#define UHCI_DATE_REG(i) (REG_UHCI_BASE(i) + 0xfc)

/* UHCI_DATE : RW; bitpos: [31:0]; default: 369364993;
 * version information
 */

#define UHCI_DATE    0xFFFFFFFF
#define UHCI_DATE_M  (UHCI_DATE_V << UHCI_DATE_S)
#define UHCI_DATE_V  0xFFFFFFFF
#define UHCI_DATE_S  0

#endif /* __ARCH_XTENSA_SRC_ESP32_HARDWARE_ESP32_UHCI_H */
