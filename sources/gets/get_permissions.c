/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_permissions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 13:46:39 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/26 13:13:40 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*get_permissions(mode_t mode, int ugo)
{
	int		r_mask;
	int		w_mask;
	int		x_mask;

	r_mask = FT_RPERM(mode, ugo);
	w_mask = FT_WPERM(mode, ugo);
	x_mask = FT_XPERM(mode, ugo);
	if ((mode & r_mask) && (mode & w_mask) && (mode & x_mask))
		return ("rwx");
	else if ((mode & r_mask) && (mode & w_mask))
		return ("rw-");
	else if ((mode & r_mask) && (mode & x_mask))
		return ("r-x");
	else if (mode & r_mask)
		return ("r--");
	else if ((mode & w_mask) && (mode & x_mask))
		return ("-wx");
	else if (mode & w_mask)
		return ("-w-");
	else if (mode & x_mask)
		return ("--x");
	else
		return ("---");
}
