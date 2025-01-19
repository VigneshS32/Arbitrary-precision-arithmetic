#include "dll.h"

// insert the digit to last
// Insert a digit at the end of the list
int dl_insert_last(Dlist **head, Dlist **tail, int data) 
{
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
 // insert the digit to first 
int dl_insert_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));
    if(new==NULL)
    {
        return FAILURE;
    }
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
   if(*head == NULL && *tail == NULL)
   {
     
     *head = new;
     *tail = new;
      
   }
   else
   {   
       new->next = *head;
       (*head)->prev = new;
       *head = new;
       
   }
    return SUCCESS;
}


 //print the result
void print_list(Dlist *head)
{
	/* Cheking the list is empty or not */
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
	   // printf("Head -> ");
	    while (head)		
	    {
		    /* Printing the list */
		    printf("%d ", head -> data);

		    /* Travering in forward direction */
		    head = head -> next;
		     
	    }
    	printf(" \n");
    }
}

//free the list
void free_list(Dlist **head) {
    Dlist *current = *head; // Start at the head
    Dlist *next_node;

    while (current != NULL) {
        next_node = current->next; // Save the pointer to the next node
        free(current);            // Free the current node
        current = next_node;      // Move to the next node
    }

    *head = NULL; // Set the head pointer to NULL after freeing all nodes
}


// Add two lists (digit-wise)
void add_lists(Dlist **result, Dlist **tail_result, Dlist *to_add) {
    Dlist *t1 = *tail_result, *t2 = to_add;
    int carry = 0;
    int num1,num2;
    int res;
    Dlist *temp_result = NULL, *temp_tail = NULL;

    while (t1 != NULL || t2 != NULL || carry > 0) {
        

        if (t1 == NULL)
        {
            num1 =0;
        } 
        else
        {
            num1 = t1->data;
            t1 = t1->prev;
        }

        if (t2 == NULL)
        {
            num2 = 0;
        } 
        else
        {
            num2 = t2->data;
            t2 = t2->prev;
        }
        res = num1+num2+carry;
        if(res>9)
        {
        carry = res/ 10;
        res = res % 10;
       }
       else
       {
        carry = 0;
       }


        dl_insert_first(&temp_result, &temp_tail, res);
    }

    free_list(result); // Free the previous result list0
    *result = temp_result;
    *tail_result = temp_tail;
}

// Multiply two lists (digit-wise)
void multiply_lists(Dlist *tail1, Dlist *tail2, Dlist **result, Dlist **tail_result) {
    Dlist *t2 = tail2;
    int carry, res, shift = 0;

    while (t2 != NULL) {
        int multiplier = t2->data;
        Dlist *temp_result = NULL, *temp_tail = NULL;
        carry = 0;

        Dlist *t1 = tail1;
        while (t1 != NULL) {
            res = t1->data * multiplier + carry;
            carry = res / 10;
            res %= 10;
            dl_insert_first(&temp_result, &temp_tail, res);
            t1 = t1->prev;
        }

        if (carry > 0) {
            dl_insert_first(&temp_result, &temp_tail, carry);
        }
        // Add ending  zeros for the current place value (shift)
        for (int i = 0; i < shift; i++) {
            dl_insert_last(&temp_result, &temp_tail, 0);
        }

        add_lists(result, tail_result, temp_tail); // Add temp_result to the main result
        free_list(&temp_result); // Free the temporary result list
        t2 = t2->prev;
        shift++;
    }
}
  