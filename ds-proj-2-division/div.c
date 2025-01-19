/*
 NAME         :  VIGNESH S
 REG ID       :  24017f_025
 PROJECT NAME :   APC
 DATE         :  30-11-24
 BRIEF        :  Arithmetic operation using Doubly linked list
*/
#include "dll.h"
// Function to perform the division and print the result
void perform_division(char *num1, char *num2) {
    Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL;
    Dlist *quotient_head = NULL, *quotient_tail = NULL;
    Dlist *remainder_head = NULL, *remainder_tail = NULL;

    // Convert the first number into a doubly linked list
    for (int i = 0; i < strlen(num1); i++) {
        dl_insert_last(&head1, &tail1, num1[i] - '0');
    }

    // Convert the second number into a doubly linked list
    for (int i = 0; i < strlen(num2); i++) {
        dl_insert_last(&head2, &tail2, num2[i] - '0');
    }

    printf("Dividend: ");
    print_list(head1);
    printf("Divisor: ");
    print_list(head2);

    // Perform division
    divide_lists(head1, tail1, head2, tail2, &quotient_head, &quotient_tail, &remainder_head, &remainder_tail);

    // Print the quotient and remainder
    printf("Quotient: ");
    print_list(quotient_head);
    printf("Remainder: ");
    print_list(remainder_head);
}

int main(int argc, char *argv[]) {
    // Validate command line arguments
    if (argc != 4 || argv[2][0] != '/') {
        printf("Enter valid arguments: ./program number1 / number2\n");
        return 0;
    }

    // Perform division
    perform_division(argv[1], argv[3]);

    return 0;
}
