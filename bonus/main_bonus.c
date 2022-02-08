/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odakhch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 22:06:24 by odakhch           #+#    #+#             */
/*   Updated: 2022/02/07 22:30:34 by odakhch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

int	rowlenght(t_raw	*raw)
{
	int	row;

	row = 0;
	while (raw->map[row])
		row++;
	return (row);
}

void	size_map(t_raw	*raw)
{
	int	i;
	int	j;

	i = 0;
	raw->len_l = rowlenght(raw);
	if (raw->len_l == 0)
	{
		free(raw->map);
		error();
	}
	raw->len_c = ft_strlen(raw->map[0]);
	while (i < raw->len_l)
	{
		j = 0;
		while (j < raw->len_c)
		{
			if (ft_strlen(raw->map[i]) != raw->len_c)
			{
				error();
			}
			j++;
		}
		i++;
	}
	parse_map(raw);
}

char	**ft_return_map(char	*file, int	*i)
{
	int		j;
	char	**dst;

	j = 0;
	while (file[j])
	{
		if ((file[j] == '\n' && file[j + 1] == '\n')
			|| file[0] == '\n'
			|| (file[j] == '\n' && file[j + 1] == '\0'))
			*i = -1;
		j++;
	}
	dst = ft_split(file, '\n');
	if (!dst)
		return (NULL);
	return (dst);
}

void	ft_read_map(char	*file, t_raw	*raw)
{
	int	i;

	i = 0;
	raw->map = ft_return_map(file, &i);
	if (raw->map == NULL)
		return ;
	if (i == -1)
	{
		error();
		return ;
	}
}

int	main(int argc, char **av)
{
	int		fd;
	t_raw	raw;
	int		i;
	char	*res;

	if (argc == 2 && av[1])
	{
		i = 0;
	fd = open(av[1], O_RDONLY);
		(void)argc;
		if (fd < 0)
			error();
	res = ft_read_file(fd);
		ft_read_map(res, &raw);
		size_map(&raw);
		show_map(raw);
	}
	else
		printf("INVALID NUMBERE OF ARGUMENT \n");
	return (0);
}
