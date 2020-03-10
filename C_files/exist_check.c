/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exist_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 20:45:23 by jerbs             #+#    #+#             */
/*   Updated: 2020/03/08 10:29:36 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool		file_exist(char *filename)
{
	struct stat	buffer;

	return (stat(filename, &buffer) == 0);
}

int			is_executable(char *bin_path, struct stat f)
{
	if (f.st_mode & S_IFREG)
	{
		if (!(f.st_mode & S_IXUSR))
		{
			ft_putstr_fd("\033[1;31mError:\033[0m ", 1);
			ft_putstr_fd("\033[4mexecution denied\033[0m on '", 1);
			ft_putstr_fd(bin_path, 1);
			ft_putstr_fd("'\n", 1);
		}
		free(bin_path);
		return (1);
	}
	free(bin_path);
	return (0);
}

int			check_bins(char **command, char **envp)
{
	int				i;
	char			*bin_path;
	char			**path;
	struct stat		f;

	path = ft_strsplit(get_env_var("PATH", envp), ':');
	i = -1;
	while (path && path[++i])
	{
		if (ft_strstartswith(command[0], path[i]))
			bin_path = ft_strdup(command[0]);
		else
			bin_path = ft_pathjoin(path[i], command[0]);
		if (lstat(bin_path, &f) == -1)
			free(bin_path);
		else
		{
			free_tab(path);
			return (is_executable(bin_path, f));
		}
	}
	if (path)
		free_tab(path);
	return (0);
}
