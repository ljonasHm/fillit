/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 14:17:58 by ljonas            #+#    #+#             */
/*   Updated: 2019/12/05 14:18:05 by ljonas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h> /*forbbiden*/

int		ft_checkttrmn(char **ttrmn);
int		ft_check1(char	**ttrmn);
int		ft_check2(char	**ttrmn);
int		ft_check3(char **ttrmn);
int		ft_check4(char **ttrmn);

#endif
