/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:30:45 by oelleaum          #+#    #+#             */
/*   Updated: 2025/02/19 16:02:18 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../minilibx-linux/mlx.h"
#include <pthread.h>

inline static double	scale(double unscaled_num, double new_min,
		double new_max, double old_max)
{
	return ((new_max - new_min) * (unscaled_num) / old_max + new_min);
}

// Nouvelle version : set_complexes initialise z et c en local
static void set_complexes(int x, int y, t_data *f, t_coords *z, t_coords *c)
{
    if (f->fractal_number == 1)
    {
        z->x = 0.0;
        z->y = 0.0;
        c->x = (scale(x, -3, +3, f->square_size) * f->zoom) + f->shift_view.x;
        c->y = (scale(y, -3, +3, f->square_size) * f->zoom) - f->shift_view.y;
    }
    else if (f->fractal_number == 2)
    {
        z->x = (scale(x, -3, +3, f->square_size) * f->zoom) + f->shift_view.x;
        z->y = (scale(y, -3, +3, f->square_size) * f->zoom) - f->shift_view.y;
        c->x = f->julia_constant.x;
        c->y = f->julia_constant.y;
    }
}

inline static void	iterations_to_color(int i, int *color, t_data *f)
{
	t_color	colors;
	double	t;

	t = (double)i / f->max_iterations;
	colors.r = (char)(9 * (1 - t) * t * t * t * t * 255);
	colors.g = (char)(15 * (1 - t) * (1 - t) * t * t * 255);
	colors.b = (char)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	*color = colors.color;
}

// Nouvelle version : iterate_on_pixels utilise z et c locaux
static void iterate_on_pixels(int x, int y, t_data *f)
{
    int i;
    int color;
    t_coords z, c, z_squared;

    set_complexes(x, y, f, &z, &c);
    i = 0;
    while (i < f->max_iterations)
    {
        z_squared.x = (z.x * z.x) - (z.y * z.y);
        z_squared.y = 2 * z.x * z.y;
        z.x = z_squared.x + c.x;
        z.y = z_squared.y + c.y;
        if ((z.x * z.x) + (z.y * z.y) > f->escape_value)
        {
            iterations_to_color(i, &color, f);
            *(unsigned int *)(f->mlx.img.pixels + (y * f->mlx.img.line_len) + (x * (f->mlx.img.bpp))) = color;
            return;
        }
        i++;
    }
    *(unsigned int *)(f->mlx.img.pixels + (y * f->mlx.img.line_len) + (x * (f->mlx.img.bpp))) = BLACK;
}

// thread_render appelle iterate_on_pixels qui gère tout en local
static void *thread_render(void *arg)
{
    t_thread_args *args = (t_thread_args *)arg;
    int x, y;
    for (y = args->start_y; y < args->end_y; y++) {
        for (x = 0; x < args->f->square_size; x++) {
            iterate_on_pixels(x, y, args->f);
        }
    }
    return NULL;
}

void render_fractal(t_data *f)
{
    pthread_t threads[THREADS];
    t_thread_args args[THREADS];
    int i;
    int lines_per_thread = f->square_size / THREADS;

    for (i = 0; i < THREADS; i++) {
        args[i].f = f;
        args[i].start_y = i * lines_per_thread;
        args[i].end_y = (i == THREADS - 1) ? f->square_size : (i + 1) * lines_per_thread;
        pthread_create(&threads[i], NULL, thread_render, &args[i]);
    }
    for (i = 0; i < THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    int offset_x = (f->win_width - f->square_size) / 2;
    int offset_y = (f->win_height - f->square_size) / 2;
    mlx_put_image_to_window(f->mlx.mlx, f->mlx.win, f->mlx.img.img_p, offset_x, offset_y);
}
