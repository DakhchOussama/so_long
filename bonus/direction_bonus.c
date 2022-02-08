/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odakhch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 22:18:07 by odakhch           #+#    #+#             */
/*   Updated: 2022/01/19 23:14:55 by odakhch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

int	win_cond_right(t_rck	*rck)
{
	if (rck->map[rck->raw.y][rck->raw.x - 1] != 'E' ||
			(rck->map[rck->raw.y][rck->raw.x - 1] == 'E' &&
	rck->raw.collectible == 0))
		return (1);
	return (0);
}

int	win_cond_up(t_rck	*rck)
{
	if (rck->map[rck->raw.y - 1][rck->raw.x] != 'E' ||
			(rck->map[rck->raw.y - 1][rck->raw.x] == 'E' &&
	rck->raw.collectible == 0))
		return (1);
	return (0);
}

int	win_cond_left(t_rck	*rck)
{
	if (rck->map[rck->raw.y][rck->raw.x + 1] != 'E' ||
			(rck->map[rck->raw.y][rck->raw.x + 1] == 'E' &&
	rck->raw.collectible == 0))
		return (1);
	return (0);
}

int	win_cond_dowm(t_rck	*rck)
{
	if (rck->map[rck->raw.y + 1][rck->raw.x] != 'E' ||
			(rck->map[rck->raw.y + 1][rck->raw.x] == 'E' &&
	rck->raw.collectible == 0))
		return (1);
	return (0);
}

int	direction(int keyboard, t_rck *rck)
{
	ft_player_position(rck);
	if (keyboard == 53)
		exit_game2();
	else if (keyboard == 0 && rck->map[rck->raw.y][rck->raw.x - 1] != '1' &&
			win_cond_right(rck))
		move_right(rck);
	else if (keyboard == 13 && rck->map[rck->raw.y - 1][rck->raw.x] != '1' &&
			win_cond_up(rck))
		move_up(rck);
	else if (keyboard == 2 && rck->map[rck->raw.y][rck->raw.x + 1] != '1' &&
			win_cond_left(rck))
		move_left(rck);
	else if (keyboard == 1 && rck->map[rck->raw.y + 1][rck->raw.x] != '1' &&
			win_cond_right(rck))
		move_down(rck);
	return (0);
}
