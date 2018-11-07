#include "miunit.h"
#include <lcthw/list_algis.h>
#include <assert.h>
#include <string.h>



char *values[] = {"XXX","12345", "abcd","xjvef" , "NDSS" };

#define NUM_VALUES 5

Linked_List LL_Create()
{
	Linked_List *llist =  LL_Create();
}

char *all_tests()
{
	mu_suite_start();
	return NULL;
}

RUN_TESTS(all_tests);
