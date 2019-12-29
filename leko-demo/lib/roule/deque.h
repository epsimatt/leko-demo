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

/* A double-ended queue. */
typedef struct deque {
    void **ptr;
    unsigned int capacity;
    unsigned int len;
} Deque;

/* Frees up the memory allocated by `dq`. */
void deque_free(Deque *dq);

/* Removes the last element from the deque and returns it. */
void *deque_pop_back(Deque *dq);

/* Removes the first element from the deque and returns it. */
void *deque_pop_front(Deque *dq);

/* Appends an element to the back of the deque. */
void deque_push_back(Deque *dq, void *value);

/* Appends an element to the front of the deque. */
void deque_push_front(Deque *dq, void *value);

/* Shrinks the capacity of the deque as much as possible. */
void deque_shrink_to_fit(Deque *dq);

/* Creates a new deque with the specified `capacity`. */
Deque deque_with_capacity(int capacity);
