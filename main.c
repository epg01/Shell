#include "Shell.h"

/**
 * Match - Function to check if the Path variable matches the second argument.
 *         of the function.
 * @Path: Variable to check if it matches the viable Key1.
 * @Key1: Data that is analyzed if it matches or not with path.
 * Return: Returns 0 on success, 1 otherwise.
 */

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

/**
 * Destroy - Function to destroy the data inserted in the Path variable
 *           found in.
 *           the structure, structure Element_
 * @PATH: Function that destroys dynamically allocated memory in Path.
 */

void
Destroy(char *PATH)
{
	free(PATH);
}

/**
 * Execve - Function that creates a child by calling fork to be able to execute
 *          the command (written without the path in the terminal).
 * @Path: Non-relative path passed as the first argument, in order to correctly
 *        execute the execve function.
 * @argv: A double pointer that points to an array of pointers,
 *        containing the command and arguments passed from the termianl.
 * Return: Returns 0 on success, 1 otherwise.
 */

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

/**
 * main - Simple shell startup
 * Return: 0 almost successful.
 */

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

	while (write(1, "$ ", 2) && getline(&String_Character, &Counter_Character, stdin) != EOF)
	{
		Analizar_String_Character(String_Character, &list);

		free(String_Character);
		String_Character = NULL;
		Counter_Character = 0;
	}
	write(1, "\n", 1);

	/*
	 * Eliminamos la estructura creada recientemente.
	 */

	List_Destroy(&list);

	return (0);
}
