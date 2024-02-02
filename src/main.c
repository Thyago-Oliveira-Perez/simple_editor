#include <stdio.h>
#include "../include/functions.h"

int main(int argc, char **argv)
{
  char *file_location = argv[1];

  int option = menu();

  if (option == 0)
  {
    return 0;
  }

  if (option == 1)
  {
    read_file(file_location);
  }

  return 0;
}
