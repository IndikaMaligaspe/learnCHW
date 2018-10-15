#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dbg.h"

#define BUFF_SIZE 256
int getline(char **line , FILE *stream);



int read_and_find_string(char *file_name, char *find_what)
{
	check((file_name != NULL), "File name can not be empty");
	check((find_what != NULL), "Empty String to search");
	FILE *file = fopen(file_name,"r");
	check(file,"File not found!");
	char *line= NULL;
    int len = 0;
    // char *read ;
	//Get the size of the file
	line = malloc(BUFF_SIZE);
	while((len = getline(&line ,file)) != -1){
		printf("%s",line);
		fseek(file,len,0);
	}

	fclose(file);
	if(line)
		free(line);


error:
	return 1;	
}


int getline(char **line , FILE *stream)
{
  char *_line = NULL;
  char c;
  if (stream==NULL)
  	return -1;
  c = fgetc(stream);
  if (c=='\0')
  	return -1;
  if (c == '\n')
  	return -1;
  if (c == EOF)
  	return -1;

  int buf_size = 0;	 
  char buffer[1];	
  _line = malloc(BUFF_SIZE);
  while (c != EOF){
  	buffer[0] = (char) c;
    strcpy(_line,buffer);
    buf_size++;
    if (c == '\n'){
    	printf("************************\n");
    	printf("%s", _line);
    	return -1;
    }
    	

    c = fgetc(stream);
  }
  return -1;
}

int main(int argc , char *argv[])
{
	read_and_find_string(NULL, NULL);
	read_and_find_string("wingrep.c", NULL);
	read_and_find_string(NULL,"dbg.h");
	read_and_find_string("wingrep.c","dbg.h");
	// read_and_find_string("ex19.c","dbg.h");
}