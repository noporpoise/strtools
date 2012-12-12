/*
 strrev.c
 project: strtools
 url: http://sourceforge.net/projects/strlen/
 author: Isaac Turner <turner.isaac@gmail.com>
 Copyright (C) 12-Dec-2012

 build: type 'make'

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
#include <ctype.h>

size_t buff_len = 512, len = 0;

// Warning: this buffer IS NOT NULL terminated
char *buff = NULL;

void flush_buffer()
{
  size_t i;
  for(i = len; i > 0; i--)
  {
    putc(buff[i-1], stdout);
  }
  putc('\n', stdout);

  len = 0;
}

void read_stdin()
{
  int c, prev_c = '\n';
  len = 0;

  if(buff == NULL)
  {
    buff = (char*)malloc(buff_len * sizeof(char));
  }

  while((c = getchar()) != EOF)
  {
    if(c == '\n' || c == '\r')
    {
      // Flush buffer
      flush_buffer();
    }
    else
    {
      // Check buffer size
      if(len >= buff_len)
      {
        buff_len *= 2;
        buff = realloc(buff, buff_len * sizeof(char));

        if(buff == NULL)
        {
          fprintf(stderr, "%s:%i: Out of memory\n", __FILE__, __LINE__);
          exit(EXIT_FAILURE);
        }
      }

      // Add to buffer
      buff[len++] = c;
    }
    prev_c = c;
  }

  if(prev_c != '\n' && prev_c != '\r')
  {
    // Flush buffer
    flush_buffer();
  }
}

int main(int argc, char* argv[])
{
  if(argc == 2 &&
     (strcasecmp(argv[1], "-h") == 0 || strcasecmp(argv[1], "--h") == 0 ||
      strcasecmp(argv[1], "-help") == 0 || strcasecmp(argv[1], "--help") == 0))
  {
    printf("usage: strrev [string1 ..]\n");
    printf(
"  Print string reversed.  If args not given reads from STDIN.\n");
    exit(EXIT_FAILURE);
  }

  // Turn off buffering
  setbuf(stdout, NULL);

  if(argc == 1)
  {
    // Read from STDIN
    read_stdin();
  }
  else
  {
    int i;
    size_t j;

    for(i = 1; i < argc; i++)
    {
      if(strcmp(argv[i], "-") == 0)
      {
        read_stdin();
      }
      else
      {
        size_t len = strlen(argv[i]);

        for(j = 0; j < len / 2; j++)
        {
          char tmp = argv[i][j];
          argv[i][j] = argv[i][len-1-j];
          argv[i][len-1-j] = tmp;
        }

        printf("%s\n", argv[i]);
      }
    }
  }

  if(buff != NULL)
  {
    free(buff);
  }

  return EXIT_SUCCESS;
}
