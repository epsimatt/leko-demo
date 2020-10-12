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

#pragma once

#define LEVEL_00 "0,0,0,0,0,0,0,0,0,0,0,0,0,0,0," \
                 "0,0,0,0,0,0,0,0,0,0,0,0,0,0,0," \
                 "0,0,0,0,0,0,0,0,0,0,0,0,0,0,0," \
                 "0,0,0,0,0,0,0,0,0,0,0,0,0,0,0," \
                 "0,0,0,0,0,0,0,0,0,0,0,0,0,0,0," \
                 "0,0,0,0,0,0,0,0,0,0,0,0,0,0,0," \
                 "0,0,0,0,0,0,0,0,0,0,0,0,0,0,0," \
                 "0,0,0,0,0,0,0,0,0,0,0,0,0,0,0," \
                 "0,0,0,0,0,0,0,0,0,0,0,0,0,0,0," \
                 "0,0,0,0,0,0,0,0,0,0,0,0,0,0,0," \
                 "0,0,0,0,0,0,0,0,0,0,0,0,0,0,0," \
                 "0,0,0,0,0,0,0,0,0,0,0,0,0,0,0," \
                 "0,0,0,0,0,0,0,0,0,0,0,0,0,0,0," \
                 "0,0,0,0,0,0,0,0,0,0,0,0,0,0,0," \

#define LEVEL_01 "0,0,0,0,0,0,0,0,0,0,0,0,0,0,0," \
                 "0,0,0,1,0,0,0,0,0,0,0,0,0,0,0," \
                 "0,0,0,1,1,1,1,0,0,0,0,0,0,0,0," \
                 "0,0,0,1,0,7,1,6,0,1,0,0,0,0,0," \
                 "0,0,0,1,2,1,1,1,0,1,1,1,0,0,0," \
                 "0,0,0,1,6,0,4,0,5,7,1,0,0,0,0," \
                 "0,0,0,1,1,0,1,0,1,1,1,0,0,0,0," \
                 "0,0,0,0,1,5,0,0,1,0,0,0,0,0,0," \
                 "0,0,0,0,1,3,5,4,1,0,0,0,0,0,0," \
                 "0,0,0,0,1,2,6,3,1,0,0,0,0,0,0," \
                 "0,0,0,0,1,1,7,1,1,0,0,0,0,0,0," \
                 "0,0,0,0,0,1,1,1,0,0,0,0,0,0,0," \
                 "0,0,0,0,0,0,0,1,0,0,0,0,0,0,0," \
                 "0,0,0,0,0,0,0,0,0,0,0,0,0,0,0," 

const char *LEVEL_LIST[2] = { 
    LEVEL_00, 
    LEVEL_01 
};