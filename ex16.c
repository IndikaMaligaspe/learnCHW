#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
	char *name;
	int age;
	int height;
	int weight;
};

struct Person *Person_create(char *name, int age, int height, int weight)
{
	struct Person *who = malloc(sizeof(struct Person));
	assert(who != NULL);

	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight = weight;

	return who;
}

void Person_destroy(struct Person *who)
{
	assert(who != NULL);

	free(who->name);
	free(who);
}

void Person_print(struct Person *who)
{
	printf("Name: %s. \n",who->name);
	printf("\tAge: %d\n",who->age);
	printf("\tHeight: %d\n",who->height);
	printf("\tWeight: %d\n",who->weight);
}

int main(int argc, char *argv[])
{

	//make two people structures
	struct Person *indi = Person_create("Indika M", 41,64,110);
	struct Person *sumu = Person_create("Sumu M",41,51,72);

	//print them out and where they are in memory
	printf("Indika is in memeory location: %p \n",indi);
	Person_print(indi);

	printf("Sumu is in memory location: %p \n",sumu);
	Person_print(sumu);

	//make all 20 years and prnt them
	indi->age +=20;
	indi->height -=2;
	indi->weight +=40;
	Person_print(indi);

	sumu->age +=20;
	sumu->weight +=2;
	Person_print(sumu);

	Person_destroy(indi);
	Person_destroy(sumu);
	return 0;

}
