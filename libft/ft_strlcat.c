/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokarimi <mokarimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:16:46 by mokarimi          #+#    #+#             */
/*   Updated: 2025/11/02 10:53:39 by mokarimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lendst;
	size_t	i;

	if (!dst && dstsize == 0)
		return (ft_strlen(src));
	lendst = ft_strlen(dst);
	i = 0;
	if (dstsize <= lendst)
		return (dstsize + ft_strlen(src));
	while (src[i] && (lendst + i) < dstsize - 1)
	{
		dst[lendst + i] = src[i];
		i++;
	}
	dst[lendst + i] = '\0';
	return (lendst + ft_strlen(src));
}
/*
int	main(void)
{
	char	src[] = "hello 1337";
	char	dst[] = "simo";

	printf("%lu\n",ft_strlcat(dst,src,8));
	printf("%s\n",dst);
}
	*/