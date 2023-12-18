#include "../incs/minirt.h"

t_vec3	canvas_to_viewport(int Cx, int Cy, t_viewport *viewp)
{
	t_vec3	v;

	v.x = Cx * (viewp->viewport_width / viewp->img_width);
	v.y = Cy * (viewp->viewport_height / viewp->img_height);
	v.z = viewp->distance_cam_to_viewport;
	return (v);
}
