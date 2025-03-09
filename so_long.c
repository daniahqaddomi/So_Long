/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dqaddomi <dqaddomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:48:24 by daniah            #+#    #+#             */
/*   Updated: 2025/03/09 14:29:19 by dqaddomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize(t_game *game, t_data *data)
{
	game->mlx = NULL;
	game->window = NULL;
	game->img_wall = NULL;
	game->img_player = NULL;
	game->img_exit = NULL;
	game->img_collectible = NULL;
	game->img_empty = NULL;
	game->map = NULL;
	game->row = 0;
	game->column = 0;
	game->img_width = 0;
	game->img_height = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->exit_flag = 0;
	game->moves = 0;
	game->exit_num = 0;
	game->start_pos = 0;
	game->collectibles_num = 0;
	game->i = 0;
	game->j = 0;
	game->x = 0;
	game->y = 0;
	data->position_x = game->player_x;
	data->position_y = game->player_y;
}

void	initialize_game(t_game *game, char *map_path)
{
	initialize(game, &game->data);
	game->map = read_map(game, map_path);
	if (!game->map)
		exit(1);
	if (!validate_map(game))
	{
		ft_printf("Error: Invalid elements\n");
		free_map(game->map);
		exit(1);
	}
	if (!check_walls(game))
	{
		ft_printf("Error: Invalid walls\n");
		free_game(game);
		exit(1);
	}
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		free_game(game);
		exit(1);
	}
	if (img(game))
		exit(1);
	initialize_window(game);
}

int	main(int argc, char *argv[])
{
	t_game	game;
	int		len;

	len = ft_strlen(argv[1]);
	if (argc != 2)
	{
		ft_printf("Error: Invalid number of arguments\n");
		return (1);
	}
	if (ft_strncmp(argv[1] + len - 4, ".ber", 4) != 0)
	{
		ft_printf("Error: Map file must be .ber\n");
		return (1);
	}
	initialize_game(&game, argv[1]);
	render(&game);
	setup_hooks(&game);
	mlx_loop(game.mlx);
	return (0);
}
