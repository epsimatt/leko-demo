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

#include <stdlib.h>

typedef struct {
    void **ptr;
    unsigned int capacity;
    unsigned int len;
} Vec;

/* Moves all the elements of `other_v` into `v`. */
void vec_append(Vec *v, Vec *other_v);

/* Frees up the memory allocated by `v`. */
void vec_free(Vec *v);

/* Returns a reference to the element at the specified `index`. */
void *vec_get(Vec *v, unsigned int index);

/* Inserts an element at the specified `index`. */
void vec_insert(Vec *v, unsigned int index, void *value);

/* Constructs a new, empty vector. */
Vec vec_new(void);

/* Removes the last element from the vector and returns it. */
void *vec_pop(Vec *v);

/* Adds an element at the end of the vector. */
void vec_push(Vec *v, void *value);

/* Removes the element at the specified `index`. */
void vec_remove(Vec *v, unsigned int index);

/*
    Resizes the vector, extending it with each new slot set to `default_value`
    if `new_len` is greater than the current length.
*/
void vec_resize(Vec *v, unsigned int new_len, void *default_value);

/* Replaces the element at the specified `index`, with `value`. */
void vec_set(Vec *v, unsigned int index, void *value);

/* Shrinks the capacity of the vector as much as possible. */
void vec_shrink_to_fit(Vec *v);

/* Shortens the vector. This function has no effect if `length` is greater than the current length of `v`. */
void vec_truncate(Vec *v, unsigned int new_length);

/* Creates a new vector with the specified `capacity`. */
Vec vec_with_capacity(int capacity);
