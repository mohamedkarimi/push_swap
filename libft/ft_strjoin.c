/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokarimi <mokarimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:16:39 by mokarimi          #+#    #+#             */
/*   Updated: 2025/10/28 11:05:10 by mokarimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*fullstr;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	total_len = s1_len + s2_len;
	fullstr = (char *)malloc(total_len + 1);
	if (!fullstr)
		return (NULL);
	ft_strlcpy(fullstr, s1, s1_len + 1);
	ft_strlcat(fullstr, s2, s1_len + s2_len + 1);
	return (fullstr);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*s1;
	char	*s2;

	s1 = NULL;
	s2 = NULL;
	printf("%s",ft_strjoin(s1,s2));
}
	*/