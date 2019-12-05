/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrayne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:50:19 by rrayne            #+#    #+#             */
/*   Updated: 2019/10/30 20:58:28 by rrayne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# define BUFF_SIZE 5000

int					get_next_line(int fd, char **line);

typedef struct		s_gnl
{
	int				fd;
	char			*stack;
	struct s_gnl	*next;
}					t_gnl;

#endif
