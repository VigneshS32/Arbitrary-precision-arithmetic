#include <stdio.h>
#include <stdlib.h>

// Define the structure for the doubly linked list
typedef struct Dlist {
    int data;
    struct Dlist *prev;
    struct Dlist *next;
} Dlist;

#define SUCCESS 0
#define FAILURE -1

// Function to insert a digit at the end of the list
int dl_insert_last(Dlist **head, Dlist **tail, int data) {
    Dlist *new = malloc(sizeof(Dlist));
    if (new == NULL) {
        return FAILURE;
    }
    new->data = data;
    new->next = NULL;
    new->prev = NULL;

    if (*head == NULL) { // If the list is empty
        *head = *tail = new;
    } else {
        (*tail)->next = new;
        new->prev = *tail;
        *tail = new;
    }
    return SUCCESS;
}

// Function to print the list
void print_list(Dlist *head) {
    if (head == NULL) {
        printf("INFO: List is empty\n");
        return;
    }
    while (head) {
        printf("%d", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to free the list
void free_list(Dlist **head) {
    Dlist *current = *head;
    Dlist *next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    *head = NULL;
}

// Function to add two lists (handles carry and alignment)
void add_lists(Dlist **result, Dlist **tail_result, Dlist *to_add) {
    Dlist *t1 = *result, *t2 = to_add;
    int carry = 0;

    Dlist *temp_result = NULL, *temp_tail = NULL;

    // Align `t1` and `t2` digit-wise addition
    while (t1 != NULL || t2 != NULL || carry > 0) {
        int sum = carry;

        if (t1 != NULL) {
            sum += t1->data;
            t1 = t1->next;
        }

        if (t2 != NULL) {
            sum += t2->data;
            t2 = t2->next;
        }

        carry = sum / 10;
        sum %= 10;

        dl_insert_last(&temp_result, &temp_tail, sum);
    }

    *result = temp_result;
    *tail_result = temp_tail;
}

// Function to multiply two lists
void multiply_lists(Dlist *head1, Dlist *head2, Dlist **result, Dlist **tail_result) {
    Dlist *t2 = head2;
    int carry, res, shift = 0;

    // Traverse through each digit of the second number (head2)
    while (t2 != NULL) {
        int multiplier = t2->data;
        Dlist *temp_result = NULL, *temp_tail = NULL;
        carry = 0;

        // Add zeros at the beginning based on shift value (this is for proper place value alignment)
        for (int i = 0; i < shift; i++) {
            dl_insert_last(&temp_result, &temp_tail, 0);
        }

        Dlist *t1 = head1;
        // Multiply the current digit of head2 with each digit of head1
        while (t1 != NULL) {
            res = t1->data * multiplier + carry;
            carry = res / 10;
            res %= 10;
            dl_insert_last(&temp_result, &temp_tail, res);
            t1 = t1->next;
        }

        // If there's a carry, add it to the result
        if (carry > 0) {
            dl_insert_last(&temp_result, &temp_tail, carry);
        }

        // Debug: Print partial result before adding
        printf("Partial result: ");
        print_list(temp_result);

        // Add this temporary result to the final result
        add_lists(result, tail_result, temp_result);

        // Free temporary result
        free_list(&temp_result);

        // Move to the next digit in the second number
        t2 = t2->next;
        shift++;
    }
}

int main(int argc, char *argv[]) {
    // Validate command-line arguments
    if (argc < 4 || argv[2][0] != 'x' || argv[2][1] != '\0') {
        printf("Enter valid arguments.\n");
        printf("Usage: ./program 1234 x 5678\n");
        return 0;
    }

    // Initialize the lists
    Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL;
    Dlist *result = NULL, *tail_result = NULL;

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
    multiply_lists(head1, head2, &result, &tail_result);

    // Debug: Print the result
    printf("Result: ");
    print_list(result);

    // Free allocated memory
    free_list(&head1);
    free_list(&head2);
    free_list(&result);

    return 0;
}
