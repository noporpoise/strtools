/*
 strlen.c
 project: strlen
 url: http://sourceforge.net/projects/strlen/
 author: Isaac Turner <turner.isaac@gmail.com>
 Copyright (C) 27-Jan-2012

 build: gcc -o strlen -Wall strlen.c

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
  if(argc == 2 &&
     (strcasecmp(argv[1], "-h") == 0 || strcasecmp(argv[1], "--h") == 0 ||
      strcasecmp(argv[1], "-help") == 0 || strcasecmp(argv[1], "--help") == 0))
  {
    printf("usage: strlen [string1 ..]\n");
    printf(
"  Prints length of strings, one per line.  If args not given reads from STDIN\n"
"  and prints the length of each line.\n");
    exit(EXIT_FAILURE);
  }

  if(argc == 1)
  {
    // Read from STDIN
    int old_c = EOF, c = getchar();
    unsigned long length = 0;

    while(c != EOF)
    {
      if(c == '\n' || c == '\r')
      {
        if(old_c == '\r' && c == '\n')
        {
          // Character read in was part of previous end-of-line
        }
        else
        {
          printf("%lu\n", length);
          length = 0;
        }
      }
      else
      {
        length++;
      }

      old_c = c;
      c = getchar();
    }

    if(old_c != '\n' && old_c != '\r')
    {
      printf("%lu\n", length);
    }
  }
  else
  {
    int i;
    for(i = 1; i < argc; i++)
    {
      printf("%lu\n", (unsigned long)strlen(argv[i]));
    }
  }

  return EXIT_SUCCESS;
}
