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

static t_base	*get_player_and_map(t_player *player, char *buf, int fd)
{
	int		read;
	char	*found;
	t_base	*map;

	read = get_next_line(0, &buf);
	if (read == 0)
	{
		perror("Error no input in stdin: ");
		exit(-1);
	}
	found = ft_strstr(buf, "exec p1");
	if (found == NULL)
		exchange_player_chars(player);
	found = NULL;
	ft_strdel(&buf);
	read = get_next_line(0, &buf);
	found = ft_strstr(buf, "Plateau");
	if (found != NULL)
		map = create_empty(get_dim(buf, 1), get_dim(buf, 2));
	else
		map = create_empty(1, 1);
	print_map(map, fd);
	found = NULL;
	ft_strdel(&buf);
	return (map);
}

static int	piece_loop(t_base *piece, t_base *map, t_player *player, char *buf)
{
	static int	row_num;
	int			end;

	end = 0;
	row_num = row_num + update_piece(piece, buf);
	if (piece->height == row_num)
	{
		end = place_piece(piece, map, player);
		row_num = 0;
		free_base(&piece);
	}
	return (end);
}

static void	main_while(t_base *map, t_player *player, int fd, char *buf)
{
	char	*found;
	int		end;
	t_base	*piece;

	end = 0;
	while (get_next_line(0, &buf) != 0 && end == 0)
	{
		put_logs(buf, fd);
		found = ft_strstr(buf, "Piece");
		if (ft_isdigit(buf[0]) == 1)
			update_map(map, buf);
		else if (found != NULL)
		{
			piece = create_empty(get_dim(buf, 1), get_dim(buf, 2));
			found = NULL;
		}
		else if (buf[0] == '.' || buf[0] == '*')
			end = piece_loop(piece, map, player, buf);
		ft_strdel(&buf);
	}
}

int	main(void)
{
	char		*buf;
	int			fd;
	t_player	*player;
	t_base		*map;

	player = set_up_player();
	fd = set_up_logging();
	buf = ft_strnew(1);
	map = get_player_and_map(player, buf, fd);
	main_while(map, player, fd, buf);
	ft_putchar_fd('\n', fd);
	ft_putstr_fd("ERROR: Piece doesn't fit anywhere\n", fd);
	insert_piece(0, 0);
	free_player(&player);
	free_base(&map);
	close(fd);
	return (0);
}
