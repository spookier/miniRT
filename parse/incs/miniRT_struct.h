/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:41:07 by yhwang            #+#    #+#             */
/*   Updated: 2023/11/24 12:58:07 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_STRUCT_H
# define MINIRT_STRUCT_H

# include "./miniRT_parse.h"

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_ambient
{
	int			check;
	double		lighting;
	t_rgb		rgb;
}	t_ambient;

typedef struct s_camera
{
	int			check;
	t_vec3		xyz_pos;
	t_vec3		xyz_vec;
	int			fov;
}	t_camera;

typedef struct s_light
{
	int			check;
	t_vec3		xyz_pos;
	double		brightness;
	t_rgb		rgb;
}	t_light;

typedef struct s_obj
{
	int			obj_type;
	t_vec3		xyz_pos;
	t_vec3		xyz_vec;
	double		diameter;
	double		height;
	t_rgb		rgb;
}	t_obj;

typedef struct s_scene
{
	t_ambient	*ambient;
	t_camera	*camera;
	t_light		*light;
	t_obj		**obj;
	int			n_sphere;
	int			n_plane;
	int			n_cylinder;
}	t_scene;

#endif
