/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveplayer_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odakhch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:41:55 by odakhch           #+#    #+#             */
/*   Updated: 2022/01/21 15:02:59 by odakhch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

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
	if (rck->map[rck->raw.y][rck->raw.x - 1] == 'D')
		lose();
	rck->map[rck->raw.y][rck->raw.x] = '0';
	rck->map[rck->raw.y][rck->raw.x - 1] = 'P';
	ft_player_position(rck);
	rck->cmp++;
	put_txt(rck->fact, rck->raw);
	display_map(rck);
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
	if (rck->map[rck->raw.y - 1][rck->raw.x] == 'D')
		lose();
	rck->map[rck->raw.y][rck->raw.x] = '0';
	rck->map[rck->raw.y - 1][rck->raw.x] = 'P';
	ft_player_position(rck);
	rck->cmp++;
	put_txt(rck->fact, rck->raw);
	display_map(rck);
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
	if (rck->map[rck->raw.y][rck->raw.x + 1] == 'D')
		lose();
	rck->map[rck->raw.y][rck->raw.x] = '0';
	rck->map[rck->raw.y][rck->raw.x + 1] = 'P';
	ft_player_position(rck);
	rck->cmp++;
	put_txt(rck->fact, rck->raw);
	display_map(rck);
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
	if (rck->map[rck->raw.y + 1][rck->raw.x] == 'D')
		lose();
	rck->map[rck->raw.y][rck->raw.x] = '0';
	rck->map[rck->raw.y + 1][rck->raw.x] = 'P';
	ft_player_position(rck);
	rck->cmp++;
	put_txt(rck->fact, rck->raw);
	display_map(rck);
}
