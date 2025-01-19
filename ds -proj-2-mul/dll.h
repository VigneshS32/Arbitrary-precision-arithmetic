#ifndef DLL_H
#define DLL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE -1
 
 
typedef struct Dlist {
    int data;
    struct Dlist *next;
    struct Dlist *prev;
} Dlist;

int dl_insert_last(Dlist **head, Dlist **tail, int data);
int dl_insert_first(Dlist **head, Dlist **tail, int data);
void print_list(Dlist *head);
void free_list(Dlist **head);
void add_lists(Dlist **result, Dlist **tail_result, Dlist *to_add);
void multiply_lists(Dlist *head1, Dlist *head2, Dlist **result, Dlist **tail_result);

#endif
