#include <stdio.h>

int main(int argc , char *argv[])
{
	int areas[] = {10,12,13,14,20};
	char name[] = "KIM";
	char full_name[] = { 'K','I','N','D','I','K','A','\0'};

	//WARNING: On some systems you may haveto change the 
	//%ld on this code to %u since it will use unsigned ints
	printf("The size of an int %ld\n",sizeof(int));
	printf("The size of areas(int[]): %ld\n",sizeof(areas));
	printf("The number of ints in the areas: %ld\n",sizeof(areas) / sizeof(int));
	printf("The first area is %d, the 2nd %d . \n",areas[0],areas[1]);
	printf("The size of a char : %ld.\n",sizeof(char));
	printf("The size of name(char[]): %ld.\n",sizeof(name));
	printf("The number of chairs : %ld.\n",sizeof(name) / sizeof(char));
	printf("The size of a full_name (char[]) : %ld\n",sizeof(full_name));
	printf("The number chars : %ld\n",sizeof(full_name) / sizeof(char));
	printf("The name and full_name: %s , %s\n",name , full_name);

	return 0;

}
