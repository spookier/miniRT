/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 08:18:00 by acostin           #+#    #+#             */
/*   Updated: 2022/12/14 08:37:48 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		print_all(va_list args, const char *str, int num_args);
int		count_flags(const char *str, char *flags);

/* utils */
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int nb);
int		ft_unsigned_int(unsigned int nb);
int		ft_hexa(unsigned long nb, int sign);
int		ft_putpointer_check(unsigned long nb);

#endif
