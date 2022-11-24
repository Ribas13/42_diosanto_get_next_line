/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosanto <diosanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:36:56 by diosanto          #+#    #+#             */
/*   Updated: 2022/11/24 13:00:04 by diosanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
//# include <sys/types.h>
//# include <sys/uio.h>

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
int			ft_strlen(char *str);
char		*ft_strjoin(char *str1, char *str2);
char		ft_clean(char *buff);

#endif
