/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_solution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:38:11 by sclolus           #+#    #+#             */
/*   Updated: 2016/11/12 00:46:46 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"
#include <unistd.h>

static size_t	ft_str_index(t_square *square, t_tetri *tetri, size_t block)
{
	return (tetri->blocks[block].x + tetri->x
			+ (tetri->blocks[block].y + tetri->y) * (square->size + 1));
}

void			ft_print_solution(t_square *square, size_t count,
									t_tetri **tetris)
{
	size_t	len;
	char	str[square->size * (square->size + 1)];
	size_t	i;
	size_t	u;

	len = square->size * (square->size + 1);
	i = 0;
	while (i < len)
	{
		str[i] = (i % (square->size + 1) == square->size) ? '\n' : '.';
		++i;
	}
	i = 0;
	while (i < count)
	{
		u = 0;
		while (u < 4)
		{
			str[ft_str_index(square, tetris[i], u)] = 'A' + i;
			u++;
		}
		i++;
	}
	write(1, str, len);
}
