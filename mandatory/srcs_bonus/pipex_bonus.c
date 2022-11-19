/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:23:56 by sharrach          #+#    #+#             */
/*   Updated: 2022/11/19 09:58:16 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	here_doc(int argc, char *argv[])
{
	int		fd[2];
	char	*line;

	if (argc < 6)
		ft_error("Error: wrong args count");
	if (pipe(fd) == -1)
		ft_perror("pipe");
	close(fd[STDIN_FILENO]);
	while (1)
	{
		ft_putstr_fd("here_doc> ", STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
		if (ft_strncmp(line, argv[2], ft_strlen(argv[2])) == 0 
			&& line[ft_strlen(argv[2])] == '\n')
		{
			free(line);
			break;
		}
		ft_putstr_fd(line, fd[STDOUT_FILENO]);
		free(line);
	}
	return (fd[STDOUT_FILENO]);
}

void ft_execute(char *cmd, char **env)
{
	int fd[2];
	int pid;

	if (pipe(fd) == -1)
		ft_perror("pipe");
	pid = fork();
	if (pid == -1)
		ft_perror("fork");
	if (pid == 0)
	{
		close(fd[STDIN_FILENO]);
		dup2(fd[STDOUT_FILENO], STDOUT_FILENO);
		close(fd[STDOUT_FILENO]);
		ft_get_cmd_path(*cmd, env);
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
	int	fd[2];
	int	*p[2];
	int	i;

	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0)
	{
		fd[STDIN_FILENO] = here_doc(argc, argv);
		fd[STDOUT_FILENO] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0666);
		i = 3;
	}
	else
	{
		fd[STDIN_FILENO] = open(argv[1], O_RDONLY);
		fd[STDOUT_FILENO] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
		i = 2;
	}
	*p = malloc((argc - 2) * sizeof(int *));
	while (argv[i])
	{
		if (i != argc - 2)
			if (pipe(*p1) == -1)
				ft_perror("pipe");
		ft_execute(argv[i], env);
		i++;
	}
}
