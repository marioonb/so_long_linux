/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 09:10:07 by mbelorge          #+#    #+#             */
/*   Updated: 2020/07/02 23:04:23 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void				search_number_sprite(t_sl *sl)
{
	int				x;
	int				y;

	x = 0;
	while (x < sl->map.lo)
	{
		y = 0;
		while (y < sl->map.la)
		{
			if (sl->map.tabmap[x][y] == 'C')
				sl->sprite_nb++;
			y++;
		}
		x++;
	}
}

