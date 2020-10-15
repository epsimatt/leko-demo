/*
    Copyright (c) 2020 epsimatt

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

/* `Sound` 리소스 포인터 변수 */
static Sound *sn_list[SNL_LEN] = {
    &sn_blk_marked,
    &sn_blk_pressed,
};

/* `Sound` 리소스 파일 */
static const char *snf_list[SNL_LEN] = {
    "res/sounds/blk_marked.wav",
    "res/sounds/blk_pressed.wav",
};

/* `Texture2D` 리소스 포인터 변수 */
static Texture2D *tx_list[TXL_LEN] = {
    &tx_blocks,
    &tx_border,
    &tx_buttons,
    &tx_clicked,
    &tx_playfield,
};

/* `Texture2D` 리소스 파일 */
static const char *txf_list[TXL_LEN] = {
    "res/images/blocks.png",
    "res/images/border.png",
    "res/images/buttons.png",
    "res/images/clicked.png",
    "res/images/playfield.png",
};

/* 게임의 현재 장면 */
Scene current_scene = INIT;

/* `Music` 리소스 파일을 불러온 다음, 그 내용을 `mu`에 저장한다. */
LEKO_IMPL bool LoadResourceMu(Music *mu, const char *file_name) {
    *mu = LoadMusicStream(file_name);
    return (mu->ctxData != NULL);
}

/* `Sound` 리소스 파일을 불러온 다음, 그 내용을 `sn`에 저장한다. */
LEKO_IMPL bool LoadResourceSn(Sound *sn, const char *file_name) {
    *sn = LoadSound(file_name);
    return (sn->sampleCount != 0);
}

/* `Texture2D` 리소스 파일을 불러온 다음, 그 내용을 `tx`에 저장한다. */
LEKO_IMPL bool LoadResourceTx(Texture2D *tx, const char *file_name) {
    *tx = LoadTexture(file_name);
    return (tx->id != 0);
}

/* 게임에 사용되는 모든 리소스 파일을 준비한다. */
LEKO_IMPL bool LoadAllResources(void) {
    static int result;

    // https://github.com/raysan5/raylib/issues/323
    ft_default = LoadFontEx("res/font/nanumgothic-coding.ttf", 24, NULL, 128);

    for (int i = 0; i < SNL_LEN; i++)
        result = (sn_list[i] != NULL && !LoadResourceSn(sn_list[i], snf_list[i]));

    for (int i = 0; i < TXL_LEN; i++)
        result = (tx_list[i] != NULL && !LoadResourceTx(tx_list[i], txf_list[i]));

    return result;
}

/* 레벨 문자열 `str`를 배열로 변환하여, `result`에 저장한다. */
LEKO_IMPL bool LoadLevelFromStr(const char *str, Block result[PF_HEIGHT][PF_WIDTH]) {
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
        result[py][px].pos1 = (Vector2){
            (float) (PF_STX + px * BLOCK_SZ),
            (float) (PF_STY + py * BLOCK_SZ)};
        result[py][px].pos2 = result[py][px].pos1;

        token = strtok(NULL, ",");
        index++;
    }

    return true;
}

/* 게임의 다음 장면으로 넘어간다. */
LEKO_IMPL void MoveTo(int next_scene) {
    if (current_scene != next_scene) {
        switch (next_scene) {
            case GAMEPLAY:
                InitGameplayScreen();
                break;
        }

        current_scene = next_scene;
    }
}

/* 게임의 현재 장면을 업데이트한다. */
LEKO_IMPL void UpdateCurrentScreen(void) {
    BeginDrawing();

    switch (current_scene) {
        case INIT:
            LoadAllResources();
            MoveTo(GAMEPLAY);
            break;

        case GAMEPLAY:
            UpdateGameplayScreen();
            break;
    }

    EndDrawing();
}