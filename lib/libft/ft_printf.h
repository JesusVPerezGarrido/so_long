/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:10:36 by jeperez-          #+#    #+#             */
/*   Updated: 2024/09/30 19:16:44 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <stdint.h>

int		ft_printf(char const *str, ...);
int		ft_printchr(char c);
int		ft_printstr(char *str);
char	*ft_hextoa(unsigned int hex, int upp);
char	*ft_ptrtoa(void *ptr);
int		ft_printptr(void *ptr);
int		ft_printnbr(int nbr);
int		ft_printunbr(unsigned int nbr);
char	*ft_uitoa(unsigned int n);
int		ft_printhex(int hex, int upp);

#endif
