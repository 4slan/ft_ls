/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_directory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:39:53 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/04 13:23:31 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dir		*new_directory(const char *name)
{
	t_dir	*directory;

	if (!(directory = (t_dir *)ft_memalloc(sizeof(t_dir))))
		return (NULL);
	directory->name = ft_strdup(name);
	directory->length = ft_strlen(name);
	directory->nb_files = 0;
	directory->total_blocks = 0;
	directory->namlen_wmax = 0;
	directory->nlink_wmax = 0;
	directory->size_wmax = 0;
	directory->ownername_wmax = 0;
	directory->groupname_wmax = 0;
	directory->file_head = NULL;
	directory->subdir_head = NULL;
	return (directory);
}