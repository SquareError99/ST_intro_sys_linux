#include <stdio.h>


int
main (int argc, char *argv[])
{
  int i;
  if (argc <= 1)
    {
      printf ("Usage: %s src dest\n", argv[0]);
      return -1;
    }
  else
    {
      for (i = 1; i < argc; i++)
	printf ("%s ", argv[i]);
    }
  printf ("\n");
  return 0;



}
