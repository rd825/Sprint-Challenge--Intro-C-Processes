// necessary imports
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  struct dirent *name;
  struct stat buffer;
  char *path;
  char *filepath;
  DIR *directory;

  // PARSE COMMAND LINE:
  // check if user has inputted commands
  if (argc > 1)
  {
    // set path as user-inputted path
    path = argv[1];
  }
  else
  {
    // set path as current directory
    path = ".";
  }

  // OPEN DIRECTORY:
  // check for issues opening
  if ((directory = opendir(path)) == NULL)
  {
    printf("Directory could not be opened: %s\n", path);
    exit(1);
  }

  // REPEATEDLY READ AND PRINT ENTRIES:
  while ((name = readdir(directory)) != NULL)
  {
    // set the filepath as the previously set path + directory name
    // + 2 spaces for null pointer and /
    filepath = malloc(strlen(path) + strlen(name->d_name) + 2);

    // build filepath for stat
    // check if item name is "." or ".."
    if (strcmp(name->d_name, ".") != 0 && strcmp(name->d_name, "..") != 0)
    {
      sprintf(filepath, "%s/%s", path, name->d_name);
    }
    else
    {
      sprintf(filepath, "%s", name->d_name);
    }

    if (stat(filepath, &buffer) != -1)
    {
      // check if it's a dir, Windows return value for dir is 16895
      if (buffer.st_mode == 16895)
      {
        printf("  <DIR> %s\n", name->d_name);
      }
      else
      {
        printf("%10ld %s\n", buffer.st_size, name->d_name);
      }
    }

    free(filepath);
  }

  closedir(directory);
  return (0);
}