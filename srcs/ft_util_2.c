/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:49:39 by severi            #+#    #+#             */
/*   Updated: 2022/06/15 22:58:33 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	set_up_logging(void)
{
	int	fd;

	fd = open("logs.txt", O_WRONLY);
	if (fd < 0 || fd >= 4096)
	{
		perror("Error: ");
		exit(-1);
	}
	ft_putstr_fd("STARTING NEW LOGGING\n\n", fd);
	return (fd);
}

void	put_logs(char *buf, int fd)
{
	ft_putstr_fd("### ", fd);
	ft_putstr_fd(buf, fd);
	ft_putchar_fd('\n', fd);
}

t_player	*set_up_player(void)
{
	t_player	*player;

	player = (t_player *) malloc(sizeof(t_player));
	player->player_num = 1;
	player->player_char = 'O';
	player->last_pos = 'o';
	player->enemy_char = 'X';
	player->enemy_last_pos = 'x';
	player->x = 0;
	player->y = 0;
	player->best_move = 100;
	player->last_move = 100;
	player->fits = 0;
	return (player);
}

void	exchange_player_chars(t_player *player)
{
	player->player_num = 2;
	player->player_char = 'X';
	player->last_pos = 'x';
	player->enemy_char = 'O';
	player->enemy_last_pos = 'o';
}
