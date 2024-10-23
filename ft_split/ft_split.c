/**
Function name:
ft_split

Prototype:
char ** ft_split(char const *s, char c);

Turn in files:
-

Parameters:
s: The string to be split.
c: The delimiter character.

Return value:
The array of new strings resulting from the split.
NULL if the allocation fails.

External functs:
malloc, free

Description
Allocates (with malloc(3)) and returns an array
of strings obtained by splitting 's' using the
character 'c' as a delimiter. The array must end
with a NULL pointer.
**/
#include <stdio.h>
#include <stdlib.h>

// returns nothing but manipulaties dest, bc im lazy :p
// ATTENTION: really unsafe implementaton
char *my_strncpy(char *dest, const char *src, size_t count)
{
  int i = 0;
  while (i < count)
  {
    dest[i] = src[i];
    i++;
  }
  return NULL; // is wrong
}

#define DEBUG 1
// #define DEBUG 0

char **my_ft_split(char const *s, char c)
{
  if(DEBUG){
    printf("\ns: '%s', c: '%c' - ", s, c);
  }

  int i = 0;
  int split_count = 0;
  char **splitted;
  if (s == NULL)
  {
    return NULL;
  }

  while (s[i])
  {
    if (s[i] == c)
    {
      split_count++;
    }
    i++;
  }

  //+1 because "1 split means 2 strings"
  splitted = malloc(sizeof(char *) * (split_count + 1));
  if (splitted == NULL)
  {
    return NULL;
  }

  int start = 0;
  int split_index = 0;
  i=0;
  while (1)
  {
    if (!s[i] || s[i] == c)
    {
      char * single = malloc(sizeof(char) * (i - start + 1));
      if (single == NULL)
      {
        return NULL;
      }
      my_strncpy(single, s + start, i - start);
      single[i-start] = '\0';
      splitted[split_index++] = single;
      start = i + 1;
      if(!s[i]){
        break;
      }
    }
    i++;
  }

  return splitted;
}

int main()
{
  char **splitted;
  printf("START\n");
  
  splitted = my_ft_split("", '_');
  printf("%s", splitted[0]);

  splitted = my_ft_split("foo_bar", '_');
  printf("%s, %s", splitted[0], splitted[1]);

  splitted = my_ft_split("foo__bar", '_');
  printf("%s, %s, %s", splitted[0], splitted[1], splitted[2]);

  splitted = my_ft_split("foo_bar_", '_');
  printf("%s, %s, %s", splitted[0], splitted[1], splitted[2]);

  printf("\n\nEND");
}