/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wboutzou <wboutzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 20:23:45 by wboutzou          #+#    #+#             */
/*   Updated: 2022/06/25 21:23:08 by wboutzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <string.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

struct	s_pos{
	int	player_x;
	int	player_y;
};
typedef struct s_pos	t_pos;

struct	s_count{
	int	exit;
	int	start;
	int	coll;
	int	moves;
};
typedef struct s_count	t_count;

struct s_o_long{
	void		*mlx;
	void		*mlx_win;
	char		**map;
	int			width;
	int			height;
	void		*e;
	void		*p;
	void		*c;
	void		*o;
	void		*wall;
	t_count		count;
	t_pos		pos;
};
typedef struct s_o_long	t_game;

char	*get_next_line(int fd);
char	*ft_strcpy(char *dest, char *src);
char	**ft_split(char const *s, char c);
char	*ft_strldup(const char *s1, int len);
int		checkarg(int argc, char *argv);
char	*ft_strjoin(char *s1, char *s2);
void	matrix(int fd, t_game *game);
void	window(t_game *game);
void	render(t_game *game);
int		checker_map(t_game *game);
int		key_hook(int keycode, t_game *game);
void	switch_pos(t_game *game, int step_y, int step_x);
#endif