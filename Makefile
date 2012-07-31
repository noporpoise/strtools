CFLAGS = -O3 -Wall -Wextra

all:
	gcc -o strlen $(CFLAGS) strlen.c
	gcc -o strcmp $(CFLAGS) strcmp.c
	gcc -o uc $(CFLAGS) change_case.c
	gcc -o lc $(CFLAGS) -DLOWER_CASE=1 change_case.c

clean:
	rm strlen uc lc
