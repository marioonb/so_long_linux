/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:12:31 by mbelorge          #+#    #+#             */
/*   Updated: 2020/05/02 19:09:31 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_double_tab(char **tab, int lenght)
{
	int	i;

	i = 0;
	while (i < lenght)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_all(t_sl *sl)
{
	if (sl->mlx_ptr && sl->win_ptr)
	{
		mlx_clear_window(sl->mlx_ptr, sl->win_ptr);
		mlx_destroy_window(sl->mlx_ptr, sl->win_ptr);
	}
	free_double_tab(sl->old_map.tabmap, sl->map.lo);
	free_double_tab(sl->map.tabmap, sl->map.lo);
	//free_orientation(sl);
}

/*void	free_orientation(t_sl *sl)
{
	if (sl->t_so.orientation)
		free(sl->t_so.orientation);
	if (sl->t_so.path)
		free(sl->t_so.path);
	if (sl->t_we.orientation)
		free(sl->t_we.orientation);
	if (sl->t_we.path)
		free(sl->t_we.path);
	if (sl->t_ea.orientation)
		free(sl->t_ea.orientation);
	if (sl->t_ea.path)
		free(sl->t_ea.path);
	if (sl->player.orientation != NULL)
		free(sl->player.orientation);
	if (sl->player.path != NULL)
		free(sl->player.path);
	if (sl->t_spr.orientation != NULL)
		free(sl->t_spr.orientation);
	if (sl->t_spr.path != NULL)
		free(sl->t_spr.path);
}*/
