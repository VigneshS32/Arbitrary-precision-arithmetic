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
 
// Function Prototypes
void dl_insert_last(Dlist **head, Dlist **tail, int data);
void dl_insert_first(Dlist **head, Dlist **tail, int data);
void print_list(Dlist *head);
int subtract_lists(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **head3, Dlist **tail3);
int compare_lists(Dlist *head1, Dlist *head2);
void divide_lists(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **quotient_head, Dlist **quotient_tail, Dlist **remainder_head, Dlist **remainder_tail);

#endif