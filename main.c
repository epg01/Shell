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
		temp[index] = '\0';
		printf("Elemento insertado\n%s\n", temp);
		return (temp);
	}
}

void
Get_Path(List *list)
{
	Posicionar_Path(environ);

	printf("La variable environ esta en el path\n");
	printf("%s\n", *environ);
	printf("movemos la variable envirn para a puntar al \\\n");
	Posicionar_Environ(environ);
	printf("%s\n", *environ);
	printf("Procedemos a ingresar las rutas en la estructura de datos\n");

	while(**environ)
		Data_Path();
	printf("Se creo la base de datos, ahora procedemos a imprimir dichas rutas\n");
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
