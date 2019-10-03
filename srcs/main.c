/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 17:59:46 by kmira             #+#    #+#             */
/*   Updated: 2019/08/29 21:54:44 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

#define BUFFER 300

void	buffer_output(const char *str, int length, int final)
{
	static char		buff[BUFFER];
	static int		location;
	int				i;

	i = 0;
	while (i < length)
	{
		if (location == BUFFER)
		{
			write(1, buff, location);
			ft_bzero(buff, BUFFER);
			location = 0;
		}
		buff[location++] = str[i++];
	}
	if (final == 1 && location != 0)
	{
		write(1, buff, location);
		ft_bzero(buff, BUFFER);
		location = 0;
	}
}

int		convert(const char *format_str, size_t *index, va_list args)
{
	t_string		converted_string;
	t_format		format;
	t_spec_functs	function;
	int				arg_size;

	*index = *index + 1;
	format = extract_format(format_str, index);
	set_specifier_handler(&function, format.specifier);
	arg_size = get_argument_size(format.specifier[0], format.length);
	if (arg_size == -1)
		return (1);
	converted_string = do_function(&function, arg_size, &format, args);
	buffer_output(converted_string.output, converted_string.length, 0);
	*index = *index + 1;
	if (converted_string.free == TRUE)
		free(converted_string.output);
	return (converted_string.length);
}

int		ft_printf(const char *format_str, ...)
{
	size_t	i;
	size_t	j;
	size_t	result;
	va_list args;

	va_start(args, format_str);
	i = 0;
	result = 0;
	while (format_str[i] != '\0')
	{
		j = 0;
		while (format_str[j + i] != '\0' && format_str[j + i] != '%')
			j++;
		buffer_output(&(format_str[i]), j, 0);
		result = result + j;
		i = i + j;
		if (format_str[i] == '%')
			result += convert(format_str, &i, args);
	}
	va_end(args);
	buffer_output("", 0, 1);
	return (result);
}
