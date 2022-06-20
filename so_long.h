/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wboutzou <wboutzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 20:23:45 by wboutzou          #+#    #+#             */
/*   Updated: 2022/06/20 20:10:22 by wboutzou         ###   ########.fr       */
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
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

struct so_long{
   char **map;
   int width;
   int height;
   int exit;
   int start;
   int coll;
};
typedef struct so_long t_game;

char    *get_next_line(int fd);
char	*ft_strcpy(char *dest, char *src);
char	**ft_split(char const *s, char c);
char	*ft_strldup(const char *s1, int len);
int	    checkarg(int argc, char *argv);
char *ft_strjoin(char *s1, char *s2);
#endif