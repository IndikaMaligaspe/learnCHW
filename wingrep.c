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
	if (size > BUFF_SIZE)
		read_chunk = BUFF_SIZE;

	char *buf = malloc(read_chunk);
	size_t nread;
	int i = 0;
	char *read_line = malloc(sizeof(buf));
	strcpy(read_line,"");
	while((nread = fread(buf,sizeof(buf),1,file)) > 0){
		i = i+1;
		debug("iteration - %d size of read_line - %d\n",i,sizeof(read_line) );
		if(buf[sizeof(buf)-1] == '\n'){
			debug("starting new line.... with iteration %d",i);
			int line_size = sizeof(read_line)+sizeof(buf)+1;
			debug("line size - %d ",line_size);
			char *line = malloc(line_size);
			debug("line allocated");
			strcpy(line,read_line);
			strcat(line,buf);
			printf(line);
			free(line);
			free(read_line);
			read_line = malloc(read_chunk);
		}else{
			debug("starting chunk...");
			read_line = realloc(read_line,(sizeof(buf)*i));
			debug("realoocation done... with size - %d",sizeof(read_line));
			strcat(read_line,buf);
		}	

	}

	free(buf);
	free(read_line);
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