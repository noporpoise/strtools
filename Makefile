all:
	gcc -o strlen -Wall strlen.c
	gcc -o uc -Wall change_case.c
	gcc -o lc -Wall -DLOWER_CASE=1 change_case.c

clean:
	rm strlen uc lc
