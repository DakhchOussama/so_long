/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   showmap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odakhch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:28:14 by odakhch           #+#    #+#             */
/*   Updated: 2022/01/19 17:28:18 by odakhch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	free_mlx(t_fact	*fact)
{
	if (fact->mlx)
	{
		mlx_destroy_image(fact->mlx, fact->pic.floor.img);
		mlx_destroy_image(fact->mlx, fact->pic.player.img);
		mlx_destroy_image(fact->mlx, fact->pic.exit.img);
		mlx_destroy_image(fact->mlx, fact->pic.wall.img);
		mlx_destroy_image(fact->mlx, fact->pic.collect.img);
		mlx_destroy_window(fact->mlx, fact->win);
		mlx_clear_window(fact->mlx, fact->win);
		free(fact->mlx);
	}
	exit_game2();
}

int	ft_cross(t_rck	*rck)
{
	free_mlx(&rck->fact);
	return (0);
}
