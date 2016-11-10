/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unclaim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 04:43:43 by jguyon            #+#    #+#             */
/*   Updated: 2016/11/10 04:45:29 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

void	ft_unclaim(t_square *square, t_tetri *tetri)
{
	size_t	i;

	i = 0;
	while (i < BLOCK_COUNT)
	{
		square->blocks[CELL(tetri, i, square->size)] = 0;
		++i;
	}
}
