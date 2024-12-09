/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarcevs <gkarcevs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:32:16 by girts521          #+#    #+#             */
/*   Updated: 2024/06/20 15:57:54 by gkarcevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	joined_str = (char *)malloc((ft_strlen((char *)s1) \
				+ ft_strlen((char *)s2) + 1) * sizeof(char));
	if (joined_str == NULL)
		return (NULL);
	while (i < (size_t)ft_strlen((char *)s1))
	{
		joined_str[i] = s1[i];
		i++;
	}
	while (j < (size_t)ft_strlen((char *)s2))
	{
		joined_str[i + j] = s2[j];
		j++;
	}
	joined_str[ft_strlen((char *)s1) + ft_strlen((char *)s2)] = '\0';
	return (joined_str);
}
