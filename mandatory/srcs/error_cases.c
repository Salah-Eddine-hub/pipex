/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:56:21 by sharrach          #+#    #+#             */
/*   Updated: 2022/11/22 14:53:18 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	check_args(void)
{
	ft_putstr("args: ./pipex [file1] [cmd1] [cmd2] [file2]\n");
	exit(1);
}

void	wrong_arg(char **cmd)
{
	ft_putstr(*cmd);
	ft_putstr(" cmd not found");
	free_2d(cmd);
	exit(1);
}

void	ft_perror(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}
