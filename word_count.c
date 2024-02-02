#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

void count(FILE *fp, int *countWord, int *countLine, int *countChar){	//function that updates the word count, char count, and line count
	char ch;		//variable that represents each character
	int spaces = 1;		//variable to help keep track of spaces
	
	while((ch = fgetc(fp)) != EOF){ //while loop that gets every character in the file until it reaches EOF
		(*countChar)++;		//everytime it loops it adds 1 to the character count
		if (ch == '\n'){	//if statement checking for \n and adds 1 to line count
			(*countLine)++;
			spaces = 1;
		} else if (ch == ' '){	//another if statement checking if the char is a space
			spaces = 1;
		} else {
			if (spaces){	//if it detected that the char is a space, then add 1 to word count
				(*countWord)++;
				spaces = 0;
			}
		}
	}
	if (ch != '\n' && ch != EOF && *countChar > 0){	//if statement at end of file to check the last line
		(*countLine)++;
	}
}

int main(int argc, char *argv[]){
	FILE *fp;		//variable for file pointer
	if (argc == 2){		//if statement checking if we have entered a file with a.out
		fp = fopen(argv[1], "r");
        	if (fp == NULL){	//checking if file exists
                 	printf("File not Found");
                	return 1;
        	}
	} else {		//else use stdin if no argument entered with a.out
		fp = stdin;
	}
	
	int numWords = 0;	//3 integer variables that I enter as parameters into count so that they hold the number of words, lines, and chars
	int numLines = 0;
	int numChars = 0;
	count(fp, &numWords, &numLines, &numChars);	//call my function count where the variables should correctly be updated to the correct number amounts
	
	printf("Number of Lines: %d\n", numLines);	//print the values of each variable
	printf("Number of Words: %d\n", numWords);
	printf("Number of Characters: %d\n", numChars);

	if (fp != stdin){				//check if we were using a file, and close it
		fclose(fp);
	}
	return 0;
}
