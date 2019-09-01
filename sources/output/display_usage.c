/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_usage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 04:24:15 by amalsago          #+#    #+#             */
/*   Updated: 2019/08/22 13:35:14 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		display_usage(char c)
{
	ft_strerror("ft_ls: illegal option -- ");
	ft_putchar_fd(c, STDERR_FILENO);
	ft_error_exit("\nusage: ft_ls [-lRart] [file ...]\n");
}
