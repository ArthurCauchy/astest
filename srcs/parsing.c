/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 13:53:02 by acauchy           #+#    #+#             */
/*   Updated: 2018/04/02 17:21:53 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static t_ast	*new_ast_node(t_token token, t_word *arglist)
{
	t_ast	*node;

	if (!(node = (t_ast*)malloc(sizeof(t_ast))))
		exit_error("malloc() error");
	node->token = token;
	node->arg = ft_strdup(arg);
	node->left = NULL;
	node->right = NULL;
	return (node);
}

static void		add_ast_semicol(t_word *word, t_ast **root, t_ast *current)
{
	t_ast	*new;

	new = new_ast_node(SEMICOL, NULL);
	if (!current)
		current = new;
	else if (current == SEMICOL)
	{
		current->right = new;
		current = new;
	}
	else if (current == ARG)
	{
		new->left = current;
		current = new;
	}
}

static void		add_ast_arg(t_word *word, t_ast **root, t_ast *current)
{
	t_ast	*new;


}

void			syntax_analysis(t_word *wordlist, t_ast **root)
{
	t_ast	*current;

	current = NULL;
	while (*wordlist)
	{
		if (ft_strcmp(wordlist->str, ";") == 0)
			add_ast_semicol(wordlist, root, current);
		else
			add_ast_arg(wordlist, root, current);
		if (!*root)
			*root = current;
		wordlist = wordlist->next;		
	}
}
