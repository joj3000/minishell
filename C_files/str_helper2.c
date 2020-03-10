/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_helper2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 20:58:27 by jerbs             #+#    #+#             */
/*   Updated: 2020/03/07 21:02:19 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_bzero(void *s, size_t n)
{
	char	*ptr;
	size_t	i;

	if (!n)
		return ;
	ptr = s;
	i = 0;
	while (i < n)
		*(ptr + i++) = 0;
}

char		*str_betwin_col(char *s)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	new = (char *)malloc(sizeof(char) * ct_till_col(s) + 1);
	if (s[i] == ':')
		i++;
	while (s[i] && s[i] != ':')
	{
		new[j] = s[i];
		j++;
		i++;
	}
	new[j] = 0;
	return (new);
}

char		*str_after_eq(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] == '=')
			return (&str[++i]);
	return (NULL);
}

char		*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}
