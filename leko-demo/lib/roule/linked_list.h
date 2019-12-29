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

#include <stdbool.h>

typedef struct node {
    int value;
    struct node *prev;
    struct node *next;
} Node;

/* A doubly linked list. */
typedef struct {
    int len;
    Node *head;
    Node *tail;
} LinkedList;

/* Removes all elements from the `list`. */
void linked_list_clear(LinkedList *list);

/* Returns `true` if `list` contains a node with `value`. */
bool linked_list_contains(LinkedList *list, int value);

/* Constructs an empty `LinkedList`. */
LinkedList linked_list_new(void);

/* Adds the `node` at the end of the `list`. */
void linked_list_push_back(LinkedList *list, Node *node);

/* Adds the `node` at the beginning of the `list`. */
void linked_list_push_front(LinkedList *list, Node *node);

/* Constructs an empty `Node`. */
Node *node_new(int value);
