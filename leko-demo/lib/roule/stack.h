/*
    Copyright (c) 2019 epsimatt <epsimatt@protonmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

typedef struct stack {
    void **ptr;
    unsigned int capacity;
    unsigned int len;
} Stack;

/* Frees up the memory allocated by `s`. */
void stack_free(Stack *s);

/* Constructs a new, empty stack. */
Stack stack_new(void);

/* Returns the last element of the stack without removing it from the stack. */
void *stack_peek(Stack *s);

/* Removes the last element from the stack and returns it. */
void *stack_pop(Stack *s);

/* Adds an element at the end of the stack. */
void stack_push(Stack *s, void *value);

/* Creates a new stack with the specified `capacity`. */
Stack stack_with_capacity(int capacity);
