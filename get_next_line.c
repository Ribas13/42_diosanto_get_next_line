/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosanto <diosanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:25:32 by diosanto          #+#    #+#             */
/*   Updated: 2022/11/24 01:40:45 by diosanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

/* GET_NEXT_LINE:
	call read --> after that, check for newline on the buffer. If true, we have
	reached the end of the line. stop there and return.
	if false, keep adding the buffer to the stash string and keep reading.
*/

// 1. read from fd and add to linked list;
// 2. extract from stash to line;
// 3. clean up stash;

char	*get_next_line(int fd)
{
	static t_list	*stash = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
	read_and_store(fd, &stash);
	if (!stash)
		return (NULL);
	extract_line(stash, &line);
	clean_stash(&stash);
	if (line[0] == '\0')
	{
		free_stash(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

// 1. Uses read() to add characters to the stash(linked list).

void	read_and_store(int fd, t_list **stash)
{
	char	*buff;
	int		counter;

	counter = 1;
	while (!found_new_line(*stash) && counter != 0)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return ;
		counter = (int)read(fd, buff, BUFFER_SIZE);
		if ((!*stash && counter == 0) || counter == -1)
			free(buff);
		buff[counter] = '\0';
		add_to_stash(stash, buff, counter);
		free(buff);
	}
}

// 2. Extracts all characters from stash and stores them in out line.
// stopping after the first \n it finds

void	extract_line(t_list *stash, char **line)
{
	int	i;
	int	j;

	if (!stash)
		return ;
	generate_line(line, stash);
	if (!*line)
		return ;
	j = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				(*line)[j++] = stash->content[i];
				break ;
			}
			(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
}

// Frees the entire stash
/* 
 * After extracting the line that was read, we don't need those chars anymore.
 * This function clears the stash so only the chars that haven't been
 * returned at the end of get_next_line() remain in our static stash.
*/

void	clean_stash(t_list **stash)
{
	t_list	*last;
	t_list	*clean_node;
	int		i;
	int		j;

	clean_node = malloc(sizeof(t_list));
	if (!stash || !clean_node)
		return ;
	clean_node->next = NULL;
	last = ft_lst_get_last(*stash);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	clean_node->content = malloc(sizeof(char) * (ftlen(last->content) - i) + 1);
	if (!clean_node->content)
		return ;
	j = 0;
	while (last->content[i])
		clean_node->content[j++] = last->content[i++];
	clean_node->content[j] = '\0';
	free_stash(*stash);
	*stash = clean_node;
}

void	free_stash(t_list *stash)
{
	t_list	*current;
	t_list	*next;

	current = stash;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("tests/test.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (line == NULL)
			break ;
		free(line);
	}
	return (0);
}