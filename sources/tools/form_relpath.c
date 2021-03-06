/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_relpath.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 15:59:17 by amalsago          #+#    #+#             */
/*   Updated: 2019/08/08 13:44:24 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*form_relpath(const char *dirname, char const *basename)
{
	char	*path;

	if (!dirname || !basename)
		return (NULL);
	if (!(path = ft_strnew(ft_strlen(dirname) + 1 + ft_strlen(basename))))
		return (NULL);
	path = ft_strcpy(path, dirname);
	if (!ft_strequ(dirname, "/"))
		path = ft_strcat(path, "/");
	path = ft_strcat(path, basename);
	return (path);
}
