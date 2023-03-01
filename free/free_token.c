/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltunan <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:22:24 by maltunan          #+#    #+#             */
/*   Updated: 2023/01/30 15:22:24 by maltunan         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_token(void)
{
	t_token		*tmp;
	t_token		*token;

	token = g_ms.token;
	while (token)
	{
		free(token->str);
		token = token->next;
	}
	token = g_ms.token;
	while (token)
	{
		tmp = token;
		token = token->next;
		free(tmp);
	}
}
