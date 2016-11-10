/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:22:07 by jguyon            #+#    #+#             */
/*   Updated: 2016/11/10 04:31:13 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H

# define MAX_FILE_SIZE 545
# define MAX_TETRI_COUNT 26
# define BLOCK_COUNT 4
# define FILE_ERROR 0
# define BITFIELD_SIZE 64
# define MAX_SQUARE_SIZE 484
# define CELL(x, y, size) (y * size + x)

# include <sys/types.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct	s_block
{
	size_t	x;
	size_t	y;
}				t_block;

typedef struct	s_tetri
{
	t_block		blocks[BLOCK_COUNT];
	size_t		width;
	size_t		height;
	size_t		x;
	size_t		y;
}				t_tetri;

typedef struct	s_square
{
	size_t		size;
	char		blocks[MAX_SQUARE_SIZE];
}				t_square;

size_t			ft_read_file(char *path, char **content);
size_t			ft_read_content(char *content, size_t size);
size_t			ft_get_tetris(char *content, size_t count, t_tetri **tetris);
int				ft_is_claimed(t_square *square, t_tetri *tetri);
void			ft_claim(t_square *square, t_tetri *tetri);
void			ft_unclaim(t_square *square, t_tetri *tetri);

#endif
