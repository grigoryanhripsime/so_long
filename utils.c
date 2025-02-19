/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrigrigo <hrigrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:16:18 by hrigrigo          #+#    #+#             */
/*   Updated: 2024/04/29 20:28:11 by hrigrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	map_len(t_map *map)
{
	int	len;

	len = 0;
	while (map)
	{
		len++;
		map = map -> next;
	}
	return (len);
}

char	*ft_strchr(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_isspace(s[i]))
			return ((char *) s);
		i++;
	}
	return (0);
}

void	*anim(t_game *game)
{
	static int	i;

	if (i < 50)
	{
		i++;
		return (game -> coin1);
	}
	if (i < 150)
	{
		i++;
		return (game -> coin);
	}
	i = 0;
	return (game -> coin);
}
