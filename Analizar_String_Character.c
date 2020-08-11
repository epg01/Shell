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

int Execve_(char **argv)
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
	{
		execve(*argv, argv, NULL);
		sleep(3);
	}
	else
	{
		wait(&status);
		return (0);
	}
}

int _Length(char *String)
{
	int length = 0;
	while (String && *String)
		length++, String++;
	return (length);
}
void Analizar_String_Character(char *String, List *list)
{
	int Counter_WORD;
	char **argv;
	int index = 1;
	Element *element = element = list->Head;

	Counter_WORD = Counter_Word(String);

	if (!(argv = (char **)malloc(sizeof(char *) + (Counter_WORD + 1))))
		return ;

	*argv = strtok(String, " \n\t");

	while (index < Counter_WORD)
		argv[index++] = strtok(NULL, " \n\t");
	argv[index] = NULL;

	while (element)
	{
		if (!(list->Match(element->Path, *argv)))
		{
			Execve_(argv);
			break;
		}
		else if (!(list->Match("env", *argv)))
		{
			char **Temp = environ;
			while (*Temp)
				printf("%s\n", *Temp++);
			break ;
		}
		else
		{
			char *Temp;
			int index = 0, index1 = 0;
			int Length = _Length(*argv) + 1;

			if (!(Temp = (char *)malloc(sizeof(char) * (element->Length_Path + Length + 1))))
				return ;
			while (index < (Length + element->Length_Path))
			{
				if (index < element->Length_Path)
					Temp[index] = element->Path[index];
				else if (index == element->Length_Path)
					Temp[index] = '/';
				else
					Temp[index] = (*argv)[index1++];
				index++;
			}
			Temp[index]  = '\0';
			list->Execve(Temp, argv);
			free(Temp);
		}
		element = element->Next;
	}
	free(argv);
}
