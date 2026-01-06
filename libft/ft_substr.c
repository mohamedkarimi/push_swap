/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokarimi <mokarimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:17:23 by mokarimi          #+#    #+#             */
/*   Updated: 2025/10/28 10:32:16 by mokarimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	alloc_len;
	char	*sub;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		alloc_len = ft_strlen(s) - start;
	else
		alloc_len = len;
	sub = (char *)malloc(alloc_len + 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, alloc_len + 1);
	return (sub);
}
/*
int	main(void)
{
	char	orig[] = "hello";
	char	*cop;

	cop = ft_substr(orig,2,5);
	printf("%s",cop);
	free(cop);
}
*/