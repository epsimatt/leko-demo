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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "raylib.h"

#define DEFAULT_WIDTH 1024
#define DEFAULT_HEIGHT 768

#define TARGET_FPS 120

#define CLR_TEXT (Color) { 231, 231, 231, 255 }

#define SNL_LEN 2
#define TXL_LEN 4

#define BLOCK_SZ 48
#define ISTR_SZ 16
#define LVSTR_SZ 421

#define MAX_ELAPSED_TIME 3599
#define MAX_LEVEL 1

#define PF_STX (5 * BLOCK_SZ)
#define PF_STY BLOCK_SZ

#define PF_WIDTH 15
#define PF_HEIGHT 14

/* 게임 장면 목록 */
typedef enum scene {
    INIT,
    OPTIONS,
    GAMEPLAY
} Scene;

/* 블록의 종류 */
typedef enum block_type {
    BLT_EMPTY,
    BLT_WALL,
    BLT_RED,
    BLT_ORANGE,
    BLT_YELLOW,
    BLT_GREEN,
    BLT_SKYBLUE,
    BLT_BLUE,
    BLT_PURPLE
} BlockType;

/* 블록의 상태 */
typedef enum block_state {
    BLS_NORMAL,
    BLS_MARKED,
    BLS_FALLING,
    BLS_DRAGGING
} BlockState;

/* 블록을 나타내는 구조체 */
typedef struct block {
    BlockType type; // 블록의 종류를 나타낸다.
    BlockState state; // 블록의 상태를 나타낸다.
    Vector2 pos1; // 블록의 처음 위치를 나타낸다.
    Vector2 pos2; // 블록의 현재 위치를 나타낸다.
    int _frame_counter; // 블록의 프레임 카운터
} Block;

Font fn_default;

Sound sn_blk_marked;
Sound sn_blk_pressed;

Texture2D tx_blocks;
Texture2D tx_border;
Texture2D tx_clicked;
Texture2D tx_playfield;

time_t elapsed_time;

int _elapsed_time;
int current_score;
int highest_score;

/* `Music` 리소스 파일을 불러온 다음, 그 내용을 `mu`에 저장한다. */
bool LoadResourceMu(Music *mu, const char *file_name);

/* `Sound` 리소스 파일을 불러온 다음, 그 내용을 `sn`에 저장한다. */
bool LoadResourceSn(Sound *sn, const char *file_name);

/* `Texture2D` 리소스 파일을 불러온 다음, 그 내용을 `tx`에 저장한다. */
bool LoadResourceTx(Texture2D *tx, const char *file_name);

/* 레벨 문자열 `str`를 배열로 변환하여, `result`에 저장한다. */
bool LoadLevelFromStr(const char *str, Block result[PF_HEIGHT][PF_WIDTH]);

/* 게임의 다음 장면으로 넘어간다. */
void MoveTo(int next_scene);

/* 게임의 현재 장면을 업데이트한다. */
void UpdateCurrentScreen(void);

/* 게임 플레이 화면을 초기화한다. */
void InitGameplayScreen(void);

/* 게임 플레이 화면을 업데이트한다. */
void UpdateGameplayScreen(void);

/* 게임 플레이 화면을 종료한다. */
int FinishGameplayScreen(void);