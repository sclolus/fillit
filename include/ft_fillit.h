/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:22:07 by jguyon            #+#    #+#             */
/*   Updated: 2016/11/11 09:44:23 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H

# define MAX_FILE_SIZE 545
# define MAX_TETRI_COUNT 26
# define BLOCK_COUNT 4
# define GRID_SIZE 22

# include <sys/types.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct	s_block
{
	size_t	x;
	size_t	y;
}				t_block;

typedef struct	s_box
{
	unsigned char	row0 : 4;
	unsigned char	row1 : 4;
	unsigned char	row2 : 4;
	unsigned char	row3 : 4;
}				t_box;

typedef struct	s_tetri
{
	t_box			box;
	size_t			x;
	size_t			y;
	struct s_tetri	*prev;
	size_t			width;
	size_t			height;
	t_block			blocks[BLOCK_COUNT];
}				t_tetri;

typedef struct	s_square
{
	unsigned int	grid[GRID_SIZE];
	size_t			size;
}				t_square;

size_t			ft_read_file(char *path, char **content);
size_t			ft_read_content(char *content, size_t size);
size_t			ft_get_tetris(char *content, size_t count, t_tetri **tetris);
void			ft_init_square(t_square *square, size_t count,
								t_tetri **tetris);
int				ft_claim(t_square *square, t_tetri *tetri);
void			ft_unclaim(t_square *square, t_tetri *tetri);
int				ft_move(t_square *square, t_tetri *tetri);
void			ft_solve(t_square *square, size_t count,
							t_tetri **tetris);
void			ft_print_solution(t_square *square, size_t count,
									t_tetri **tetris);
#endif
