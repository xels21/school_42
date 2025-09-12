
/*
Assignment name  : first_word
Expected files   : first_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its first word, followed by a
newline.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.

Examples:
```
$> ./first_word "FOR PONY" | cat -e
FOR$
$> ./first_word "this        ...    is sparta, then again, maybe    not" | cat -e
this$
$> ./first_word "   " | cat -e
$
$> ./first_word "a" "b" | cat -e
$
$> ./first_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
```
*/

#include <unistd.h>

void write_newline()
{
  write(1, "\n", 1);
}

int itoa(int value, char *str, int base)
{
  int len = 0;
  do
  {
    str[len++] = value % base + '0';
  } while (value /= base);
  str[len] = '\0';
  return len;
}

#define TRUE 1
#define FALSE 0

// int debug = TRUE;
int debug = FALSE;

int main(int argc, char **argv)
{
  char *str;

  if (debug)
  {
    char snum[5];
    int len = itoa(argc, snum, 10);
    write(1, "argc: ", 6);
    write(1, snum, len);
    write(1, "\n", 1);
  }

  // If the number of parameters is not 1 ... simply display a newline.
  if (argc != 2)
  {
    write(1, "\n", 1);
    return (1);
  }

  str = argv[1];

  // start string pointer after all spaaces and tabs
  while (*str == ' ' || *str == '\t')
  {
    str++;
  }
  // if no word is found, return newline
  if (*str == '\0')
  {
    write(1, "\n", 1);
    return (1);
  }
  while (*str != ' ' && *str != '\t' && *str != '\0')
  {
    write(1, str, 1);
    str++;
  }
  write(1, "\n", 1);
  return (0);
}