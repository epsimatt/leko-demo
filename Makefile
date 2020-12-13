#
# Copyright (c) 2020 jdeokkim
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
#

.PHONY: all clean

PROJ_PATH := leko-demo

BIN_PATH := $(PROJ_PATH)/bin
LIB_PATH := $(PROJ_PATH)/lib
SRC_PATH := $(PROJ_PATH)/src

RLIB_PATH := $(LIB_PATH)/raylib
RGUI_PATH := $(LIB_PATH)/raygui

INPUT = $(SRC_PATH)/btn.c $(SRC_PATH)/core.c $(SRC_PATH)/game.c $(SRC_PATH)/main.c
OUTPUT = $(BIN_PATH)/$(PROJ_PATH)

CC := gcc
CFLAGS := -g -I$(RGUI_PATH) -std=c99 -O2 -D_DEFAULT_SOURCE
LDLIBS := -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

$(OUTPUT): $(INPUT)
	mkdir -p $(BIN_PATH)
	$(CC) $(INPUT) -o $(OUTPUT) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

clean:
	rm -rf $(BIN_PATH)