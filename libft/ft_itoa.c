/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokarimi <mokarimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 10:30:27 by mokarimi          #+#    #+#             */
/*   Updated: 2025/10/28 23:09:22 by mokarimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len_n(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	size_t	lenn;

	lenn = len_n(n);
	if (n == 0)
		return (ft_strdup("0"));
	str = (char *)malloc(lenn + 1);
	if (!str)
		return (NULL);
	str[lenn] = '\0';
	num = n;
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	lenn--;
	while (num > 0)
	{
		str[lenn] = (num % 10) + '0';
		num = num / 10;
		lenn--;
	}
	return (str);
}

/*
int	main(void)
{
	int	i;
	int	arr[5] = {0, 2, 3, 4, 5};

	i = 0;
	while (i < 5)
	{
		printf("%s", ft_itoa(arr[i]));
		i++;
	}
}
	*/