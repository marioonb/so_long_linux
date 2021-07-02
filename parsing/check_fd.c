/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:12:31 by mbelorge          #+#    #+#             */
/*   Updated: 2020/05/02 19:09:31 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void		ft_read_fd(int fd, t_sl *sl)
{
	char	*line;
	line = NULL;


	sl->map.tabmap = malloc (sizeof(char*) * sl->map.lo + 1);
	for(int i = 0; i < sl->map.lo; i++) // 3 colonnes
		sl->map.tabmap[i] = (char*) malloc( sizeof(char) * sl->map.la + 1);
	//printf("largeur de map = %d\n", sl->map.la);
	while (get_next_line(fd, &line) == 1)
	{
		//if (line[0] == '1') // AJ
			check_map(line, sl);
		free(line);
	}
	//free(line);
	sl->map.tabmap[sl->map.lo] = NULL;
	//ft_read_tab_char(sl->map.tabmap);
	check_error_border_map(sl->map.tabmap, sl->map);
	check_error_inside_map(sl->map.tabmap, sl->map);
	free(line);
}
