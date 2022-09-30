#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>



int main(int argc, char *argv[]){



   for(int i=1;i<argc;i++)
       {
       printf("%s ",argv[i]);
       }
   putchar('\n');    
return 0;
}
