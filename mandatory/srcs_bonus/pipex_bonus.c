/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:23:56 by sharrach          #+#    #+#             */
/*   Updated: 2022/11/16 19:37:39 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void here_doc(int argc, char *argv[])
{
    int	fd[2];
	int pid;
	char	*line;

	if (argc < 6)
		ft_error("Error: wrong args count");
	if (pipe(fd) == -1)
		perror("pipe");
	pid = fork();
	if (pid == -1)
		perror("fork");
	if (pid == 0)
	{
		close(fd[STDIN_FILENO]);
		ft_putstr_fd("here_doc> ", 1);
		line = get_next_line(1);
		while(line)
		{
			if(ft_strncmp(argv[2], line, ft_strlen(line)) == 0)
			{
				free(line);
				close(fd[STDOUT_FILENO]);
				exit(EXIT_SUCCESS);
			}
			ft_putstr_fd("here_doc> ", 1);
			// ft_putstr(line);
			// ft_putstr("\n");
			// free(line);
			
		}
		free(line);
		close(fd[STDOUT_FILENO]);
	}
	else
	{
		close(fd[STDOUT_FILENO]);
		if (dup2(fd[STDIN_FILENO], STDIN_FILENO) == -1)
			perror("dup2");
		close(fd[STDIN_FILENO]);
		waitpid(pid, NULL, 0);
	}
}

void ft_execute(char *cmd, char **env)
{
	int fd[2];
	int pid;

	if (pipe(fd) == -1)
		perror("pipe");
	pid = fork();
	if (pid == -1)
		perror("pid");
	if (pid == 0)
	{
		close(fd[STDIN_FILENO]);
		dup2(fd[STDOUT_FILENO], STDOUT_FILENO);
		close(fd[STDOUT_FILENO]);
		ft_get_cmd_path(cmd, env);
	}
	else
	{
		close (fd[STDOUT_FILENO]);
		dup2(fd[STDIN_FILENO], STDIN_FILENO);
		close(fd[STDIN_FILENO]);
		waitpid(pid, NULL, 0);
	}
}

void ft_pipex(int argc, char *argv[], char **env)
{
	int fd[2];

	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0)
	{
		here_doc(argc, argv);
		fd[STDOUT_FILENO] = open(argv[argc - 1], O_CREAT | O_WRONLY | O_APPEND);
	}
	else
	{
		fd[STDIN_FILENO] = open(argv[1], O_RDONLY);
		fd[STDOUT_FILENO] = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC);
		dup2(fd[STDIN_FILENO], STDIN_FILENO);
	}
	dup2(fd[STDOUT_FILENO], STDOUT_FILENO);
	ft_execute(argv[argc - 2], env);
}