/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:56:08 by sharrach          #+#    #+#             */
/*   Updated: 2022/11/22 14:57:13 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_strcpy(char *dst, const char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if ((char)c == s[i])
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (n > i)
	{
		str[i] = 0;
		i++;
	}
}

char	*ft_strnljoin(char *s1, char *s2)
{
	char	*s;
	int		s_len;
	int		s2_len;
	int		i;

	s2_len = 0;
	while (s2[s2_len] && s2[s2_len] != '\n')
		s2_len++;
	if (s2[s2_len] == '\n')
		s2_len++;
	s = ((char *)malloc(ft_strlen(s1) + s2_len + 1));
	if (s == 0)
		return (NULL);
	ft_strcpy(s, (char *) s1);
	s_len = ft_strlen(s);
	i = 0;
	while (i < s2_len)
	{
		s[s_len + i] = s2[i];
		i++;
	}
	s[s_len + i] = '\0';
	free (s1);
	return (s);
}
