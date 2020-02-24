/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 14:18:13 by ljonas            #+#    #+#             */
/*   Updated: 2020/02/24 15:54:41 by ljonas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_error_exit(int z, char **ttrmn, t_list *head)
{
	if (z == 0)
	{
		free(head);
		ft_putstr("error\n");
	}
	else if (z == 1)
		ft_putstr("error\n");
	else if (z == 2)
	{
		free(head);
		free(ttrmn);
		ft_putstr("error\n");
	}
	else if (z == -1 || z > 26)
	{
		ft_headfree(head);
		ft_putstr("error\n");
	}
	return (0);
}

int		main(int ac, char **av)
{
	int			fd;
	int			q;
	char		**ttrmn;
	t_list		*head;

	if (ac == 2)
	{
		if (!(head = (t_list *)malloc(sizeof(t_list))))
			return (ft_error_exit(1, NULL, head));
		if (!(ttrmn = (char **)malloc(sizeof(char *) * 4)))
			return (ft_error_exit(0, NULL, head));
		fd = open(av[1], O_RDONLY);
		if (read(fd, NULL, 0) == -1)
			return (ft_error_exit(2, ttrmn, head));
		q = ft_gettrmn(ttrmn, head, fd);
		free(ttrmn);
		if (q == 0 || q == -1 || q > 26)
			return (ft_error_exit(q, NULL, head));
		ft_placettrm(head, q);
		ft_headfree(head);
		close(fd);
	}
	else
		ft_putstr("usage: ./fillit source_file\n");
	return (0);
}
