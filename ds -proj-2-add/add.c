/*
 NAME         :  VIGNESH S
 REG ID       :  24017f_025
 PROJECT NAME :   APC
 DATE         :  30-11-24
 BRIEF        :  Arithmetic operation using Doubly linked list


*/
#include "dll.h"

int main(int argc, char *argv[])
{
    system("clear");
     
    
    //validate CLA
    if(argc < 4 || argv[2][0]!= '+')
    {
        printf("Enter the valid no. arg\n");
        printf("./ 1234 + 1234.......\n");
        return 0;
    }
    else
    {
        // Create separate pointers for different doubly linked lists
        Dlist *head1 = NULL;  // Head of the first list
        Dlist *head2 = NULL;  // Head of the second list
        Dlist *head3 = NULL; // Head of the result (sum) list  
        Dlist *tail1 = NULL;  // tail of the first list
        Dlist *tail2 = NULL;  // tailof the second list
        Dlist *tail3 = NULL;  //tail of the result (sum) list
        

        int num1,num2,res;
        int carry=0;
        
        int arg1_len = strlen(argv[1]);
        int arg3_len = strlen(argv[3]);
        
        for(int i=0;i<arg1_len;i++)
        {
        dl_insert_last(&head1, &tail1, (argv[1][i]-'0')); //  atoi not work becz it expect str not char so using char -'0'= int
        }
        for(int i=0;i<arg3_len;i++)
        {
        dl_insert_last(&head2, &tail2, (argv[3][i]-'0'));
        }

        Dlist *t1 = tail1;
        Dlist *t2 = tail2;
        Dlist *t3 = tail3;

        printf("First no :");
        print_list(head1);
        printf("Second no :");
        print_list(head2);
      while(t1 != NULL || t2 != NULL || carry>0 )
      {
        if(t1 == NULL)
        {
            num1 = 0;
        }
        else
        {
            num1 = t1->data;
            t1=t1->prev;
        }

        
        if(t2 == NULL)
        {
            num2 = 0;
        }
        else
        {
            num2 = t2->data;
            t2=t2->prev;
        }
        
        res = num1 + num2 + carry;
        if(res>9)
        {
            carry=res/10;
             res=res%10;
        }
        else
        {
            carry = 0;
        }

        dl_insert_first(&head3, &tail3, res);
   
    } 
      printf("Sum is :");
      print_list(head3);  
    }
     

    }