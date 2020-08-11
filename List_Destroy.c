#include "Shell.h"

/**
 *  List_Destro - Destroys  the  linked  list  specified  bylist.
 *                No  other  operationsare  permitted  after  calling 
 *                List_Destroy unless List_Init is  called  again. The
 *                List_Destroyo peration removes all elements from a linked
 *                list and calls the function passed as destroyto List_Init
 *                once for each element as it is removed, provideddestroy
 *                was not set to NULL.
 * @list: Pointer to a function of type structure.
 */

void
List_Destroy(List *list)
{
	char *Path;

	while (list->Size_List > 0)
		if ((Rem_Nex_Element(list, NULL, &Path) == 0) && (list->Destroy != NULL))
			list->Destroy(Path);
	memset(list, 0, sizeof(List));
	return ;
}
