/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 11:12:31 by mbelorge          #+#    #+#             */
/*   Updated: 2019/05/02 19:09:31 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int			key_control(int key, t_sl *sl)
{
	sl->speed_moove = 0.2;
	if (key == KEY_W)
		sl->move.av = 1;
	if (key == KEY_S)
		sl->move.rec = -1;
	if (key == KEY_D)
		sl->move.right = 1;
	if (key == KEY_A)
		sl->move.left = 1;
	//if (key == KEY_LEFT || key == KEY_RIGHT)
	//{
	//	sl->move.cam = 1;
	//	if (key == KEY_LEFT)
	//		sl->rotate = 0.1;
	//	else
	//		sl->rotate = -0.1;
	//}
	if (key == ECHAP)
		close_cross(sl);
	return (0);
}

int			key_control2(int key, t_sl *sl)
{
	if (key == KEY_W)
		sl->move.av_rec = 0;
	if (key == KEY_S)
		sl->move.av_rec = 0;
	if (key == KEY_D)
		sl->move.right = 0;
	if (key == KEY_A)
		sl->move.left = 0;
	//if (key == KEY_LEFT || key == KEY_RIGHT)
	//	sl->move.cam = 0;
	if (key == ECHAP)
		close_cross(sl);
	return (0);
}

int			close_cross(t_sl *sl)
{
	sl->save = 1; // a retirer
	free_all(sl);
	exit(EXIT_SUCCESS);
}
