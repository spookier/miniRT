#include "../incs/minirt.h"

void exit_prog(t_all *all, char *str)
{
	if(!all)
		exit(1);
	if(str)
		printf("%s\n", str);
	free_mem(all);
	exit(0);
}