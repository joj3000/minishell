/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:15:36 by jerbs             #+#    #+#             */
/*   Updated: 2020/03/08 10:43:12 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prompt(void)
{
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("\033[1;37m(ﾉ\033[0m", 1);
	ft_putstr_fd("\033[1;36m◕\033[0m", 1);
	ft_putstr_fd("\033[1;37mヮ\033[0m", 1);
	ft_putstr_fd("\033[1;36m◕\033[0m", 1);
	ft_putstr_fd("\033[1;37m)ﾉ\033[0m", 1);
	ft_putstr_fd("\033[1;32m*:･ﾟ\033[0m", 1);
	ft_putstr_fd("\033[1;31m♡ \033[0m", 1);
	ft_putstr_fd("\033[1;33m♡ \033[0m", 1);
	ft_putstr_fd("\033[1;35m♡ \033[0m", 1);
	ft_putstr_fd("\033[1;36m♡ \033[0m", 1);
	ft_putstr_fd("\033[1;37m: \033[0m", 1);
}

void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		prompt();
		signal(SIGINT, signal_handler);
	}
}

int		main(void)
{
	int			flag;
	char		**term_cmd;
	char		*line;
	extern char	**environ;

	term_cmd = NULL;
	flag = 1;
	while (flag == 1)
	{
		prompt();
		signal(SIGINT, signal_handler);
		get_next_line(0, &line);
		if (user_input(line, environ, term_cmd) == 0)
			flag = 0;
		freed(line);
	}
	if (term_cmd)
		free_tab(term_cmd);
}
