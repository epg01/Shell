#include "shell.h"


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
char *
Data_Path()
{
	char *temp;
	int counter = 1;   /*
			    * Para incluir el caracter '\0'.
			    */
	int index = 0;

	while((*environ)[index] != ':' && (*environ)[index])
		counter++, index++;
	if((temp = (char *)malloc(sizeof(char) * counter)) == NULL)
		return NULL;
	else
	{
		index = 0;
		while(*(*environ) != ':' && **(environ))
			temp[index++] = *(*environ)++;
		if (**environ == ':')
			(*environ)++;
		temp[index] = '\0';
		return (temp);
	}
}

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
void
Get_Path(List *list)
{
	Posicionar_Path(environ);
	Posicionar_Environ(environ);
	while(**environ)
		Ins_Next_Element(list, NULL,Data_Path());
}

int
main(void)
{
	List list;

	/*
	 *   Inicializamos la estructura.
	 */

	List_Init(&list, NULL, NULL);
	Get_Path(&list);
}
