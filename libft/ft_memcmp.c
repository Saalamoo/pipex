/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalamoo <saalamoo@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:44:58 by saalamoo          #+#    #+#             */
/*   Updated: 2022/11/15 13:45:15 by saalamoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str;
	unsigned char	*str2;

	str = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*str != *str2)
			return (*str - *str2);
		str++;
		str2++;
		n--;
	}
	return (0);
}
// int main(void)
// {
//     char str1[] = "ABCD";
//     char str2[] = "abcd";
//     printf("%d\n", ft_memcmp(str1, str2, 4));
//     return (0);
// //it will return -32 a -A
// }
