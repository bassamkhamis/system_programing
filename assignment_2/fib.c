#include <stdio.h>
#include <stdlib.h>

void printf_fibonacci(int num){
   int v1 =0,v2=1,v3;

   if( num == 0)
      printf("%d\n",0);
      
   else if( num == 1)
      printf("%d, %d\n",0,1);
      
   else if(num >= 2)  
   {
      printf("%d, %d,",0,1);
      for(int i = 2; i<=num; i++)
      {
           v3 = v1 + v2;
           printf(" %d",v3);
           if(i != num)
              printf(",");
           v1 = v2 ;
           v2 = v3 ;
      }
      
   }  
  putchar('\n');

   

}
