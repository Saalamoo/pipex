/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalamoo <saalamoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:52:08 by saalamoo          #+#    #+#             */
/*   Updated: 2022/12/06 16:59:01 by saalamoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*ds;
	char	*sr;

	ds = (char *)dst;
	sr = (char *)src;
	i = 0;
	if (!ds && !sr)
		return (NULL);
	if (ds > sr)
	{
		while (len-- > 0)
		{
			ds[len] = sr[len];
		}
	}
	else
	{
		while (i < len)
		{
			ds[i] = sr[i];
			i++;
		}
	}
	return (dst);
}
// int main(void)
// {
//     char dest[] = "Hello";
//     char src[] = "ABC";
//     char *res = ft_memmove(dest, src, 3);
//     printf ("ft_memm: %s\n", res);
// 	printf ("memmove: %s\n", memmove(dest, src, 3));
//     return(0);
// }
