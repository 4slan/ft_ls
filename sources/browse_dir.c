/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 21:42:58 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/22 19:18:49 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				print_list(t_list *list)
{
	while (list != NULL)
	{
		if (list->next == NULL)
			ft_printf("%s -> NULL\n", list->content);
		else
			ft_printf("%s -> ", list->content);
		list = list->next;
	}
}

void				recursive_browse(t_list *sdir_head)
{
	if (sdir_head != NULL)
	{
		while (sdir_head != NULL)
		{
			browse_dir(sdir_head->content);
			sdir_head = sdir_head->next;
		}
	}
}

t_dir				*browse_dir(const char *path)
{
	DIR				*dp;
	struct dirent	*dirent;
	t_dir			*current_dir;
	t_file			*file;

	if ((dp = opendir(path)) == NULL)					// Trying to open given path
		return (NULL);
	else
		ft_printf("\n%s folder is opened\n", path);
	current_dir = initialize_directory();
	current_dir->name = ft_strdup(path);
	while ((dirent = readdir(dp)) != NULL)				// Reading directory entry by entry
	{
		++(current_dir->nb_files);						// Counting number of files including hidden + . and ..
		if (is_hidden(dirent->d_name))					// Checking for hidden files
			continue ;									// Skipping hiddent files
		file = new_file();								// !!! Need to check allocation
		file->dirname = ft_strdup(path);
		if (current_dir->file_head == NULL)				// Checking if file_head pointer is NULL
			current_dir->file_head = file;				// If file_head pointer pointed no NULL so now it points to first file
		fill_file_struct(file, dirent);					// Filling file structure
		determine_wmax(dirent, file, current_dir);
		check_subdir(file, dirent, current_dir);		// Checking if actual file is a directory
		push_end(current_dir->file_head, file);			// Appending new node to file list
	}
	//print_list(current_dir->sdir_head);
	display_long(current_dir);
	recursive_browse(current_dir->sdir_head);
	closedir(dp);
	return (current_dir);
}
