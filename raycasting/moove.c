/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:12:31 by mbelorge          #+#    #+#             */
/*   Updated: 2020/05/02 19:09:31 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	player_stop(t_sl *sl, int x, int y)
{
	if ((sl->map.tabmap[x][y] == '1') ||
		(sl->map.tabmap[x][y] == '2'))
		return (0);
	else
		return (1);
}

void		ft_left_right(t_sl *sl)
{
	int tmpx;
	int tmpy;

	tmpx = sl->player.i;
	tmpy = sl->player.j;
	if (sl->move.right == 1)
	{
		sl->moove ++;
		printf("nb d action %d", sl->moove);
		if (sl->map.tabmap[tmpx][tmpy + 1] == 'X')
		{
			//sl->player.j = sl->player.j + 1;
			sl->point = sl->point - 1;
			if (sl->point <= 0)
				printf("YOUR DEAD\n\n");

		}
		else if (!player_stop(sl, sl->player.i, sl->player.j + 1))
			sl->player.j = tmpy;
		else
		{
			sl->map.tabmap[tmpx][tmpy] = '0';
			sl->player.j = sl->player.j + 1;
			if (sl->map.tabmap[tmpx][tmpy + 1] == 'E' || sl->map.tabmap[tmpx][tmpy + 1] == 'C')
				playing_rules(sl, tmpx, tmpy + 1);
			sl->map.tabmap[tmpx][tmpy + 1] = 'P';
		}
	}
	if (sl->move.left == 1)
	{
		sl->moove ++;
		printf("nb d action %d", sl->moove);
		if (sl->map.tabmap[tmpx][tmpy - 1] == 'X')
		{
			//sl->player.j = sl->player.j - 1;
			sl->point = sl->point - 1;
			if (sl->point <= 0)
			{	printf("YOUR DEAD\n\n");
				sl->loose = 1;}

		}
		else if (!player_stop(sl, sl->player.i, sl->player.j - 1))
			sl->player.j = tmpy;
		else
		{
			sl->map.tabmap[tmpx][tmpy] = '0';
			sl->player.j = sl->player.j - 1;
			if (sl->map.tabmap[tmpx][tmpy - 1] == 'E' || sl->map.tabmap[tmpx][tmpy - 1] == 'C')
				playing_rules(sl, tmpx, tmpy - 1);
			sl->map.tabmap[tmpx][tmpy - 1] = 'P';
		}
	}
	sl->move.right = 0;
	sl->move.left = 0;
}


void check_is_finish(t_sl *cub)
{
//printf("entre dans finish ??\n");
		if (cub->sprite_nb > 0)
		{
			printf("GAME OVER\n\n");
			cub->loose = 1;
			//exit(EXIT_SUCCESS);
		}
		else
		{

			printf("YOU WIN !!!!\n\n");
			cub->win = 1;
		}

}

void playing_rules(t_sl *cub, int i, int j)
{
	if(cub->map.tabmap[i][j] == 'E' || cub->map.tabmap[i][j] == 'X')
		check_is_finish(cub);
	else if (cub->map.tabmap[i][j] == 'C')
		cub->sprite_nb = cub->sprite_nb - 1;
}

void		ft_up_and_down(t_sl *sl)
{
	int tmpx;
	int tmpy;
	//printf("player,x = %d, le y est a %d dans up et down\n", sl->player.i, sl->player.j);
	tmpx = sl->player.i;
	tmpy = sl->player.j;
	if (sl->move.av != 0)
	{
		sl->moove++;
		printf("nb d action %d", sl->moove);
		if (sl->map.tabmap[tmpx - 1][tmpy] == 'X')
		{
			//sl->player.i = sl->player.i - 1;
			sl->point = sl->point - 1;
			if (sl->point <= 0)
				printf("YOUR DEAD\n\n");

		}
		else if (!player_stop(sl, sl->player.i - 1, sl->player.j))
			sl->player.i = tmpx;
		else
		{
			sl->map.tabmap[tmpx][tmpy] = '0';
			sl->player.i = sl->player.i - 1;
			if (sl->map.tabmap[tmpx - 1][tmpy] == 'E' || sl->map.tabmap[tmpx - 1][tmpy] == 'C')
				playing_rules(sl, tmpx - 1, tmpy);
			sl->map.tabmap[tmpx - 1][tmpy] = 'P';
		}
	}
	if (sl->move.rec != 0)
	{
		sl->moove++;
		printf("nb d action %d", sl->moove);
		if (sl->map.tabmap[tmpx + 1][tmpy] == 'X')
		{
			//sl->player.i = sl->player.i + 1;
			sl->point = sl->point - 1;
			if (sl->point <= 0)
				printf("YOUR DEAD\n\n");
		}
		else if (!player_stop(sl, sl->player.i + 1, sl->player.j))
			sl->player.i = tmpx;
		else
		{
			sl->map.tabmap[tmpx][tmpy] = '0';
			sl->player.i = sl->player.i + 1;
			if (sl->map.tabmap[tmpx + 1][tmpy] == 'E' || sl->map.tabmap[tmpx + 1][tmpy] == 'C')
				playing_rules(sl, tmpx + 1, tmpy);
			sl->map.tabmap[tmpx + 1][tmpy] = 'P';
		}
	}
	sl->move.av = 0;
	sl->move.rec = 0;
}
