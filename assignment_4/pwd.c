#include <unistd.h>
#include <stdio.h>

int main()
{
    char buf[200];
    char * return_val = getcwd(buf,200);
    printf("%s\n",return_val);



  return 0;
}
