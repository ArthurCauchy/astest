/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_parse_or.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 13:53:02 by acauchy           #+#    #+#             */
/*   Updated: 2018/04/09 10:07:18 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astest.h"

void		parse_or(t_word **symbol, t_ast **current)
{
	t_ast	*or;

	parse_and(symbol, current);
	while (*symbol && ft_strcmp((*symbol)->str, "||") == 0)
	{
		or = new_ast_node(OR, NULL);
		or->left = *current;
		parse_and(symbol, current);
		or->right = *current;
		*current = or;
	}
}
