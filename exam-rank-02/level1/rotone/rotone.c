/*
Assignment name  : rotone
Expected files   : rotone.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the next one in alphabetical order.

'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.

The output will be followed by a \n.

If the number of arguments is not 1, the program displays \n.

Example:

$>./rotone "abc"
bcd
$>./rotone "Les stagiaires du staff ne sentent pas toujours tres bon." | cat -e
Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo.$
$>./rotone "AkjhZ zLKIJz , 23y " | cat -e
BlkiA aMLJKa , 23z $
$>./rotone | cat -e
$
$>
$>./rotone "" | cat -e
$
$>
*/

#include <unistd.h>

void rotone(const char *text)
{
  while (text && *text)
  {
    if ((*text >= 'a' && *text < 'z') || (*text >= 'A' && *text < 'Z'))
    {
      char temp = *text + 1;
      write(1, &temp, 1);
    }
    else if (*text == 'z')
    {
      write(1, "a", 1);
    }
    else if (*text == 'Z')
    {
      write(1, "A", 1);
    }
    else
    {
      write(1, text, 1);
    }
    text++;
  }
}

int main(int argc, char const *argv[])
{
  if (argc == 2)
  {
    rotone(argv[1]);
  }
  write(1, "\n", 1);
  return 0;
}
