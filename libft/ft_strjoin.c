/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalamoo <saalamoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:10:20 by saalamoo          #+#    #+#             */
/*   Updated: 2022/12/07 15:36:32 by saalamoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

// int main (void)
// {
// 	// char	*s1 = "where is my ";
// 	// char	*res = ft_strjoin(NULL, s1);
//     char	*s1 = "where is my ";
// 	char	*res = ft_strjoin(s1, NULL);
// 	// char str1[] = "welcom";
//     // char str2 [] = " Hello World";
//     // char *res = ft_strjoin(str1, str2);
// 	printf("%s\n", res);
//     return (0);
// }
