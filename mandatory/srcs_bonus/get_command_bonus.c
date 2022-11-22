/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:33:11 by sharrach          #+#    #+#             */
/*   Updated: 2022/11/22 14:54:35 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static	char	**get_path(char *env[])
{
	char	**paths;
	int		i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	if (!env[i])
		return (NULL);
	paths = ft_split(env[i] + 5, ':');
	return (paths);
}

static	char	*ft_strcat(char *dest, const char *src)
{
	int	i;
	int	j;
	int	lendest;
	int	lensrc;
	int	lenofboth;

	i = 0;
	j = 0;
	lendest = ft_strlen(dest);
	lensrc = ft_strlen(src);
	lenofboth = lendest + lensrc;
	while (i < lendest)
		i++;
	while (i < lenofboth)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

static	char	*ft_stradd(char const *s1, char const *s2)
{
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	s = ((char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s == 0)
		return (NULL);
	ft_strcpy(s, (char *) s1);
	ft_strcat(s, (char *) s2);
	free((void *)s1);
	return (s);
}

int	ft_get_cmd_path(char *args, char **env)
{
	char	**cmd;
	char	**path;
	char	*add_slash;
	int		i;

	cmd = ft_split(args, ' ');
	path = get_path(env);
	if (!path)
		return (0);
	i = 0;
	while (path[i])
	{
		add_slash = ft_strjoin(path[i], "/");
		add_slash = ft_stradd(add_slash, cmd[0]);
		if (!access(add_slash, F_OK) && !access(add_slash, X_OK))
		{
			if (execve(add_slash, cmd, NULL) == -1)
				ft_perror("exceve");
		}
		free(add_slash);
		i++;
	}
	free_2d(cmd);
	free_2d(path);
	return (0);
}
