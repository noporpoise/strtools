/*
 strlen.c
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

// CMP_FUNC is either strcmp or strcasecmp

// stringification with macro expansion...
// http://stackoverflow.com/a/2653351/431087
#define xstr(a) str(a)
#define str(a) #a

int main(int argc, char* argv[])
{
  if(argc != 3)
  {
    printf("usage: " xstr(CMP_FUNC) " <string1> <string2>\n");
    exit(EXIT_FAILURE);
  }

  // Turn off buffering
  setbuf(stdout, NULL);

  printf("%i\n", CMP_FUNC(argv[1], argv[2]));

  return EXIT_SUCCESS;
}
