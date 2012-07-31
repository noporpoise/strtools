CFLAGS = -O3 -Wall -Wextra

all:
	gcc -o strlen $(CFLAGS) strlen.c
	gcc -o strcmp $(CFLAGS) strcmp.c
	gcc -o char2ascii $(CFLAGS) char2ascii.c
	gcc -o ascii2char $(CFLAGS) ascii2char.c
	gcc -o uc $(CFLAGS) change_case.c
	gcc -o lc $(CFLAGS) -DLOWER_CASE=1 change_case.c

clean:
	rm -f strlen strcmp uc lc char2ascii ascii2char
