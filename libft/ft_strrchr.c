/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokarimi <mokarimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:17:15 by mokarimi          #+#    #+#             */
/*   Updated: 2025/11/01 20:48:31 by mokarimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	while (len_s > 0)
	{
		len_s--;
		if (s[len_s] == (char)c)
			return ((char *)&s[len_s]);
	}
	if ((char)c == '\0')
		return ((char *)s + ft_strlen(s));
	return (NULL);
}
/*
int	main(void)
{
   // printf("%s",ft_strrchr("hello karkimi",'\0'));
	const char *str = "Hello World";

	printf("%s\n", ft_strrchr(str, '\0'));
	printf("%s\n", strrchr(str, 0));
	printf("%s\n", ft_strrchr(str, 'o'));
	printf("%s\n", ft_strrchr(str, 'z'));
	printf("%s\n", ft_strrchr(str, '\0'));

}
*/