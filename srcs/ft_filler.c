/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:38:19 by severi            #+#    #+#             */
/*   Updated: 2022/06/15 23:04:40 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_player	*set_up_player(void)
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
	return (player);
}

static void	exchange_player_chars(t_player *player)
{
	player->player_num = 2;
	player->player_char = 'X';
	player->last_pos = 'x';
	player->enemy_char = 'O';
	player->enemy_last_pos = 'o';
}

int	main(void)
{
	char		*buf;
	int			fd;
	int			read;
	int			row_num;
	char		*found;
	int			end;
	t_player	*player;
	t_base		*map;
	t_base		*piece;

	end = 0;
	read = 1;
	row_num = 0;
	player = set_up_player();
	fd = open("logs.txt", O_WRONLY);
	ft_putstr_fd("STARTING NEW LOGGING\n\n", fd);
	read = get_next_line(0, &buf);
	found = ft_strstr(buf, "exec p1");
	if (found == NULL)
		exchange_player_chars(player);
	found = NULL;
	ft_strdel(&buf);
	read = get_next_line(0, &buf);
	found = ft_strstr(buf, "Plateau");
	if (found != NULL)
	{
		map = create_empty(get_dim(buf, 1), get_dim(buf, 2));
		print_map(map, fd);
	}
	found = NULL;
	ft_strdel(&buf);
	while (1 && end == 0)
	{
		while ((read = get_next_line(0, &buf)) != 0 && end == 0)
		{
			ft_putstr_fd("### ", fd);
			ft_putstr_fd(buf, fd);
			ft_putchar_fd('\n', fd);
			found = ft_strstr(buf, "Piece");
			if (ft_isdigit(buf[0]) == 1)
				update_map(map, buf);
			else if (found != NULL)
			{
				piece = create_empty(get_dim(buf, 1), get_dim(buf, 2));
				found = NULL;
			}
			else if (buf[0] == '.' || buf[0] == '*')
			{
				row_num = row_num + update_piece(piece, buf);
				if (piece->height == row_num)
				{
					end = place_piece(piece, map, player, fd);
					row_num = 0;
					free_base(&piece);
				}
			}
			ft_strdel(&buf);
		}
	}
	return (0);
}
