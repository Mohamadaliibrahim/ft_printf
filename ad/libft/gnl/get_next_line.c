/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajabado <ajabado@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:21:49 by mkaterji          #+#    #+#             */
/*   Updated: 2024/06/27 15:37:59 by ajabado          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static t_fd_list	*get_node(t_fd_list **head, int fd)
{
	t_fd_list	*current;

	current = *head;
	while (current)
	{
		if (current->fd == fd)
			return (current);
		current = current->next;
	}
	current = (t_fd_list *)malloc(sizeof(t_fd_list));
	if (!current)
		return (NULL);
	current->fd = fd;
	current->str = NULL;
	current->next = *head;
	*head = current;
	return (current);
}

static void	remove_node(t_fd_list **head, int fd)
{
	t_fd_list	*current;
	t_fd_list	*prev;

	current = *head;
	prev = NULL;
	while (current)
	{
		if (current->fd == fd)
		{
			if (prev)
				prev->next = current->next;
			else
				*head = current->next;
			if (current->str)
				free(current->str);
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

static char	*parse(int fd, char *buf, char *str)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		else if (bytes_read == 0)
			break ;
		buf[bytes_read] = '\0';
		if (!str)
			str = ft_strdup("");
		temp = str;
		str = ft_strjoin(temp, buf);
		free(temp);
		temp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (str);
}

static char	*extract(char *line)
{
	size_t	i;
	char	*str;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
		return (0);
	str = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!(*str))
	{
		free(str);
		str = NULL;
	}
	line[i + 1] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	char				*line;
	char				*buf;
	static t_fd_list	*fd_list;
	t_fd_list			*node;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	node = get_node(&fd_list, fd);
	if (!node)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = parse(fd, buf, node->str);
	free(buf);
	if (!line)
	{
		remove_node(&fd_list, fd);
		return (NULL);
	}
	node->str = extract(line);
	if (!node->str)
		remove_node(&fd_list, fd);
	return (line);
}
