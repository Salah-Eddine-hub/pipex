/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:33:31 by sharrach          #+#    #+#             */
/*   Updated: 2022/11/16 18:28:07 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

static  void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != '\0')
		ft_putchar_fd(s[i++], fd);
	ft_putchar_fd('\n', fd);
}

void ft_error(char *str)
{
    ft_putendl_fd(str, STDOUT_FILENO);
    exit(EXIT_FAILURE);
}