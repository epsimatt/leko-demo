/*
    Copyright (c) 2019 epsimatt

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

#pragma once

#include <stdbool.h>
#include "core.h"

#define LVSTR_SZ 421

/* 그림 리소스 파일을 불러온 다음, 그 내용을 `tx`에 저장한다. */
bool LoadResourceTx(Texture2D *tx, const char *file_name);

/* 레벨 문자열 `str`를 배열로 변환하여, `result`에 저장한다. */
bool LoadLevelFromStr(const char *str, Block result[PF_HEIGHT][PF_WIDTH]);

/* 블록의 실제 좌표를 레벨 좌표로 변환한다. */
Vector2 toLevelCoords(Vector2 pos);

/* 블록의 실제 X좌표를 레벨 X좌표로 변환한다. */
int toLevelX(float x);

/* 블록의 실제 Y좌표를 레벨 Y좌표로 변환한다. */
int toLevelY(float y);