/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dqaddomi <dqaddomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 00:31:34 by daniah            #+#    #+#             */
/*   Updated: 2025/03/09 15:09:59 by dqaddomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_elements(t_game *game)
{
	if (game->exit_num != 1)
	{
		ft_printf("Error: Invalid number of exit\n");
		free_game(game);
		exit(1);
	}
	if (game->start_pos != 1)
	{
		ft_printf("Error: Invalid number of player\n");
		free_game(game);
		exit(1);
	}
	if (game->collectibles_num == 0)
	{
		ft_printf("Error: No collectibles found\n");
		free_game(game);
		exit(1);
	}
	return (1);
}

int	check_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->column)
	{
		if (game->map[0][i] != '1' || game->map[game->row - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < game->row)
	{
		if (game->map[i][0] != '1' || game->map[i][game->column - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
