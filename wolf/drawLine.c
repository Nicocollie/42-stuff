#include <math.h>
#include <stdio.h> //printf
#include "mlx.h"
#include "header.h"

void	swap(int *a1, int *b2) 
{ 
	*a1 = *a1 ^ *b2;
	*b2 = *a1 ^ *b2;
	*a1 = *a1 ^ *b2;
}

void	veritcal_line(t_window_info *info, t_line_info *line)
{
	int y = line->p1.y;
	while (y < line->p2.y)
	{
		mlx_pixel_put(info->mlx, info->window, line->p1.x, y++, line->color);	
	}	
}

void drawline(t_window_info *info, t_line_info *line)
{
	line->rise = line->p2.y - line->p1.y;
	line->run =	line->p2.x - line->p1.x;
	if (!line->run)
	{
		if (line->p2.y < line->p1.y)
			swap(&line->p1.y, &line->p2.y);
		veritcal_line(info, line);
	}
	else
	{
		line->m = (float)(line->rise) / line->run;
		line->adjust = (line->m > 0) ? 1 : -1;
		line->delta = fabs((float)line->rise) * 2;
		line->threshold = fabs((float)line->run);
		line->thresholdInc = fabs((float)line->run) * 2;
		if (line->m <= 1 && line->m >= -1)
		{
			line->y = line->p1.y;
			if (line->p2.x < line->p1.x)
			{
				swap(&line->p2.x, &line->p1.x);
				line->y = line->p2.y;
			}
			int temp = line->p1.x;
			while (temp < line->p2.x)
			{
				mlx_pixel_put(info->mlx, info->window, temp++, line->y, line->color);
				line->offset += line->delta;
				if (line->offset >= line->threshold)
				{
					line->y += line->adjust;
					line->threshold += line->thresholdInc;
				}
			}
		}
		else
		{
			line->x = line->p1.x;
			if (line->p2.y < line->p1.y)
			{
				swap(&line->p1.y, &line->p2.y);
				line->x = line->p2.x;
			}
			int temp = line->p1.y;
			while (temp < line->p2.y)
			{
				mlx_pixel_put(info->mlx, info->window, line->x, temp++, line->color);
				line->offset += line->delta;
				if (line->offset >= line->threshold)
				{
					line->x += line->adjust;
					line->threshold += line->thresholdInc;
				}
			}
		}
	}
	printf("%i - %i\n%i - %i\nslope: %f\n", line->p1.x, line->p1.y, line->p2.x, line->p2.y, line->m);
}
