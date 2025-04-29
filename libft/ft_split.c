/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalamoo <saalamoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 12:42:28 by saalamoo          #+#    #+#             */
/*   Updated: 2023/03/12 16:56:17 by saalamoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	wordcount(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

int	wordlen(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
		i++;
		if (s[i] && s[i] != c)
		j++;
		while (s[i] && s[i] != c)
		i++;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		wordnum;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	wordnum = wordlen(s, c);
	ptr = (char **)malloc(sizeof(char *) * (wordnum + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < wordnum)
	{
		while (*s == c)
		s++;
	ptr[i] = (char *)malloc(sizeof(char) * (wordcount(s, c) + 1));
	j = 0;
		while (*s && *s != c)
	ptr[i][j++] = *s++;
	ptr[i][j] = '\0';
	i++;
	}
	ptr[i] = NULL;
	return (ptr);
}

// int main (void)
// {
//     char *str = "";
//     char c = ' ';
//     char **ptr = ft_split(str, c);
//     int i = 0;
// 	// ft_
//     while (ptr[i])
//     printf("%s\n", *ptr);
// 	free(ptr);
// }