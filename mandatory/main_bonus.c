/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:25:27 by sharrach          #+#    #+#             */
/*   Updated: 2022/11/16 17:49:19 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex_bonus.h"


int main(int argc, char *argv[], char **env)
{
	if (argc < 5)
		ft_error("Error: Invalid argument");
	ft_pipex(argc, argv, env);
	return (0);
}