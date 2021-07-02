/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:12:31 by mbelorge          #+#    #+#             */
/*   Updated: 2020/05/02 19:09:31 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void		check_arg(t_sl *sl, char **argv)
{
	//printf("\npas de probleme avant checkargs\n");
	if (ft_strlen(argv[1]) < 4)
		ft_error_div(6);
	if ((sl->ext = ft_substr(argv[1], ft_strlen(argv[1]) - 4,
		ft_strlen(argv[1]))) && ft_strncmp(sl->ext, ".ber", 4) != 0)
		ft_error_div(6);
	free(sl->ext);
	//printf("\npas de probleme apres checkargs\n");
}

void		check_error_resolution(t_sl *c)
{
	int		max_x;
	int		max_y;

	if (!c->resol.width || !c->resol.heigth)
		ft_error_fd(1, " ");
	c->mlx_ptr = mlx_init();
	if (c->resol.width < 1 || c->resol.heigth < 1)
		ft_error_fd(1, "xx");
	mlx_get_screen_size(c->mlx_ptr, &max_x, &max_y);
	if (c->resol.width > max_x)
		c->resol.width = max_x;
	if (c->resol.heigth > max_y)
		c->resol.heigth = max_y;
}

