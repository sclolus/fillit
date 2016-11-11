/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_claim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 04:33:30 by jguyon            #+#    #+#             */
/*   Updated: 2016/11/11 21:55:41 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"
#include <stdio.h>

int		ft_claim(t_square *square, t_tetri *tetri)
{
	size_t	shifter;

	shifter = 28 - tetri->x;
	if ((square->grid[tetri->y] & (((unsigned int)tetri->box.row0) << shifter))
			|| (square->grid[tetri->y + 1] 
			& (((unsigned int)tetri->box.row1) << shifter))
			|| (square->grid[tetri->y + 2]
			& (((unsigned int)tetri->box.row2) << shifter))
			|| (square->grid[tetri->y + 3]
			& (((unsigned int)tetri->box.row3) << shifter)))
		return (0);
	square->grid[tetri->y] ^= ((unsigned int)tetri->box.row0) << shifter;
	square->grid[tetri->y + 1] ^= ((unsigned int)tetri->box.row1) << shifter;
	square->grid[tetri->y + 2] ^= ((unsigned int)tetri->box.row2) << shifter;
	square->grid[tetri->y + 3] ^= ((unsigned int)tetri->box.row3) << shifter;
	return (1);
}
