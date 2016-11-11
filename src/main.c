/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:23:38 by jguyon            #+#    #+#             */
/*   Updated: 2016/11/11 23:36:44 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_fillit.h"

int		main(int argc, char **argv)
{
	char		*str;
	size_t		nbr_tetris;
	size_t		size;
	t_tetri		**tetris;
	t_square	square;

	str = NULL;
	tetris = NULL;
	if (argc != 2
		|| !(str = (char*)malloc(sizeof(char) * MAX_FILE_SIZE + 1))
		|| !(size = ft_read_file(argv[1], &str))
		|| !(nbr_tetris = ft_read_content(str, size))
		|| !(tetris = (t_tetri**)malloc(sizeof(t_tetri*) * nbr_tetris))
		|| !(ft_get_tetris(str, nbr_tetris, tetris)))
	{
		free(str);
		free(tetris);
		write(1, "error\n", 6);
		return (0);
	}
	ft_init_square(&square, nbr_tetris, tetris);
	ft_solve(&square, nbr_tetris, tetris);
	ft_print_solution(&square, nbr_tetris, tetris);
	free(str);
	ft_destroy_tetris(nbr_tetris, tetris);
	return (0);
}
