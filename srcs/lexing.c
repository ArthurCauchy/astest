/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 13:53:13 by acauchy           #+#    #+#             */
/*   Updated: 2018/04/13 12:04:21 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astest.h"

int				lex_is_separator(char c)
{
	return (c == ' ' || c == '\t' || c == '\0');
}

void			add_word(char *str, t_word **wordlist)
{
	t_word	*word;
	t_word	*cur;

	word = new_word(str);
	if (!*wordlist)
		*wordlist = word;
	else
	{
		cur = *wordlist;
		while (cur->next)
			cur = cur->next;
		cur->next = word;
	}
}

static void		update_quotes(char *cmdline, t_lexdata *lexdata)
{
	if (lexdata->quoted == 0)
	{
		if (cmdline[lexdata->i] == '\'')
			lexdata->quoted = 1;
		else if (cmdline[lexdata->i] == '"')
			lexdata->quoted = 2;
	}
	else if (lexdata->quoted == 1)
	{
		if (cmdline[lexdata->i] == '\'')
			lexdata->quoted = 0;
		else if (cmdline[lexdata->i] == '"')
			lexdata->buff[lexdata->j++] = cmdline[lexdata->i];
	}
	else if (lexdata->quoted == 2)
	{
		if (cmdline[lexdata->i] == '"')
			lexdata->quoted = 0;
		else if (cmdline[lexdata->i] == '\'')
			lexdata->buff[lexdata->j++] = cmdline[lexdata->i];
	}
}

static void		init_lexdata(char *cmdline, t_lexdata **lexdata)
{
	if (!(*lexdata = (t_lexdata*)ft_memalloc(sizeof(t_lexdata))))
		exit_error("ft_memalloc() error");
	if (!((*lexdata)->buff = (char*)malloc(ft_strlen(cmdline))))
		exit_error("malloc() error");
}

void			lex_analysis(char *cmdline, t_word **wordlist)
{
	t_lexdata	*lexdata;

	init_lexdata(cmdline, &lexdata);
	while (lexdata->i <= ft_strlen(cmdline))
	{
		if (!lexdata->quoted && lex_is_separator(cmdline[lexdata->i]))
			lex_space_word(cmdline, wordlist, lexdata);
		else if (!lexdata->quoted && cmdline[lexdata->i] == ';')
			lex_semicol_word(cmdline, wordlist, lexdata);
		else if (!lexdata->quoted && cmdline[lexdata->i] == '&')
			lex_amp_and_word(cmdline, wordlist, lexdata);
		else if (!lexdata->quoted && cmdline[lexdata->i] == '|')
			lex_pipe_or_word(cmdline, wordlist, lexdata);
		else if (!lexdata->quoted && cmdline[lexdata->i] == '>')
			lex_rshift_word(cmdline, wordlist, lexdata);
		else if (!lexdata->quoted && cmdline[lexdata->i] == '<')
			lex_lshift_word(cmdline, wordlist, lexdata);
		else if (cmdline[lexdata->i] == '\'' || cmdline[lexdata->i] == '"')
			update_quotes(cmdline, lexdata);
		else
			lexdata->buff[lexdata->j++] = cmdline[lexdata->i];
		++lexdata->i;
	}
	free(lexdata->buff);
	free(lexdata);
}
