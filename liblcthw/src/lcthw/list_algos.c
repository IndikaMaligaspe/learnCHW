#include <lcthw/dbg.h>
#include <lcthw/list_algos.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static Linked_List *ll;

Linked_List *LL_Create()
{
	return calloc(1,sizeof(Linked_List));
}

void LL_Delete(Linked_List *Llist)
{
	printf("deleting linked list \n ");
}
int main(int argc, char *argv[])
{
	if (argc != 0) {
		printf("app naem - %s \n", argv[0]);
	}
	ll = LL_Create();
	LL_Delete(ll);
}

