/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 22:11:14 by sharrach          #+#    #+#             */
/*   Updated: 2022/11/16 16:30:17 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

//libraries
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>

//functions libft
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const	char *str);
void	*free_2d(char **arr);
void    ft_putstr(char *str);

//functions pipex
void	exec_first_cmd(int *pipefd, int *fd, char **av, char *env[]);
void	exec_second_cmd(int *pipefd, int *fd, char **av, char *env[]);
int     ft_get_cmd_path(char **cmd, char *env[]);
void    wrong_arg(char **cmd);
void    check_args(void);

#endif