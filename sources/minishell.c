/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:11:58 by agiguair          #+#    #+#             */
/*   Updated: 2023/05/22 15:02:49 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_sig	g_signal;

void	ft_header(void)
{
	printf("\033[1;32m\n\n");
	printf("MMMMMMMM               MMMMMMMM  iiii                     iiii    \
              hhhhhhh                                lllllll lllllll\nM:::::::M\
             M:::::::M i::::i                   i::::i                 h:::::h \
                               l:::::l l:::::l\nM::::::::M           M::::::::M\
  iiii                     iiii                  h:::::h                        \
        l:::::l l:::::l\nM:::::::::M         M:::::::::M                         \
                        h:::::h                                l:::::l l:::::l\nM:\
:::::::::M       M::::::::::Miiiiiiinnnn  nnnnnnnn    iiiiiii     ssssssssss   h:::\
:h hhhhh           eeeeeeeeeeee    l::::l  l::::l\nM:::::::::::M     M:::::::::::Mi\
:::::in:::nn::::::::nn  i:::::i   ss::::::::::s  h::::hh:::::hhh      ee::::::::::::\
ee  l::::l  l::::l\nM:::::::M::::M   M::::M:::::::M i::::in::::::::::::::nn  i::::i \
ss:::::::::::::s h::::::::::::::hh   e::::::eeeee:::::eel::::l  l::::l\nM::::::M M::\
::M M::::M M::::::M i::::inn:::::::::::::::n i::::i s::::::ssss:::::sh:::::::hhh::::\
::h e::::::e     e:::::el::::l  l::::l\nM::::::M  M::::M::::M  M::::::M i::::i  n:::\
::nnnn:::::n i::::i  s:::::s  ssssss h::::::h   h::::::he:::::::eeeee::::::el::::l  l\
::::l\nM::::::M   M:::::::M   M::::::M i::::i  n::::n    n::::n i::::i    s::::::s    \
  h:::::h     h:::::he:::::::::::::::::e l::::l  l::::l\nM::::::M    M:::::M    M::::\
::M i::::i  n::::n    n::::n i::::i       s::::::s   h:::::h     h:::::he::::::eeeee\
eeeeee  l::::l  l::::l\nM::::::M     MMMMM     M::::::M i::::i  n::::n    n::::n i::::\
i ssssss   s:::::s h:::::h     h:::::he:::::::e           l::::l  l::::l\nM::::::M    \
           M::::::Mi::::::i n::::n    n::::ni::::::is:::::ssss::::::sh:::::h     h:::::h\
e::::::::e         l::::::ll::::::l\nM::::::M               M::::::Mi::::::i n::::n    n:\
:::ni::::::is::::::::::::::s h:::::h     h:::::h e::::::::eeeeeeee l::::::ll::::::l\nM::::\
::M               M::::::Mi::::::i n::::n    n::::ni::::::i s:::::::::::ss  h:::::h     h::\
:::h  ee:::::::::::::e l::::::ll::::::l\nMMMMMMMM               MMMMMMMMiiiiiiii nnnnnn    nn\
nnnniiiiiiii  sssssssssss    hhhhhhh     hhhhhhh    eeeeeeeeeeeeee lllllllllll\
lllll\n");
	printf("\033[0m");
	printf("By Jlarue and Agiguair\n\n");
}

void	ft_free_data(t_data *data)
{
	int	i;

	i = -1;
	while (data->ms_env[++i])
		free(data->ms_env[i]);
	free(data->ms_env);
	free(data);
}

int	history(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '	')
		{
			add_history(str);
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_minishell(char *str, t_data *data, pid_t pid)
{
	while (1)
	{
		signal_controller(0);
		if (g_signal.exit_status == 0)
			str = readline("\1\033[1;32m\2Minishell\1\033[0m\2\
\1\033[1;36m\2~\1\033[0m\2> ");
		else
			str = readline("\1\033[1;32m\2Minishell\1\033[0m\2\
\1\033[1;31m\2~\1\033[0m\2> ");
		if (!str)
			break ;
		if (str)
		{
			if (history(str) == 0)
				pid = lex_pars(str, data);
			if (pid == 0)
			{
				ft_free_data(data);
				exit(g_signal.exit_status);
			}
			waitpid(pid, NULL, 0);
			sig_init(1);
			free(str);
		}
	}
	ft_exit(data, NULL);
}

int	main(int argc, char **argv, char **env)
{
	char	*str;
	pid_t	pid;
	t_data	*data;

	(void) argc;
	(void) argv;
	test_isatty();
	pid = 1;
	str = NULL;
	data = malloc(sizeof(t_data));
	if (!data)
	{
		write(2, "Error Malloc\n", 14);
		exit (GENERAL_ERROR);
	}
	data = do_env(env, data, str);
	ft_header();
	sig_init(0);
	ft_minishell(str, data, pid);
	ft_free_data(data);
	return (0);
}
