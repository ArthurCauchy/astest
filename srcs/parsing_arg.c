/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 13:53:02 by acauchy           #+#    #+#             */
/*   Updated: 2018/04/06 15:00:41 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astest.h"

void	parse_arg(t_word **symbol, t_ast **current)
{
	t_word	*cur;
	t_ast	*curr_arg;

	curr_arg = NULL;
	*symbol = (*symbol)->next;
	while (*symbol && (ft_strcmp((*symbol)->str, "||") != 0 && ft_strcmp((*symbol)->str, "&&") != 0))
	{
		if (curr_arg)
		{
			cur = curr_arg->arglist;
			while (cur->next)
				cur = cur->next;
			cur->next = new_word((*symbol)->str);
		}
		else
		{
			curr_arg = new_ast_node(ARG, *symbol);
			*current = curr_arg;
		}
		*symbol = (*symbol)->next;
	}
}
