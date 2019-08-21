/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 17:59:46 by kmira             #+#    #+#             */
/*   Updated: 2019/08/21 02:44:54 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

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
	write(1, converted_string.output, converted_string.length);
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
		write(1, &(format[i]), j);
		result = result + j;
		i = i + j;
		if (format[i] == '%')
			result += convert(format, &i, args);
	}
	va_end(args);
	system("leaks test.out");
	return (result);
}
