/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 05:06:23 by jguyon            #+#    #+#             */
/*   Updated: 2016/11/10 20:59:50 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

#include <unistd.h>
#include <stdio.h>

int		ft_solve_one(t_square *square, size_t count, t_tetri **tetris, size_t i)
{
	t_tetri	*tetri;

	if (i >= count)
		return (1);
	tetri = tetris[i];
	tetri->x = 0;
	tetri->y = 0;
	while (1)
	{
		if (!ft_is_claimed(square, tetri))
		{
			ft_claim(square, tetri);
			if (ft_solve_one(square, count, tetris, i + 1))
				return (1);
			ft_unclaim(square, tetri);
		}
		if (!ft_move(square, tetri))
			return (0);
	}
}

void	ft_solve(t_square *square, size_t count, t_tetri **tetris)
{
	while (!ft_solve_one(square, count, tetris, 0))
		++(square->size);
}
