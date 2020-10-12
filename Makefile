#
# Copyright (c) 2020 epsimatt
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

.PHONY: clean

BIN_PATH := leko-demo/bin
LIB_PATH := leko-demo/lib
SRC_PATH := leko-demo/src

CC := gcc
CFLAGS := -std=c99 -O2 -D_DEFAULT_SOURCE
LDFLAGS := -g
LDLIBS := -lraylib -lGL -lm -lpthread -ldl -lrt -lX11


INPUT := $(SRC_PATH)/btn.c $(SRC_PATH)/core.c $(SRC_PATH)/game.c $(SRC_PATH)/main.c $(SRC_PATH)/opts.c
OUTPUT := ld_linux

_: 
	mkdir -p $(BIN_PATH)
	$(CC) $(INPUT) -o $(BIN_PATH)/$(OUTPUT) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(BIN_PATH)/$(OUTPUT)