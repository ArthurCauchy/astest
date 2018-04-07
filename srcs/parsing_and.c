/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_and.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 13:53:02 by acauchy           #+#    #+#             */
/*   Updated: 2018/04/07 13:02:57 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astest.h"

void		parse_and(t_word **symbol, t_ast **current)
{
	t_ast	*and;

	parse_pipe(symbol, current);
	while (*symbol && ft_strcmp((*symbol)->str, "&&") == 0)
	{
		and = new_ast_node(AND, NULL);
		and->left = *current;
		parse_pipe(symbol, current);
		and->right = *current;
		*current = and;
	}
}
