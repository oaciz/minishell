/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltunan <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:22:54 by maltunan          #+#    #+#             */
/*   Updated: 2023/01/30 15:22:55 by maltunan         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	append_arguments(t_token **token, t_process *process)
{
	char		*data;

	if ((*token)->type == STRING)
	{
		data = clean_quote((*token)->str);
		process->execute = push_array(process->execute, data);
	}
	else
	{
		data = clean_quote((*token)->str);
		process->redirects = push_array(process->redirects, data);
		*token = (*token)->next;
		if (!(*token) || (*token)->type != STRING)
		{
			free_token();
			if (!(*token))
				token_err(0);
			else
				token_err((*token)->type);
			return (FALSE);
		}
		data = clean_quote((*token)->str);
		process->redirects = push_array(process->redirects, data);
	}
	return (TRUE);
}

int	lexer(void)
{
	t_token		*token;
	t_process	*process;

	token = g_ms.token;
	while (token)
	{
		if (token->type == PIPE || token->prev == NULL)
		{
			if (token->type == PIPE)
				token = token->next;
			process = init_process();
			process_addback(&g_ms.process, process);
			g_ms.process_count++;
		}
		if (!token)
			break ;
		if (!append_arguments(&token, process))
			return (FALSE);
		if (token)
			token = token->next;
	}
	free_token();
	return (TRUE);
}
