#include <stdio.h>

int main(int argc,char *argv[]){
	int i = 0;
	
	if (argc == 1) {
		printf("you only have one argument, You suck. \n");
	}else if (argc > 1 && argc <4){
		printf("Here is your argument list: \n");
		
		for (i=0;i<argc; i++){
			printf("%s ",argv[i]);
		}
		printf("\n");
	}else {
		printf("You have too many arguments. You suck \n");
	}

	int var = 13;
	// printf("bit wise vale -- %d",__numOf_SET_Bits(var));	
}

int __numOf_SET_Bits(int var){
	return (var&01)?1+__numOf_SET_Bits(var>>1):__numOf_SET_Bits(var>>1);
}
