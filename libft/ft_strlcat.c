/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalamoo <saalamoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:04:21 by saalamoo          #+#    #+#             */
/*   Updated: 2022/12/12 14:28:56 by saalamoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	y;
	size_t	j;

	if (dst)
		i = ft_strlen(dst);
	else
		i = 0;
	j = 0;
	y = ft_strlen(src);
	if (dstsize <= i)
		return (y + dstsize);
	while (src[j] && i < dstsize - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (i + ft_strlen(&src[j]));
}

// int main (void)
// {
//     char *dst = NULL;
//     char *src = NULL;
//     printf("%zu\n", ft_strlcat(dst, src, 3));
// }
