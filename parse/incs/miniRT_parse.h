/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_parse.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:39:00 by yhwang            #+#    #+#             */
/*   Updated: 2023/12/18 20:57:20 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_PARSE_H
# define MINIRT_PARSE_H

# include "../libft/incs/libft.h"
# include "../libft/incs/get_next_line.h"

# include "./miniRT_struct.h"

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# define BLACK			"\x1b[0m"
# define RED			"\x1b[31m"

# define SPHERE			1
# define PLANE			2
# define CYLINDER		3

# define ERR_ATOD		1.41421356237309504880
# define ERR_ATOI		-2147483648

# define EPSILON			1e-3

/* parse_main.c */
int			check_arg(char *argv);
int			check_element(t_p_scene *scene);
t_p_scene	*parse(t_p_scene *scene, char *argv);
t_p_scene	*parse_main(int argc, char **argv);

/* parse_init.c */
int			parse_init_scene_obj(t_p_scene *scene, int i);
int			parse_init_scene(t_p_scene *scene);

/* parse_map.c */
void		change_tab_to_space(char **line);
void		convert_line(char **line);
void		finish_gnl(char **line, int fd, int flag);
int			parse_map(t_p_scene *scene, char *argv);

/* parse_check_id.c */
int			parse_obj(t_p_scene *scene, char *line);
int			check_id(t_p_scene *scene, char *line, int *flag);

/* parse_ambient.c */
int			parse_ambient_lighting(t_p_scene *scene, char *lighting);
int			parse_ambient_rgb(t_p_scene *scene, char *rgb);
int			parse_ambient(t_p_scene *scene, char *line);

/* parse_camera.c */
int			parse_camera_pos(t_p_scene *scene, char *pos);
int			parse_camera_vec(t_p_scene *scene, char *vec);
int			parse_camera_fov(t_p_scene *scene, char *fov);
int			parse_camera(t_p_scene *scene, char *line);

/* parse_light.c */
int			parse_light_pos(t_p_scene *scene, char *pos);
int			parse_light_brightness(t_p_scene *scene, char *brightness);
int			parse_light_rgb(t_p_scene *scene, char *rgb);
int			parse_light(t_p_scene *scene, char *line);

/* parse_sphere.c */
int			parse_sphere_pos(t_p_scene *scene, int i, char *pos);
int			parse_sphere_diameter(t_p_scene *scene, int i, char *diameter);
int			parse_sphere_rgb(t_p_scene *scene, int i, char *rgb);
int			parse_sphere(t_p_scene *scene, int i, char *line);

/* parse_plane.c */
int			parse_plane_pos(t_p_scene *scene, int i, char *pos);
int			parse_plane_vec(t_p_scene *scene, int i, char *vec);
int			parse_plane_rgb(t_p_scene *scene, int i, char *rgb);
int			parse_plane(t_p_scene *scene, int i, char *line);

/* parse_cyinder.c */
int			parse_cylinder_pos(t_p_scene *scene, int i, char *pos);
int			parse_cylinder_vec(t_p_scene *scene, int i, char *vec);
int			parse_cylinder_diameter_height(t_p_scene *scene,
				int i, char *diameter, char *height);
int			parse_cylinder_rgb(t_p_scene *scene, int i, char *rgb);
int			parse_cylinder(t_p_scene *scene, int i, char *line);

/* print_scene.c */
void		print_sphere(t_p_scene *scene);//
void		print_plane(t_p_scene *scene);//
void		print_cylinder(t_p_scene *scene);//
void		print_scene(t_p_scene *scene);//

/* utils_lib.c */
void		*ft_realloc(void *old_ptr, size_t old_len, size_t new_len);
void		free_2d(char **str);
void		free_scene(t_p_scene *scene, int flag);

/* utils_range.c */
int			check_int(int i, int min, int max);
int			check_double(double d, double min, double max);
int			check_rgb(int r, int g, int b);
int			check_xyz_pos(double x, double y, double z);
int			check_xyz_vec(double x, double y, double z);

/* utils.c */
void		err_msg(char *str);
int			get_char_idx(char *str, char c);
int			count_token(char *str, char del, int count);

#endif
