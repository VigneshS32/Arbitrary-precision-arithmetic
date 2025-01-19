/*
 NAME         :  VIGNESH S
 REG ID       :  24017f_025
 PROJECT NAME :   APC
 DATE         :  30-11-24
 BRIEF        :  Arithmetic operation using Doubly linked list
*/
#include "dll.h"

int main(int argc, char *argv[]) {
    // Validate command-line arguments
    if (argc < 4 || argv[2][0] != 'x' ) {
        printf("Enter valid arguments.\n");
        printf("Usage: ./program 1234 x 5678\n");
        return 0;
    }

    // Initialize the lists
    Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL;
    Dlist *r_head = NULL, *r_tail = NULL;

    // Insert digits of the first number into the first list
    for (int i = 0; argv[1][i] != '\0'; i++) {
        dl_insert_last(&head1, &tail1, argv[1][i] - '0');
    }

    // Insert digits of the second number into the second list
    for (int i = 0; argv[3][i] != '\0'; i++) {
        dl_insert_last(&head2, &tail2, argv[3][i] - '0');
    }

    // Debug: Print input lists
    printf("First Number: ");
    print_list(head1);
    printf("Second Number: ");
    print_list(head2);

    // Perform multiplication
    multiply_lists(tail1, tail2, &r_head, &r_tail);

    // Debug: Print the result
    printf("Result: ");
    print_list(r_head);

    // Free allocated memory
    free_list(&head1);
    free_list(&head2);
    free_list(&r_head);

    return 0;
}
