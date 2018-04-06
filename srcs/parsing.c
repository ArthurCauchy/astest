/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 13:53:02 by acauchy           #+#    #+#             */
/*   Updated: 2018/04/06 15:17:02 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astest.h"

static void		print_ast(t_ast *root)
{
	t_word	*cur;

	if (!root)
		return ;
	ft_putstr("(");
	print_ast(root->left);
	if (root->token == ARG)
	{
		cur = root->arglist;
		while (cur)
		{
			ft_putstr(cur->str);
			cur = cur->next;
		}
	}
	else if (root->token == AND)
		ft_putstr(" AND ");
	else if (root->token == OR)
		ft_putstr(" OR ");
	print_ast(root->right);
	ft_putstr(")");
}

static void		build_tree(t_word **wordlist, t_ast **root)
{
	t_word	*start_word;

	start_word = new_word("");
	start_word->next = *wordlist;
	*wordlist = start_word;
	parse_or(wordlist, root);
}

void			syntax_analysis(t_word *wordlist, t_ast **root)
{
	build_tree(&wordlist, root);
	print_ast(*root);
}
