/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unclaim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 04:43:43 by jguyon            #+#    #+#             */
/*   Updated: 2016/11/28 23:42:34 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

void	ft_unclaim(t_square *restrict square, t_tetri *restrict tetri)
{
	size_t	shifter;

	shifter = 28 - tetri->x;
	square->grid[tetri->y] ^= ((unsigned int)tetri->box.row0) << shifter;
	square->grid[tetri->y + 1] ^= ((unsigned int)tetri->box.row1) << shifter;
	square->grid[tetri->y + 2] ^= ((unsigned int)tetri->box.row2) << shifter;
	square->grid[tetri->y + 3] ^= ((unsigned int)tetri->box.row3) << shifter;
}
