/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosanto <diosanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:36:56 by diosanto          #+#    #+#             */
/*   Updated: 2022/11/24 01:05:01 by diosanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

//Prototypes

char		*get_next_line(int fd);
void		read_and_store(int fd, t_list **stash);
void		extract_line(t_list *stash, char **line);
int			found_new_line(t_list *stash);
t_list		*ft_lst_get_last(t_list *stash);
void		add_to_stash(t_list **stash, char *buff, int counter);
void		generate_line(char **line, t_list *stash);
void		clean_stash(t_list **stash);
void		free_stash(t_list *stash);
int			ftlen(const char *str);

#endif
