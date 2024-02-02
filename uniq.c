#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printLines(FILE *fp){
	char *currentLine = NULL;
	char *lastLine = NULL;
	size_t linesize = 0;
	ssize_t lineread = 0;

	while ((lineread = getline(&currentLine, &linesize, fp)) != -1){
		if (lastLine == NULL || strcmp(currentLine, lastLine) != 0){
			printf("%s", currentLine);
		}
		char *temp = lastLine;	//swap the pointers of the last and current lines
                lastLine = currentLine;
		currentLine = temp;
	}
	:free(lastLine);
	free(currentLine);
}

int main(int argc, char *argv[]){
	FILE *fp;
	if (argc == 2){
		fp = fopen(argv[1], "r");
		if (fp == NULL){
			printf("File not Found\n");
			return 1;	
		}
	} else {
		fp = stdin;
	}
	
	printLines(fp);
	
	if (fp != stdin){
		fclose(fp);
	}	
	return 0;
}
