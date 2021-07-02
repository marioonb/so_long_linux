/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:53:29 by mbelorge          #+#    #+#             */
/*   Updated: 2020/02/10 17:17:24 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibX/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "./libft/libft.h"

# define ECHAP		65387
# define KEY_W		119
# define KEY_S		115
# define KEY_A		97
# define KEY_D		100

typedef struct	s_bmp
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char t;
}				t_bmp;

typedef struct	s_map
{
	int			lo;
	int			la;
	int			x;
	int			y;
	char		**tabmap;

}				t_map;

typedef struct	s_resol
{
	int			width;
	int			heigth;

}				t_resol;

typedef struct	s_image
{
	void		*img;
	char		*adrr;
	int			bpx;
	int			line_l;
	int			endian;

}				t_image;

typedef struct	s_move
{
	int			av_rec;
	int			av;
	int			rec;
	int			left;
	int			right;
	int			cam;

}				t_move;

typedef struct	s_param
{
	void		*mlx_ptr;
	void		*win_ptr;

}				t_param;

typedef struct	s_player
{
	double		x;
	double		y;
	int		i;
	int		j;
	char		orientation;
	double		dir_x;
	double		dir_y;
	double		plan_x;
	double		plan_y;

}				t_player;

typedef struct	s_texture
{
	char		*path;
	int			width;
	int			height;
	t_image		i;
}				t_texture;

typedef struct	s_color
{
	char		orientation;
	int			r;
	int			g;
	int			b;
	int			color_hex;

}				t_color;

typedef struct	s_raycast
{
	int			x;
	int			y;
	double		camera_x;
	double		raydir_x;
	double		raydir_y;
	int			xactual;
	int			yactual;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	int			step_x;
	int			step_y;
	double		pwd;
	int			hit;
	int			line_heigth;
	int			draw_start;
	int			draw_end;
	int			side;
	double		wall_x;
	int			textposx;
	int			textposy;
	double		step;
	double		position;
	int			color;
}				t_raycast;

typedef struct	s_sprite
{
	double		x;
	double		y;
	int			place;
	t_texture	t;
	double		distwall;
}				t_sprite;

typedef struct	s_sp
{
	double		x;
	double		y;
	double		invdet;
	double		transform_x;
	double		transform_y;
	int			screen_x;
	int			sprite_h;
	int			start_y;
	int			start_x;
	int			end_y;
	int			end_x;
	int			width;
	int			height;
	double		*distance_tab;
}				t_sp;

typedef struct	s_sl
{
	t_resol		resol;
	t_sprite	*sprite;
	t_sp		sp;
	char		sp_path;
	int			sprite_nb;
	void		*mlx_ptr;
	void		*win_ptr;
	t_texture	col;
	t_texture	play;
	t_texture	wal;
	t_texture	att;
	t_texture	ex;
	t_texture	back;
	t_color		color_floor;
	t_color		color_ceiling;
	t_map		map;
	t_map		old_map;
	t_param		param;
	t_player	player;
	int			save;
	t_raycast	ray;
	t_image		img;
	double		speed_moove;
	double		olddir_x;
	double		olddir_y;
	double		oldplan_x;
	double		oldplan_y;
	int			moove;
	double		rotate;
	t_image		minimap;
	char		*sprite_path;
	t_move move;
	char		*ext;
	int			object;
	int			point;
	int			end;
	int			loose;
	int			win;
}				t_sl;

t_map			check_fd (int fd);
t_map			lenght_map(int fd);
void			ft_read_fd(int fd,t_sl *sl);
t_resol			resolution_parse(char *line);
void			define_texture(t_sl *sl, char *line);
t_texture		texture_parse(char *line);
void			define_color(t_sl *sl, char *line);
t_color			color_parse(char *line);
void			check_map(char *line, t_sl *sl);
void			check_line(char *line, char a);
void			fill_map(char **map, char *line, t_map m);
void			check_error_border_map (char **map, t_map m);
void			check_error_inside_map (char **map, t_map m);
void			ft_error_map(int index, char a, int b, int c);
void			check_path(char *path, char *s);
void			check_color(t_color color);
void			check_color2(char *buff, char c);
void			check_error_resolution(t_sl *sl);
void			ft_error_fd(int index, char *s);
void			ft_error_color_fd(int index, char c);
void			ft_error_div(int index);
void			start_game(t_sl *sl);
int				close_cross(t_sl *sl);
void			search_player(t_sl *sl);
void			put_ceiling_and_floor(t_sl *sl);
void			raycasting(t_sl *sl);
void			ft_position_initial(t_sl *sl);
void			get_texture (t_sl *sl);
int				key_control(int key, t_sl *sl);
void			ft_left_right(t_sl *sl);
int				create_rgb(int r, int g, int b);
void			image_pixel(t_image *image, int x, int y, int argb);
void			ft_up_and_down (t_sl *sl);
void			put_minimap(t_sl *sl);
void			ft_draw_walls(t_sl *sl);
void			init_raycast(t_sl *sl);
void			calcul_sidedist(t_sl *sl);
void			ft_rev_char_tab(char *tab, int size);
void			inv(t_sl *sl);
int				key_control2(int key, t_sl *sl);
void			calcul_wall_orientation(t_sl *sl);
unsigned int	my_mlx_pixel_get(t_image img, int x, int y);
void			header_bmp(t_sl *sl, unsigned char header[54],
				unsigned int pixel_bytes_per_row);
void			get_img_data(t_sl *sl,
				t_bmp img_data[sl->resol.heigth][sl->resol.width]);
unsigned char	get_t(unsigned int color);
unsigned char	get_r(unsigned int color);
unsigned char	get_g(unsigned int color);
unsigned char	get_b(unsigned int color);
void			save_original_map (t_sl *sl);
void			free_double_tab(char **tab, int lenght);
void			free_orientation(t_sl *sl);
void			free_all(t_sl *sl);
void			search_number_sprite(t_sl *sl);
void			init_sprite(t_sl *sl);
void			ft_error_texture (int index, char *s);
void			get_texture_sprite(t_sl *c);
void			sprite(t_sl *sl);
void			sort_sprite(t_sl *cub);
void			draw_sprite (t_sl *cub, int stripe, int i);
void			calcul_draw_sprite(t_sl *cub);
void			position_sprite(t_sl *cub);
void			check_arg(t_sl *sl, char **argv);
void			put_background(t_sl *sl);
void			playing_rules(t_sl *cub, int i, int j);
void			check_is_finish(t_sl *cub);

#endif
