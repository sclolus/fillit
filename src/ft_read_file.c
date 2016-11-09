/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 19:18:19 by sclolus           #+#    #+#             */
/*   Updated: 2016/11/09 19:28:56 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

size_t			ft_read_file(char *path, char **content)
{
	int		fd;
	size_t	size;

	if (!(fd = open(path, O_RDONLY)))
		return (0);
	if (MAX_FILE_SIZE == (size = read(fd, *content, MAX_FILE_SIZE))
		&& read(fd, *content + size, 1))
		return (MAX_FILE_SIZE + 1);
	close(fd);
	return (size);
}
