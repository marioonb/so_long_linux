/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 11:12:31 by mbelorge          #+#    #+#             */
/*   Updated: 2019/05/02 19:09:31 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void black_screen(t_sl *sl)
{
	int yy = sl->resol.width - 100 - 2 ; 
	int y;
	int i = 0;
	int j; 
	int x = 20;
	int color = create_rgb(0,0,0);
	while (i < 40)
	{
		j = 0;
		y = yy;
		while (j < 100)
		{
			image_pixel(&sl->img, y, x, color);
			j++;
			y++;
		}
		i++;
		x++;
	}
}

static void point_number(t_sl *cub)
{
	char *string = "Vous avez";
	int vert = create_rgb(0, 128, 0);
	char *string2 = "00";

	//if (cub->point == 5)
	//	string2 = "5 points";
	//if (cub->point == 4)
	//	string2 = "4 points";
	//if (cub->point == 3)
	//{
	//	string = "oops vous avez ";
	//	string2 = "3 points";
	//} 
	//if (cub->point == 2)
	//{
	//	string = "Attention, vous avez ";
	//	string2 = "2 points";
	//}
	//if (cub->point == 1)
	//{
	//	string = "Attention, vous avez ";
	//	string2 = "1 point";
	//}
	//if (cub->point == 0)
	//{
	//	string = "DOMMAGE !!";
	//	string2 = "0 point";
	//}
	string2 = ft_itoa(cub->moove);
	char *string4 = ft_itoa(cub->point);
	string = "PV  : ";
	char *string3 = "PDD : ";
	//black_screen(cub);
	///////mlx_string_put(cub->mlx_ptr, cub->win_ptr, cub->resol.width - 100, 30, vert, string);
	mlx_string_put(cub->mlx_ptr, cub->win_ptr, cub->resol.width - 90, 35, vert, string3);
	mlx_string_put(cub->mlx_ptr, cub->win_ptr, cub->resol.width - 50, 35, vert, string2);

	mlx_string_put(cub->mlx_ptr, cub->win_ptr, cub->resol.width - 90, 50, vert, string);
	mlx_string_put(cub->mlx_ptr, cub->win_ptr, cub->resol.width - 50, 50, vert, string4);
}


void	init_texture(t_sl *sl)
{

	sl->play.i.img = mlx_xpm_file_to_image(sl->mlx_ptr, "./images/perso1.xpm", &sl->play.width, &sl->play.height);
	sl->play.i.adrr = mlx_get_data_addr(sl->play.i.img, &sl->play.i.bpx, &sl->play.i.line_l, &sl->play.i.endian);

	sl->wal.i.img = mlx_xpm_file_to_image(sl->mlx_ptr, "./images/wall.xpm", &sl->wal.width, &sl->wal.height);
	sl->wal.i.adrr = mlx_get_data_addr(sl->wal.i.img, &sl->wal.i.bpx, &sl->wal.i.line_l, &sl->wal.i.endian);

	sl->back.i.img = mlx_xpm_file_to_image(sl->mlx_ptr, "./images/back.xpm", &sl->back.width, &sl->back.height);
	sl->back.i.adrr = mlx_get_data_addr(sl->back.i.img, &sl->back.i.bpx, &sl->back.i.line_l, &sl->back.i.endian);

	sl->ex.i.img = mlx_xpm_file_to_image(sl->mlx_ptr, "./images/end.xpm", &sl->ex.width, &sl->ex.height);
	sl->ex.i.adrr = mlx_get_data_addr(sl->ex.i.img, &sl->ex.i.bpx, &sl->ex.i.line_l, &sl->ex.i.endian);

	sl->col.i.img = mlx_xpm_file_to_image(sl->mlx_ptr, "./images/burger.xpm", &sl->col.width, &sl->col.height);
	sl->col.i.adrr = mlx_get_data_addr(sl->col.i.img, &sl->col.i.bpx, &sl->col.i.line_l, &sl->col.i.endian);

	//sl->play.i.img = mlx_xpm_file_to_image(sl->mlx_ptr, "./images/perso1.xpm", &sl->play.width, &sl->play.height);
	//sl->play.i.adrr = mlx_get_data_addr(sl->play.i.img, &sl->play.i.bpx, &sl->play.i.line_l, &sl->play.i.endian);
}

static int	ft_play_game(t_sl *sl)
{

	put_background(sl);
	black_screen(sl);
	//put_player(cub);
	ft_up_and_down(sl);
	ft_left_right(sl);
	//put_minimap(cub);
	//sprite(cub);
	//if (cub->win == 0 && cub->loose == 0 && cub->point > 0)
	//mlx_clear_window(sl->mlx_ptr, sl->win_ptr);
	
	//black_screen(sl); 
	printf("Les resol sont %d, %d\n", sl->resol.width, sl->resol.heigth);
	mlx_put_image_to_window(sl->mlx_ptr, sl->win_ptr,
	sl->img.img, 0, 0);
	point_number(sl);
	mlx_destroy_image(sl->mlx_ptr, sl->img.img); /////

	
	//printf("C est bon ?? \n");
//	mlx_destroy_image(sl->mlx_ptr, sl->img.img);
			//printf("BUG \n");
	return (0);
}

void		start_game(t_sl *sl)
{
	//sl->mlx_ptr = mlx_init();
	sl->win_ptr = mlx_new_window(sl->mlx_ptr, sl->resol.width,
	sl->resol.heigth, "so_long");
//	sl->img.img = mlx_new_image(sl->mlx_ptr, sl->resol.width, sl->resol.heigth); /////
//	sl->img.adrr = mlx_get_data_addr(sl->img.img, &sl->img.bpx, /////////////////
//			&sl->img.line_l, &sl->img.endian); //////////////////////////////////
	search_player(sl);
	search_number_sprite(sl);
	init_texture(sl);
	mlx_hook(sl->win_ptr, 2, 1L << 0, key_control, sl);
	mlx_hook(sl->win_ptr, 3, 1L << 1, key_control2, sl);
	mlx_hook(sl->win_ptr, 17, 0L, close_cross, sl);
	mlx_loop_hook(sl->mlx_ptr, ft_play_game, sl);
	mlx_loop(sl->mlx_ptr);
}

void		search_player(t_sl *sl)
{
	int		x;
	int		y;
	int		compt;

	compt = 0;
	x = -1;
	while (++x < sl->map.lo)
	{
		y = -1;
		while (++y < sl->map.la)
		{
			if (sl->map.tabmap[x][y] == 'P')
			{
				//sl->player.orientation = sl->map.tabmap[x][y];
				//printf("IIII");
				sl->player.x = x; // + 0.5;
				sl->player.y = y;// + 0.5;
				sl->player.i = x;// + 0.5;
				sl->player.j = y;// + 0.5;
				compt++;
				//printf("\nplayer Y = %d", x, y);
			}
			if (compt > 1)
				ft_error_map(7, ' ', 0, 0);
		}
	}
	//if (sl->player.orientation == ' ')
	//	ft_error_map(8, ' ', 0, 0);
	//ft_position_initial(sl);
	//ft_read_tab_char(sl->map.tabmap);
	//printf("player.x = %d, le y est a %d dans search\n", sl->player.i, sl->player.j);
}


