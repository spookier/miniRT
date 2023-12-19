/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:43:51 by acostin           #+#    #+#             */
/*   Updated: 2023/12/19 02:04:40 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "minirt.h"

# define M_PI 3.14159265358979323846

# define SPHERE			1
# define PLANE			2
# define CYLINDER		3

# define TOP			0
# define BOTTOM			1

# define TRUE 		1 // while (1) - will never leave loop
# define FALSE 		0

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;

}	t_rgb;

typedef struct s_data // USED TO DRAW PIXEL
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}	t_data;			

typedef struct s_mlx // MLX GRAPHICS ENGINE
{
	void	*mlx;
	void	*mlx_win;

}	t_mlx;			

typedef struct s_viewport
{
	double	aspect_ratio;
	int		img_width;
	int		img_height;
	double	viewport_width;
	double	viewport_height;
	double	distance_cam_to_viewport;
	double	fov;

}	t_viewport;

typedef struct s_camera
{
	t_vec3	origin;
	t_vec3	direction;

}	t_camera;

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	direction;

}	t_ray;

typedef struct s_light
{
	t_vec3		position;
	int			color;
	float		intensity;

}	t_light;

typedef struct s_ambient
{
	int			color;
	float		intensity;

}	t_ambient;

typedef struct s_obj
{
	int			type;
	t_vec3		center;
	t_vec3		xyz_vec;
	double		radius;
	double		height;
	t_rgb		color;

}	t_obj;

// Define the scene (assuming maximum 3 spheres for simplicity)
typedef struct s_scene
{
	int				num_spheres;
	int				num_planes;
	int				num_cylinder;
	t_obj			*obj;
	t_ambient		ambient;
	t_light			light;

}	t_scene;

typedef struct s_all 
{
	t_mlx			g_eng;
	t_data			img;
	t_viewport		viewp;
	t_camera		cam;
	t_scene			scene;

}	t_all;

#endif
