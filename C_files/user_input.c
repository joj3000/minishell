/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 20:39:33 by jerbs             #+#    #+#             */
/*   Updated: 2020/03/08 10:43:05 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		cd_cmd(char **envp, char *str)
{
	if (!str || ft_strcmp(str, "~") == 0)
	{
		str = get_home_var(envp);
		chdir(str);
	}
	else if (ft_strcmp(str, "-") == 0)
		return ;
	else if (access(str, F_OK) == 0 && access(str, X_OK) == -1)
	{
		ft_putstr_fd("\033[1;31mError:\033[0m ", 1);
		ft_putstr_fd("\033[4mexecution denied\033[0m on '", 1);
		ft_putstr_fd(str, 1);
		ft_putstr_fd("'\n", 1);
	}
	else if (chdir(str) < 0)
	{
		ft_putstr_fd("\033[1;31mError:\033[0m '", 1);
		ft_putstr_fd(str, 1);
		ft_putstr_fd("' is ", 1);
		ft_putstr_fd("\033[4mnot a directory\033[0m", 1);
		ft_putstr_fd(" or ", 1);
		ft_putstr_fd("\033[4mdoesn't exist\033[0m\n", 1);
	}
}

void		user_input_part1(char *line, char **term_cmd)
{
	int i;

	i = 0;
	if (term_cmd[1])
	{
		while (line[i] && line[i] != '\t' && line[i] != ' ')
			i++;
		ft_putstr_fd(&line[++i], 1);
		write(1, "\n", 1);
	}
}

void		user_input_part2(char **term_cmd)
{
	if (term_cmd[1] && term_cmd[2])
		setenv(term_cmd[1], term_cmd[2], 1);
}

void		user_input_part3(char **term_cmd)
{
	if (term_cmd[1])
		unsetenv(term_cmd[1]);
}

int			user_input(char *line, char **envp, char **term_cmd)
{
	term_cmd = split_ws(line);
	if (term_cmd == NULL || *term_cmd == NULL)
	{
		free_tab(term_cmd);
		return (1);
	}
	if (term_cmd[0][0] == '/')
		all_other_command_special(envp, term_cmd);
	else if (ft_strcmp(term_cmd[0], "echo") == 0)
		user_input_part1(line, term_cmd);
	else if (ft_strcmp(term_cmd[0], "cd") == 0)
		cd_cmd(envp, term_cmd[1]);
	else if (ft_strcmp(term_cmd[0], "setenv") == 0)
		user_input_part2(term_cmd);
	else if (ft_strcmp(term_cmd[0], "unsetenv") == 0)
		user_input_part3(term_cmd);
	else if (ft_strcmp(term_cmd[0], "exit") == 0)
	{
		free_tab(term_cmd);
		return (0);
	}
	else
		all_other_command(envp, term_cmd);
	free_tab(term_cmd);
	return (1);
}
