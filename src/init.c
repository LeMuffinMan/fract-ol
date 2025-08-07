/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:40:50 by oelleaum          #+#    #+#             */
/*   Updated: 2025/01/28 13:56:49 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../minilibx-linux/mlx.h"
#include <stdlib.h>
#include <X11/Xlib.h>

// Fonction pour récupérer la taille de l'écran
void set_fullscreen_size(t_data *f)
{
    Display *d = XOpenDisplay(NULL);
    if (!d) {
        f->win_width = 800;
        f->win_height = 800;
        return;
    }
    Screen *s = DefaultScreenOfDisplay(d);
    f->win_width = s->width;
    f->win_height = s->height;
    f->square_size = (f->win_width < f->win_height) ? f->win_width : f->win_height;
    XCloseDisplay(d);
}

int init_data(t_data *f)
{
    set_fullscreen_size(f);
    f->fractal_number = 1;
    f->escape_value = 4;
    f->max_iterations = MIN_I;
    f->shift_view.x = 0.0;
    f->shift_view.y = 0.0;
    f->zoom = 1.0;
    f->z.x = 0;
    f->z.y = 0;
    f->c.x = 0;
    f->c.y = 0;
    return (0);
}

int init_win(t_data *f)
{
    f->mlx.mlx = mlx_init();
    if (f->mlx.mlx == NULL)
        quit(f);
    f->mlx.win = mlx_new_window(f->mlx.mlx, f->win_width, f->win_height, "Fractol");
    if (f->mlx.win == NULL)
        quit(f);
    f->mlx.img.img_p = mlx_new_image(f->mlx.mlx, f->square_size, f->square_size);
    if (f->mlx.img.img_p == NULL)
        quit(f);
    f->mlx.img.pixels = mlx_get_data_addr(f->mlx.img.img_p, &f->mlx.img.bpp,
            &f->mlx.img.line_len, &f->mlx.img.endian);
    if (f->mlx.img.pixels == NULL)
        quit(f);
    f->mlx.img.bpp /= 8;
    render_fractal(f);
    return (0);
}

int	quit(t_data *f)
{
	if (!f)
		exit(1);
	if (f->mlx.img.img_p)
		mlx_destroy_image(f->mlx.mlx, f->mlx.img.img_p);
	if (f->mlx.win)
		mlx_destroy_window(f->mlx.mlx, f->mlx.win);
	if (f->mlx.mlx)
	{
		mlx_loop_end(f->mlx.mlx);
		mlx_destroy_display(f->mlx.mlx);
		free(f->mlx.mlx);
	}
	exit(0);
}
