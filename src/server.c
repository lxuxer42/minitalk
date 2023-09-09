/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:15:01 by rdelicad          #+#    #+#             */
/*   Updated: 2023/09/09 17:13:18 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"


static void sig_handler(int sig)
{
    static char c = 0;
    static int bit_cont = 0;

    if (sig == SIGUSR1)
        c = c | (1 << bit_cont);
    bit_cont++;

    if (bit_cont == 8)
    {
        ft_printf("Mensaje recibido: %c\n", c);
        if (c == '\0')
            ft_printf("\n");
        bit_cont = 0;
        c = 0; // Reinicia la variable c para el siguiente mensaje
    }
}

int	main(void)
{
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	ft_printf("Servidor en ejecucion (PID: %d)\n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}
