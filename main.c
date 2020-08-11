#include "Shell.h"

int
Match(char *Path, char *Key1)
{
	while (*Path && *Path == *Key1)
		Path++, Key1++;
	if (*Path)
		return (1);
	else
		return (0);
}

void
Destroy(char *PATH)
{
	free(PATH);
}

int
Execve(char *Path, char **argv)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (child_pid == 0)
		return (execve(Path, argv, NULL));
	else
		wait(&status);
	return (0);
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

	List_Init(&list, Destroy, Execve, Match);
	Get_Path(&list);

	/*
	 * Finalizacion de la creación de la estructura de datos.
	 */

	/*
	 * Aparición de la shell.
	 */

	while(write(1, "$ ", 2) && getline(&String_Character, &Counter_Character, stdin) != EOF)
	{
		Analizar_String_Character(String_Character, &list);

		free(String_Character);
		String_Character = NULL;
		Counter_Character = 0;
	}
	write(1, "\n", 1);

	List_Destroy(&list);
}
