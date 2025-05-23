/****************************************************************************
 * include/nuttx/sensors/bme688.h
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

#ifndef __INCLUDE_NUTTX_SENSORS_BME688_H
#define __INCLUDE_NUTTX_SENSORS_BME688_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include <stdint.h>

#if defined(CONFIG_I2C) && defined(CONFIG_SENSORS_BME688)
/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Configuration ************************************************************/

/* Oversampling settings */

#define BME688_OS_SKIPPED    (0x00)   /* Output set to 0x8000 */
#define BME688_OS_1X         (0x01)
#define BME688_OS_2X         (0x02)
#define BME688_OS_4X         (0x03)
#define BME688_OS_8X         (0x04)
#define BME688_OS_16X        (0x05)

/* IIR filter settings */

#define BME688_FILTER_COEF0     (0)
#define BME688_FILTER_COEF1     (1)
#define BME688_FILTER_COEF3     (2)
#define BME688_FILTER_COEF7     (3)
#define BME688_FILTER_COEF15    (4)
#define BME688_FILTER_COEF31    (5)
#define BME688_FILTER_COEF63    (6)
#define BME688_FILTER_COEF127   (7)

/* Prerequisites:
 *
 * CONFIG_BME688
 *   Enables support for the BME688 driver
 */

/****************************************************************************
 * Public Types
 ****************************************************************************/

struct i2c_master_s;

struct bme688_config_s
{
  /* Oversampling settings */

  uint8_t temp_os;

#ifndef CONFIG_BME688_DISABLE_PRESS_MEAS
  uint8_t press_os;
#endif

#ifndef CONFIG_BME688_DISABLE_HUM_MEAS
  uint8_t hum_os;
#endif

#ifdef CONFIG_BME688_ENABLE_IIR_FILTER
  /* Filter coefficient */

  uint8_t filter_coef;
#endif

#ifndef CONFIG_BME688_DISABLE_GAS_MEAS
  /* Gas settings */

  int16_t target_temp;      /* degrees Celsius */
  uint16_t heater_duration; /* ms */
  uint8_t nb_conv;
  int16_t amb_temp;         /* degrees Celsius */
#endif
};

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

#ifdef __cplusplus
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/****************************************************************************
 * Name: bme688_register
 *
 * Description:
 *   Register the BME688 character device
 *
 * Input Parameters:
 *   devno   - Instance number for driver
 *   i2c     - An instance of the I2C interface to use to communicate with
 *             BME688
 *
 * Returned Value:
 *   Zero (OK) on success; a negated errno value on failure.
 *
 ****************************************************************************/

int bme688_register(int devno, FAR struct i2c_master_s *i2c,
                    FAR struct bme688_config_s *config);

#undef EXTERN
#ifdef __cplusplus
}
#endif

#endif /* CONFIG_I2C && CONFIG_SENSORS_BME688 */
#endif /* __INCLUDE_NUTTX_BME688_H */
