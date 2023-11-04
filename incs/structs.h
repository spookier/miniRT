#ifndef STRUCTS_H
# define STRUCTS_H

#include "minirt.h"

# define M_PI 3.14159265358979323846


typedef int bool;
# define TRUE 	1 // while (1) - will never leave loop
# define FALSE 	0

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;


typedef struct	s_data 	// USED TO DRAW PIXEL
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;			

typedef struct s_mlx 	// MLX GRAPHICS ENGINE
{
	void	*mlx;
	void	*mlx_win;
}	t_mlx;			

typedef struct s_viewport
{
	double	aspect_ratio;
	int		img_width;
	int		img_height;
	double 	viewport_width;
	double 	viewport_height;
	double 	distance_cam_to_viewport;
	double 	fov;

}	t_viewport;

typedef struct s_camera
{
	t_vec3 origin;
	t_vec3 direction;

}	t_camera;

typedef struct s_ray
{
	t_vec3 origin; 		// O
	t_vec3 direction;	// D

}	t_ray;

typedef struct s_sphere 
{
    double radius;
	t_vec3 center;
    //int color[3]; // RGB
	t_rgb color;
} t_sphere;


typedef struct s_light
{
	t_vec3 			position;
    int 			color;
    float 			intensity;
}	t_light;

// Define the scene (assuming maximum 3 spheres for simplicity)
typedef struct s_scene
{
    t_sphere 	spheres[4];
    float 		viewport_size[2];
    float 		projection_plane_d;
	t_light     lights;
} t_scene;


typedef struct s_all 
{
	t_mlx			g_eng;
	t_data			img;
	t_viewport		viewp;
	t_camera 		cam;
	t_scene			scene;

}	t_all;

#endif