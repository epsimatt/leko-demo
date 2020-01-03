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

#include "core.h"

Scene current_scene = INIT;

/* 그림 리소스 파일을 불러온 다음, 그 내용을 `tx`에 저장한다. */
bool LoadResourceTx(Texture2D *tx, const char *file_name) {
    *tx = LoadTexture(file_name);
    return (tx->id != 0);
}

/* 레벨 문자열 `str`를 배열로 변환하여, `result`에 저장한다. */
bool LoadLevelFromStr(const char *str, Block result[PF_HEIGHT][PF_WIDTH]) {
    char buffer[LVSTR_SZ];
    char *token;

    int index = 0;
    int px, py;

    strncpy(buffer, str, LVSTR_SZ);
    token = strtok(buffer, ",");

    while (token != NULL) {
        py = index / PF_WIDTH;
        px = index % PF_WIDTH;

        result[py][px].type = atoi(token);
        result[py][px].state = BLS_NORMAL;
        result[py][px].pos1 = (Vector2) { 
            (float) (PF_STX + px * BLOCK_SZ), 
            (float) (PF_STY + py * BLOCK_SZ)
        };
        result[py][px].pos2 = result[py][px].pos1;
        
        token = strtok(NULL, ",");
        index++;
    }

    return true;
}

/* 게임의 다음 장면으로 넘어간다. */
void MoveTo(int next_scene) {
    if (current_scene != next_scene) {
        switch (next_scene) {
            case OPTIONS:
                break;

            case GAMEPLAY:
                InitGameplayScreen();

                break;
        }

        current_scene = next_scene;
    }
}

/* 게임의 현재 장면을 업데이트한다. */
void UpdateCurrentScreen(void) {
    BeginDrawing();

    switch (current_scene) {
        case INIT:
            MoveTo(GAMEPLAY);

            break;

        case OPTIONS:
            break;

        case GAMEPLAY:
            UpdateGameplayScreen();

            break;
    }

    EndDrawing();
}