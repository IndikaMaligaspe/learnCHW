#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dbg.h"

#define BUFF_SIZE 200
char * getline(char **line , FILE *stream);


// struct FileList{
// 	char *filename;
// 	char *matches[];
// 	int isFound;

// };

// struct file{
// 	File *FILE;
// 	struct FileList *file_list;
// };



int read_and_find_string(char *file_name, char *find_what)
{
	check((file_name != NULL), "File name can not be empty");
	check((find_what != NULL), "Empty String to search");
	FILE *file = fopen(file_name,"r");
	check(file,"File not found!");
	char *line= NULL;
    size_t len = 0;
    // char *read ;
	//Get the size of the file
	
	while((line = getline(&line ,file)) != NULL){
		printf("%s",line);
	}

	fclose(file);
	if(line)
		free(line);


error:
	return 1;	
}


char * getline(char **line , FILE *stream)
{
	int c = fgetc(stream);
	char buffer[1];
	if (stream == '\0')
		return NULL;

	if (c == EOF)
		return NULL;
    line = malloc(sizeof(char));
	while( c != EOF){
		c = fgetc(stream);
		if (c == '\0')
			return NULL;
		buffer[0] = c;
		int size  = (strlen(*line) + 8);
		line = realloc(*line,size);
		strcat(*line,buffer);
		if (c == '\n')
			return *line;
	}
	return *line;
}

int main(int argc , char *argv[])
{
	read_and_find_string(NULL, NULL);
	read_and_find_string("wingrep.c", NULL);
	read_and_find_string(NULL,"dbg.h");
	read_and_find_string("wingrep.c","dbg.h");
	// read_and_find_string("ex19.c","dbg.h");
}