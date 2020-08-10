#include "Shell.h"

int Ins_Next_Element(List *list, Element *element, char *Path)
{
	Element *New_Element;

	if(!(New_Element = (Element *)malloc(sizeof(Element))))
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
