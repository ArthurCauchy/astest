/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 10:29:04 by acauchy           #+#    #+#             */
/*   Updated: 2018/04/11 11:32:51 by acauchy          ###   ########.fr       */
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

static void		delete_ast_node(t_ast *node)
{
	if (!node)
		return ;
	delete_ast_node(node->left);
	delete_ast_node(node->right);
	delete_wordlist(&node->arglist);
	free(node);
}

void			delete_ast(t_ast **ast)
{
	delete_ast_node(*ast);
	*ast = NULL;
}
