/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalamoo <saalamoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:38:25 by saalamoo          #+#    #+#             */
/*   Updated: 2022/12/12 12:39:55 by saalamoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	str = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == '\0')
		return (0);
	while (i < n)
	{
		if (str[i] == str2[i] && str[i] && str2[i])
			i++;
		else
			return (str[i] - str2[i]);
	}
	return (0);
}

// int main()
// {
// 	// char str1[] = "hello";
// 	// char str2[] = "hello";
// 	printf("FT: %d\n", ft_strncmp("test\200", "test\0", 6));
// 	printf("OG: %d\n", strncmp("test\200", "test\0", 6));
// }