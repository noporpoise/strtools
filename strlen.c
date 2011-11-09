// gcc -o strlen -Wall strlen.c

#include <stdio.h>
#include <strings.h>
#include <string.h>

int main(int argc, char* argv[])
{
  if(argc == 1 && (strcmp(argv[0],"-h") == 0 || strcmp(argv[0],"-H") == 0))
  {
    printf("usage: strlen <string>\n");
    printf("Prints length of a string (if <str> not given read from stdin)\n");
    return -1;
  }

  if(argc == 1)
  {
    // Read from STDIN
    int c;
    int length = 0;

    while((c = getchar()) != EOF)
    {
      if(c == '\n' || c == '\r') {
        printf("%i\n", length);
        length = 0;
      }
      else {
        length++;
      }
    }

    if(c == '\n' || c == '\r') {
      printf("%i\n", length);
    }
  }
  else
  {
    int i;
    for(i = 1; i < argc; i++)
    {
      printf("%i\n", (int)strlen(argv[i]));
    }
  }
  
  return 0;
}
