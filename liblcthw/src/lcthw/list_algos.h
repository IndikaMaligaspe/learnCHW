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
void LL_Clear(Linked_List *list);
void LL_delete(Linked_List** list);
void LL_push(Linked_List *list, char *word);
void LL_print(Linked_List *list);
char *LL_pop(Linked_List *list);

#define LIST_FOREACH(L,S,M,V) LL_Node * _node = NULL; \
  LL_Node *V = NULL; \
  for (V = _node = L->S; _node != NULL; _node = node->M)


#endif
