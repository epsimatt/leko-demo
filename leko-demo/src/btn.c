/*
    Copyright (c) 2020 jdeokkim

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

#include "btn.h"

/* 버튼 구조체를 초기화한다. */
Button *InitButton(Texture2D texture,
                   Rectangle source,
                   Vector2 pos) {
    Button *result = (Button *) malloc(sizeof(Button));

    *result = (Button) {
        texture,
        source,
        pos,
        WHITE,
        BTS_NORMAL,
        false
    };

    return result;
}

/* 주어진 버튼을 화면에 그린다. */
void DrawButton(Button *button) {
    Vector2 mouse_pos = GetMousePosition();
    Rectangle btn_bounds = {
        button->pos.x,
        button->pos.y,
        button->source.width,
        button->source.height
    };

    button->action = false;

    if (button->state != BTS_DISABLED && CheckCollisionPointRec(mouse_pos, btn_bounds)) {
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            button->state = BTS_PRESSED;
        else
            button->state = BTS_FOCUSED;

        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
            button->action = true;
    } else {
        button->state = BTS_NORMAL;
    }

    switch (button->state) {
        case BTS_DISABLED:
        case BTS_NORMAL:
            DrawTextureRec(
                button->texture,
                button->source,
                button->pos,
                WHITE
            );

            break;

        case BTS_FOCUSED:
            DrawTextureRec(
                button->texture,
                (Rectangle) {
                    button->source.x,
                    button->source.y + button->source.height,
                    button->source.width,
                    button->source.height
                },
                button->pos,
                WHITE
            );

            break;

        case BTS_PRESSED:
            DrawTextureRec(
                button->texture,
                (Rectangle) {
                    button->source.x,
                    button->source.y + 2.0f * button->source.height,
                    button->source.width,
                    button->source.height
                },
                button->pos,
                WHITE
            );

            break;
    }
}