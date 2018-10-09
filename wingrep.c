#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dbg.h"

#define BUFF_SIZE 1024


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
	//Get the size of the file
	fseek(file,0,SEEK_END);
	int size = ftell(file);
	int read_chunk = size;

	debug("Size of file : %d",size);
	//Go to the begning of file
	rewind(file);
	if (size < BUFF_SIZE)
		read_chunk = BUFF_SIZE;

	char *buf = malloc(read_chunk);
	size_t nread;

	while((nread = fread(buf,1,sizeof(buf),file)) > 0){
		printf("%s",buf);
	}
	free(buf);
	fclose(file);


error:
	return 1;	
}

int main(int argc , char *argv[])
{
	read_and_find_string(NULL, NULL);
	read_and_find_string("wingrep.c", NULL);
	read_and_find_string(NULL,"dbg.h");
	read_and_find_string("wingrep.c","dbg.h");
	read_and_find_string("ex19.c","dbg.h");
}