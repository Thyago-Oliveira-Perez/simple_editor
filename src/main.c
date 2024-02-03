#include <stdio.h>
#include "../include/functions.h"

#define READ_FILE 1
#define EDIT_FILE 2
#define APPEND_FILE 3
#define EXIT 0

int main(int argc, char **argv)
{
  char *file_location = argv[1];

  int option = menu();

  switch (option)
  {
  case READ_FILE:
    read_file(file_location);
    break;

  case EXIT:
    return 0;
    break;

  default:
    printf("Invalid option\n");
    break;
  }

  return 0;
}
