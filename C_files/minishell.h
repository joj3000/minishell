/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:13:42 by jerbs             #+#    #+#             */
/*   Updated: 2020/03/08 10:54:43 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <stdbool.h>
# include <signal.h>
# define BUFF_SIZE 32
# define FD_SIZE 4092

int		get_next_line(const int fd, char **line);
char	*ft_strchr(const char *s, int c);
void	ft_strdel(char **as);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strsub(char const *s, unsigned int start, size_t len);

int		ft_strcmp(char *s1, char *s2);
void	ft_putstr_fd(char const *s, int fd);

char	**ft_strsplit(char const *s, char c);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strcat(const char *s1, const char *s2);
char	*ft_strdup_free(char *s1, char *src);
void	del_path2_updt_env(char **updt_env);
char	**split_ws(char *str);

void	freed(char *s);
void	free_tab(char **tab);
char	*ft_strjoin_free1(char *s1, char *s2);

int		is_in(char *s, char c);

/*
** user_cmd.c
*/
int		user_input(char *line, char **envp, char **term_cmd);
void	cd_cmd(char **envp, char *str);

/*
** all_other_commands.c
*/
int		all_other_command(char **envp, char **term_cmd);
int		all_other_command_special(char **envp, char **term_cmd);

/*
** exist_check.c
*/
int		check_bins(char **command, char **envp);
bool	file_exist(char *filename);
int		is_executable(char *bin_path, struct stat f);

/*
** str_helper1.c
*/
char	*ft_strjoinch(char const *s1, char c);
int		ft_strstartswith(char *s1, char *s2);
int		ft_strendswith(char *s1, char *s2);
char	*ft_strjoincl(char *s1, char *s2, int free_both);
char	*ft_pathjoin(char *p1, char *p2);

/*
** str_helper2.c
*/
char	*ft_strnew(size_t size);
char	*str_betwin_col(char *s);
char	*str_after_eq(char *str);
void	ft_bzero(void *s, size_t n);

/*
** x_env_var.c
*/
int		find_env_var(char *var, char **envp);
char	*get_env_var(char *var, char **envp);
char	*get_home_var(char **envp);

/*
** count.c
*/
int		ct_slash(char *s);
int		ct_till_col(char *s);

#endif
