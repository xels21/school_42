#include <stdio.h>
#include "utils.h"

int main(int argc, char **argv)
{
  // Test atoi
  char num[] = "-123";
  printf("atoi(\"-123\") = %d\n", atoi(num));

  // Test stringLength
  char str1[] = "hello";
  printf("stringLength(\"hello\") = %d\n", stringLength(str1));

  // Test reverseString
  char str2[] = "world";
  reverseString(str2);
  printf("reverseString(\"world\") = %s\n", str2);

  // Test reverseString
  char str3[] = "-123";
  reverseStringWOffset(str3, 1);
  printf("reverseStringWOffset(\"-123\", 1) = %s\n", str3);

  // Test itoa
  char buf[20];
  itoa(255, buf, 10);
  printf("itoa(255) = %s\n", buf);

  itoa(12345, buf, 10);
  printf("itoa(12345) = %s\n", buf);

  itoa(1111, buf, 10);
  printf("itoa(1111) = %s\n", buf);

  itoa(-12345, buf, 10);
  printf("itoa(-12345) = %s\n", buf);

  itoa(1337789, buf, 16);
  printf("itoa(1337789, 16) = %s\n", buf);

  itoa(0, buf, 10);
  printf("itoa(0) = %s\n", buf);

  return 0;
}
