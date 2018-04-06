/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 10:29:04 by acauchy           #+#    #+#             */
/*   Updated: 2018/04/06 15:11:02 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astest.h"

t_ast			*new_ast_node(t_token token, t_word *arglist)
{
	t_ast	*node;

	if (!(node = (t_ast*)malloc(sizeof(t_ast))))
		exit_error("malloc() error");
	node->token = token;
	if (arglist)
		node->arglist = new_word(arglist->str);
	else
		node->arglist = NULL;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
