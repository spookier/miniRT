/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:41:07 by yhwang            #+#    #+#             */
/*   Updated: 2023/12/18 20:57:10 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_STRUCT_H
# define MINIRT_STRUCT_H

# include "./miniRT_parse.h"

typedef struct s_p_vec3
{
	double	x;
	double	y;
	double	z;
}	t_p_vec3;

typedef struct s_p_rgb
{
	int	r;
	int	g;
	int	b;
}	t_p_rgb;

typedef struct s_p_ambient
{
	int			check;
	double		lighting;
	t_p_rgb		rgb;
}	t_p_ambient;

typedef struct s_p_camera
{
	int			check;
	t_p_vec3	xyz_pos;
	t_p_vec3	xyz_vec;
	int			fov;
}	t_p_camera;

typedef struct s_p_light
{
	int			check;
	t_p_vec3	xyz_pos;
	double		brightness;
	t_p_rgb		rgb;
}	t_p_light;

typedef struct s_p_obj
{
	int			obj_type;
	t_p_vec3	xyz_pos;
	t_p_vec3	xyz_vec;
	double		diameter;
	double		height;
	t_p_rgb		rgb;
}	t_p_obj;

typedef struct s_p_scene
{
	t_p_ambient	*ambient;
	t_p_camera	*camera;
	t_p_light	*light;
	t_p_obj		**obj;
	int			n_sphere;
	int			n_plane;
	int			n_cylinder;
}	t_p_scene;

#endif
