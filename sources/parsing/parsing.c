/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:10:48 by agiguair          #+#    #+#             */
/*   Updated: 2023/05/08 17:12:14 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	count_wc(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == ' ' && str[i - 1] != ' ')
			j++;
		i++;
	}
	return (j);
}

void	get_redirect_in(char **tabtab, t_cmds *cmds)
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	while (tabtab[i])
	{
		if (tabtab[i][0] == '<')
			str = fill_str_redirect(str, tabtab[i]);
		i++;
	}
	if (str)
		cmds->in = ft_strdup(str);
	else
		cmds->in = ft_strdup("");
	if (str)
		free(str);
	return ;
}

void	get_redirect_out(char **tabtab, t_cmds *cmds)
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	while (tabtab[i])
	{
		if (tabtab[i][0] == '>')
			str = fill_str_redirect(str, tabtab[i]);
		i++;
	}
	if (str)
		cmds->out = ft_strdup(str);
	else
		cmds->out = ft_strdup("");
	if (str)
		free(str);
	return ;
}

void	get_opt(char **tabtab, t_cmds *cmds)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (tabtab[i])
	{
		if (tabtab[i][0] != '>' && tabtab[i][0] != '<')
			k++;
		i++;
	}
	cmds->opt = malloc(sizeof(char *) * (k + 1));
	if (!cmds->opt)
		return ;
	i = 0;
	k = 0;
	while (tabtab[i])
	{
		if (tabtab[i][0] != '>' && tabtab[i][0] != '<')
		{
			cmds->opt[k++] = delete_quote(tabtab[i]);
		}
		i++;
	}
	cmds->opt[k] = NULL;
}

t_cmds	*first_cmds(char *str)
{
	int		i;
	char	**tabtab;
	t_cmds	*cmds;

	i = -1;
	cmds = malloc(sizeof(t_cmds));
	if (!cmds)
		return (NULL);
	tabtab = ft_split_quote(str, ' ');
	while (tabtab[++i])
	{
		if (tabtab[i][0] != '>' && tabtab[i][0] != '<')
		{
			cmds->cmd = delete_quote(tabtab[i]);
			break ;
		}
	}
	if (!tabtab[i])
		cmds->cmd = ft_strdup("");
	get_redirect_in(tabtab, cmds);
	get_redirect_out(tabtab, cmds);
	get_opt(tabtab, cmds);
	cmds->next = NULL;
	free_tab_fc(tabtab);
	return (cmds);
}
