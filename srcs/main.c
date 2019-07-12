/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 17:59:46 by kmira             #+#    #+#             */
/*   Updated: 2019/07/11 21:29:19 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

char	*s_handler(t_format *format, char *string)
{
	write(1, string, ft_strlen(string));
	(void)format;
	return (NULL);
}

int		convert(const char *format, size_t *index, va_list args)
{
	t_format					formatter;
	t_polymorphous_functions	function;

	if (format[*index] == '%')
		*index = *index + 1;
	formatter = extract_format(format, index);

	//I might be able to cast it as something
	function.function = set_specifier_handler(&function, formatter.specifier);
	// extract_specifier_handler;
	// specifier_handler();

	write(1, "SPECIFIER: ", 12);
	write(1, formatter.specifier, 1);
	write(1, " END\n", 5);

	*index = *index + 1;
	(void)args;
	(void)format;
	return (1);
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
	return (result);
}
