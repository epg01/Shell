#include "Shell.h"

int
Rem_Nex_Element(List *list, Element *element, char **Path)
{
	Element *Old_Element;

	if (!(list->Size_List))
		return (1);

	if (!element)
	{
		*Path       = list->Head->Path;
		Old_Element = list->Head;
		list->Head  = list->Head->Next;

		if (list->Size_List == 1)
			list->Tail = NULL;
	}
	else
	{
		if (element->Next == NULL)
			return -1;

		*Path         = element->Path;
		Old_Element   = element->Next;
		element->Next = element->Next->Next;

		if (element->Next == NULL)
			list->Tail = element;
	}

	free (Old_Element);

	(list->Size_List)--;
	return (0);
}
