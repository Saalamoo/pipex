/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalamoo <saalamoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:02:47 by saalamoo          #+#    #+#             */
/*   Updated: 2022/11/20 15:45:55 by saalamoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*rp;

	i = 0;
	rp = (char *)s;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (&rp[i]);
		i++;
	}
	if ((char)c == '\0')
	{
		return (&rp[i]);
	}
	return (NULL);
}
// int main(void)
// {
//     char s1[] = "Hello World";
//     char c1 = 'a';
//     char *res;
//     res = ft_strchr(s1, c1);
//     printf("%s\n", res);
//     return(0);
// }
