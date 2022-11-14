#include <dirent.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <inttypes.h>
/****************************************************/
  #define SOCKET          01100
  #define SYMBOLIC_LINK   01010
  #define REGULAR         4   //01000
  #define BLOCK           6  //00110
  #define DIRERCTOR       4  //00100
  #define CHARACHTER      2  //00010
  #define FIFO            1  //00001 
/****************************************************/

#if 0
           struct stat {
               dev_t     st_dev;         /* ID of device containing file */
               ino_t     st_ino;         /* Inode number */
               mode_t    st_mode;        /* File type and mode */
               nlink_t   st_nlink;       /* Number of hard links */
               uid_t     st_uid;         /* User ID of owner */
               gid_t     st_gid;         /* Group ID of owner */
               dev_t     st_rdev;        /* Device ID (if special file) */
               off_t     st_size;        /* Total size, in bytes */
               blksize_t st_blksize;     /* Block size for filesystem I/O */
               blkcnt_t  st_blocks;      /* Number of 512B blocks allocated */

               /* Since Linux 2.6, the kernel supports nanosecond
                  precision for the following timestamp fields.
                  For the details before Linux 2.6, see NOTES. */

               struct timespec st_atim;  /* Time of last access */  /* st_atim.tv_sec */
               struct timespec st_mtim;  /* Time of last modification */
               struct timespec st_ctim;  /* Time of last status change */

           #define st_atime st_atim.tv_sec      /* Backward compatibility */
           #define st_mtime st_mtim.tv_sec
           #define st_ctime st_ctim.tv_sec
           };
           
                    struct passwd {
               char   *pw_name;       /* username */
               char   *pw_passwd;     /* user password */
               uid_t   pw_uid;        /* user ID */
               gid_t   pw_gid;        /* group ID */
               char   *pw_gecos;      /* user information */
               char   *pw_dir;        /* home directory */
               char   *pw_shell;      /* shell program */
           };


	  struct group {
               char   *gr_name;        /* group name */
               char   *gr_passwd;      /* group password */
               gid_t   gr_gid;         /* group ID */
               char  **gr_mem;         /* NULL-terminated array of pointers
                                          to names of group members */
           };




#endif

 typedef struct {
    
       uint16_t other_x:1;
       uint16_t other_w:1;
       uint16_t other_r:1;
       
       uint16_t group_x:1;
       uint16_t group_w:1;
       uint16_t group_r:1;
       
       uint16_t user_x:1;
       uint16_t user_w:1;
       uint16_t user_r:1;
       
       uint16_t sticky:1;
       uint16_t guid:1;
       uint16_t suid:1;
       
       uint16_t typefile:4;
    
  }mymode_t;

typedef union{

    uint16_t mode;
    mymode_t mode_bits;
    


}mode_u; 

int main(int argc, char *argv[] ){


		struct stat statbuf ;
		struct dirent * entityDir ;
		DIR * ptr=NULL;
		struct passwd *ptrInfo=NULL; // metadat for user/passward ......
		struct group *ptrgroupInfo=NULL; // information about user group.... 
		char *timeCal = NULL;
		mode_u mode_val = {0};
		
		ptr = opendir(argv[1]);
		chdir(argv[1]);
		
		while( (entityDir= readdir(ptr) ) != NULL){
		
		
		    //printf("%ld          %s \n",entityDir->d_ino, entityDir->d_name);
		    if (stat(entityDir->d_name, &statbuf) < 0 ){
		       
		       printf("stat failed\n");
		       return 0;
		    }
		    
		    mode_val.mode = statbuf.st_mode;
		    timeCal = ctime(&(statbuf.st_atim.tv_sec) );
		    ptrInfo = getpwuid(statbuf.st_uid);
		    ptrgroupInfo = getgrgid(statbuf.st_gid);
		    
		   
		 /*   
		    printf("%c%c%c",
		              (mode_val.mode_bits.typefile == DIRERCTOR)?'d':'-',
		               (mode_val.mode_bits.typefile == CHARACHTER)?'c':'-',
		                (mode_val.mode_bits.typefile == BLOCK)?'b':'-'
		              
		              
		              
		              
		              );
		    
		    */
		    
		    if(mode_val.mode_bits.typefile == DIRERCTOR)
		         printf("d");
		     else if(mode_val.mode_bits.typefile == REGULAR)  
		       printf("-");		         
		     else if(mode_val.mode_bits.typefile == CHARACHTER)  
		       printf("c");  
		     else if(mode_val.mode_bits.typefile == BLOCK)  
		       printf("b");  
		     else
		        printf("-"); 
		        
		    printf("%c%c%c%c%c%c%c%c%c",  
		    
		    			             (mode_val.mode_bits.user_r)?'r':'-',
						     (mode_val.mode_bits.user_w)?'w':'-',
						     (mode_val.mode_bits.user_x)?'x':'-',

						     
						     (mode_val.mode_bits.group_r)?'r':'-',
						     (mode_val.mode_bits.group_w)?'w':'-',
						     (mode_val.mode_bits.group_x)?'x':'-',
						     		    
		                                      (mode_val.mode_bits.other_r)?'r':'-',
						     (mode_val.mode_bits.other_w)?'w':'-',
						     (mode_val.mode_bits.other_x)?'x':'-'

		             );
		    
		    printf(" inode=%lu links=%lu user=%s group=%s size=%lu blocks=%lu %s %s",
		    statbuf.st_ino
		    ,statbuf.st_nlink,
		     ptrInfo->pw_name,
		     ptrgroupInfo->gr_name,
		      statbuf.st_size,
		       statbuf.st_blocks,
		       entityDir->d_name,
		       timeCal
		       
		       );
		
		
		}
		
                  closedir(ptr);


return 0;
}
