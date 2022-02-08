/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odakhch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:51:50 by odakhch           #+#    #+#             */
/*   Updated: 2022/01/19 18:38:45 by odakhch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_BONUS_H
# define SOLONG_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>

# define FLOOR	"img/floor.xpm"
# define WALL	"img/wall.xpm"
# define PLAYER	"img/player.xpm"
# define COLLECT	"img/collect.xpm"
# define EXIT	"img/exit.xpm"
# define ENEMIE	"img/enemie.xpm"

typedef struct t_raw
{
	char	**map;
	int		len_l;
	int		len_c;
	int		player;
	int		collectible;
	int		exit;
	int		wall;
	int		enemie;
	int		space;
	int		x;
	int		y;
}				t_raw;

typedef struct t_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		h;
	int		w;
}				t_img;

typedef struct t_pic
{
	t_img	floor;
	t_img	player;
	t_img	collect;
	t_img	exit;
	t_img	wall;
	t_img	enemie;
}				t_pic;

typedef struct t_fact
{
	int		x;
	int		y;
	t_pic	pic;
	void	*mlx;
	void	*win;
	int		pos_enemie;
}				t_fact;

typedef struct t_rck
{
	t_fact	fact;
	t_raw	raw;
	char	**map;
	int		cmp;
}				t_rck;

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(const char	*str);
char	*ft_strdup(const char	*s1);
size_t	ft_strlcpy(char *dst, const char	*src, size_t	size);
char	*ft_strjoin(char	*s1, char	*s2);
char	*red_line(int fd);
char	*ft_read_file(int fd);
char	**ft_split(const char *s, char c);
char	**free_t(unsigned int i, char **tab);
char	*ft_itoa(int n);
size_t	taille(int nb);
void	verif_map(t_raw *raw);
int		rowlenght(t_raw *raw);
void	parse_map(t_raw *raw);
void	size_map(t_raw *raw);
void	test(t_raw	*raw, int r, int c);
void	init_txt(t_fact *fact, t_img *txt, char *path);
void	get_txt(t_fact *fact);
void	wrigth_txt(char c, t_fact fact, int i, int j);
void	put_txt(t_fact	fact, t_raw	raw);
void	free_mlx(t_fact *fact);
int		ft_cross(t_rck *rck);
int		win_cond_right(t_rck *rck);
int		win_cond_up(t_rck *rck);
int		win_cond_left(t_rck *rck);
int		win_cond_dowm(t_rck *rck);
void	ft_player_position(t_rck *rck);
void	move_right(t_rck *rck);
void	move_up(t_rck *rck);
void	move_left(t_rck *rck);
void	move_down(t_rck *rck);
int		direction(int keyboard, t_rck *rck);
void	show_map(t_raw raw);
void	error(void);
void	exit_game(void);
void	exit_game2(void);
void	map_exit(char *message);
void	lose(void);
void	display_map(t_rck *rck);

#endif
