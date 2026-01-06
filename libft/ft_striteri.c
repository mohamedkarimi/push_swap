/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokarimi <mokarimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:16:32 by mokarimi          #+#    #+#             */
/*   Updated: 2025/10/29 00:38:08 by mokarimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void	too_upper(unsigned int i,char *c)
{
	(void)i;
	if(*c >= 'a' && *c <= 'z')
		*c -= 32;
}
int	main(void)
{
	char	str[] = "hello";

	ft_striteri(str,&too_upper);
	printf("%s",str);
}
*/