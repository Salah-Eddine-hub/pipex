/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:31:35 by sharrach          #+#    #+#             */
/*   Updated: 2022/11/18 17:22:42 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
#define PIPEX_BONUS_H

//libraries
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>


int     ft_get_cmd_path(char **cmd, char **env);
void	ft_pipex(int argc, char *argv[], char **env);
void	ft_execute(char **cmd, char **env);
int		here_doc(int argc, char *argv[]);
//functions libft
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const	char *str);
void	*free_2d(char **arr);
void	ft_error(char *str);
void	ft_perror(char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putstr(char *str);


// function get_next_line
char	*get_next_line(int fd);
char	*ft_strnljoin(char *s1, char *s2);
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *s, int c);
void	ft_strcpy(char *dst, const char *src);

#endif