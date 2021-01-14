# Abenezer Gebeyehu
# project 2
# lab section 218
CFLAGS= -g -Wall -std=c89 -pedantic-errors
all: project2_agebeyeh_218.c readFile.c  strtok.c readFile2.c encode.c writeFile.c decode.c
	gcc -g -Wall -o project2_agebeyeh_218 project2_agebeyeh_218.c  readFile.c  strtok.c readFile2.c encode.c writeFile.c decode.c
clean:
	rm project2_agebeyeh_218