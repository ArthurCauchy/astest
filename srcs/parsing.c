/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 13:53:02 by acauchy           #+#    #+#             */
/*   Updated: 2018/04/04 13:55:25 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astest.h"

static t_ast	*new_ast_node(t_token token, t_word *arglist)
{
	t_ast	*node;

	if (!(node = (t_ast*)malloc(sizeof(t_ast))))
		exit_error("malloc() error");
	node->token = token;
	node->arglist = new_word(arglist->str);
	node->parent = NULL;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

static void		add_ast_arg(t_word *word, t_ast **current)
{
	t_ast	*new;
	t_word	*cur;

	if (!*current)
		*current = new_ast_node(ARG, word);
	if ((*current)->token == ARG)
	{
		cur = (*current)->arglist;
		while (cur->next)
			cur = cur->next;
		cur->next = new_word(word->str);
	}
	else if ((*current)->token == AND)
	{
		new = new_ast_node(ARG, word);
		(*current)->right = new;
		new->parent = *current;
		*current = new;
	}
	else if ((*current)->token == OR)
	{
		new = new_ast_node(ARG, word);
		(*current)->right = new;
		new->parent = *current;
		*current = new;
	}
}

static void		add_ast_and(t_word *word, t_ast **current)
{
	t_ast	*new;

	(void)word;
	new = new_ast_node(AND, NULL);
	if (!*current)
		*current = new;
	else if ((*current)->token == ARG)
	{
		new->left = *current;
		(*current)->parent = new;
	}
	else if ((*current)->token == AND)
	{
		new->left = *current;
		(*current)->parent = new;
	}
	*current = new;
}


static void		add_ast_or(t_word *word, t_ast **current)
{
	(void)word;
	(void)current;
}

void			syntax_analysis(t_word *wordlist, t_ast **root)
{
	t_ast	*current;

	current = NULL;
	while (wordlist)
	{
		if (ft_strcmp(wordlist->str, "&&") == 0)
			add_ast_and(wordlist, &current);
		else if (ft_strcmp(wordlist->str, "||") == 0)
			add_ast_or(wordlist, &current);
		else
			add_ast_arg(wordlist, &current);
		wordlist = wordlist->next;
	}
	*root = current;
	while (*root && (*root)->parent) // remonter vers root
		*root = (*root)->parent;
}
