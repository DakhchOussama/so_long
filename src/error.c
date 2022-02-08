/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odakhch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:41:45 by odakhch           #+#    #+#             */
/*   Updated: 2022/01/18 20:43:53 by odakhch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	error(void)
{
	write(1, "ERROR", 5);
	exit(EXIT_FAILURE);
}

void	exit_game(void)
{
	write(1, "good game", 9);
	exit(EXIT_FAILURE);
}

void	exit_game2(void)
{
	write(1, "By", 2);
	exit(EXIT_FAILURE);
}

void	map_exit(char	*message)
{
	ft_putstr(message);
	exit(EXIT_FAILURE);
}
