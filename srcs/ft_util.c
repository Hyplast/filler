/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:49:39 by severi            #+#    #+#             */
/*   Updated: 2022/06/15 21:20:17 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_base(t_base **base)
{
	int	i;

	i = 0;
	while (i < (*base)->height)
	{
		free((*base)->contents[i++]);
	}
	free((*base)->contents);
	free((*base));
}

void	insert_piece(int x, int y)
{
	//printf("%d %d\n", player->x, player->y);
	ft_putnbr_fd(x ,1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(y ,1);
	ft_putchar_fd('\n', 1);
}


int	get_dim(char *str, int d)
{
	int i;
	int j;
	int	result;
	char	*temp;
	

	j = 0;
	i = 0;
	while (j != d)
	{
		while (str[i] != ' ')
			i++;
		i++;
		j++;
	}
	j = 0;
	while (ft_isdigit(str[i + j]) == 1)
		j++;
	temp = ft_strsub(str, (unsigned int)i, (unsigned int)j);
	result = ft_atoi(temp);
	ft_strdel(&temp); 
	return (result);
}
