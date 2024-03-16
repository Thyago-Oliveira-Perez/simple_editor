#include <stdio.h>
#include "../include/functions.h"

#define SEE_FILE_CONTENT 1
#define EDIT_FILE 2
#define APPEND_FILE 3
#define EXIT 0

int main(int argc, char **argv)
{
  char buffer[1024] = {0};
  char *file_location = argv[1];

  while (1)
  {
    int option = menu();

    switch (option)
    {
    case SEE_FILE_CONTENT:
      see_file_content(buffer, file_location);
      break;

    case EDIT_FILE:
      edit_file(buffer, file_location);
      break;

    case EXIT:
      return 0;
      break;

    default:
      printf("Invalid option\n");
      break;
    }
  }

  return 0;
}
