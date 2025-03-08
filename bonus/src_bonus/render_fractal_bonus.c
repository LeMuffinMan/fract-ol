/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractal_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:30:45 by oelleaum          #+#    #+#             */
/*   Updated: 2025/02/22 10:53:27 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/fractol_bonus.h"
#include "../../minilibx-linux/mlx.h"
#include <math.h>
#include <pthread.h>
#include <stdlib.h>

int	first_render(t_data *f)
{
	iterate_on_pixels(f);
	f->max_iterations += 2;
	if (f->max_iterations >= 40)
		f->flags.fractal_switch = 0;
	return (0);
}

void set_complexes(int x, int y, t_data *f, t_coords *z, t_coords *c) {
    z->x = 0.0;
    z->y = 0.0;
    if (f->fractal_number == 2 || f->fractal_number == 7
        || f->fractal_number == 1 || f->fractal_number == 9) {
        c->x = (scale(x, -3, +3, WINSIZE) * f->zoom) + f->shift_view.x;  // Fixed missing ')'
        c->y = (scale(y, -3, +3, WINSIZE) * f->zoom) - f->shift_view.y;
    } else if (f->fractal_number == 3) {
        c->x = (scale(x, -3, +3, WINSIZE) * f->zoom) + f->shift_view.x;
        c->y = (scale(y, +3, -3, WINSIZE) * f->zoom) + f->shift_view.y;
    } else if (f->fractal_number == 4 || f->fractal_number == 5
               || f->fractal_number == 6 || f->fractal_number == 8) {
        z->x = (scale(x, -3, +3, WINSIZE) * f->zoom) + f->shift_view.x;  // Fixed missing ')'
        z->y = (scale(y, +3, -3, WINSIZE) * f->zoom) + f->shift_view.y;
        c->x = f->julia_constant.x;
        c->y = f->julia_constant.y;
    }
}

void *thread_render(void *arg) {
    t_thread_data *data = (t_thread_data *)arg;
    t_data *f = data->f;
    int x, y;

    for (y = data->start_y; y < data->end_y; y++) {
        for (x = 0; x < WINSIZE; x++) {
            set_complexes(x, y, f, &data->z, &data->c);  // Pass local z and c
            render_fractal(x, y, f, &data->z, &data->c);  // Pass local z and c
        }
    }
    return NULL;
}

void iterate_on_pixels(t_data *f) {
    pthread_t threads[NUM_THREADS];
    t_thread_data thread_data[NUM_THREADS];
    int i;
    int segment_height = WINSIZE / NUM_THREADS;

    for (i = 0; i < NUM_THREADS; i++) {
        thread_data[i].f = f;
        thread_data[i].start_y = i * segment_height;
        thread_data[i].end_y = (i + 1) * segment_height;
        if (i == NUM_THREADS - 1) {
            thread_data[i].end_y = WINSIZE; // Ensure the last thread covers the remaining rows
        }
        // Initialize local z and c
        thread_data[i].z.x = 0.0;
        thread_data[i].z.y = 0.0;
        thread_data[i].c.x = 0.0;
        thread_data[i].c.y = 0.0;
        pthread_create(&threads[i], NULL, thread_render, &thread_data[i]);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    mlx_put_image_to_window(f->mlx.mlx, f->mlx.win, f->mlx.img.img_p, 0, 0);
    mlx_do_sync(f->mlx.mlx);
}

void render_fractal(int x, int y, t_data *f, t_coords *z, t_coords *c)
{
    int i;
    int color;
    t_coords coords;

    i = 0;
    color = 0;
    while (i < f->max_iterations) {
        calculate_f(f, z, c);  // Pass local z and c
        coords.x = x;
        coords.y = y;
        if (colorize_pixel(coords, f, color, i))
            return;
        i++;
    }
    if (f->flags.psyche_switch == 1)
        color = BLACK;
    else
        *(unsigned int *)(f->mlx.img.pixels + (y * f->mlx.img.line_len) + (x * (f->mlx.img.bpp))) = BLACK;
}
