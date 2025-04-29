/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalamoo <saalamoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:32:44 by saalamoo          #+#    #+#             */
/*   Updated: 2022/12/12 12:39:29 by saalamoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*rp;

	i = 0;
	rp = (char *)s;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
		{
			return (rp + i);
		}
		i--;
	}
	return (NULL);
}
// int main()
// {
// // 	char *str = "tripouille";
// //    const char ch = '\0';
// //    char *ret;
// //    char *og;
// //    ret = ft_strrchr(str, "");
// //    printf("MINE: 	String after |%c| is - |%s|\n", ch, ret);
// //    og = strrchr(str, "");
// //    printf("String after |%c| is - |%s|\n", ch, og);

// 	printf("%s",ft_strrchr("hi in form",""));
// 	printf("%s",strrchr("hi in form",""));
// }