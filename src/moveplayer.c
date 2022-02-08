/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveplayer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odakhch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:03:17 by odakhch           #+#    #+#             */
/*   Updated: 2022/01/19 13:35:08 by odakhch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	move_right(t_rck	*rck)
{
	if (rck->map[rck->raw.y][rck->raw.x - 1] == 'C')
		rck->raw.collectible--;
	if ((rck->map[rck->raw.y][rck->raw.x - 1] == '1'
		|| rck->map[rck->raw.y][rck->raw.x - 1] == 'E') &&
			rck->raw.collectible != 0)
		return ;
	if (rck->map[rck->raw.y][rck->raw.x - 1] == 'E')
	{
		free(rck->map);
		exit_game();
	}
	rck->map[rck->raw.y][rck->raw.x] = '0';
	rck->map[rck->raw.y][rck->raw.x - 1] = 'P';
	ft_player_position(rck);
	printf("%d\n", rck->cmp++);
	put_txt(rck->fact, rck->raw);
}

void	move_up(t_rck	*rck)
{
	if (rck->map[rck->raw.y - 1][rck->raw.x] == 'C')
		rck->raw.collectible--;
	if ((rck->map[rck->raw.y - 1][rck->raw.x] == '1'
		|| rck->map[rck->raw.y - 1][rck->raw.x] == 'E') &&
			rck->raw.collectible != 0)
		return ;
	if (rck->map[rck->raw.y - 1][rck->raw.x] == 'E')
	{
		free(rck->map);
		exit_game();
	}
	rck->map[rck->raw.y][rck->raw.x] = '0';
	rck->map[rck->raw.y - 1][rck->raw.x] = 'P';
	ft_player_position(rck);
	printf("%d\n", rck->cmp++);
	put_txt(rck->fact, rck->raw);
}

void	move_left(t_rck	*rck)
{
	if (rck->map[rck->raw.y][rck->raw.x + 1] == 'C')
		rck->raw.collectible--;
	if ((rck->map[rck->raw.y][rck->raw.x + 1] == '1'
		|| rck->map[rck->raw.y][rck->raw.x + 1] == 'E') &&
			rck->raw.collectible != 0)
		return ;
	if (rck->map[rck->raw.y][rck->raw.x + 1] == 'E')
	{
		free(rck->map);
		exit_game();
	}
	rck->map[rck->raw.y][rck->raw.x] = '0';
	rck->map[rck->raw.y][rck->raw.x + 1] = 'P';
	ft_player_position(rck);
	printf("%d\n", rck->cmp++);
	put_txt(rck->fact, rck->raw);
}

void	move_down(t_rck	*rck)
{
	if (rck->map[rck->raw.y + 1][rck->raw.x] == 'C')
		rck->raw.collectible--;
	if ((rck->map[rck->raw.y + 1][rck->raw.x] == '1'
		|| rck->map[rck->raw.y + 1][rck->raw.x] == 'E') &&
			rck->raw.collectible != 0)
		return ;
	if (rck->map[rck->raw.y + 1][rck->raw.x] == 'E')
	{
		free(rck->map);
		exit_game();
	}
	rck->map[rck->raw.y][rck->raw.x] = '0';
	rck->map[rck->raw.y + 1][rck->raw.x] = 'P';
	ft_player_position(rck);
	printf("%d\n", rck->cmp++);
	put_txt(rck->fact, rck->raw);
}
