#include "utils.h"

int stringLength(char *str)
{
  int len = 0;
  while (str[len] != '\0')
  {
    len++;
  }
  return len;
}

int reverseString(char *str)
{
  int len = stringLength(str);
  for (int i = 0; i < len / 2; i++)
  {
    char tmp = str[i];
    str[i] = str[len - 1 - i];
    str[len - 1 - i] = tmp;
  }
  return len;
}

int reverseStringWOffset(char *str, int offset)
{
  return reverseString(str + offset) + offset;
}


int itoa(int value, char *str, int base)
{
  int len = 0;
  int tempSingleDigit = 0;
  int negOffset = 0;
  // handle 0 explicitely, otherwise empty string is printed for 0
  if (value == 0)
  {
    str[len++] = '0';
    str[len] = '\0';
    return len;
  }

  // handle negative numbers
  if ((value < 0))
  {
    str[len++] = '-';
    negOffset = 1;
    value = -value;
  }

  while (value > 0)
  {
    tempSingleDigit = value % base;
    if (tempSingleDigit > 9)
    {
      str[len++] = tempSingleDigit + 'a' - 10;
    }
    else
    {
      str[len++] = tempSingleDigit + '0';
    }
    value /= base;
  }

  str[len] = '\0';

  reverseStringWOffset(str, negOffset);

  return len;
}
