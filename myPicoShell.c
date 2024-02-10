#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "Strings.h"

//extern char **environ;

int
main ()
{
  char *str = NULL;
  size_t n = 0;
  while (1)
    {
      StringsDynamicsGetStr (&str, n);
      if (StringsFindCommand (str, "exit") == 0)
	break;
      else if (StringsFindCommand (str, "echo") == 0)
	{
	  StringsFindWords (str, "echo");
	  printf ("%s\n", str);
	}

      else if (StringsFindCommand (str, "pwd") == 0)
	{
	  char *current_dir = (char *) malloc (sizeof (char) * 1000);
	  current_dir = get_current_dir_name ();
	  printf ("%s \n", current_dir);
	  free (current_dir);
	  current_dir = NULL;
	}
      else
	{
	  pid_t returned_pid = fork ();
	  if (returned_pid > 0)
	    {
	      int wstatus;
	      wait (&wstatus);
	    }
	  else if (returned_pid == 0)
	    {
	      char *command_argv =  (char *) malloc (sizeof (char) * 100);
	      char *new_program_argv[] = { NULL };
	      char *new_program_envp[] = { NULL };
	      StringsCommand (str, command_argv);
	      printf("%s\n", str);
	      // execvp(command_argv, new_program_argv);
	      execve (command_argv, new_program_argv, new_program_envp);
	      printf ("I am not in the mode of execution. Exec failed\n");
		free (command_argv);
		command_argv = NULL;
	      return -1;
	    }
	  else
	    {
	      printf ("ERROR: I could not get a child\n");
	    }
	}
      free (str);
      str = NULL;
      n = 0;

    }
  printf ("Good Bye:)\n");
  return 0;
}
