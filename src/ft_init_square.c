/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 05:23:47 by jguyon            #+#    #+#             */
/*   Updated: 2016/11/10 07:00:58 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"


#include <stdio.h>

void	ft_init_square(t_square *square, size_t count)
{
	size_t	size;
	size_t	i;

	size = 2;
	while (size * size < 4 * count)
		++size;
	square->size = size;
	i = 0;
	while (i < MAX_SQUARE_SIZE)
	{
		square->blocks[i] = 0;
		++i;
	}
}
