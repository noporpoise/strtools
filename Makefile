ifndef CC
	CC=gcc
endif

CFLAGS = -O3 -Wall -Wextra

all:
	$(CC) -o strrev $(CFLAGS) strrev.c
	$(CC) -o strlen $(CFLAGS) strlen.c
	$(CC) -o strcmp $(CFLAGS) -DCMP_FUNC=strcmp strcmp.c
	$(CC) -o strcasecmp $(CFLAGS) -DCMP_FUNC=strcasecmp strcmp.c
	$(CC) -o char2ascii $(CFLAGS) char2ascii.c
	$(CC) -o ascii2char $(CFLAGS) ascii2char.c
	$(CC) -o uc $(CFLAGS) change_case.c
	$(CC) -o lc $(CFLAGS) -DLOWER_CASE=1 change_case.c

clean:
	rm -f strrev strlen strcmp strcasecmp uc lc char2ascii ascii2char
