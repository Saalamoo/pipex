/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalamoo <saalamoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:35:31 by saalamoo          #+#    #+#             */
/*   Updated: 2022/12/12 14:29:10 by saalamoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i])
	{
		i++;
	}
	dest = (char *)malloc(sizeof (char) * i + 1);
	if (!dest)
	{
		return (0);
	}
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// int main()
// {
// 	char *name;
// 	char *cp;

// 	name = "hello";
// 	cp = ft_strdup(name);
// 	printf("%s\n", cp);
// }