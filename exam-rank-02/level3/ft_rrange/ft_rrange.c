/*
https://42-cursus.gitbook.io/guide/exams/exam-rank-02/level-3/ft_rrange
Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.
*/

#include <unistd.h> ///< for write
#include <stdlib.h> ///< for malloc
#include <stdio.h>  ///< for printf

int *ft_rrange(int start, int end)
{
  int temp;
  int length;

  if (start > end)
  {
    temp = start;
    start = end;
    end = temp;
  }

  length = end - start + 1;

  int *arr = (int *)malloc(sizeof(int) * length);
  if (!arr)
    return NULL;

  for (int i = 0; i < length; i++)
  {
    arr[i] = end - i;
  }
  return arr;
}

void print_array(int *arr, int len)
{
  for (int i = 0; i < len; i++)
  {
    printf("%d", arr[i]);
    if (i < len - 1)
      printf(", ");
  }
  printf("\n");
}

int main(void)
{
  int *arr;
  int len;

  // Test 1: (1, 3) => 3, 2, 1
  arr = ft_rrange(1, 3);
  len = 3;
  printf("ft_rrange(1, 3): ");
  print_array(arr, len);
  free(arr);

  // Test 2: (-1, 2) => 2, 1, 0, -1
  arr = ft_rrange(-1, 2);
  len = 4;
  printf("ft_rrange(-1, 2): ");
  print_array(arr, len);
  free(arr);

  // Test 3: (0, 0) => 0
  arr = ft_rrange(0, 0);
  len = 1;
  printf("ft_rrange(0, 0): ");
  print_array(arr, len);
  free(arr);

  // Test 4: (0, -3) => -3, -2, -1, 0
  arr = ft_rrange(0, -3);
  len = 4;
  printf("ft_rrange(0, -3): ");
  print_array(arr, len);
  free(arr);

  return 0;
}
