/* * * * * * * * * * * * * * * * * * * * * * * * * * *
*   Auther   : Bassam Khamsi                         *
*   Date     : 13 AGU                                *
*   Version  : v3                                    *
*   Function : Implement shell Run on linux          *
* * * * * * * * * * * * * * * * * * * * * * * * * * */


/************************** Includes ********************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>


/************************ Globale variables ******************************************************************/
typedef enum{Black,Red, Green,Yellow, Blue,Purple, Cyan, White}Index;
 char * setcolor[] = {"\033[0;30m", "\033[0;31m", "\033[0;32m","\033[0;33m", "\033[0;34m","\033[0;35m",          "\033[0;36m", "\033[0;37m"};
 
char local_var_name[100][15]={0};
char local_var_val[100][15]={0};
int num_var=-1;
int  row=0, column=0;
 
/*********************** Function Declaration *****************************************************************/
int message( char buffer[] ) ;
void myfork(char argv[5][20], int row);
int parse( char buffer[], char argv[5][20] );
int isVariable(char buffer[], char argv[5][20]);



/*********************** Main Function************************************************************************/
int main(){

                
          while(1)
          {
          
            row=0, column=0;
           int stat=0, flag=0;
           char buffer[100]={0};  
           char argv[5][20]={0}; 
           
            // dispay message and get commands from user and set color text    
            // Check if user enter nothing  

            if( 0 == message( buffer ) )
                continue;  
                          
           // if return 1 ===> user set variable like( x=5 ) 
           // Not need to continue through program (no fork needed)
           if( parse( buffer,argv ) )
              continue;
           
           // This function check if user Enter command related to Variable like set expor
           if(isVariable( buffer,argv ) )
             continue ;   

            // Fork function create a child and parent MUST wait untill child finsh its operation
            myfork(argv, row);
          
        }          
 return 0;
}

/************************************** Function Implemention ***************************************************/

int isVariable(char buffer[], char argv[5][20]){
  
     int ii;
            if( !strcmp(buffer,"set") )
            {
                  for(int i=0; i<=num_var; i++){
                    printf("%s=%s\n",local_var_name[i], local_var_val[i] );
                  
                  }           
                  return 1 ; // We don't need to go through the program 
            }
            
            else if( !strcmp(argv[0],"export") )
            {
            
                  for( ii=0; (ii<=num_var); ii++)
                  {
                  
                     if( !strcmp(argv[1],local_var_name[ii]) )
                     {
                        setenv(local_var_name[ii], local_var_val[ii], 1);
                        break;
                       }
                     
                      } 
                   if( ii > num_var)
                      printf("variable does not exist!!\n");
                      
                   // continue ;  // export Don't need fork
                   return 1 ; // We don't need to go through the program
            }
   return 0; 
            
}
/*********************************************************************************************************/
int parse( char buffer[], char argv[5][20] ){

  int flag = 0;
  char temp[20] = {0};
  int index_arr_num=0;
  for(int i=0; buffer[i] != '\0'; i++)
    {
         if(buffer[i] == '='){
             num_var++ ;
             index_arr_num = num_var;  // Incase new variablr
             for(int s=0; s<i; s++){
             local_var_name[num_var][s]=buffer[s]; 
             }
             for(int j=0; j<num_var; j++) // loop if it not new variable 
             { 
              
                if( !strcmp( local_var_name[j], local_var_name[num_var] ) ) // if it variable already exist
                {
                  num_var--;
                  index_arr_num = j ;
                  break;
                }
             }
             for(int m=i+1, num=0; buffer[m] != '\0'; m++,num++){
             local_var_val[index_arr_num][num]=buffer[m]; 
             }
             flag = 1;
             break;
         }
         
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
  return flag;  

}
/**********************************************************************************************/
void myfork(char argv[5][20], int row){

    char *argvp[5] = {NULL} ; // Max argument 4
    int ret_pid=0, stat;
    
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

/*************************************************************************************************/
int message( char buffer[] ){

              
            printf("%s",setcolor[Green]);    //Set color green
            printf("How Can I Help You");
            printf("%s",setcolor[Red]);      //Then,set color Res
            printf(" $");
            printf("%s",setcolor[White]);    //Set color white
            fgets(buffer,100,stdin);
            // remove last char (ASCI code of (enter button) )
            int len = strlen(buffer) ;
            buffer[len -1]='\0' ;
            len--;
            return (len);

}
