/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyzing_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odakhch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:37:43 by odakhch           #+#    #+#             */
/*   Updated: 2022/01/19 23:14:34 by odakhch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

void	ft_player_position(t_rck	*rck)
{
	int	r;
	int	c;

	r = 0;
	while (r < rck->raw.len_l)
	{
		c = 0;
		while (c < rck->raw.len_c)
		{
			if (rck->map[r][c] == 'P')
			{
				rck->raw.x = c;
				rck->raw.y = r;
			}
			c++;
		}
		r++;
	}
}

void	display_map(t_rck	*rck)
{
	char	*str;

	str = ft_itoa(rck->cmp);
	mlx_string_put(rck->fact.mlx, rck->fact.win, 30, 30, 0xFFFFFF, "MOVES :");
	mlx_string_put(rck->fact.mlx, rck->fact.win, 120, 30, 0xFFFFFF, str);
	free(str);
}

void	verif_map(t_raw	*raw)
{
	if (raw->collectible < 1)
		map_exit("Error : no collectible\n");
	if (raw->exit < 1)
		map_exit("Error : no exit\n");
	if (raw->player == 0)
		map_exit("Error : no player\n");
	if (raw->exit > 1)
		error();
	if (raw->player > 1)
		error();
	if (raw->enemie == 0)
		map_exit("Error : no enemie\n");
}

void	test(t_raw *raw, int r, int c )
{
	if ((r == 0 || r == raw->len_l - 1) && raw->map[r][c] != '1')
		error();
	else if ((c == 0 || c == raw->len_c - 1) && raw->map[r][c] != '1')
		error();
}

void	parse_map(t_raw	*raw)
{
	int	r;
	int	c;

	r = 0;
	while (r < raw->len_l)
	{
		c = 0;
		while (c < raw->len_c)
		{
			test(raw, r, c);
			if (raw->map[r][c] == 'C')
				raw->collectible++;
			else if (raw->map[r][c] == 'E')
				raw->exit++;
			else if (raw->map[r][c] == 'P')
				raw->player++;
			else if (raw->map[r][c] == '1')
				raw->wall++;
			else if (raw->map[r][c] == 'D')
				raw->enemie++;
			c++;
		}
		r++;
	}
	verif_map(raw);
}
