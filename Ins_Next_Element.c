#include "Shell.h"

/**
 * Ins_Next_Element - Inserts an element just after element in the
 *                    linked list specified by list.If elementis NULL, the
 *                    new element is inserted at the head of the list.The new
 *                    element contains a pointer to Path, so the memory
 *                    referenced by data should remain valid as long as the
 *                    element remains in the list. It is the responsibil-ity of
 *                    the caller to manage the storage associated with data.
 *
 * @element:   If elementis NULL, the new element is inserted
 *             at the head of the list.
 * @list:      Points to the data structure list.
 * @Path:      Pointer that contains the data to be added to the created node.
 * Return: Value0 if inserting the element is successful, or –1 otherwise.
 */

int Ins_Next_Element(List *list, Element *element, char *Path)
{
	Element *New_Element;

	New_Element = (Element *)malloc(sizeof(Element));
	if (!New_Element)
		return (-1);

	New_Element->Path = Path;
	Length_PATH(New_Element, (New_Element->Length_Path));
	if (!element)
	{
		if (!(list->Tail))
			list->Tail = New_Element;
		New_Element->Next  = list->Head;
		list->Head         = New_Element;
	}
	else
	{
		if (!(element->Next))
			list->Tail = New_Element;
		New_Element        = element->Next;
		element->Next      = New_Element;
	}

	(list->Size_List)++;

	return (0);
}
