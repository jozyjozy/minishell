/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:34:31 by agiguair          #+#    #+#             */
/*   Updated: 2023/05/11 14:26:16 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define GENERAL_ERROR 1
# define BAD_USE_BUILTINS 2
# define CMD_CANT_EXEC 126
# define CMD_NOT_FOUND 127
# define INVALID_ARG_EXIT 128
# define FATAL_ERROR_NEEDS_ADD 128
# define SCRIPT_ENDED_CTRL_C 130
# define SUCCESS 0
# include "../sources/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <dirent.h>
# include <signal.h>

typedef struct s_data
{
	char	**ms_env;

}	t_data;

typedef struct s_cmds
{
	char			*cmd;
	char			**opt;
	char			*in;
	char			*out;
	struct s_cmds	*next;
}	t_cmds;

typedef struct s_sig
{
	int				sigquit;
	int				sigint;
	unsigned char	exit_status;
	pid_t			pid;
	int				checker;
}	t_sig;

typedef struct s_pids
{
	pid_t			pid;
	struct s_pids	*next;

}	t_pids;

/* -------------------------------- MINISHELL ------------------------------- */
/* ----- minishell.c ----- */
void	ft_header(void);
void	ft_free_data(t_data *data);
int		history(char *str);
void	ft_minishell(char *str, t_data *data, pid_t pid);
/* ----- minishell2.c ----- */
char	*ft_shlvl(char *shlvl);
void	do_pwd(t_data *data);
t_data	*do_env(char **env, t_data *data, char *str);
void	sus(t_data *data, int i);
/* ----- minishell3.c ----- */
void	test_isatty(void);
int		check_if_mini(t_cmds *cmds);
/* -------------------------------- BUILTINS -------------------------------- */
/* ----- builtins.c ----- */
int		ft_is_builtins(t_cmds *cmd, t_data	*data);
void	ft_is_builtins2(t_cmds *cmds, t_data *data);
/* ----- cd.c ----- */
void	go_to_home(char *str);
void	check_home(t_data *data);
void	ft_cd(t_cmds *cmds, t_data *data);
/* ----- echo.c ----- */
int		ft_start_opt(t_cmds *cmds);
void	ft_printf_echo(t_cmds *cmds, int chk);
void	ft_echo(t_cmds *cmd);
/* ----- env.c ----- */
void	ft_env(t_data *data, t_cmds *cmds);
/* ----- exit.c ----- */
void	ft_exit(t_data *data, t_cmds *cmds);
/* ----- pwd.c ----- */
void	ft_pwd(t_cmds *cmds);
/* ----- export.c ----- */
/* export.c */
void	export_opt(char *str);
void	not_valid_identifier(char *str);
int		event_not_found(char *str, int bol);
int		check_export(char *str);
void	ft_export(t_cmds *cmds, t_data *data);
/* export2.c */
int		check_export_join(char *str);
void	export_add_var(char *str, t_data *data, int k);
void	do_export(char *str, t_data *data);
/* export3.c */
char	*fill_tmp_export_all(char *str);
/* exportsansopt.c */
int		ft_strncmp2(const char *s1, const char s2, size_t n);
int		ft_get_not_in_tab(char *str, char **tab);
char	**get_low(t_data *data, char **tab, int j);
char	**get_str_ea(char **tab, t_data *data, int j);
void	export_ascii(t_data *data);
void	print_export(char *tab);
/* ----- unset.c ----- */
void	ft_unset(t_data *data, t_cmds *cmds);
void	remove_var(t_data *data, t_cmds *cmds, int j, int k);
int		check_unset_ph(t_cmds *cmds, int j);
void	check_unset_ph2(t_cmds *cmds, t_data *data, int i, int j);
/* ----------------------------------- EXEC --------------------------------- */
/* ----- check_fd.c ----- */
int		len_cmds_lst(t_cmds *cmds);
int		check_fdout2(char *str);
char	*get_name_error2(char	*str);
void	freefds(int	**tab, int i);
int		**check_fd(t_cmds *cmds, t_data *data);
/* ----- check_fdin.c ----- */
void	ft_free_fdin(char **fdins);
int		isquote(char *str);
int		do_open(t_data *data, char *str2, int k, int qot);
int		check_fdin(char *str, int k, t_data *data);
/* ----- check_fdout.c ----- */
void	ft_free_fdout(char **fdouts);
int		check_fdout(char *str);
void	perrorms2(t_cmds *cmds);
void	perrorms(t_cmds *cmds);
/* ----- exec.c ----- */
char	*get_path(char **env);
char	*get_valid_path(char *env, char *cmd);
int		child_redirect(int *pipefd, int *fd, t_cmds *cmds);
void	exec_cmd(t_cmds *cmds, t_data *data);
/* ----- exec2.c ----- */
void	wait_and_check(t_cmds *cmds, t_pids *pids, t_data *data);
char	*get_access(char *str1, char *env);
void	exv(t_cmds *cmds, t_data *data);
void	parent_redirect(int	*pipefd);
int		redirect(t_cmds *cmds, int *fd, t_pids *pids);
/* ----- exec3.c ----- */
t_pids	*last_pids(t_pids *pids);
char	*get_name_error(char *str);
void	free_fds(int **fds, t_cmds *cmds);
void	free_pids(t_pids *pids);
void	wait_all(t_pids *pids);
/* --------------------------------- HEREDOC -------------------------------- */
/* ----- expand_heredoc.c ----- */
int		get_len_tmp_heredoc(char *line);
int		get_var_2_heredoc(char *line, t_data *data, char *final);
char	*fill_exp_heredoc(char *line, t_data *data, int len, int i);
int		get_var_heredoc(char *line, t_data *data);
char	*ft_expand_heredoc(char *line, t_data *data, int i);
/* ----- expand_heredoc2.c ----- */
int		fill_tmp_get_var_heredoc(char *line, char *tmp, int j);
int		fontion_return_heredoc(char *final);
int		not_found_heredoc(char *final, char *line);
int		pass_exp_heredoc(char *line);
/* ----- heredoc.c ----- */
int		ft_heredoc(char *str, t_data *data, int qot);
int		not_here_doc(char *line, int i);
/* --------------------------------- PARSING -------------------------------- */
/* ----- expand_2.c ----- */
int		fill_tmp_get_var(char *line, char *tmp, int j);
int		fontion_return(char *final);
int		not_found(char *final, char *line, int dbl);
int		pass_exp(char *line);
/* ----- expand.c ----- */
int		get_len_tmp(char *line);
int		get_var_2(char *line, t_data *data, char *final, int dbl);
char	*fill_exp(char *line, t_data *data, long long len, int i);
int		get_var(char *line, t_data *data);
char	*ft_expand(char *line, t_data *data, long long i);
/* ----- free.c ----- */
void	ft_free_pars(t_cmds *cmds, char **cmd, char *str);
int		check_cmds(t_cmds *cmds);
void	ft_free_rdc(t_cmds *cmds);
/* ----- lex_parsing.c ----- */
void	ft_trim_rdc(char *str);
pid_t	do_execv(t_cmds *cmds, t_data *data);
pid_t	pars(char **cmd, t_data *data);
int		check_syntax(char *line);
pid_t	lex_pars(char *line, t_data *data);
/* ----- parsing.c ----- */
int		count_wc(char *str);
void	get_redirect_in(char **tabtab, t_cmds *cmds);
void	get_redirect_out(char **tabtab, t_cmds *cmds);
void	get_opt(char **tabtab, t_cmds *cmds);
t_cmds	*first_cmds(char *str);
/* ----- quote.c ----- */
int		check_quote(char *str);
char	*fill_delete_quote(char *final, char *str);
char	*delete_quote(char *str);
/* ----- syntax.c ----- */
int		check_pipe(char *line, int slp, int dbl);
int		ft_check_bracket_in(char *line);
int		ft_check_bracket_out(char *line);
int		check_angle_brackets(char *line);
/* ----- utils.c ----- */
void	check_data(t_cmds *cmds);
void	ft_lstclear_cmd(t_cmds *cmds);
int		lst_cmd_mid(char *str, t_cmds *cmds);
char	*fill_str_redirect(char *str, char *tabtab);
void	free_tab_fc(char **tabtab);
/* --------------------------------- SIGNALS -------------------------------- */
/* ----- signals.c ----- */
void	signal_controller(int i);
void	*ft_memdel(void *ptr);
void	sig_int(int code);
void	sig_quit(int code);
void	sig_init(int mode);

extern t_sig	g_signal;

#endif
