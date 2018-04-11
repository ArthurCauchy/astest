/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 11:16:48 by acauchy           #+#    #+#             */
/*   Updated: 2018/04/11 11:39:36 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astest.h"

int	exec_ast(t_ast *node)
{
	if (node->token == SEMICOL)
		return (exec_ast_semicol(node));
	else if (node->token == OR)
		return (exec_ast_or(node));
	else if (node->token == AND)
		return (exec_ast_and(node));
	else if (node->token == PIPE)
		return (exec_ast_pipe(node));
	else
		return (exec_ast_arg(node));
}
