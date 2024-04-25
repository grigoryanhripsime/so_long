/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trimming.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrigrigo <hrigrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:16:16 by hrigrigo          #+#    #+#             */
/*   Updated: 2024/04/25 19:02:27 by hrigrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check(int c, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char *s1, char *set)
{
	int		start;
	int		end;
	char	*str;
	int		i;

	if (!s1 || !set)
		return (0);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (end >= start && check(s1[end], (char *) set))
		end--;
	str = (char *)malloc(end - start + 2);
	if (!str)
		return (0);
	i = 0;
	while (start + i <= end)
	{
		str[i] = s1[start + i];
		i++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

void	trimming_map_start(t_map **map)
{
	t_map	*tmp;
	t_map	*next;

	tmp = *map;
	while (tmp)
	{
		tmp -> line = ft_strtrim(tmp -> line, " \f\n\r\t\v");
		if (!ft_strlen(tmp -> line))
		{
			next = tmp -> next;
			free(tmp -> line);
			free(tmp);
			tmp = next;
			tmp -> prev = NULL;
		}
		else
			break ;
	}
	(*map) = tmp;
}

void	trimming_map_end(t_map **map)
{
	t_map	*tmp;
	t_map	*prev;

	tmp = *map;
	while (tmp && tmp -> next)
		tmp = tmp -> next;
	while (tmp && tmp -> prev)
	{
		tmp -> line = ft_strtrim(tmp -> line, " \f\n\r\t\v");
		if (!ft_strlen(tmp -> line))
		{
			prev = tmp -> prev;
			free(tmp -> line);
			free(tmp);
			tmp = prev;
			tmp -> next = NULL;
		}
		else
			break ;
	}
}

void	trimming_lines(t_map **map)
{
	t_map	*tmp;

	tmp = *map;
	while (tmp)
	{
		tmp -> line = ft_strtrim(tmp -> line, " \f\n\r\t\v");
		if (!ft_strlen(tmp ->line) || ft_strchr(tmp -> line))
		{
			free_map_struct(*map);
			error_exit("White-space in map!!\n");
		}
		tmp = tmp -> next;
	}
}
