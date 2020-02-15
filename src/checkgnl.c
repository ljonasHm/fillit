/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkgnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrayne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 19:42:18 by rrayne            #+#    #+#             */
/*   Updated: 2020/02/15 19:42:29 by rrayne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			ft_checkgnl(int i, int g, int q, char **ttrmn)
{
	if (i != 0 || g != 0)
	{
		if (i != 0 && q == 0)
			ft_cleartt(ttrmn, i);
		if (q != 0 && i != 0)
			ft_cleartt(ttrmn, i);
		if (q != 0)
			return (-1);
		return (0);
	}
	return (q);
}

int			ft_ultra_clear(int i, int q, char **ttrmn, char *tt)
{
	ft_cleartt(ttrmn, i);
	free(tt);
	if (q > 0)
		return (-1);
	return (0);
}

t_list		*ft_goodres(t_mas *mas, t_list *tmp, t_list *head, t_ttpos *tmppos)
{
	mas->i++;
	tmppos->num = mas->i;
	tmp->content = tmppos;
	tmp = ft_nextlst(tmp, head, mas);
	return (tmp);
}

t_list		*ft_numi(t_list *tmp, t_ttpos *tmppos, t_mas *mas)
{
	mas->i--;
	ft_clearch(mas, tmppos->simb);
	tmppos->num = 0;
	tmp->content = tmppos;
	tmppos->cord[1]++;
	return (tmp);
}

t_list		*ft_restreat(t_mas *mas, t_ttpos *tmppos, t_list *tmp, t_list *head)
{
	if (mas->res == 1)
		tmp = ft_goodres(mas, tmp, head, tmppos);
	else if (mas->res == -1)
	{
		tmppos->cord[0] = 0;
		if (mas->q - 6 > mas->i)
		{
			ft_clearallmas(mas, head);
			mas->i = -1;
		}
		tmp = ft_nextlst(tmp, head, mas);
	}
	else if (mas->res == 0)
		tmppos->cord[1]++;
	return (tmp);
}
