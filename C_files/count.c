/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 21:03:00 by jerbs             #+#    #+#             */
/*   Updated: 2020/03/07 21:03:50 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ct_slash(char *s)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '/')
			count++;
		i++;
	}
	return (count);
}

int			ct_till_col(char *s)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	if (s[i] == ':')
		flag = 1;
	while (s[i] && s[i] != ':')
		i++;
	return (i - flag);
}
