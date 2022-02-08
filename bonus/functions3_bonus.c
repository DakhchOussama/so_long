/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odakhch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:44:58 by odakhch           #+#    #+#             */
/*   Updated: 2022/01/21 15:02:06 by odakhch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

size_t	taille(int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
		i++;
	while (nb)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t	i;
	char	*tab;
	long	nb;

	i = taille(n);
	nb = n;
	tab = malloc(i + 1 * sizeof(char));
	if (!tab)
		return (NULL);
	if (nb < 0)
	{
		tab[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		tab[0] = '0';
	tab[i--] = '\0';
	while (nb)
	{
		tab[i] = nb % 10 + '0';
		i--;
		nb = nb / 10;
	}
	return (tab);
}
