#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
/*************************************Globale variables*******************************************************/
typedef enum{Black,Red, Green,Yellow, Blue,Purple, Cyan, White}Index;
 char * setcolor[] = {"\033[0;30m", "\033[0;31m", "\033[0;32m","\033[0;33m", "\033[0;34m","\033[0;35m",          "\033[0;36m", "\033[0;37m"};

int main(){

          char local_var_name[100][15]={0};
          char local_var_val[100][15]={0};
          int num_var=-1;
          
                  
          while(1)
          {
          
           int len=0, ret_pid=0, row=0, column=0;
           int stat=0, flag=0;
           char buffer[100]={0};  
           char argv[5][20]={0}; 
            printf("%s",setcolor[Green]);    //Set color green
            printf("How Can I Help You");
            printf("%s",setcolor[Red]);      //Then,set color Res
            printf(" $");
            printf("%s",setcolor[White]);    //Set color white
            fgets(buffer,100,stdin);
            len = strlen(buffer);
             if( len == 1 )
                continue;            

            buffer[len -1]='\0' ;
            for(int i=0; i<len; i++)
            {
                 if(buffer[i] == '='){
                     num_var++ ;
                     for(int s=0; s<i; s++){
                     local_var_name[num_var][s]=buffer[s]; 
                     }
                     for(int m=i+1, num=0; buffer[m] != '\0'; m++,num++){
                     local_var_val[num_var][num]=buffer[m]; 
                     }
                     flag = 1;
                     break;
                 }
            
            }
            
            if(flag)
              continue;
              
            for(int i=0; buffer[i] != '\0'; i++ )
            {
                         
                 if(buffer[i] == ' ')
                 {
                   if(buffer[i-1] != ' ')
                   {
                      row++;
                      column = 0; 
                   }
                  
                  continue ;  //Ignore Spaces
                 
                 }                  
                argv[row][column] = buffer[i];
                column++;
                if( column == 20)
                   column = 0;

            }
            int ii;
            if( !strcmp(buffer,"set") ){
                  for(int i=0; i<=num_var; i++){
                    printf("%s = %s\n",local_var_name[i], local_var_val[i] );
                  
                  }           
              continue ;
            }
            
            else if( !strcmp(argv[0],"export") ){
                  for( ii=0; (ii<=num_var); ii++){
                  
                     if( !strcmp(argv[1],local_var_name[ii]) ){
                     
                        setenv(local_var_name[ii], local_var_val[ii], 1);
                        //printf("EXPORT\n");
                        break;
                       }
                     
                      } 
                   if( ii > num_var)
                      printf("variable does not exist!!\n");
                      
                    continue ;  // export Don't need fork
            }
            
            char *argvp[5] = {NULL} ; // Max argument 4
            for(int i=0; i <= row; i++){
                argvp[i] = argv[i] ;
            }
           
             ret_pid = fork();
             
             if( ret_pid < 0 )
             {
              perror("ERROR");
             }
             else if( ret_pid > 0 )   // parent
             {
             wait(&stat);
             
             }
             else if( ret_pid == 0  )  //Child
             {
                 execvp( argvp[0],(char*const*)argvp);
                 perror("Fork ERROR");
             
             }
          
          }
          
          
return 0;
}
