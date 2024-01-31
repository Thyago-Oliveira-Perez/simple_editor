#include <stdio.h>

void read_file(char *file_location)
{
  FILE *file = fopen(file_location, "r");
  char buffer[1024] = {0};
  fread(buffer, 1024, 1, file);
  fclose(file);
  printf("Content:\n%s\n", buffer);
}

void main(int argc, char **argv)
{
  char *file_location = argv[1];
  read_file(file_location);
}
