/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosanto <diosanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:25:26 by diosanto          #+#    #+#             */
/*   Updated: 2022/11/24 13:03:19 by diosanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// len is strlen until \n is found
int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		len++;
	return (len);
}

// allocates mem for the new string (line + buffer until newline is found)
// returns everything that was read before + the last buffer until the new line
// if there is a '\n'.
char	*ft_strjoin(char *str1, char *str2)
{
	int		i;
	char	*final_str;

	i = 0;
	final_str = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!final_str)
		return (NULL);
	while (str1 && str1[i])
	{
		final_str[i] = str1[i];
		i++;
	}
	free(str1);
	while (*str2)
	{
		final_str[i++] = *str2;
		if (*str2++ == '\n')
			break ;
	}
	final_str[i] = '\0';
	return (final_str);
}

//
char	ft_clean(char *buff)
{
	int	i;
	int	is_new_line;
	int	j;

	i = 0;
	j = 0;
	is_new_line = 0;
	while (buff[i])
	{
		if (is_new_line)
			buff[j++] = buff[i];
		if (buff[i] == '\n')
			is_new_line = 1;
		buff[i++] = '\0';
	}
	return (is_new_line);
}
