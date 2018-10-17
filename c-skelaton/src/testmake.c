#include <stdio.h>
#include "dbg.h"

int main(int argc, char *argv[])
{
	char *name = "Indika";

	printf("Hello World !!!");

	debug("Hello world from %s",name);
	error:
		return 1;
}
