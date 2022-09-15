#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

int main(){

  char inputMessage [100] ="0";
   char *ptr ="How can I hellp you > ";
   char str_int[20];
   char str_int2[20];
   int num = 0; 
   
   /* ---------------------------------------- */
   
   
  while(1)
   {

      printf("%s",ptr);
      fgets(inputMessage,100,stdin);

     // scanf("%[^\n]%*c",inputMessage);


      if ( 10 == strcmp( inputMessage, "exit" ) )
      {
          printf("Good bye\n");
          break;
      }
       else if ( 10 == strcmp( inputMessage, "fact" ) )
      {
         printf("Enter a number: ");
         fflush(stdout);
         fgets(str_int,20,stdin);
         num = strtol(str_int,NULL,0);
         factorial(num);
      }
      else if ( 10 == strcmp( inputMessage, "rand" ) )
      {
       printf_randam();
      }    

     else if ( 10 == strcmp( inputMessage, "fib" ) )
      {
        printf("Enter a number: ");
        fflush(stdout);
        fgets(str_int,20,stdin);
        num = strtol(str_int,NULL,0);
        printf_fibonacci(num);
        //printf("\n");
       
      }
      else if( 10 != inputMessage[0] ) 
      {
         printf("You Said: %s",inputMessage);
        // printf("\n");
      }
      else
      {
      // printf(" ");
      }
  }

   return 0;

}





