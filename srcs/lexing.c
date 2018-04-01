#include "astest.h"

static int		is_separator(char c)
{
	return (c == ' ' || c == '\t' || c == '\0');
}

static void		add_word(char *str, t_word **wordlist)
{
	t_word	*word;
	t_word	*cur;
	char	*word_str;

	if (!(word = (t_word*)malloc(sizeof(t_word))))
		exit_error("malloc() error");
	if (!(word_str = ft_strdup(str)))
		exit_error("ft_strdup() error");
	word->str = word_str;
	word->next = NULL;
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

static void		lex_space_word(char *cmdline, t_word **wordlist, t_lexdata *lexdata) 
{
	lexdata->buff[lexdata->j] = '\0';
	lexdata->j = 0;
	if (ft_strlen(lexdata->buff) > 0)
		add_word(lexdata->buff, wordlist);
	while (lexdata->i <= ft_strlen(cmdline) && is_separator(cmdline[++lexdata->i]));
	--lexdata->i;
}

static void		lex_semicol_word(char *cmdline, t_word **wordlist, t_lexdata *lexdata) 
{
	(void)cmdline;
	lexdata->buff[lexdata->j] = '\0';
	lexdata->j = 0;
	if (ft_strlen(lexdata->buff) > 0)
		add_word(lexdata->buff, wordlist);
	add_word(";", wordlist);
}
void			lex_analysis(char *cmdline, t_word **wordlist)
{
	t_lexdata	*lexdata;
	int			quoted;

	quoted = 0;
	if (!(lexdata = (t_lexdata*)ft_memalloc(sizeof(t_lexdata))))
		exit_error("ft_memalloc() error");
	if (!(lexdata->buff = (char*)malloc(ft_strlen(cmdline))))
		exit_error("malloc() error");
	while (lexdata->i <= ft_strlen(cmdline))
	{
		if (!quoted && is_separator(cmdline[lexdata->i]))
			lex_space_word(cmdline, wordlist, lexdata);
		else if (!quoted && cmdline[lexdata->i] == ';')
			lex_semicol_word(cmdline, wordlist, lexdata);
		else if (cmdline[lexdata->i] == '"')
			quoted = (quoted) ? 0 : 1;
		else
			lexdata->buff[lexdata->j++] = cmdline[lexdata->i];
		++lexdata->i;
	}
}
