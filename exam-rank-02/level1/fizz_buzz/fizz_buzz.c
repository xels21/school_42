
/*
Assignment name  : fizzbuzz
Expected files   : fizzbuzz.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that prints the numbers from 1 to 100, each separated by a
newline.

If the number is a multiple of 3, it prints 'fizz' instead.

If the number is a multiple of 5, it prints 'buzz' instead.

If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead.

Example:

$>./fizzbuzz
1
2
fizz
4
buzz
fizz
7
8
fizz
buzz
11
fizz
13
14
fizzbuzz
[...]
97
98
fizz
buzz
$>
*/

#include <unistd.h>
#include "../../utils/utils.h" ///< for itoa

int main(int argc, char **argv)
{
  int foundOne = 0;
  for (int i = 1; i <= 100; i++)
  {
    foundOne = 0;
    if (i % 3 == 0)
    {
      write(1, "fizz", 4);
      foundOne = 1;
    }
    if (i % 5 == 0)
    {
      write(1, "buzz", 4);
      foundOne = 1;
    }

    if (!foundOne)
    {
      char snum[5];
      int len = itoa(i, snum, 10);
      write(1, snum, len);
    }

    write(1, "\n", 1);
  }
  return (0);
}