/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fullsq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrayne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 19:46:50 by rrayne            #+#    #+#             */
/*   Updated: 2020/02/19 16:45:01 by ljonas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_reshotka(t_mas *mas, t_ttpos *tmppos, int s)
{
	if ((tmppos->y[0] + tmppos->cord[0]) > s
		&& (tmppos->y[1] + tmppos->cord[0]) > s
		&& (tmppos->y[2] + tmppos->cord[0]) > s
		&& (tmppos->y[3] + tmppos->cord[0]) > s)
		return (0);
	if ((tmppos->x[0] + tmppos->cord[1]) > s
		&& (tmppos->x[1] + tmppos->cord[1]) > s
		&& (tmppos->x[2] + tmppos->cord[1]) > s
		&& (tmppos->x[3] + tmppos->cord[1]) > s)
		return (0);
	if (mas->sq[tmppos->y[0] + tmppos->cord[0]][tmppos->x[0]
		+ tmppos->cord[1]] != '.')
		return (0);
	if (mas->sq[tmppos->y[1] + tmppos->cord[0]][tmppos->x[1]
		+ tmppos->cord[1]] != '.')
		return (0);
	if (mas->sq[tmppos->y[2] + tmppos->cord[0]][tmppos->x[2]
		+ tmppos->cord[1]] != '.')
		return (0);
	if (mas->sq[tmppos->y[3] + tmppos->cord[0]][tmppos->x[3]
		+ tmppos->cord[1]] != '.')
		return (0);
	return (1);
}

int		ft_fullttrm(t_mas *mas, t_ttpos *tmppos, int s)
{
	if (tmppos->cord[0] != -1 && ft_reshotka(mas, tmppos, s) == 1)
	{
		mas->sq[tmppos->y[0] + tmppos->cord[0]][tmppos->x[0]
			+ tmppos->cord[1]] = tmppos->simb;
		mas->sq[tmppos->y[1] + tmppos->cord[0]][tmppos->x[1]
			+ tmppos->cord[1]] = tmppos->simb;
		mas->sq[tmppos->y[2] + tmppos->cord[0]][tmppos->x[2]
			+ tmppos->cord[1]] = tmppos->simb;
		mas->sq[tmppos->y[3] + tmppos->cord[0]][tmppos->x[3]
			+ tmppos->cord[1]] = tmppos->simb;
		return (1);
	}
	else if (tmppos->cord[0] != -1 && ft_reshotka(mas, tmppos, s) != 1)
		return (0);
	return (-1);
}

int		ft_fullsq(t_mas *mas, t_list *head, int s)
{
	t_list	*tmp;
	t_ttpos	*tmppos;

	tmp = head;
	while (mas->q > mas->i)
	{
		tmppos = (t_ttpos *)tmp->content;
		if (tmppos->num == 0)
		{
			ft_search(s, tmppos);
			mas->res = ft_fullttrm(mas, tmppos, s);
			tmp = ft_restreat(mas, tmppos, tmp, head);
		}
		else if (tmppos->num == mas->i)
			ft_numi(tmp, tmppos, mas);
		else if (tmppos->num != mas->i && tmppos->num != 0)
			tmp = ft_nextlst(tmp, head, mas);
		if (mas->i == -1)
			return (0);
	}
	return (1);
}

void	ft_placettrm(t_list *head, int q)
{
	int		s;
	t_mas	*mas;

	mas = (t_mas *)malloc(sizeof(t_mas));
	ft_sqinit(mas);
	s = ft_sqrt(q) - 1;
	while (1)
	{
		mas->i = 0;
		mas->q = q;
		mas->res = 0;
		ft_sq(mas, s);
		if (ft_fullsq(mas, head, s))
			break ;
		s++;
	}
	ft_printfsq(mas, s);
}

t_list	*ft_nextlst(t_list *tmp, t_list *head, t_mas *mas)
{
	if (tmp->next == NULL && mas->i == 0)
		mas->i = -1;
	if (tmp->next == NULL)
		tmp = head;
	else
		tmp = tmp->next;
	return (tmp);
}
