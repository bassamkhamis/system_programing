#include <stdio.h>
#include <stdlib.h>

void factorial(int num){
  int fact = 1 ;

  for(int i =1; i<=num; i++)
  {
 
        fact *= i;   
  }
  
  printf("Result is: %d\n",fact);
  


}
