/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_groupname_wmax.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 12:53:31 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/08 10:05:17 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		determine_groupname_wmax(t_dir *directory, t_file *file)
{
	size_t	groupname_w;

	groupname_w = ft_strlen(file->groupname);
	if (groupname_w > directory->groupname_wmax)
		directory->groupname_wmax = groupname_w;
}
