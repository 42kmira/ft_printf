/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 17:59:46 by kmira             #+#    #+#             */
/*   Updated: 2019/08/22 02:59:09 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

#define BUFFER 5000

void	buffer_output(const char *str, int length, int final)
{
	static char		buff[BUFFER];
	static int		location;
	int				offset;
	int				i;

	i = 0;
	offset = 0;
	while (i < length)
	{
		if (location + offset == BUFFER)
		{
			write(1, buff, location + offset);
			ft_bzero(buff, BUFFER);
			location = 0;
			offset = 0;
		}
		buff[location + offset++] = str[i++];
	}
	location = location + offset;
	if (final == 1 && location != 0)
	{
		write(1, buff, location);
		ft_bzero(buff, BUFFER);
		location = 0;
	}
}

int		convert(const char *format, size_t *index, va_list args)
{
	t_string		converted_string;
	t_format		formatter;
	t_spec_functs	function;
	int				arg_size;

	if (format[*index] == '%')
		*index = *index + 1;
	formatter = extract_format(format, index);
	set_specifier_handler(&function, formatter.specifier);
	arg_size = get_arguement_size(formatter.specifier[0], formatter.length);
	if (arg_size == -1)
		return (1);
	converted_string = do_function(&function, arg_size, &formatter, args);
	buffer_output(converted_string.output, converted_string.length, 0);
	if (converted_string.free == TRUE)
		free(converted_string.output);
	*index = *index + 1;
	return (converted_string.length);
}

int		ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	j;
	size_t	result;
	va_list args;

	va_start(args, format);
	i = 0;
	result = 0;
	while (format[i] != '\0')
	{
		j = 0;
		while (format[j + i] != '\0' && format[j + i] != '%')
			j++;
		buffer_output(&(format[i]), j, 0);
		result = result + j;
		i = i + j;
		if (format[i] == '%')
			result += convert(format, &i, args);
	}
	va_end(args);
	buffer_output("", 0, 1);
	return (result);
}
