/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 05:06:23 by jguyon            #+#    #+#             */
/*   Updated: 2016/11/10 08:28:08 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

#include <unistd.h>
#include <stdio.h>

int		ft_solve_one(t_square *square, size_t count, t_tetri **tetris, size_t i)
{
	if (i >= count)
		return (1);
	tetris[i]->x = 0;
	tetris[i]->y = 0;
	while (1)
	{
		if (!ft_is_claimed(square, tetris[i]))
		{
			ft_claim(square, tetris[i]);
			if (ft_solve_one(square, count, tetris, i + 1))
				return (1);
			ft_unclaim(square, tetris[i]);
		}
		if (!ft_move(square, tetris[i]))
			return (0);
	}
}

void	ft_solve(t_square *square, size_t count, t_tetri **tetris)
{
	while (!ft_solve_one(square, count, tetris, 0))
		++(square->size);
}
