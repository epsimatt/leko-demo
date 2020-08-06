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

#include "core.h"

static int result;

/* 배경 화면을 그린다. */
static void DrawBackground(void);

/* 전경 화면을 그린다. */
static void DrawForeground(void);

/* 배경 화면을 그린다. */
static void DrawBackground(void) {
    // TODO: ...
}

/* 전경 화면을 그린다. */
static void DrawForeground(void) {
    // TODO: ...
}

/* 게임 설정 화면을 초기화한다. */
void InitOptionsScreen(void) {
    result = 0;
}

/* 게임 설정 화면을 업데이트한다. */
void UpdateOptionsScreen(void) {
    DrawBackground();
    DrawForeground();
}

/* 게임 설정 화면을 종료한다. */
int FinishOptionsScreen(void) {
    return result;
}