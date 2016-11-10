/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_solution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:38:11 by sclolus           #+#    #+#             */
/*   Updated: 2016/11/10 20:40:11 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"
#include <unistd.h>

void			ft_print_solution(t_square *square, size_t count, t_tetri **tetris)
{
	size_t	len;
	char	str[square->size * (square->size + 1)];
	size_t	i;
	size_t	u;

	len = square->size * (square->size + 1);
	i = 0;
	while (i < len)
	{
		if (i % (square->size + 1) == square->size)
			str[i++] = '\n';
		else
			str[i++] = '.';
	}
	i = 0;
	while (i < count)
	{
		u = 0;
		while (u < BLOCK_COUNT)
		{
			str[tetris[i]->blocks[u].x + tetris[i]->x + (tetris[i]->blocks[u].y + tetris[i]->y) * (square->size + 1)] = 'A' + i;
			u++;
		}
		i++;
	}
	write(1, str, len);
}
