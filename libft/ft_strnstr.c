/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalamoo <saalamoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:50:58 by saalamoo          #+#    #+#             */
/*   Updated: 2022/12/06 15:33:55 by saalamoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	a;
	size_t	b;
	char	*str;

	str = (char *)haystack;
	if (*needle == '\0')
		return (str);
	if (str == NULL && len == 0)
		return (NULL);
	a = 0;
	while (str[a] != '\0' && a < len)
	{
		b = 0;
		while (str[a + b] == needle[b] && (a + b) < len)
		{
			if (needle[b + 1] == '\0')
				return (&str[a]);
			b++;
		}
		a++;
	}
	return (NULL);
}

// int main(void)
// {
// 	printf("%s\n", ft_strnstr(NULL, "fake", 0));
// 	return (0);
// }