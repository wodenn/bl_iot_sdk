/*
 * Copyright (c) 2016-2023 Bouffalolab.
 *
 * This file is part of
 *     *** Bouffalolab Software Dev Kit ***
 *      (see www.bouffalolab.com).
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *   1. Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *   2. Redistributions in binary form must reproduce the above copyright notice,
 *      this list of conditions and the following disclaimer in the documentation
 *      and/or other materials provided with the distribution.
 *   3. Neither the name of Bouffalo Lab nor the names of its contributors
 *      may be used to endorse or promote products derived from this software
 *      without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef __USBD_CORE_H
#define __USBD_CORE_H

#include "bflb_bsp_driver_glue.h"
#include "usb_def.h"
#include "usbd_conf.h"
#include "usbd_def.h"
#include "usbd_ioreq.h"
#include "usbd_ctlreq.h"

#define USBD_SOF                    USBD_LL_SOF

USBD_StatusTypeDef USBD_Init(USBD_HandleTypeDef *pdev, USBD_DescriptorsTypeDef *pdesc, uint8_t id);
USBD_StatusTypeDef USBD_DeInit(USBD_HandleTypeDef *pdev);
USBD_StatusTypeDef USBD_Start(USBD_HandleTypeDef *pdev);
USBD_StatusTypeDef USBD_Stop(USBD_HandleTypeDef *pdev);
USBD_StatusTypeDef USBD_RegisterClass(USBD_HandleTypeDef *pdev, USBD_ClassTypeDef *pclass);

USBD_StatusTypeDef USBD_RunTestMode(USBD_HandleTypeDef  *pdev); 
USBD_StatusTypeDef USBD_SetClassConfig(USBD_HandleTypeDef  *pdev, uint8_t cfgidx);
USBD_StatusTypeDef USBD_ClrClassConfig(USBD_HandleTypeDef  *pdev, uint8_t cfgidx);

USBD_StatusTypeDef USBD_LL_SetupStage(USBD_HandleTypeDef *pdev, uint8_t *psetup);
USBD_StatusTypeDef USBD_LL_DataOutStage(USBD_HandleTypeDef *pdev , uint8_t epnum, uint8_t *pdata);
USBD_StatusTypeDef USBD_LL_DataInStage(USBD_HandleTypeDef *pdev , uint8_t epnum, uint8_t *pdata);

USBD_StatusTypeDef USBD_LL_Reset(USBD_HandleTypeDef  *pdev);
USBD_StatusTypeDef USBD_LL_SetSpeed(USBD_HandleTypeDef  *pdev, USBD_SpeedTypeDef speed);
USBD_StatusTypeDef USBD_LL_Suspend(USBD_HandleTypeDef  *pdev);
USBD_StatusTypeDef USBD_LL_Resume(USBD_HandleTypeDef  *pdev);

USBD_StatusTypeDef USBD_LL_SOF(USBD_HandleTypeDef  *pdev);
USBD_StatusTypeDef USBD_LL_IsoINIncomplete(USBD_HandleTypeDef  *pdev, uint8_t epnum);
USBD_StatusTypeDef USBD_LL_IsoOUTIncomplete(USBD_HandleTypeDef  *pdev, uint8_t epnum);

USBD_StatusTypeDef USBD_LL_DevConnected(USBD_HandleTypeDef  *pdev);
USBD_StatusTypeDef USBD_LL_DevDisconnected(USBD_HandleTypeDef  *pdev);

/* USBD Low Level Driver */
USBD_StatusTypeDef USBD_LL_Init (USBD_HandleTypeDef *pdev);
USBD_StatusTypeDef USBD_LL_DeInit (USBD_HandleTypeDef *pdev);
USBD_StatusTypeDef USBD_LL_Start(USBD_HandleTypeDef *pdev);
USBD_StatusTypeDef USBD_LL_Stop (USBD_HandleTypeDef *pdev);
USBD_StatusTypeDef USBD_LL_OpenEP  (USBD_HandleTypeDef *pdev, uint8_t  ep_addr, uint8_t  ep_type, uint16_t ep_mps);

USBD_StatusTypeDef USBD_LL_CloseEP (USBD_HandleTypeDef *pdev, uint8_t ep_addr);   
USBD_StatusTypeDef USBD_LL_FlushEP (USBD_HandleTypeDef *pdev, uint8_t ep_addr);   
USBD_StatusTypeDef USBD_LL_StallEP (USBD_HandleTypeDef *pdev, uint8_t ep_addr);   
USBD_StatusTypeDef USBD_LL_ClearStallEP (USBD_HandleTypeDef *pdev, uint8_t ep_addr);   
uint8_t            USBD_LL_IsStallEP (USBD_HandleTypeDef *pdev, uint8_t ep_addr);   
USBD_StatusTypeDef USBD_LL_SetUSBAddress (USBD_HandleTypeDef *pdev, uint8_t dev_addr);   
USBD_StatusTypeDef USBD_LL_Transmit (USBD_HandleTypeDef *pdev, uint8_t  ep_addr, uint8_t  *pbuf, uint16_t  size);

USBD_StatusTypeDef USBD_LL_PrepareReceive(USBD_HandleTypeDef *pdev, uint8_t  ep_addr, uint8_t  *pbuf, uint16_t  size);

uint32_t USBD_LL_GetRxDataSize  (USBD_HandleTypeDef *pdev, uint8_t  ep_addr);
void  USBD_LL_Delay (uint32_t Delay);


#endif

