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

int Rem_Nex_Element(List *list, Element *element, char **Path)
{
	Element *Old_Element;

	if (!(list->Size_List))
		return (0);

	if (element == NULL)
	{
		*Path       = list->Head->Path;
		Old_Element = list->Head;
		list->Head  = list->Head->Next;
	}

	if (list->Size_List == 1)
	{
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
void List_Destroy(List *list)
{
	char *Path;

	while (list->Size_List > 0)
		if ((Rem_Nex_Element(list, NULL, &Path) == 0) && (list->Destroy != NULL))
			list->Destroy(Path);
	return ;
}
void
Get_Path(List *list)
{
	Posicionar_Path(environ);
	Posicionar_Environ(environ);
	while(**environ)
		Ins_Next_Element(list, NULL,Data_Path());
	printf("Eliminamos la estructura de datos");
	List_Destroy(list);
//	printf("Tamaño de la lista = %d\n", list->Size_List);
}

void Destroy(char *PATH)
{
	free(PATH);
}

int
main(void)
{
	List list;

	List_Init(&list, Destroy, NULL);
	Get_Path(&list);
}
