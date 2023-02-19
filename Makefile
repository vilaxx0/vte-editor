all: clean build

clean:
	rm -f vte

build: main.c
	$(CC) main.c ./source_files/raw_mode.c -o vte -Wall -Wextra -pedantic -std=c99
