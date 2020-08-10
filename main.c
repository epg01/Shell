#include "Shell.h"

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
	List_Destroy(&list);
}
