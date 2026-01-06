/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokarimi <mokarimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:15:29 by mokarimi          #+#    #+#             */
/*   Updated: 2025/10/30 18:09:57 by mokarimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	a[] = "42nétwork";
	char	b[] = "42netword";
	printf("Compare 8 bytes: %d\n", ft_memcmp(a, b, 8));
	printf("Compare 9 bytes: %d\n", ft_memcmp(a, b, 9));
	printf("Compare 3 bytes: %d\n", ft_memcmp(a, b, 3));
	return (0);
}
*/