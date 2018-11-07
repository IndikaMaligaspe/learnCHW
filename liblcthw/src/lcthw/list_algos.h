#ifndef lcthw_list_algos_h
#define lcthw_list_algos_h

#include <stdlib.h>

typedef struct LL_Node {
	struct LL_Node *next;
	char *word;
} LL_Node;

typedef struct Linked_List {
	int count;
	LL_Node *first;
	LL_Node *last;
} Linked_List;

Linked_List *LL_Create();
void LL_deleet(Linked_List *Llist);

#endif
