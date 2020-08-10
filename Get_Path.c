#include "Shell.h"

void
Get_Path(List *list)
{
	Posicionar_Path(environ);
	Posicionar_Environ(environ);
	while(**environ)
		Ins_Next_Element(list, NULL,Data_Path());
}
