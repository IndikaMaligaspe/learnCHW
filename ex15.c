#include <stdio.h>

int main(int argc , char *argv[])
{
	//create two arrays we care about
	int *ages = (int[]){23,43,12,89,2};
	char *names[] = {
		"Alan","Frank",
		"Mary","John","Lisa"
	};
	//safely get the size of ages
	//int count = sizeof(ages) / sizeof(int);
	int i =0;
        int count = 5;
	//first print using indexing
	//for (i = 0; i < count; i++){
	//	printf("%s has %d been years alive. \n",names[i],ages[i]);
	//}

	while(ages != '\0'){
		printf("%s has lived %d years. \n",names[i],*ages);
		ages++;
		i++;
	}
	count = i;
	// set up the pointers to the start of the array
	int **cur_age = &ages;
	char **cur_name = names;

	//second way using pointers
	printf("\n\n");
	printf("with pointers way 1 *(pointer +i).\n");
	for (i = 0; i <count; i++){
		printf("%s is %d years old. \n",*(cur_name +i), **cur_age+i);
	}
	printf("\n\n");

	printf("with pointers way 2 as arrays pointer[i].\n");
	//third way, pointers are just arrays
	for (i = 0; i < count; i++){
		printf("%s is %d years old again. \n",cur_name[i],*cur_age[i]);
	}
	printf("\n\n");
	printf("with pointers way 3 as *pointer).\n");
	// fourth way with pointers in a stupid complex way
	/*     
	for (cur_name = names, cur_age = ages; 
		(cur_age -ages) < count; cur_name++, cur_age++) {
		printf("%s lived %d years so far. \n", *cur_name, *cur_age);	
	}
	*/	
	return 0;
}
