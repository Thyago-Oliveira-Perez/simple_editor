#include "../../include/functions.h"
#include <stdio.h>

int menu()
{
  printf("Choose an option:\n");
  printf("1. Read file\n");
  printf("2. Edit file\n");
  printf("3. Append file\n");
  printf("0. Exit\n");
  printf(":");
  int option;
  scanf("%d", &option);
  return option;
}

void read_file(char *file_location)
{
  FILE *file = fopen(file_location, "r");
  char buffer[1024] = {0};
  fread(buffer, 1024, 1, file);
  fclose(file);
  printf("Content:\n%s\n", buffer);
}