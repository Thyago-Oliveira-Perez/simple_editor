#include "../../include/functions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

void clear_screen()
{
  system(CLEAR_SCREEN);
}

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

void see_file_content(char *buffer, char *file_location)
{
  while (1)
  {
    clear_screen();
    read_file(buffer, file_location);
    char option;
    printf("0. Back to menu\n");
    printf(":");
    scanf("%c", &option);
    if (option == '0')
    {
      clear_screen();
      break;
    }
    else
    {
      printf("Invalid option\n");
    }
  }
}

void read_file(char *buffer, char *file_location)
{
  FILE *file = fopen(file_location, "r");
  fread(buffer, 1024, 1, file);
  fclose(file);
  printf("Content:\n%s\n", buffer);
}

void edit_line(char *buffer, int current_line)
{
  for (int i = 0; i < current_line; i++)
  {
    buffer = strchr(buffer, '\n') + 1;
  }

  char *line_end = strchr(buffer, '\n');
  char saved[1024] = {0};
  strcpy(saved, line_end);
  scanf("%s", buffer);
  strcpy(buffer + strlen(buffer), saved);
}

void edit_file(char *buffer, char *file_location)
{
  FILE *file;
  int current_line = 0;

  read_file(buffer, file_location);

  printf("Which line do you want to edit?: ");
  scanf("%d", &current_line);

  edit_line(buffer, current_line);
  file = fopen(file_location, "w");
  fwrite(buffer, strlen(buffer), 1, file);
  fclose(file);
}