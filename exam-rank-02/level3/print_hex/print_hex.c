/*
https://42-cursus.gitbook.io/guide/exams/exam-rank-02/level-3/print_hex

Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$
*/

#include "../../utils/utils.h" ///< for stringLength
#include <unistd.h>            ///< for write

char digToHex(int dig)
{
  if (dig >= 0 && dig <= 9)
    return '0' + dig;
  if (dig >= 10 && dig <= 15)
    return 'a' + (dig - 10);
  return '0';
}

void print_hex(int nb)
{
  nb = (nb < 0) ? 0 : nb;
  char hexStr[20];
  int len = 0;
  if (nb == 0)
  {
    hexStr[len++] = '0';
  }
  else
  {
    while (nb > 0)
    {
      int dig = nb % 16;
      hexStr[len++] = digToHex(dig);
      nb /= 16;
    }
  }
  hexStr[len] = '\0';
  reverseString(hexStr);
  write(1, hexStr, len);
}

void print_hex_recursive(int nb)
{
    char *hex = "0123456789abcdef";
    if (nb >= 16)
        print_hex_recursive(nb / 16);
    char c = hex[nb % 16];
    write(1, &c, 1);
}

int main(int argc, char const *argv[])
{
  if (argc == 2)
  {
    print_hex(atoi(argv[1]));
  }
  write(1, "\n", 1);
  return 0;
}
