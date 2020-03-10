/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_env_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 20:55:41 by jerbs             #+#    #+#             */
/*   Updated: 2020/03/07 20:57:40 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			find_env_var(char *var, char **envp)
{
	int		i;
	char	*tmp;

	i = -1;
	while (envp[++i])
	{
		tmp = ft_strjoinch(var, '=');
		if (ft_strstartswith(envp[i], tmp))
		{
			free(tmp);
			return (i);
		}
		free(tmp);
	}
	return (i);
}

char		*get_env_var(char *var, char **envp)
{
	int		i;
	char	*tmp;

	i = -1;
	while (envp[++i])
	{
		tmp = ft_strjoinch(var, '=');
		if (ft_strstartswith(envp[i], tmp))
		{
			free(tmp);
			return (ft_strchr(envp[i], '=') + 1);
		}
		free(tmp);
	}
	return (NULL);
}

char		*get_home_var(char **envp)
{
	int i;

	i = -1;
	while (envp[++i])
		if (ft_strstartswith(envp[i], "HOME") == 1)
			return (str_after_eq(envp[i]));
	return (NULL);
}
