#include "Shell.h"

/**
 * List_Init - Initializes the linked list specified by list. This operation
 *             must be called for a linked list before the list can be used
 *             with any other operation.The Destroy argument provides a way
 *             to free dynamically allocated data when, List_Destroy is called.
 *             For example, if the list contains data dynamically allocate
 *             dusing malloc,Destroy should be set tofreeto free the
 *             data as the linked list is destroyed. For structured data
 *             containing several dynamically allocated members,destroy should
 *             be set to a user-defined function that calls free for each
 *             dynamically allocated member as well as for the structure
 *             it self. For a linked list containing data that should not be
 *             freed,destroy should be set to NULL
 *
 * @Destroy:   Pointer to Destroy function.
 * @Execve:    Pointer to Execve function.
 * @Match:     Pointer to Match function.
 * @list:      Pointer to list structure.
 */

void
List_Init(List *list, void (*Destroy)(char *Path), int (*Execve)(char *Path, char **argv), int (*Match)(char *Key1, char *Key2))
{
	list->Size_List = 0;
	list->Head      = NULL;
	list->Tail      = NULL;
	list->Destroy   = Destroy;
	list->Execve    = Execve;
	list->Match     = Match;

}
