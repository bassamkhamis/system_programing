#include <stdio.h>
#include <string.h>

int main()
{
   char inputMessage [100] ="0";
   char exitMessage[]="exit";
   
   /* ---------------------------------------- */
   while(1)
   {
      printf("How can I hellp you > ");
      fgets(inputMessage,100,stdin);

      if ( 10 != strcmp( inputMessage, "exit" ) )
      {
         printf("You Said: %s",inputMessage);
      }
      else
      {
         printf("Good bye\n");
         break;
      }
   }

   return 0;

}
