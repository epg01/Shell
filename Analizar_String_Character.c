#include "Shell.h"

int Counter_Word(char *String)
{
	int State = 0;
	int Counter_Word = 0;

	while(*String)
	{
		if  (*String == ' ' || *String == '\n' || *String == '\t')
			State = 0;
		else
			if (!State)
				Counter_Word++, State = 1;
		String++;
	}
	return (Counter_Word);
}


void Analizar_String_Character(char *String, List *list)
{
	int Counter_WORD;
	char **argv;
	int index = 1;
	Counter_WORD = Counter_Word(String);

	if (!(argv = (char **)malloc(sizeof(char *) + (Counter_WORD + 1))))
		return ;
	*argv = strtok(String, " \n\t");
	while (index < Counter_WORD)
		argv[index++] = strtok(NULL, " \n\t");
	argv[index] = NULL;

	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
	}
	if (child_pid == 0)
		execve(*argv, argv, NULL);
	else
		wait(&status);
}
