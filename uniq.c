#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printLines(FILE *fp){		//function that emulates the uniq functionality and prints the lines accordingly
	char *currentLine = NULL;	//pointer for current line
	char *lastLine = NULL;		//pointer for last or previous line
	size_t linesize = 0;		//variable representing linesize 
	ssize_t lineread = 0;		//variable representing the line to be read

	while ((lineread = getline(&currentLine, &linesize, fp)) != -1){	//loop that reads the lines using getline
		if (lastLine == NULL || strcmp(currentLine, lastLine) != 0){	//if statement checking if the previous line is null or if the last two lines are different
			printf("%s", currentLine);				
		}
		char *temp = lastLine;	//swap the pointers of the last and current lines
                lastLine = currentLine;
		currentLine = temp;
	}
	free(lastLine);			//free both pointers for current and last line
	free(currentLine);
}

int main(int argc, char *argv[]){	//main
	FILE *fp;			//file pointer variable
	if (argc == 2){			//checks if there is a input for a text file and opens
		fp = fopen(argv[1], "r");	
		if (fp == NULL){	//checks if file not found or if file pointer is null
			printf("File not Found\n");
			return 1;	
		}
	} else {			//else use stdin to run the function
		fp = stdin;
	}
	
	printLines(fp);			//run the function printLines to emulate uniq
	
	if (fp != stdin){		//checks if we were using a text file, if so then close
		fclose(fp);
	}	
	return 0;
}
