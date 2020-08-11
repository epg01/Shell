#include "Shell.h"

int Match(char *Path, char *Key1)
{
	while (*Path && *Path == *Key1)
		Path++, Key1++;
	if (*Path)
		return (1);
	else
		return (0);
}

void Destroy(char *PATH)
{
	free(PATH);
}

int
main(void)
{
	List list;
	char *String_Character = NULL;
	ssize_t Counter_Character  = 0;

	/*
	 * Creacion de la estructura de datos que contendra las rutas.
	 */

	List_Init(&list, Destroy, NULL, Match);
	Get_Path(&list);

	/*
	 * Finalizacion de la creación de la estructura de datos.
	 */

	/*
	 * Aparición de la shell.
	 */

	write(1, "$ ", 2);
	while(getline(&String_Character, &Counter_Character, stdin) != EOF)
	{
		Analizar_String_Character(String_Character, &list);

		free(String_Character);
		Counter_Character = 0;
		write(1, "$ ", 2);
	}
	write(1, "\n", 1);

	List_Destroy(&list);
}
