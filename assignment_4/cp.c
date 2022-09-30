#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>



int main(int argc, char *argv[]){

   char buffer[100];
   ssize_t read_count;
   int df_src,df_des;
   df_src = open(argv[1], O_RDONLY);
   df_des = open(argv[2], O_CREAT | O_WRONLY,0644); //O_RDONLY
   
   if(df_src == -1 || df_des == -1)
   {
   printf("ERROR fails to open\n");
   exit(1);
   }
   
   else{ 
          while ( (read_count = read(df_src, buffer,100)) )
            {
        
                if( -1 == write(df_des,buffer,read_count) )
                    printf("ERROR Fails to write\n");
        
            }

      }
   
   close(df_src);
   close(df_des);

return 0;
}
