/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokarimi <mokarimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:39:49 by mokarimi          #+#    #+#             */
/*   Updated: 2025/10/30 18:11:07 by mokarimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(const char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

static char	**free_all(char **result)
{
	size_t	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

static int	fill_result(char **result, char const *s, char c)
{
	size_t	i;
	size_t	start;
	size_t	end;

	i = 0;
	start = 0;
	while (s[start])
	{
		while (s[start] == c && s[start])
			start++;
		if (s[start])
		{
			end = start;
			while (s[end] && s[end] != c)
				end++;
			result[i] = ft_substr(s, start, end - start);
			if (!result[i])
				return (0);
			i++;
			start = end;
		}
	}
	result[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!result)
		return (NULL);
	if (!fill_result(result, s, c))
		return (free_all(result));
	return (result);
}
/*
int	main(void)
{
	char	**arr;

	arr = ft_split(NULL, ' ');
	printf("%s\n",arr[0]);
	printf("%s\n",arr[1]);
	printf("%s\n",arr[2]);
	printf("%s\n",arr[3]);
	
	
	
	//printf("%s\n", arr[4]);
}
*/