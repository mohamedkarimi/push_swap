/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokarimi <mokarimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:16:26 by mokarimi          #+#    #+#             */
/*   Updated: 2025/10/24 17:16:27 by mokarimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len_s;
	char	*ptr;
	size_t	i;

	len_s = ft_strlen(s);
	if (!s)
		return (NULL);
	ptr = (char *)malloc(len_s + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*
int	main(void)
{
	char	orig[] = "hello";
	char	*cop;

	cop = ft_strdup(orig);
	printf("%s",cop);
	free(cop);
}
	*/