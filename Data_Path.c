#include "Shell.h"

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
