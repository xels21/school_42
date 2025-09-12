/*
Assignment name  : ft_strcpy
Expected files   : ft_strcpy.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:

char    *ft_strcpy(char *s1, char *s2);
*/

// https://42-cursus.gitbook.io/guide/exams/exam-rank-02/level-1/ft_strcpy

#include "../../utils/utils.h" ///< for stringLength
#include <unistd.h>            ///< for write

char *ft_strcpy(char *s1, char *s2)
{
  int i = 0;

  while (s2[i] != '\0')
  {
    s1[i] = s2[i];
    i++;
  }
  s1[i] = '\0';
  return s1;
}

int main(int argc, char const *argv[])
{
  char dst[] = "null";
  char src[] = "helooooo";
  // char* src = malloc(strlen(dst) + 1);
  ft_strcpy(dst, src);
  write(1, dst, stringLength(dst));
  return 0;
}
