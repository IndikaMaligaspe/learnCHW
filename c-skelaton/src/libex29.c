#include <stdio.h>
#include <ctype.h>
#include "dbg.h"

int print_a_message(const char *msg)
{
	printf("A STRING %s\n", msg);
	return 0;
}

int uppercase(const char *msg)
{
	int i = 0;
        long len = strlen(msg);
	// BUG:\0 termination problem fixed
	for(i = 0; i < len; i++){
		printf("%c", toupper(msg[i]));
	}
	printf("\n");

	return 0;
}

int lowercase(const char *msg)
{
	int i = 0;
        long len = strlen(msg);
	// BUG: \0 termination problems fixed
	for(i = 0; i < len ; i++){
		printf("%c",tolower(msg[i]));
	}

	printf("\n");
	return 0;
}

int fail_on_purpose(const char *msg)
{
	return 1;
}

