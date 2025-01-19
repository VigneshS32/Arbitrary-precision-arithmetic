#ifndef DLL_H
#define DLL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE -1

// Define the node structure
typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} Dlist;

int dl_insert_first(Dlist **head, Dlist **tail, int data);
int dl_insert_last(Dlist **head, Dlist **tail, int data);
void print_list(Dlist *head);
#endif