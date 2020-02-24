/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 14:17:58 by ljonas            #+#    #+#             */
/*   Updated: 2020/02/19 16:43:59 by ljonas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct	s_ttpos
{
	int			x[4];
	int			y[4];
	int			num;
	char		simb;
	int			cord[2];
}				t_ttpos;

typedef struct	s_mas
{
	char		sq[15][15];
	int			i;
	int			q;
	int			res;
}				t_mas;

int				ft_checkttrmn(char **ttrmn);
int				ft_check1(char **ttrmn);
int				ft_check2(char **ttrmn);
int				ft_check3(char **ttrmn);
int				ft_gettrmn(char **ttrmn, t_list *head, int fd);
t_ttpos			*ft_newpos(char **ttrmn, char a);
void			ft_lstaddbackpos(t_list *head, t_ttpos *pos);
void			ft_printfsq(t_mas *mas, int s);
void			ft_sq(t_mas *mas, int a);
void			ft_placettrm(t_list *head, int q);
int				ft_fullttrm(t_mas *mas, t_ttpos *tmppos, int s);
void			ft_clearch(t_mas *mas, char a);
int				ft_fullsq(t_mas *mas, t_list *head, int s);
void			ft_search(int s, t_ttpos *tmppos);
int				ft_reshotka(t_mas *mas, t_ttpos *pos, int s);
void			ft_headfree(t_list *head);
int				ft_sqrt(int q);
int				ft_neighbours(char **ttrmn);
void			ft_clearallmas(t_mas *mas, t_list *head);
void			ft_sqinit(t_mas *mas);
void			ft_addttrmn(t_list *head, char **ttrmn, int q);
void			ft_cleartt(char **ttrmn, int i);
void			ft_checkposx(t_ttpos *pos);
void			ft_checkposy(t_ttpos *pos);
void			ft_cordpl(t_ttpos *pos, char **ttrmn);
t_list			*ft_nextlst(t_list *tmp, t_list *head, t_mas *mas);
void			ft_checkposx(t_ttpos *pos);
void			ft_checkposy(t_ttpos *pos);
void			ft_cordpl(t_ttpos *pos, char **ttrmn);
int				ft_error_exit(int z, t_list *head);
int				ft_checkgnl(int i, int g, int q, char **ttrmn);
int				ft_ultra_clear(int i, int q, char **ttrmn, char *tt);
t_list			*ft_goodres(t_mas *mas, t_list *tmp, t_list *head, \
							t_ttpos *tmppos);
t_list			*ft_numi(t_list *tmp, t_ttpos *tmppos, t_mas *mas);
int				ft_clearcheck(t_mas *mas, t_list *head);
t_list			*ft_restreat(t_mas *mas, t_ttpos *tmppos, \
							t_list *tmp, t_list *head);

#endif
