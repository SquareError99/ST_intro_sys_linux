#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include "Strings.h"
#include <unistd.h>

int
main ()
{
  char str[50];

  while (1)
    {
      StringsGetStr (str, 50);
      if (StringsFindCommand (str, 20, "exit") == 0)
	break;
      else if (StringsFindCommand (str, 20, "pwd") == 0)
	{
	  char dir[100];
	  char *Current_dir = getcwd (dir, 100);
	  printf ("%s \n", Current_dir);
	}
      else if (StringsFindCommand (str, 20, "echo") == 0)
	{
	  StringsFindWords (str, 50, "echo");
	  printf ("%s\n", str);
	}
      else if (StringsFindCommand (str, 20, "cd") == 0)
	{
	  StringsFindWords (str, 50, "cd");
	  if (chdir (str) == 0)
	    {
	      continue;
	    }
	  else
	    {
	      printf ("cd: %s: No such file or directory\n", str);
	    }
	}
      else
	{
	  printf ("command '%s' not found\n", str);
	}
    }
  printf ("Good Bye:)\n");
  return 0;
}
