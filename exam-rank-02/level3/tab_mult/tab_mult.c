/*
https://42-cursus.gitbook.io/guide/exams/exam-rank-02/level-3/tab_mult

Assignment name  : tab_mult
Expected files   : tab_mult.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays a number's multiplication table.

The parameter will always be a strictly positive number that fits in an int,
and said number times 9 will also fit in an int.

If there are no parameters, the program displays \n.

Examples:

$>./tab_mult 9
1 x 9 = 9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81
$>./tab_mult 19
1 x 19 = 19
2 x 19 = 38
3 x 19 = 57
4 x 19 = 76
5 x 19 = 95
6 x 19 = 114
7 x 19 = 133
8 x 19 = 152
9 x 19 = 171
$>
$>./tab_mult | cat -e
$
$>
*/

#include <unistd.h>
#include "../../utils/utils.h" ///< for atoi

void tab_mult(int value)
{
  char buffer[50];
  char valueAsString[50];
  int result;
  int len;
  int valueLen = itoa(value, valueAsString, 10);

  for (int i = 1; i <= 9; i++)
  {
    // could be just single char parse. but this is logic can be expanded (like i<=99)
    len = itoa(i, buffer, 10);

    write(1, buffer, len);
    write(1, " x ", 3);
    write(1, valueAsString, valueLen);
    write(1, " = ", 3);

    result = i * value;
    len = itoa(result, buffer, 10);
    write(1, buffer, len);
    write(1, "\n", 1);
  }
}

int main(int argc, char const *argv[])
{
  if (argc == 2)
  {
    int num = atoi(argv[1]);
    tab_mult(num);
  }
  else
  {
    write(1, "\n", 1);
  }
  return 0;
}
