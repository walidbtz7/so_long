/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wboutzou <wboutzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 20:33:07 by wboutzou          #+#    #+#             */
/*   Updated: 2022/06/20 22:43:19 by wboutzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int checkarg(int argc, char *argv)
{
	char *ft;
	int fd;
  
	if (argc == 2)
	{
		fd = open(argv, O_RDONLY);
		if (fd < 0)
		{
			printf("the map file not found :)");
			return (0);
		}
		ft = strrchr(argv, '.');
		if (!strcmp(ft, ".ber"))
			return (fd);
		else
			printf("the map format is .ber :)");
	}
	else
		printf("you missing something (map) :) ");
	
	return (0);
}
int check_wall(t_game	*game)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (i < game->height)
	{
		if(i == 0 || i == game->height - 1)
		{
			j = 0;
			while (game->map[i][j] != '\0')
			{
				if(game->map[i][j] != '1')
					return (0);
				j++;	
			}
		}
		else
			if(game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
				return (0);
		i ++;
	}
	return (1);
}
int checkalpha(t_game *game)
{
	int	i;
	int j;

	i = 1;
	while (i < game->height - 1)
	{
		j = 1;
		while (j < game->width - 2)
		{
			if(game->map[i][j] == 'C')
			{
				game->coll++;
			}
			else if(game->map[i][j] == 'E')
				game->exit++;
			else if(game->map[i][j] == 'P')
			{	
				game->start++;
			}
			else if(game->map[i][j] != '1' && game->map[i][j] != '0')
				return (0);
			j++;
		}
		i++;
	}
	if(game->coll < 1 || game->exit < 1|| game->start < 1)
		return (0);
	return (1);
}
int check_size(t_game	*game)
{
	int	i;

	i = 0;
	if(game->map[i++] == '\0')
		return (0);
	while (game->map[i] != '\0')
	{
		if(ft_strlen(game->map[i - 1]) != ft_strlen(game->map[i]))
			return (0);
		i++;
	}
	game->width = ft_strlen(game->map[i - 1]);
	game->height = i;
	return (1);
}
int checker_map(t_game *game)
{
	if(!check_size(game) || !check_wall(game))
		return (0);
	if(!checkalpha(game))
		return (0);
	return (1);
}
int	check_read(char *read)
{
	int	i;
	int	j;
	int	n;
	int pos;

	pos = 0;
	i = 0;
	j = 0;
	n = 0;
	if(read[0] == '\n')
		return (0);
	while (read[i] != '\0')
	{
		if(read[i] == '\n' && (read[i + 1] == '\n' || read[i + 1] == '\0'))
			return (0);
		i++;
	}
	return (1);	
}
void matrix(int fd,t_game *game)
{
    char    *read;
	int i;

	i = 0;
    read = get_next_line(fd);   
	if(read == NULL)
		return ;
	if(!check_read(read))
		return ;
    game->map = ft_split(read,'\n');
	if(game->map == NULL)
		return ;
}

int main(int argc, char **argv)
{
	int fd;
	int i;
	t_game game;

	i = 0;
	fd = checkarg(argc, argv[1]);
	if (fd == 0)
		return (0);
	matrix(fd,&game);
	if(game.map == NULL)
	{
		ft_printf("Error\n");
		return (0);
	}
	if(!checker_map(&game))
		ft_printf("Error\n");
	return (0);
}