all: tracker

tracker: src/main.c src/listOfKeys.c src/readFromFile.c src/findAndReplace.c
	gcc -Iinclude src/main.c src/listOfKeys.c src/readFromFile.c src/findAndReplace.c -std=c99 -g -Wall -ansi -o a1 -I ../include -I ../assets
