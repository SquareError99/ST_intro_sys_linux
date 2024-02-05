#include <stdio.h>
#include <unistd.h>



#define RET_STATUS 0


int
main ()
{
  char dir[100];
  char *Current_dir = getcwd (dir, 100);
/*  The getcwd() function copies an absolute pathname of the  current  working
       directory to the array pointed to by buf, which is of length size.*/
  printf ("%s\n", Current_dir);

  return RET_STATUS;

}
