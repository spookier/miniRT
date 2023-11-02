#include "../incs/minirt.h"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_all *all;

	all = NULL;
	if(alloc_struct_mem(&all) == -1)
		exit_prog(all, "Error - Malloc failed");
	init_vars(all);

	start_mlx(all);
	
	exit_prog(all, NULL);

	return (0);
}