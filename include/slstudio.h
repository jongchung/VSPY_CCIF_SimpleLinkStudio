/*
 * slstudio.h - CC31xx/CC32xx Host Driver Implementation
 *
 * Copyright (C) 2014 Texas Instruments Incorporated - http://www.ti.com/ 
 * 
 * 
 *  Redistribution and use in source and binary forms, with or without 
 *  modification, are permitted provided that the following conditions 
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the   
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
*/

#ifndef __SIMPLE_LINK_STUDIO__
#define __SIMPLE_LINK_STUDIO__

#ifdef	__cplusplus
extern "C" {
#endif


// used for polling mode system 
#define SL_POLLING_MODE_USED
#define SL_STUDIO_VER  "0.0.4.14" //versions 4.10 supports UART

typedef short (__cdecl *SL_P_EVENT_HANDLER)(void* pValue);

int __cdecl SlStudio_RegisterInterruptHandler(SL_P_EVENT_HANDLER InterruptHdl , void* pValue);

int __cdecl SlStudio_DisableDevice();

int __cdecl SlStudio_EnableDevice();

char* __cdecl SlStudio_GetVer();

int __cdecl VerifyTimerFrequency(unsigned int FreqConfigured);

// SPI interface 
typedef int* SpiHandle_t;

SpiHandle_t __cdecl SlStudio_SpiOpen(char *ifName, unsigned long flags);

int __cdecl SlStudio_SpiClose(SpiHandle_t hdl);

int __cdecl SlStudio_SpiRead(SpiHandle_t hdl, unsigned char *pBuff, int len);

int __cdecl SlStudio_SpiWrite(SpiHandle_t hdl, unsigned char *pBuff, int len);

int __cdecl SlStudio_SpiStartWriteSeq(SpiHandle_t hdl);

int __cdecl SlStudio_SpiEndWriteSeq(SpiHandle_t hdl);

void __cdecl SlStudio_SpiIRQMask();

void __cdecl SlStudio_SpiIRQUnMask();


// UART Interface
typedef void* UartHandle_t;

#define UART_IF_OPEN_FLAG_NONE    0
#define UART_IF_OPEN_FLAG_RE_OPEN 1

typedef struct  
{
	unsigned int BaudRate;
	unsigned char FlowControlEnable;
	unsigned char CommPort;

} SlStudioUartIfParams_t;

UartHandle_t __cdecl SlStudio_UartOpen(char *ifName, unsigned long flags);

int __cdecl SlStudio_UartClose(void* hdl);

int __cdecl SlStudio_UartWrite(void* hdl, unsigned char* pBuffer, unsigned int BytesToWrite);

int __cdecl SlStudio_UartRead(void* hdl, unsigned char* pBuffer, unsigned int BytesToRead);

void __cdecl SlStudio_UartIRQMask();

void __cdecl SlStudio_UartIRQUnMask();

#ifdef  __cplusplus
}
#endif // __cplusplus


#endif //__SPI_H__

