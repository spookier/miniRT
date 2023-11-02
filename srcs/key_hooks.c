#include "../incs/minirt.h"

int	key_hook(int keycode, t_all *all)
{
	if (keycode == KEY_ESC)
		exit_prog(all, NULL);
	return (0);
}
