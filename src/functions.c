/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odakhch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:18:15 by odakhch           #+#    #+#             */
/*   Updated: 2022/01/19 13:13:27 by odakhch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i += 2;
	}
}

int	ft_strlen(const char	*str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		++i;
	}
	return (i);
}

char	*ft_strjoin(char	*s1, char	*s2)
{
	char	*res;
	int		len;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = 0;
	}
	len = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	free(s1);
	return (res);
}

char	*ft_strdup(const char	*s1)
{
	char	*tab;
	size_t	i;
	size_t	length;

	length = ft_strlen(s1);
	tab = malloc(length + 1 * sizeof(char));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < length)
	{
		tab[i] = s1[i];
		++i;
	}
	tab[i] = '\0';
	return (tab);
}
