#include <stdio.h>
#include "dbg.h"
#include <dlfcn.h>

typedef int (*lib_function) (const char *data);

int main(int argc, char *argv[])
{
	int rc = 0;
	check(argc == 4, "USAGE: ex29 libex29.so function data \n");

	char *lib_file = argv[1];
	char *func_to_run = argv[2];
	char *data = argv[3];

	void *lib = dlopen(lib_file, RTLD_NOW);
	check(lib != NULL, "Failed to open the library %s: %s \n",lib_file,dlerror());


	lib_function func = dlsym(lib, func_to_run);
	check(func != NULL, "Did not find %s funcition in the library %s :%s \n",lib_file,dlerror());
	rc = func(data);
	check(rc == 0, "Function %s reurn %d for data: %s \n", func_to_run,rc,data);
	if (rc == 0){
		printf("Function %s reurn %d for data: %s \n", func_to_run,rc,data);
	}
	rc = dlclose(lib);
	check(rc == 0, "Faled to close %s \n",lib_file);
	/*
	 * if (rc == 0){
		printf("Faled to close %s",lib_file);
	}
	*/
	return 0;

error:
	return 1;
}
