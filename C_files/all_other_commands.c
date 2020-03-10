/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_other_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 20:42:03 by jerbs             #+#    #+#             */
/*   Updated: 2020/03/08 10:43:03 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		print_shit(char **term_cmd)
{
	ft_putstr_fd("\033[1;31mError:\033[0m ", 1);
	ft_putstr_fd("\033[4mexecution denied\033[0m on '", 1);
	ft_putstr_fd(term_cmd[0], 1);
	ft_putstr_fd("'\n", 1);
}

int			all_other_command_special(char **envp, char **term_cmd)
{
	pid_t	pid;

	if (!file_exist(term_cmd[0]))
	{
		ft_putstr_fd("Sry love, this ", 1);
		ft_putstr_fd("\033[4mcommand doesn't exist\033[0m ...\n", 1);
		return (0);
	}
	if (access(term_cmd[0], F_OK) == 0 && access(term_cmd[0], X_OK) == -1)
	{
		print_shit(term_cmd);
		return (0);
	}
	if ((pid = fork()) != 0)
		wait(NULL);
	else if (pid == -1)
	{
		ft_putstr_fd("error\n", 1);
		return (-1);
	}
	else
		execve(term_cmd[0], (char *const *)term_cmd, envp);
	return (1);
}

void		aoc_part2(char **envp, char **term_cmd, char *tmp2)
{
	int			i;
	char		*v_env;
	char		*tmp;

	i = 0;
	v_env = NULL;
	v_env = get_env_var("PATH", envp);
	while (v_env[i])
	{
		tmp = ft_strjoin_free1(str_betwin_col(&v_env[i]), "/");
		tmp2 = ft_strjoin_free1(tmp, term_cmd[0]);
		execve(tmp2, (char *const *)term_cmd, envp);
		freed(tmp2);
		while (v_env[i] && v_env[i] != ':')
			i++;
		if (v_env[i] == ':')
			i++;
	}
}

int			all_other_command(char **envp, char **term_cmd)
{
	static char	*tmp2;
	pid_t		pid;

	if (check_bins(term_cmd, envp) == 0)
	{
		ft_putstr_fd("Sry love, this ", 1);
		ft_putstr_fd("\033[4mcommand doesn't exist\033[0m ...\n", 1);
		return (0);
	}
	if ((pid = fork()) == 0)
		aoc_part2(envp, term_cmd, tmp2);
	else if (pid == -1)
	{
		free(tmp2);
		ft_putstr_fd("Forking error\n", 1);
		return (-1);
	}
	wait(NULL);
	if (tmp2)
		freed(tmp2);
	return (1);
}
