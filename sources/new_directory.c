/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_directory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:39:53 by amalsago          #+#    #+#             */
/*   Updated: 2019/08/12 13:28:23 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** This function create t_dir structure for each new directory.
*/

t_dir		*new_directory(void)
{
	t_dir	*directory;

	if (!(directory = (t_dir *)ft_memalloc(sizeof(t_dir))))
		return (NULL);
	directory->length = 0;
	directory->nb_files = 0;
	directory->total_blocks = 0;
	directory->namlen_wmax = 0;
	directory->nlink_wmax = 0;
	directory->size_wmax = 0;
	directory->ownername_wmax = 0;
	directory->groupname_wmax = 0;
	directory->file_head = NULL;
	directory->sdir_head = NULL;
	return (directory);
}
