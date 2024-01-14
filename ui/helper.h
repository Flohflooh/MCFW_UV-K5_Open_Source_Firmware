/* Copyright 2023 Dual Tachyon
 * https://github.com/DualTachyon
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 *     Unless required by applicable law or agreed to in writing, software
 *     distributed under the License is distributed on an "AS IS" BASIS,
 *     WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *     See the License for the specific language governing permissions and
 *     limitations under the License.
 */

#ifndef UI_UI_H
#define UI_UI_H

#include <stdbool.h>
#include <stdint.h>

void UI_GenerateChannelString(char *pString, uint8_t Channel);
void UI_GenerateChannelStringEx(char *pString, bool bShowPrefix,
                                uint8_t ChannelNumber);
void UI_PrintString(const char *pString, uint8_t Start, uint8_t End,
                    uint8_t Line, uint8_t Width, bool bCentered);
void UI_PrintStringSmall(const char *pString, uint8_t Start, uint8_t End,
                         uint8_t Line);
void UI_PrintStringSmallBold(const char *pString, uint8_t Start, uint8_t End,
                             uint8_t Line);
void UI_DisplayFrequency(const char *pDigits, uint8_t X, uint8_t Y,
                         bool bDisplayLeadingZero, bool bFlag);
void UI_DisplaySmallDigits(uint8_t Size, const char *pString, uint8_t X,
                           uint8_t Y);
#if defined(ENABLE_MESSENGER) || defined(ENABLE_LIVESEEK_MHZ_KEYPAD)	
void UI_DrawLineBuffer(uint8_t (*buffer)[128], int16_t x1, int16_t y1, int16_t x2, int16_t y2, bool black);
void UI_DrawDottedLineBuffer(uint8_t (*buffer)[128], int16_t x1, int16_t y1, int16_t x2, int16_t y2, bool black, int dotSpacing);
void UI_DrawRectangleBuffer(uint8_t (*buffer)[128], int16_t x1, int16_t y1, int16_t x2, int16_t y2, bool black);
void UI_DrawPixelBuffer(uint8_t (*buffer)[128], uint8_t x, uint8_t y, bool black);

void GUI_DisplaySmallest(const char *pString, uint8_t x, uint8_t y, bool statusbar, bool fill);

#endif

void PutPixel(uint8_t x, uint8_t y, uint8_t fill);
void PutPixelStatus(uint8_t x, uint8_t y, bool fill);
void DrawHLine(int sy, int ey, int nx, bool fill);
void UI_PrintStringSmallest(const char *pString, uint8_t x, uint8_t y,
                            bool statusbar, bool fill);
void UI_DrawScanListFlag(uint8_t *pLine, uint8_t attrs);
bool UI_NoChannelName(char *channelName);
#endif

void UI_DisplayClear();
