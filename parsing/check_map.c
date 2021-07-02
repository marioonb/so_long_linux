/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:12:31 by mbelorge          #+#    #+#             */
/*   Updated: 2020/05/02 19:09:31 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	charactere_valide(char c)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P' || c == 'X')
		return (1);
	else
		return (0);
}

/*
** verifie les erreurs dans la map
*/

void		check_error_inside_map(char **map, t_map m)
{
	int		x;
	int		y;

	x = 0;
	while (x < m.lo)
	{
		y = 0;
		while (y < m.la)
		{
			if (charactere_valide(map[x][y]) != 1)
				ft_error_map(4, map[x][y], x, y);
			if (map[x][y] != '1' && map[x][y] != '4')
			{
				if (map[x - 1][y] == '4' || map[x + 1][y] == '4' ||
				map[x][y + 1] == '4' || map[x][y - 1] == '4')
					ft_error_map(5, 'x', x, y);
			}
			y++;
		}
		x++;
	}
}

/*
** verfie que les bords de la map sont bien à 1
*/

void		check_error_border_map(char **map, t_map m)
{
	int		x;
	int		y;

	x = 0;
	while (x < m.lo)
	{
		y = 0;
		while (y < m.la)
		{
			if ((x == 0 || x == m.lo - 1 || y == m.la - 1 || y == 0)
				&& (map[x][y] != '1'))
				ft_error_map(1, ' ', x, y);
			y++;
		}
		x++;
	}
}

/*
** verifie chaque ligne de la map
*/

/*void		check_line(char *line, char a)
{
	char	*temp;
	int		lenght;

	//temp = ft_strtrim(line, " ");
	lenght = ft_strlen(temp);
	if (temp[0] != '1')
		ft_error_map(2, ' ', a, 0);
	if (temp[lenght - 1] != '1')
		ft_error_map(3, ' ', a, 0);
	free(temp);
}*/
