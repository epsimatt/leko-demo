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
#include <stdlib.h>

#include "raylib.h"

/* 버튼의 상태를 나타내는 열거형 */
typedef enum button_state {
    BTS_DISABLED,
    BTS_NORMAL,
    BTS_FOCUSED,
    BTS_PRESSED
} ButtonState;

/* 버튼을 나타내는 구조체 */
typedef struct button {
    Texture2D texture;
    Rectangle source;
    Vector2 pos;
    Color tint;
    ButtonState state;
    bool action;
} Button;

/* 버튼 구조체를 초기화한다. */
Button *InitButton(Texture2D texture,
                   Rectangle source,
                   Vector2 pos,
                   Color tint);

/* 주어진 버튼을 화면에 그린다. */
void DrawButton(Button *button);