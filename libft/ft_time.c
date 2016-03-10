/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 09:07:39 by tguillem          #+#    #+#             */
/*   Updated: 2016/03/10 09:08:33 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char				*get_next(char *str)
{
	while (*str && *str != ' ' && *str != '\n')
		str++;
	return (str);
}

static char				*date_next(char **start_pos, char **end_pos)
{
	char		*result;

	*end_pos = get_next(*start_pos);
	result = ft_strsub(*start_pos, 0, *end_pos - *start_pos);
	*start_pos = *end_pos + 1;
	while (*(*start_pos) && *(*start_pos) == ' ')
		(*start_pos)++;
	return (result);
}

t_date					*ft_date(time_t *time)
{
	char		*raw_data;
	t_date		*result;
	char		*start_pos;
	char		*end_pos;

	start_pos = 0;
	raw_data = ctime(time);
	end_pos = raw_data + ft_strlen(raw_data);
	if (!(result = (t_date*)ft_memalloc(sizeof(t_date))))
		return (NULL);
	end_pos = get_next(raw_data);
	start_pos = end_pos + 1;
	result->raw_data = raw_data;
	result->day = ft_strsub(raw_data, 0, end_pos - raw_data);
	result->month = date_next(&start_pos, &end_pos);
	result->day_of_month = date_next(&start_pos, &end_pos);
	result->time = ft_strsub(start_pos, 0, 8);
	start_pos += 8;
	while (*start_pos && *start_pos == ' ')
		start_pos++;
	result->year = date_next(&start_pos, &end_pos);
	return (result);
}
