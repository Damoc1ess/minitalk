/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:33:41 by fflamion          #+#    #+#             */
/*   Updated: 2024/07/29 16:12:57 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>

void	ft_putnbr(int n);
void	ft_putstr(char *str);
void	ft_putstr_red(const char *str);
int		ft_atoi(char *str);
char	*ft_itoa(int num);
char	*ft_itoa(int n);
int		ft_strlen(const char *str);
void	reset_char_state(unsigned char *c, char **str);
void	reset_int_state(int *bit_count, int *trigger, int *len, int *i);

#endif