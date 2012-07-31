/*
 char2ascii.c
 project: strtools
 url: http://sourceforge.net/projects/strlen/
 author: Isaac Turner <turner.isaac@gmail.com>
 Copyright (C) 27-Jan-2012

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

int main(int argc, char* argv[])
{
  if(argc < 2)
  {
    printf("usage: char2ascii <string1>\n");
    exit(EXIT_FAILURE);
  }

  // Turn off buffering
  setbuf(stdout, NULL);

  int i, j;
  for(i = 1; i < argc; i++)
  {
    for(j = 0; *(argv[i] + j) != '\0'; j++)
    {
      printf("%u\n", (unsigned int)*(argv[i] + j));
    }
  }

  return EXIT_SUCCESS;
}
