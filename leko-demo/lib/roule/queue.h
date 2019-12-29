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

typedef struct queue {
    void **ptr;
    unsigned int capacity;
    unsigned int len;
} Queue;

/* Returns the last element of this queue. */
void *queue_back(Queue *q);

/* Frees up the memory allocated by `q`. */
void queue_free(Queue *q);

/* Constructs a new, empty queue. */
Queue queue_new();

/* Returns the first element of this queue. */
void *queue_front(Queue *q);

/* Removes the first element from the queue and returns it. */
void *queue_pop(Queue *q);

/* Appends an element to the back of the queue. */
void queue_push(Queue *q, void *value);

/* Creates a new stack with the specified `capacity`. */
Queue queue_with_capacity(int capacity);
