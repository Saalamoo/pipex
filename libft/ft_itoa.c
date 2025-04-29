/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalamoo <saalamoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:12:20 by saalamoo          #+#    #+#             */
/*   Updated: 2022/12/08 14:06:36 by saalamoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_num(int n)
{
	int	s;

	s = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		s++;
		n /= 10;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char			*ptr;
	size_t			len;
	unsigned int	num;

	len = ft_num(n);
	num = n;
	if (n < 0)
	{
		num = n * -1;
		len++;
	}
	ptr = (char *)malloc(sizeof(char) * len + 1);
	if (ptr == NULL)
		return (NULL);
	ptr[len] = '\0';
	if (num == 0)
		ptr[--len] = '0';
	while (num)
	{
		ptr[--len] = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		ptr[0] = '-';
	return (ptr);
}	
// #include <stdio.h>
// int main(void)
// {
// 	printf("%s", ft_itoa(-532));
// }