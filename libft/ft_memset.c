/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalamoo <saalamoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:57:05 by saalamoo          #+#    #+#             */
/*   Updated: 2022/12/06 12:18:11 by saalamoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*pb;
	unsigned char	ch;

	i = 0;
	pb = (unsigned char *)b;
	ch = c;
	while (i < len)
	{
		pb[i] = ch;
		i++;
	}
	return (b);
}
// int main (void)
// {
//     char s1 [] = "Hello World";
//     int x = 'k';
//     printf("string: %s\n", s1);
//     printf("ft_mem: %s\n", ft_memset(s1, x, 3));
// 	printf("memset: %s\n", memset(s1, x, 3));
//     return (0);
// }
