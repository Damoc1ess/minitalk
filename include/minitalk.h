/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:33:41 by fflamion          #+#    #+#             */
/*   Updated: 2024/07/28 14:34:29 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#define MINITALK_H

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
void		ft_putnbr(int n);
void		ft_putstr(char *str);
int			ft_atoi(char *str);
char		*ft_itoa(int num);
int			ft_strlen(const char *str);
static int	int_len(int n);
char		*ft_strdup(const char *s);

#endif