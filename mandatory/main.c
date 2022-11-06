/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 11:52:45 by sharrach          #+#    #+#             */
/*   Updated: 2022/10/30 12:17:42 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char *env[])
{
	int	pipefd[2];
	int	fd[2];
	int	status;

	errno = 0;
	if (ac != 5)
        check_args();
	if (pipe(pipefd) < 0)
		exit(EXIT_FAILURE);
	exec_first_cmd(pipefd, fd, av, env);
	exec_second_cmd(pipefd, fd, av, env);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(-1, &status, 0);
	// waitpid(-1, &status, 0);
	return (0);
}