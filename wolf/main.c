/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 20:55:24 by ncollie           #+#    #+#             */
/*   Updated: 2018/11/08 18:25:21 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "header.h"
#define HEIGHT 200
#define WIDTH 320
#include <unistd.h>
#include <math.h>
#include <stdio.h>  //printf

#define mapWidth 10
#define mapHeight 10

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,1},
  {1,0,1,1,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,1},
  {1,0,0,1,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,1}, 
  {1,1,1,1,1,1,1,1,1,1}
};


// void	make_line(int y, t_window_info *window)
// {
// 	int color = 0;
// 	int temp = 0;
// 	while (temp < WIDTH)
// 	{
// 		color += 10;
// 		mlx_pixel_put(window->mlx, window->window, temp++, y, color);
// 	}
// }

int	deal_key(int key, void *param)
{
	// t_window_info *info = (t_window_info *)param;
	t_player *player = (t_player *)param;
	printf("\n\n%i:\n\n", key);
	if (key == 0) //A
		write(1, "a", 1);
	if (key == 1) //S
	{
		player->location.y -= .10;
		printf("x:%f\ty:%f\n", player->location.x, player->location.y);
	}
		write(1, "s", 1);
	if (key == 2) //D
		write(1, "d", 1);
	if (key == 13) //W
		write(1, "w", 1);
	if (key == 53)
	{
		// mlx_destroy_window(info->mlx, info->window);
		exit(0);
	}
	param = NULL;
	return (0);
}

int main(void)
{
	void *mlx_ptr;
	void *win_ptr;	

	t_player_p pl = (t_player_p){ .x = 1.5, .y = 1.5};
	t_point pv = (t_point){ .x = 1, . y = 0};
	t_player player = (t_player){ .location = pl, .normal = pv, .fov = 60, .height = 32};




	t_point p1 = (t_point){ .x = 20, .y = 30};
	t_point p2 = (t_point){ .x = 20, .y = 100};
	t_point p3 = (t_point){ .x = 250, .y = 65};
	t_point p4 = (t_point){ .x = 250, .y = 0};
	t_point p5 = (t_point){ .x = 250, .y = 500};

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "awesome");



	t_window_info win_info = (t_window_info){mlx_ptr, win_ptr};
	t_line_info line = (t_line_info){ .p1 = p1, .p2 = p2, .color = 0x0000FF};
	t_line_info line1 = (t_line_info){ .p1 = p1, .p2 = p3, .color = 0xFF0000};
	t_line_info line2 = (t_line_info){ .p1 = p3, .p2 = p2, .color = 0x00FF00};
	t_line_info long_line = (t_line_info){ .p1 = p4, .p2 = p5, .color = 0x00FF00};
	drawline(&win_info, &line);
	drawline(&win_info, &line1);
	drawline(&win_info, &line2);	
	drawline(&win_info, &long_line);	

	mlx_string_put(mlx_ptr, win_ptr, 250, 235, 0xFFFFFF, "OPENED A WINDOW\n >LOOK<" );

	// mlx_clear_window(mlx_ptr, win_ptr);
	// mlx_key_hook(win_ptr, deal_key, &win_info);
	mlx_key_hook(win_ptr, deal_key, &player);
	
	mlx_loop(mlx_ptr);
}
