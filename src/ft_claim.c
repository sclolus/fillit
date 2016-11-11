/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_claim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 04:33:30 by jguyon            #+#    #+#             */
/*   Updated: 2016/11/11 06:07:15 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"
#include <stdio.h>

static void	ft_xor(unsigned int *grid, t_tetri *tetri, size_t shifter)
{
	/* square->grid[tetris->y] ^= rows[0]; */
	/* square->grid[tetris->y + 1] ^= rows[1]; */
	/* square->grid[tetris->y + 2] ^= rows[2]; */
	/* square->grid[tetris->y + 3] ^= rows[3]; */
	grid[tetri->y] ^= ((unsigned int)tetri->box.row0) << shifter;
	grid[tetri->y + 1] ^= ((unsigned int)tetri->box.row1) << shifter;
	grid[tetri->y + 2] ^= ((unsigned int)tetri->box.row2) << shifter;
	grid[tetri->y + 3] ^= ((unsigned int)tetri->box.row3) << shifter;
}

static int	ft_and(unsigned int *grid, t_tetri *tetri, size_t shifter)
{
	return ((grid[tetri->y] & (((unsigned int)tetri->box.row0) << shifter))
			|| (grid[tetri->y + 1] & (((unsigned int)tetri->box.row1) << shifter))
			|| (grid[tetri->y + 2] & (((unsigned int)tetri->box.row2) << shifter))
			|| (grid[tetri->y + 3] & (((unsigned int)tetri->box.row3) << shifter)));
}

int		ft_claim(t_square *square, t_tetri *tetri)
{
	size_t	shifter;

	shifter = 28 - tetri->x;
	if (ft_and(square->grid, tetri, shifter))
		return (0);
	ft_xor(square->grid, tetri, shifter);
	return (1);
}
