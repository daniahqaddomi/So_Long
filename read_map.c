/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dqaddomi <dqaddomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 00:21:41 by daniah            #+#    #+#             */
/*   Updated: 2025/03/09 15:17:41 by dqaddomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_line(int fd, t_game *game, char *tmp)
{
	char	*line;
	char	*join;

	line = get_next_line(fd);
	while (line)
	{
		if (game->column == 0)
			game->column = ft_strlen(line) - 1;
		else if ((ft_strchr(line, '\n') && ft_strlen(line) - 1 != game->column)
			|| (!ft_strchr(line, '\n') && ft_strlen(line) != game->column))
		{
			free(line);
			free(tmp);
			get_next_line(-1);
			ft_printf("Error: Map is not rectangular\n");
			return (NULL);
		}
		join = ft_strjoin(tmp, line);
		free(tmp);
		tmp = join;
		free(line);
		game->row++;
		line = get_next_line(fd);
	}
	return (tmp);
}

char	**read_map(t_game *game, char *file_path)
{
	int		fd;
	char	*tmp;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening map");
		return (NULL);
	}
	tmp = ft_strdup("");
	if (!tmp)
		return (NULL);
	tmp = read_line(fd, game, tmp);
	close(fd);
	if (!tmp)
		return (NULL);
	if (empty_map(game) == 1)
	{
		free(tmp);
		return (NULL);
	}
	game->map = ft_split(tmp, '\n');
	free(tmp);
	return (game->map);
}

int	empty_map(t_game *game)
{
	if (game->row == 0 || game->column == 0)
	{
		free_game(game);
		ft_printf("Empty map\n");
		return (1);
	}
	return (0);
}

int	validate_map_elements(t_game *game)
{
	while (game->i < game->row)
	{
		game->j = 0;
		while (game->j < game->column)
		{
			if (!ft_strchr("01EPC", game->map[game->i][game->j]))
				return (0);
			if (game->map[game->i][game->j] == 'E')
				game->exit_num++;
			else if (game->map[game->i][game->j] == 'P')
			{
				game->start_pos++;
				game->player_x = game->j;
				game->player_y = game->i;
			}
			else if (game->map[game->i][game->j] == 'C')
				game->collectibles_num++;
			game->j++;
		}
		game->i++;
	}
	return (1);
}

int	validate_map(t_game *game)
{
	if (!validate_map_elements(game))
		return (0);
	if (!check_map_elements(game))
		return (0);
	if (!check_game_access(game))
	{
		ft_printf("Error: The map's elements order is incorrect\n");
		free_game(game);
		exit(1);
	}
	return (1);
}
