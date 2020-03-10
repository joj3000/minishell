/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:04:08 by jerbs             #+#    #+#             */
/*   Updated: 2020/03/07 21:17:54 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		k;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) *
	(ft_strlen(s1) + ft_strlen(s2) + 1));
	i = 0;
	k = 0;
	while (s1[k])
	{
		str[i] = s1[k];
		i++;
		k++;
	}
	k = 0;
	while (s2[k])
	{
		str[i] = s2[k];
		i++;
		k++;
	}
	str[i] = 0;
	return (str);
}
