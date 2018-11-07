// #include <lcthw/gbd.h>
#include <lcthw/list.h>
#include <assert.h>
#include <stdio.h>

static List *list = NULL;

char *create_list()
{
	list = List_create();
	assert(list != NULL);

	return NULL;
}

char *destroy_list()
{
	List_clear_destroy(list);

	return NULL;
}


int main(int argc, char *argv[])
{
	if (argc != 0) {
		printf("%s",argv[0]);
	}

	create_list();
	char *item1 = "Item 1";
	char *item2 = "item 2";

	List_push(list,item1);
	List_push(list,item2);

        ListNode *node = List_pop(list);
	printf("%s",(char*)node->value);

	destroy_list();
	return 0;
}
