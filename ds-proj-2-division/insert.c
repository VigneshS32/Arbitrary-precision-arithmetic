#include "dll.h"

// insert the digit to last
void dl_insert_last(Dlist **head, Dlist **tail, int data)
{
  Dlist *new = malloc (sizeof(Dlist));
   
  new->data = data;
  new->next = NULL;
  new->prev = NULL;
  if(*head == NULL)
  {
      *head = *tail = new;
       
  }
  else
  {
      (*tail)->next = new;
      new->prev = *tail;
      *tail=new;
  }
  
}

 // insert the digit to first 
void dl_insert_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));
    
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
 
 

// Function to divide two doubly linked lists
void divide_lists(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **quotient_head, Dlist **quotient_tail, Dlist **remainder_head, Dlist **remainder_tail) {
    Dlist *t1 = head1;
    Dlist *t2 = head2;
    int dividend_digit = 0, divisor_digit = 0, quotient_digit = 0, remainder_digit = 0;
    int divisor = 0;
    Dlist *remainder = NULL;

    // Convert divisor into integer value
    t2 = head2;
    while (t2 != NULL) {
        divisor = divisor * 10 + t2->data;
        t2 = t2->next;
    }

    // Perform division process
    while (t1 != NULL) {
        dividend_digit = dividend_digit * 10 + t1->data;

        // Subtract divisor from dividend while dividend is greater than or equal to divisor
        quotient_digit = 0;
        while (dividend_digit >= divisor) {
            dividend_digit -= divisor;
            quotient_digit++;
        }

        // Insert quotient digit into the result
        dl_insert_last(quotient_head, quotient_tail, quotient_digit);

        t1 = t1->next;
    }
    // Update the remainder list
        remainder_digit = dividend_digit;
        dl_insert_last(remainder_head, remainder_tail, remainder_digit);
}


 