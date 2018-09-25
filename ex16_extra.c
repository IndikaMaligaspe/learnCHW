#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>


struct Person{
	char *name;
	int age;
	int height;
	int weight;		
};

void init_Person(struct Person *who, char *name, int age, int height,int weight)
{
	who->name = name;
	who->age = age;
	who->height = height;
	who->weight=weight;
}

void print_Person(struct Person who)
{
	printf("This persons name is - %s \n",who.name);
	printf("He is %d years old and weighs %d for his height of %d \n",who.age, who.weight, who.height);

}

int main(int argc, char * argv[]){

	struct Person indika;
	init_Person(&indika,"Indika Maligaspe",41,64,150);
	print_Person(indika);

	struct Person sumudu;
	init_Person(&sumudu,"Sumudu Maligaspe",41,51,110);
	print_Person(sumudu);

}
