/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:38:26 by jerbs             #+#    #+#             */
/*   Updated: 2020/03/02 16:19:15 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_check_char_c(char str_c, char c)
{
	if (str_c == c)
		return (1);
	return (0);
}

static int		ft_strlen_str(char const *str, int i, char c)
{
	int j;

	j = 0;
	while (!ft_check_char_c(str[i], c) && str[i] != '\0')
	{
		j++;
		i++;
	}
	return (j);
}

static int		ft_nb_str(char const *str, char c)
{
	int	count;
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (ft_check_char_c(str[i], c) == 0 && str[i] != '\0')
		{
			if (flag == 0)
			{
				count++;
				flag = 1;
			}
		}
		if (ft_check_char_c(str[i], c) == 1 && str[i] != '\0')
			flag = 0;
		i++;
	}
	return (count);
}

static char		*ft_strcpy_char(char const *str, char c, int i)
{
	char	*cpy;
	int		j;

	j = 0;
	if (!(cpy = malloc(sizeof(char) * ft_strlen_str(str, i, c) + 1)))
		return (NULL);
	while (str[i] && ft_check_char_c(str[i], c) == 0)
	{
		cpy[j] = str[i];
		i++;
		j++;
	}
	cpy[j] = '\0';
	return (cpy);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!c || !s)
		return (NULL);
	if (!(tab = malloc(sizeof(char*) * (ft_nb_str(s, c) + 1))))
		return (NULL);
	while (s[i] != '\0' && j < ft_nb_str(s, c))
	{
		while (ft_check_char_c(s[i], c) == 1)
			i++;
		tab[j] = ft_strcpy_char(s, c, i);
		j++;
		i++;
		while (s[i] != '\0' && ft_check_char_c(s[i], c) == 0)
			i++;
	}
	tab[j] = NULL;
	return (tab);
}

/*
**#include <stdio.h>
**#include <stdlib.h>
**#include <string.h>
**int     main()
**{
**	int i;
**	char **tab;
**	char str[] = " It's a me, Mario !    ";
**	char c = ' ';
**	i = 0;
**	tab = ft_strsplit(str, c);
**	while (tab[i] != 0)
**	{
**		printf("%s\n",tab[i]);
**		i++;
**	}
**	return 0;
**}
*/
