/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 16:03:10 by kmira             #+#    #+#             */
/*   Updated: 2019/07/18 13:50:32 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// t_string	apply_flags(t_format *format, t_string *str)
// {
// 	char	sign;

// 	if (str[0] || )
// }


// t_string	apply_flags(t_format *format, t_string *str)
// {
// 	char		buffer[50];
// 	t_string	output;
// 	char		pad_char;
// 	char		*cpy_start;

// 	output.length = 0;
// 	if (format->precision >= 0)
// 	{
// 		output.length = format->precision;
// 		format->flags = format->flags & ~ZERO_FLAG;
// 	}
// 	if (format->flags & ZERO_FLAG || format->flags & PLUS_FLAG || format->flags & SPACE_FLAG)
// 		output.length = output.length + 1;
// 	if (format->width > output.length)
// 		output.length = format->width;
// 	if (str->length > output.length)
// 		output.length = str->length;


// 	output.output = malloc(sizeof(*(output.output)) * (output.length + 1));
// 	output.output[output.length] = '\0';


// 	pad_char = ' ';
// 	if (format->flags & ZERO_FLAG && format->precision == -1 && format->flags & ~MINUS_FLAG)
// 		pad_char = '0';
// 	ft_memset(output.output, pad_char, output.length);
// 	if (format->flags & SPACE_FLAG)
// 		output.output[0] = ' ';
// 	if (format->flags & PLUS_FLAG && str->output[0] != '-')
// 		output.output[0] = '+';
// 	if (output.output[0] != pad_char)
// 		output.output = output.output + 1;

// 	ft_bzero(buffer, sizeof(buffer));
// 	if (format->precision > 0)
// 		ft_memset(&buffer[1], '0', format->precision);
// 	if (format->precision > str->length)
// 		ft_strcpy(&buffer[1 + (format->precision - str->length)], str->output);
// 	else
// 		ft_strcpy(&buffer[1], str->output);
// 	cpy_start = &buffer[1];
// 	if (buffer[0] != '\0')
// 		cpy_start = &buffer[0];

// 	if (format->flags & MINUS_FLAG)
// 	{
// 		// printf("HERE\n");
// 		ft_strncpy(output.output, cpy_start, ft_strlen(cpy_start));
// 	}
// 	else
// 	{
// 		// printf("THERE\n");
// 		ft_strncpy(output.output + (output.length - ft_strlen(cpy_start) + 1), cpy_start, ft_strlen(cpy_start));
// 	}
// 	// printf("\nOUTY: %s\n", cpy_start);
// 	// printf("LAST: %s\n", output.output);
// 	return (output);
// }
