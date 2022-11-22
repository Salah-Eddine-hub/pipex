/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 22:10:57 by sharrach          #+#    #+#             */
/*   Updated: 2022/11/22 11:59:58 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	exec_first_cmd(int *pipefd, char **av, char *env[])
{
	char	**cmd;
	pid_t	pid;
	int		fd[2];

	pid = fork();
	if (pid == -1)
		ft_perror("fork");
	if (pid == 0)
	{
		fd[0] = open(av[1], O_RDONLY);
		if (fd[0] == -1)
			ft_perror(av[1]);
		cmd = ft_split(av[2], ' ');
		close(pipefd[0]);
		dup2(fd[STDIN_FILENO], STDIN_FILENO);
		dup2(pipefd[STDOUT_FILENO], STDOUT_FILENO);
		if (cmd[0] && ft_get_cmd_path(&cmd[0], env))
		{
			execve(cmd[0], cmd, env);
			free_2d(cmd);
		}
		else
			wrong_arg(cmd);
	}
}

void	exec_second_cmd(int *pipefd, char **av, char *env[])
{
	char	**cmd;
	pid_t	pid;
	int		fd[2];

	pid = fork();
	if (pid == -1)
		ft_perror("fork");
	if (pid == 0)
	{
		fd[1] = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (fd[1] == -1)
			ft_perror(av[4]);
		cmd = ft_split(av[3], ' ');
		close(pipefd[1]);
		dup2(fd[STDOUT_FILENO], STDOUT_FILENO);
		dup2(pipefd[STDIN_FILENO], STDIN_FILENO);
		if (cmd[0] && ft_get_cmd_path(&cmd[0], env))
		{
			execve(cmd[0], cmd, env);
			free_2d(cmd);
		}
		else
			wrong_arg(cmd);
	}
}
