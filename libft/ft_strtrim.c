/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalamoo <saalamoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:07:02 by saalamoo          #+#    #+#             */
/*   Updated: 2022/12/12 13:44:11 by saalamoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*str;

	if (!s1)
		return (NULL);
	str = (char *)s1;
	i = 0;
	if (!set)
		return (str);
	while (s1[i] && ft_strchr(set, s1[i]))
		s1++;
	i = ft_strlen(s1);
	while (i && ft_strchr(set, s1[i]))
		i--;
	return (ft_substr(s1, 0, i + 1));
}

// int main (void)
// {
//     char str1[] = "ttttHello Fatemarttt";
//     // char set1[] = "tH";
// 	char	*ret = ft_strtrim(NULL, str1);
//     //printf("%s\n", ft_strtrim(str1, set1));
// 	printf("%s\n", ret);
//     return (0);
// }