#include "dll.h"

// insert the digit to last
int dl_insert_last(Dlist **head, Dlist **tail, int data)
{
  Dlist *new = malloc (sizeof(Dlist));
  if(new==NULL)
  {
     return FAILURE; 
  }
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