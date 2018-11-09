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

void LL_Clear(Linked_List *list)
{
  printf("Inside Clear List \n");
}

void LL_push(Linked_List *list, char *word)
{
  if (list == NULL){
    printf("The list is null \n");
    return;
  }

  LL_Node *new_node  = calloc(1,sizeof(LL_Node));
  check_mem(new_node);

  new_node->word = word;

  if(list->last == NULL){
    list->last = new_node;
    list->first = new_node;
  }else{
    list->last->next = new_node;
    list->last= new_node;
  }
  list->count++;
  printf("Inside push with %s \n",word);

 error:
  return;
}


char *LL_pop(Linked_List *list)
{
  printf("inside pop \n");
  return "poped";
}

void LL_print(Linked_List *list)
{
  if (list == NULL){
    return;
  }

  if (list->first == NULL){
    printf("list is empty");
    return;
  }

  LL_Node *node = list->first;
  while(node != NULL){
    printf("Node value - :%s \n",node->word);
    node = node->next;
  }
}
    
	     
void LL_Delete(Linked_List** list)
{
  //LL_Clear(list);
  struct Linked_List* _list = *list;
  if(_list->first->next == NULL){
     free(_list->first);
  }else{
    LL_Node *node = _list->first->next;
    while(node != NULL){
      printf("deleting  - %s \n",node->word);
      free(_list->first);
      _list->first = node;
      node = _list->first->next;
    }
  }
  free(_list->last);
  free(_list);
  *list = NULL;
  printf("deleting linked list \n ");
}

int main(int argc, char *argv[])
{
	if (argc != 0) {
	   printf("app naem - %s \n", argv[0]);
	}
	ll = LL_Create();
	char *word[] = {"Hello" , "123456"," test"};
	LL_push(ll,word[0]);
	LL_push(ll,word[1]);
	printf("List Count : %d \n",ll->count);
	LL_print(ll);
	LL_print(ll);
	char *word1 = LL_pop(ll);
	printf("got word %s \n",word1);
        LL_Delete(&ll);
	LL_print(ll);
}
	     


