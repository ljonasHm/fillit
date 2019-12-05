/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 14:18:13 by ljonas            #+#    #+#             */
/*   Updated: 2019/12/05 14:18:15 by ljonas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int     main(int ac, char **av)
{
    int     fd;
    int     i;
    char    *tt;
    char    **ttrmn;

    ttrmn = NULL;
    if (ac != 2)
        ft_putstr("error\n");
    else
    {
        if (!(ttrmn = (char **)malloc(sizeof(char*) * 4)))
        {
            ft_putstr("error\n");
            return (0);
        }
        fd = open(av[1], O_RDONLY);
        i = 0;
        while (i < 4)
        {
            get_next_line(fd, &tt);
            ttrmn[i] = tt;
            i++;
        }
        printf("%s\n", ttrmn[0]);
        printf("%s\n", ttrmn[1]);
        printf("%s\n", ttrmn[2]);
        printf("%s\n", ttrmn[3]);
        if (!(ft_checkttrmn(ttrmn)))
            ft_putstr("error\n");
    }
    return (0);
}
