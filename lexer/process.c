/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltunan <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:23:01 by maltunan          #+#    #+#             */
/*   Updated: 2023/01/30 15:23:01 by maltunan         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_process	*init_process(void)
{
	t_process	*process;

	process = ft_calloc(sizeof(t_process), 1);
	pipe(process->fd);
	process->pid = -1;
	process->execute = ft_calloc(sizeof(char *), 1);
	process->redirects = ft_calloc(sizeof(char *), 1);
	process->prev = NULL;
	process->next = NULL;
	return (process);
}

void	process_addback(t_process **process, t_process *new_process)
{
	t_process	*i_process;

	i_process = *process;
	if (!(i_process))
		*process = new_process;
	else
	{
		while (i_process->next)
			i_process = i_process->next;
		i_process->next = new_process;
		new_process->prev = i_process;
	}
}
