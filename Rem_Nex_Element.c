#include "Shell.h"

/**
 * Rem_Nex_Element - Removes the element just after element from the linked
 *                   list specified by list.If elementis NULL, the element at
 *                   the head of the list is removed.Upon return,Path points
 *                   to the data stored in the element that was removed. It is
 *                   the responsibility of the caller to manage the storage
 *                   associated with the Pata.
 * @list:        Variable that contains the direction list of elements that
 *               will be eliminated.
 * @element:     Element containing the node to delete in the list of the
 *               structure.
 * @Path:        Pointer that contains the data that will be eliminated by the
 *               Destroy function, contained in the List_ structure
 * Return:       0 if removing the element is successful, or –1 otherwise.
 */

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
			return (-1);

		*Path         = element->Path;
		Old_Element   = element->Next;
		element->Next = element->Next->Next;

		if (element->Next == NULL)
			list->Tail = element;
	}

	free(Old_Element);

	(list->Size_List)--;
	return (0);
}
