/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalamoo <saalamoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:46:03 by saalamoo          #+#    #+#             */
/*   Updated: 2022/12/06 16:56:42 by saalamoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*ds;
	char	*sr;

	ds = (char *)dst;
	sr = (char *)src;
	i = 0;
	if (src == dst)
		return (dst);
	while (i < n)
	{
		ds[i] = sr[i];
		i++;
	}
	return (dst);
}
// int main(void)
// {
//     char dest[] = "wlcome";
//     char src1[] = "Hello World";
//     char *res = ft_memcpy(dest, src1, 12);
//     printf("%s\n", res);
//     return(0);
// }