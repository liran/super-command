all: main

main: super.c
	gcc super.c -o super

clean:
	rm -f super *.o 