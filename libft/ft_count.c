/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 09:38:03 by acauchy           #+#    #+#             */
/*   Updated: 2018/02/26 09:38:06 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count(char *str, char c)
{
	int count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			++count;
		++str;
	}
	return (count);
}
