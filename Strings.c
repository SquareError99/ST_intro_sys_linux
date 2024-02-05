#include<stdio.h>
#include "Strings.h"
#include <stdlib.h>
#include <string.h>


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

int
StringsFindCommand (char *str, int size, char command[])
{
  char new_str[size];
  strcpy (new_str, str);
  char *position = strtok (new_str, " ");
  if (strcmp (position, command) == 0)
    {
      return 0;
    }
  else
    return 1;

}


void
StringsFindWords (char *str, int size, char command[])
{

  char new_str[size];
  strcpy (new_str, str);
  char *position = strstr (new_str, command);
  if (position != NULL)
    {
      position += strlen (command) + 1;
      strcpy (str, position);
    }
  else
    printf ("Something Wrong\n");

}
