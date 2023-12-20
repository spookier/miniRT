/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:43:51 by acostin           #+#    #+#             */
/*   Updated: 2023/12/20 16:52:22 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "../mlx_linux/mlx.h"
# include "vectors.h"
# include "keycodes.h"
# include "structs.h"
# include "matrix.h"
# include "../../parse/libft/incs/libft.h"
# include "../../parse/incs/miniRT_parse.h"

# define PI	3.14159265359
# define DELTA	1e-10

# define THETA	PI / 6

# define CYAN			"\x1b[36m"
# define YELLOW			"\x1b[33m"

// ALLOC MEMORY
int			alloc_struct_mem(t_all **all);

// INIT VARS
int			init_vars(t_p_scene *p_scene, t_all *all);

// INIT SCENE
void		init_scene(t_p_scene *p_scene, t_scene *scene);

// START PROGRAM FLOW
int			start_mlx(t_all *all);

// RGB
t_rgb		create_rgb(double r, double g, double b);
int			convert_rgb_to_int(t_rgb color);

// SET CAMERA VECTOR
void	rotate_scene(t_scene *scene, t_camera *cam, float angle, char flag);
void		set_cam_vec(t_all *all);

// DRAWING
void		put_pixel_coord(t_all *all, int x, int y, int color);
void		put_pixel_original(t_data *data, int x, int y, int color);
int			start_draw(t_all *all);
t_vec3		canvas_to_viewport(int Cx, int Cy, t_viewport *viewp);

// KEY HOOKS
int			key_hook(int keycode, t_all *all);

// RAY
t_ray		init_ray(t_vec3 origin, t_vec3 direction);
t_rgb		trace_ray(t_ray r, t_scene scene);

// RAY SP, PL
void		intersect_ray_sphere(t_ray r, t_obj sphere, float *t1, float *t2);
void		intersect_ray_plane(t_ray r, t_obj plane, float *t1, float *t2);

// RAY CY BODY
void		get_cylinder_centers(t_obj cylinder, t_vec3 *cy_center);
float		intersect_ray_cylinder_body(t_ray r,
				t_obj cylinder, t_vec3 *cy_center);
void		intersect_ray_cylinder(t_ray r,
				t_obj cylinder, float *t, t_vec3 *surface_normal);

// RAY CY CIRCLE
float		intersect_ray_cylinder_circle(t_ray r,
				t_obj cylinder, t_vec3 *cy_center);

// LIGHT
t_light		light_create(t_vec3 position, int color, float intensity);
t_ambient	ambient_create(int color, float intensity);
t_rgb		compute_lighting(t_vec3 P, t_vec3 N, t_obj *obj, t_scene scene);

// FREE MEMORY
void		free_mem(t_all *all);

// EXIT PROGRAM
void		exit_prog(t_all *all, char *str);
int			mlx_exit(t_all *all);

//temp
int	move_x_hook(int keycode, t_all *all);
int	pos_move_hook(int keycode, t_all *all);
int	vec_rotate_hook(int keycode, t_all *all);
int	camera_hook(int keycode, t_all *all);
int	light_hook(int keycode, t_all *all);

#endif
