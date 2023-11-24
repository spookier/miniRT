#include "../incs/minirt.h"

int alloc_struct_mem(t_all **all)
{
	*all = (t_all *)malloc(sizeof(**all));
	if (!*all)
		return (-1);
	return (0);
}