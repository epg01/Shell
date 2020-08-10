#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>

/*
 *  Macros.
 */

#define Posicionar_Path(environ)		\
	while((*environ))			\
		if((**environ) == 'P')		\
			break;			\
		else				\
			(environ)++;

#define Posicionar_Environ(environ)		\
	while(*(*environ)++ != '=');

#define Length_PATH(element, Length)			\
	while(((element)->Path)[Length])		\
		(Length)++;

/*
 *  Variable environ.
 */

extern char **environ;

struct Element_
{
	char *Path;
	int  Length_Path;
	struct Element_ *Next;
};

struct List_
{
	int Size_List;
	struct Element_ *Head;
	struct Element_ *Tail;
	void (*Destroy)(char *Path);
	void (*Execve)(char **Path);
};

typedef struct Element_ Element;
typedef struct List_    List;

#endif
