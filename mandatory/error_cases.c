/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:56:21 by sharrach          #+#    #+#             */
/*   Updated: 2022/10/13 14:41:38 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static  void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        write(1, &str[i], 1);
        i ++;
    }
}

void    check_args(void)
{
    ft_putstr("args: ./pipex [file1] [cmd1] [cmd2] [file2]\n");
    exit(1);
}

void    wrong_arg(char **cmd)
{
    ft_putstr(*cmd);
    ft_putstr(" cmd not found");
    free_2d(cmd);
    exit(1);
}