/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlahyani <wlahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:11:15 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/04/20 08:16:21 by wlahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include "./get_next_line/get_next_line.h"
# define TRUE 1
# define FALSE 0
# define SPACE 32
# define TAB  9
# define TRUE 1
# define FALSE 0
# define SPACE 32
# define TAB  9
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define ESC_KEY 53

typedef int	t_bool;

typedef struct s_ray
{
	float	ry;
	float	rx;
	int		line;
	float	ray;
	int		next_x;
	int		next_y;
}	t_ray;
typedef struct s_tex
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		w;
	int		h;
}				t_ex;

typedef struct s_alloc_lst
{
	void				*content;
	struct s_alloc_lst	*next;
}	t_alloc_lst;

typedef struct s_map
{
	t_alloc_lst	**alloc_list;
	char		**line;
	char		**map;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	double		rx;
	double		ry;
	double		i;
	double		index;
	float		view;
	float		angle;
	float		y;
	float		x;
	int			f_color;
	int			c_color;
	int			x_player;
	int			y_player;
	int			long_line;
	int			len;
}	t_map;

typedef struct s_data{
	void	*mlx;
	void	*win;
	void	*img;
	void	*wall;
	void	*player;
	void	*background;
	void	*shadow;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	t_map	*map;
	t_ex	we;
	t_ex	ea;
	t_ex	so;
	t_ex	no;
}	t_data;

// ----------> PARSING <---------- //
t_bool			check_path(char *av, t_bool a);
t_bool			check_border(t_map *map);
t_bool			check_elements(char **map);
t_bool			is_map_valid(t_map *map);
t_map			*parsing(char *av);
void			map_elements(t_map *map);
void			print_2d(char **str);
void			exit_error(char *str);
void			initialisation(t_map *map);
void			player_position(t_map *map);
void			check_empty_line(char *map);
char			**get_map(char *av);
char			*check_textures(char *path);
int				check_colors(char *str);
int				skip_spaces_begin(char *str);
int				doble_arr_len(char **str);
int				longest_line(char **map);
int				encode_rgb(int red, int green, int blue);
// ----------> DRAWING <---------- //
unsigned int	no_texture(t_data *img, double x, double y);
unsigned int	we_texture(t_data *img, double x, double y);
unsigned int	so_texture(t_data *img, double x, double y);
unsigned int	ea_texture(t_data *img, double x, double y);
t_data			*init_func(t_data *img);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			cast_rays(t_data *img);
void			draw_rays(t_data *img, float ray, int color);
void			ft_images(t_data *img);
void			destroy_window(t_data *game);
void			close_window(t_data *game);
void			move_player_w(t_data *img);
void			move_player_s(t_data *img);
void			move_player_a(t_data *img);
void			move_player_d(t_data *img);
void			turn_right(t_data *img);
void			turn_left(t_data *img);
void			up_right_rays(t_data *img);
void			up_left_rays(t_data *img);
void			down_right_rays(t_data *img);
void			down_left_rays(t_data *img);
void			right_side_angle(t_data *img, double *x);
void			left_side_angle(t_data *img, double *x);
void			ft_images(t_data *img);
void			raycasting(t_data *img);
void			dala(t_data *img, double ray, int color, double r);
void			draw_world(t_data *img);
void			debug(t_data *img);
void			draw_rays(t_data *img, float ray, int color);
double			cast_rays1(t_data *img, float view, double *rx);
double			cast_rays2(t_data *img, float view, double *rx);
double			cast_rays3(t_data *img, float view, double *rx);
double			cast_rays4(t_data *img, float view, double *rx);
double			cast_rays5(t_data *img, float view, double *rx);
double			cast_rays6(t_data *img, float view, double *rx);
int				draw_map(t_data *img);
int				draw_lines(t_data *img);
int				move_player(int key, t_data *img);
int				esc_key(int key, t_data *game);
int				cross_key(void);
void			iteration1(t_data *img, t_ray *ray1, float view);
void			iteration2(t_data *img, t_ray *ray, float view);
void			iteration3(t_data *img, t_ray *ray1, float view);
void			iteration4(t_data *img, t_ray *ray1, float view);
void			iteration5(t_data *img, t_ray *ray1, float view);
void			iteration6(t_data *img, t_ray *ray1, float view);
int				init_val1(t_data *img, t_ray *ray1, float view);
int				init_val2(t_data *img, t_ray *ray, float view);
int				init_val3(t_data *img, t_ray *ray, float view);
int				init_val4(t_data *img, t_ray *ray, float view);
int				init_val5(t_data *img, t_ray *ray, float view);
int				init_val6(t_data *img, t_ray *ray, float view);
void			ft_free(char **str);
#endif