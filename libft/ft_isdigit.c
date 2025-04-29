/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalamoo <saalamoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:35:07 by saalamoo          #+#    #+#             */
/*   Updated: 2022/12/06 12:05:06 by saalamoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
// int main(void)
// {
// 	printf("ft_isdigit: %d\n", ft_isdigit('o'));
// 	printf("isdigit: %d", isdigit('o'));
// }
