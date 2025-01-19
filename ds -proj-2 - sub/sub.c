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
    //system("clear");
     
    
    //validate CLA
    if(argc < 4 || argv[2][0]!= '-')
    {
        printf("Enter the valid no. arg\n");
        printf("./ 1234 - 1234.......\n");
        return 0;
    }
    else
    {
        // Create separate pointers for different doubly linked lists
        Dlist *head1 = NULL;  // Head of the first list
        Dlist *head2 = NULL;  // Head of the second list
        Dlist *head3 = NULL; // Head of the result (diff) list  
        Dlist *tail1 = NULL;  // tail of the first list
        Dlist *tail2 = NULL;  // tailof the second list
        Dlist *tail3 = NULL;  //tail of the result (diff) list
        

        int num1,num2,res;
        int borrow=0;
        int sign = 0;
        
        int arg1_len = strlen(argv[1]);
        int arg3_len = strlen(argv[3]);
        int c = strcmp(argv[1],argv[3]);
       if(c==0)
       {
          for (int i = 0; i < arg1_len; i++) {
            dl_insert_last(&head1, &tail1, (argv[1][i] - '0'));
            dl_insert_last(&head2, &tail2, (argv[3][i] - '0'));
        }
          printf("First no  : ");
          print_list(head1);
          printf("Second no : ");
          print_list(head2);
          printf("diff is   : ");
         for(int i=0;i<arg1_len;i++)
          printf("0 ");
          return 0;
       }
        if(arg1_len > arg3_len  || (arg1_len == arg3_len) && (c>0) )
        {

        for(int i=0;i<arg1_len;i++)
        {
        dl_insert_last(&head1, &tail1, (argv[1][i]-'0')); //  atoi not work becz it expect str not charm so using char -'0'= int
        }
        for(int i=0;i<arg3_len;i++)
        {
        dl_insert_last(&head2, &tail2, (argv[3][i]-'0')); // this funtion is written same 
                                                   //basic insert last so it return success or failure 
                                                   //but every time there will be a value so no need return 
                                                   //any sucess or failue.
        }

        }
      else
        {

        for(int i=0;i<arg3_len;i++)
        {
        dl_insert_last(&head1, &tail1, (argv[3][i]-'0')); //  atoi not work becz it expect str not charm so using char -'0'= int
        }
        for(int i=0;i<arg1_len;i++)
        {
        dl_insert_last(&head2, &tail2, (argv[1][i]-'0'));
        }
            sign = 1;
        }
         
        Dlist *t1 = tail1;
        Dlist *t2 = tail2;
        Dlist *t3 = tail3;

        printf("First no  : ");
        print_list(head1);
        printf("Second no : ");
        print_list(head2);
    
    while(t1 != NULL)
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
        
        if(borrow ==1)
        {
            num1 = num1-1;
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

        if(num1<num2)
        {
            num1 = num1 + 10;
            borrow =1;
        }
        else
        {
            borrow = 0;
        }
        
        res = num1 - num2;
        
        dl_insert_first(&head3, &tail3, res);
   
    } 
      printf("diff is : ");
      if(sign)
      {
        printf("- ");
      }

      print_list(head3);
    }
     
  
    }