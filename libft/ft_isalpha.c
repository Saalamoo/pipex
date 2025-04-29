/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalamoo <saalamoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:33:00 by saalamoo          #+#    #+#             */
/*   Updated: 2022/12/06 12:04:57 by saalamoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
// int main()
// {
// 	char c = 'a';
// 	printf("ft_isalpha: %d\n", ft_isalpha(c));
// 	printf("isalpha: %d\n", isalpha(c));
// 	return (0);
// }
