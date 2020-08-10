#include "Shell.h"

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
