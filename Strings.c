#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "Strings.h"
#include <unistd.h>

#define succes 1
#define failure 0

/*
void
StringsGetStr (char *str, int size)
{
  printf (">>>> ");
  fgets (str, size, stdin);

  int len = strlen (str) - 1;
  if (str[len] == '\n')
    str[len] = '\0';
  else
    printf ("No replacement in the string\n");

}
*/
unsigned char
StringsFindCommand (char *str, char command[])
{
  char *new_str = (char *) malloc (sizeof (char) * 100);
  strcpy (new_str, str);
  char *position = strtok (new_str, " ");
  if (strcmp (position, command) == 0)
    {
      free (new_str);
      new_str = NULL;
      return 0;
    }
  else
    {
      free (new_str);
      new_str = NULL;
      return 1;
    }
}


void
StringsFindWords (char *str, char command[])
{
  char *new_str = (char *) malloc (sizeof (char) * 1000);
  char *position;
  strcpy (new_str, str);
  position = strstr (new_str, command);

  if (position != NULL)
    {
      position += strlen (command);
      for (int i = 0; *position == ' '; i++)
	position++;
      strcpy (str, position);
      free (new_str);
      new_str = NULL;
    }
  else
    {
      free (new_str);
      new_str = NULL;
      printf ("Something Wrong\n");
    }
}

void
StringsCommand (char *str, char *position)
{
  char *new_str = (char *) malloc (sizeof (char) * 100);
  strcpy (new_str, str);
  char *token = strtok (new_str, " ");
  strcpy (position, token);
  free (new_str);
  new_str = NULL;
}



void
StringsDynamicsGetStr (char **str, size_t n)
{
  printf (">>>> ");
  *str = (char *) malloc (sizeof (char) * 100);
  /* if (*str == NULL)
     {
     fprintf(stderr, "Memory allocation failed\n");
     return failure; 
     } */
  int size = getline (str, &n, stdin);
  if ((*str)[strlen (*str) - 1] == '\n')
    {
      (*str)[strlen (*str) - 1] = '\0';
      // return succes;
    }
  else
    printf ("failed");
  // return failure;
}
