#include "Shell.h"

void
List_Init(List *list, void (*Destroy)(char *Path), void (*Execve)(char **Path))
{
	list->Size_List = 0;
	list->Head      = NULL;
	list->Tail      = NULL;
	list->Destroy   = Destroy;
	list->Execve    = Execve;

	printf("Se inicializado la lista\n");
}
