#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[])
{

	int a = 10;
	int *b = &a;
	char *hect = "asnhvhvh";
	char hept[10] = {'a','b','c','d','e','f','g'};
	char **tuk =  &hect;

	printf("size of a - %d \n",sizeof(a));
	printf("size of b - %d \n",sizeof(b));
	printf("size of hect - %d \n",sizeof(hect));
	// printf("strlen of hect - %d \n",strlen(hect));
	printf("size of *hect - %d \n",sizeof(*hect));
	// printf("size of hept - %d \n",sizeof(hept));
	printf("inside of hect  - %s \n",*tuk);

}