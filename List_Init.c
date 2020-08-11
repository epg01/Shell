#include "Shell.h"

void
List_Init(List *list, void (*Destroy)(char *Path), int (*Execve)(char *Path, char **argv), int (*Match)(char *Key1, char *Key2))
{
	list->Size_List = 0;
	list->Head      = NULL;
	list->Tail      = NULL;
	list->Destroy   = Destroy;
	list->Execve    = Execve;
	list->Match     = Match;

	printf("Se inicializado la lista\n");
}
