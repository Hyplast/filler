/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:39:24 by severi            #+#    #+#             */
/*   Updated: 2022/05/03 07:04:10 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include "get_next_line.h"

typedef struct	s_player
{
	int			player_num;
	char		player_char;
	char		last_pos;
	int			x;
	int			y;
}				t_player;

typedef struct	s_base
{
	int			**contents;
	int			height;
	int			length;
}				t_base;

#endif
