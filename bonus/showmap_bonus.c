/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   showmap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odakhch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:44:58 by odakhch           #+#    #+#             */
/*   Updated: 2022/01/21 15:05:30 by odakhch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

void	wrigth_txt(char c, t_fact fact, int i, int j)
{
	if (c == '1')
		mlx_put_image_to_window(fact.mlx, fact.win, fact.pic.wall.img,
			(fact.pic.wall.w * j), (fact.pic.wall.h * i));
	else if (c == '0')
		mlx_put_image_to_window(fact.mlx, fact.win, fact.pic.floor.img,
			(fact.pic.floor.w * j), (fact.pic.floor.h * i));
	else if (c == 'P')
		mlx_put_image_to_window(fact.mlx, fact.win, fact.pic.player.img,
			(fact.pic.player.w * j), (fact.pic.player.h * i));
	else if (c == 'E')
		mlx_put_image_to_window(fact.mlx, fact.win, fact.pic.exit.img,
			(fact.pic.exit.w * j), (fact.pic.exit.h * i));
	else if (c == 'C')
		mlx_put_image_to_window(fact.mlx, fact.win, fact.pic.collect.img,
			(fact.pic.collect.w * j), (fact.pic.collect.h * i));
	else if (c == 'D')
		mlx_put_image_to_window(fact.mlx, fact.win, fact.pic.enemie.img,
			(fact.pic.enemie.w * j), (fact.pic.enemie.h * i));
}

void	put_txt(t_fact	fact, t_raw	raw)
{
	int	i;
	int	j;

	i = 0;
	while (i < raw.len_l)
	{
		j = 0;
		while (j < raw.len_c)
		{
			wrigth_txt(raw.map[i][j], fact, i, j);
			j++;
		}
		i++;
	}
}

void	init_txt(t_fact	*fact, t_img	*txt, char	*path)
{
	txt->img = mlx_xpm_file_to_image(fact->mlx, path, &txt->h, &txt->w);
}

void	get_txt(t_fact *fact)
{
	init_txt(fact, &fact->pic.floor, FLOOR);
	init_txt(fact, &fact->pic.wall, WALL);
	init_txt(fact, &fact->pic.player, PLAYER);
	init_txt(fact, &fact->pic.collect, COLLECT);
	init_txt(fact, &fact->pic.exit, EXIT);
	init_txt(fact, &fact->pic.enemie, ENEMIE);
}

void	show_map(t_raw	raw)
{
	t_rck	rck;
	t_fact	fact;

	rck.raw = raw;
	rck.map = raw.map;
	rck.cmp = 0;
	fact.mlx = mlx_init();
	if (fact.mlx == NULL)
	{
		error();
	}
	get_txt(&fact);
	fact.win = mlx_new_window(fact.mlx, (fact.pic.floor.w * raw.len_c),
			(fact.pic.floor.h * raw.len_l), "So long_bonus!");
	put_txt(fact, raw);
	rck.fact = fact;
	mlx_hook(fact.win, 17, 0L, &ft_cross, &rck);
	mlx_hook(fact.win, 2, 1L << 0, direction, &rck);
	mlx_loop(fact.mlx);
}
