#include <stdio.h>

int main(int argc, char *argv[]){

	int i = 1;
	
	//Go through each string in argv
	//why am I skipping argv[0]
	while (i < argc){
		printf("arg %d: %s \n",i,argv[i]);
		i++;
	}

	//lets make our own array of Strings
	char *states[] = {
		"Califirnia","Oregon",
		"Washington","Texas"
	};

	int num_states = 4;

	for (i = 0;  i < num_states; i++){
		printf("state %d: %s \n",i,states[i]);
	}
	return 0;
}
