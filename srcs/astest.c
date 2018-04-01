#include "astest.h"

/*static t_ast	*new_ast_node(t_token token, char *arg)
{
	t_ast	*node;

	if (!(node = (t_ast*)malloc(sizeof(t_ast))))
		exit_error("malloc() error");
	node->token = token;
	node->arg = ft_strdup(arg);
	node->left = NULL;
	node->right = NULL;
	return (node);
}*/

/*static void		syntax_analysis(t_word *wordlist, t_ast **root)
{
}*/

int				main(void)
{
	char	buff[4096];
	int		size_read;
	t_word	*wordlist;
	//t_ast	*ast;

	wordlist = NULL;
	//ast = NULL;
	while ((size_read = read(0, buff, 4095)))
	{
		buff[size_read] = '\0';
		if (buff[size_read - 1] == '\n')
			buff[size_read - 1] = '\0';
		if (ft_strlen(buff) == 0)
			break;
		lex_analysis(buff, &wordlist);

		//test
		t_word	*cur = wordlist;
		while (cur)
		{
			ft_fminiprint(1, "\"%l0s%\"\n", cur->str);
			cur = cur->next;
		}

		//endtest
	}
	return (0);
}
