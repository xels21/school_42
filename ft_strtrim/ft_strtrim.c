#include <stdio.h>

char *my_copy(char *src)
{
  int len = strlen(src);
  char *res = (char *)malloc(sizeof(char) * len);
  int i = 0;
  while (i <= len)
  {
    res[i] = src[i];
    i++;
  }
  return res;
}

char *ft_strtrim(char *const s1, char *const set)
{
  if (s1 == NULL || set == NULL)
  {
    return NULL;
  }
  int s1_len = strlen(s1);
  int set_len = strlen(set);
  if (set_len > s1_len)
  {
    return my_copy(s1); // set longer that serach string -> cannot find
  }
  int found_prefix = 0;
  int found_postfix = 0;

  int i = 0;
  while (i < s1_len)
  {
    if (s1[i] != set[i])
    {
      break; // didn't found
    }
    if (i == set_len - 1)
    {
      found_prefix = 1;
      break;
    }
    i++;
  }
  i = s1_len - set_len;
  while (i < s1_len)
  {
    if (s1[i] != set[i])
    {
      break; // didn't found
    }
    if (i == set_len - 1)
    {
      found_postfix = 1;
      break;
    }
    i++;
  }

  if (found_prefix && found_postfix && s1_len == set_len)
  {
    char *res = malloc(sizeof(char) * 1);
    res[0] = '\0';
    return res; // can only happen when s1 == set
  }
  int i = 0;
  int res_len = s1_len;
  if (found_prefix)
  {
    res_len -= set_len;
    i = set_len;
  }
  if (found_postfix)
  {
    res_len -= set_len;
  }
  char *res = malloc(sizeof(char) * res_len);
  while (i < s1_len - (found_postfix * set_len))
  {
    
  }
}

int main()
{
  printf("Hello World");

  return 0;
}
