/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:43:01 by mbelorge          #+#    #+#             */
/*   Updated: 2020/01/02 16:45:14 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
** parcours la ligne envoyée et rempli la map,
** si la longueur est plus courte que la plus longue ligne, ajoute un espace
*/

void			fill_map(char **map, char *line, t_map m)
{
	int			i;

	m.y = 0;
	i = 0;
	//printf("line est a %s\n", line);
	while (m.y < m.la && m.x <= m.lo)
	{
		map[m.x][m.y] = line[0];
		line++;
		m.y++;
	}
	map[m.x][m.y] = '\0';
	//ft_read_tab_char(map);
//	printf("\npas de probleme apres fill_map\n");
}


void			check_map(char *ligne, t_sl *sl)
{
	//printf("\npas de probleme avant check_map\n");
	if ((int)ft_strlen(ligne) != sl->map.la)
		ft_error_div(2);
//	printf ("car ligne est a %d et la est a %d\n", (int)ft_strlen(ligne), c->map.la);
	//check_error_border_map(c->map.tabmap, c->map);
	//check_error_inside_map(c->map.tabmap, c->map);
	fill_map(sl->map.tabmap, ligne, sl->map);
	sl->map.x++;
	//printf("\npas de probleme aprescheck_map\n");
	//printf("OUOUOUOUOU\n");
	//	dprintf(1, "la resol est %d ,%d\n", sl->resol.width, sl->resol.heigth);
}
