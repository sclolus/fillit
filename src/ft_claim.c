/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_claim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 04:33:30 by jguyon            #+#    #+#             */
/*   Updated: 2016/11/10 20:56:00 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

void	ft_claim(t_square *square, t_tetri *tetri)
{
	size_t	i;

	i = 0;
	while (i < BLOCK_COUNT)
	{
		square->blocks[CELL(tetri, i, square->size)] = 1;
		++i;
	}
}
