/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:12:31 by mbelorge          #+#    #+#             */
/*   Updated: 2020/05/02 19:09:31 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void		init_struct_sl4(t_sl *sl)
{
	sl->resol.width = 900;
	sl->resol.heigth = 900;
	sl->save = 0;
	sl->play.path = NULL;
	sl->play.i.adrr = NULL;
	sl->play.width = 0;
	sl->play.height = 0;
	sl->ext = NULL;
	sl->moove = 0;
}

void		init_struct_sl3(t_sl *sl)
{
	//sl->t_spr.path = NULL;
	//sl->t_spr.width = 0;
	//sl->t_spr.heigth = 0;
	sl->map.tabmap = NULL;
	sl->player.x = 0;
	sl->player.y = 0;
	sl->move.av_rec = 0;
	sl->move.av = 0;
	sl->move.rec = 0;
	sl->move.left = 0;
	sl->move.right = 0;
	//sl->img.img = NULL;
	//sl->img.adrr = NULL;
	init_struct_sl4(sl);
}

void		init_struct_sl2(t_sl *sl)
{

	init_struct_sl3(sl);
}

void		init_struct_sl(t_sl *sl)
{
	//sl->ray.hit = 0;
	sl->color_ceiling.color_hex = 0;
	sl->map.lo = 1;
	sl->map.la = 0;
	sl->map.x = 0;
	sl->map.y = 0;
	sl->map.tabmap = NULL;
	//sl->old_map.lo = 0;
	//sl->old_map.la = 0;
	//sl->old_map.x = 0;
	//sl->old_map.y = 0;
	//sl->old_map.tabmap = NULL;
	sl->sprite_nb = 0;
	//sl->rotate = 0;
	//sl->ray.camera_x = 0;
	//sl->ray.raydir_x = 0;
	//sl->color_floor.color_hex = 0;
	//sl->color_ceiling.orientation = ' ';
	//sl->color_ceiling.r = 0;
	//sl->color_ceiling.g = 0;
	//sl->color_ceiling.b = 0;
	sl->object = 0;
	sl->point = 5;
	sl->end = 0;
	sl->loose = 0;
	sl->win = 0;
	init_struct_sl2(sl);
}

void map_size(int fd, t_sl *sl)
{
	char	*line;

	line = NULL;
	get_next_line(fd, &line);
	//dprintf(1, "line est a %s\n", line);
	//exit (EXIT_SUCCESS);
//	dprintf(1, "la taille de la line est a %d\n", ft_strlen(line));
//	dprintf(1, "la taille de la line est a %d\n", sl->map.la);

	sl->map.la = (int)ft_strlen(line);
	free(line);
	line = NULL;
//	dprintf(1, "ICI");
	while (get_next_line(fd, &line) == 1)
	{
		//dprintf(1, "line2 est a %s", line);
		sl->map.lo++;
		free(line);
		line = NULL; // a retirer
	}
	free(line);
	//sl->resol.width = 32 * sl->map.la;
	//sl->resol.heigth = 32 * sl->map.lo;
	//dprintf(1, "la resol est %d ,%d\n", sl->resol.width, sl->resol.heigth);
	//check_error_resolution(sl);
}

/*
**check_fd = check si il y a toutes les infos + reprend la taille de la map
** ft_read_fd = apel des parsing
*/

int			main(int argc, char **argv)
{
	int		fd;
	t_sl	sl;
//dprintf(1, "ICI");
	init_struct_sl(&sl);
	check_error_resolution(&sl);
	if (argc == 2) //
	{
		check_arg(&sl, argv);
		fd = open(argv[1], O_RDONLY);
		map_size(fd, &sl);
		//printf("la taille de la map est %d", sl.map.lo);
		close(fd);
		//dprintf(1, "ICI");
		fd = open(argv[1], O_RDONLY);
		ft_read_fd(fd, &sl);
		close(fd);
		start_game(&sl);
	}
	else if (argc < 2) //
		ft_error_div(4); //
	else //
		ft_error_div(3); //
	return (EXIT_SUCCESS); //
}
