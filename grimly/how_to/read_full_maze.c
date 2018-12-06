#include "structs.h"
#include "header.h"


int    fill_maze(t_maze_data *data,char *buff)
{
    int x;
    int y;
    
    x = 0;
    y = 0;
    while (*buff)
    {
        //check if it's also a valid mark at each point
        //check if R and C line up and are what they should be 
        if (*buff == '\n')
        {
            x = 0;
            y++;
            buff++;
        }
        if (!(create_point(*buff, data)))
            return (0);
        data->maze[y][x] = *(data->new_point);
        x++;
        if (*buff)
            buff++;
        
    }
    return (1);
}

int    malloc_maze(t_maze_data *data)
{
    if (!(data->maze = malloc(sizeof(t_point) * data->row)))
		return (0);
	int n = 0;
	while (n <= data->row)
	{
		if (!(data->maze[n] = malloc(sizeof(t_point) * data->col)))
			return (0) ;
		n++;
    }
    return(1);
}  

int  read_full_maze(t_maze_data *data)
{
    ssize_t size;

    char *buff;
    if ((size = data->row + (data->row * data->col)) <= 0)
        return (0);
    if (!(buff = malloc(sizeof(char) * size + 1)))
        return (0);
    if (read(0, buff, size) < 0)
       return (0);
    buff[size] = '\0';
    if (!(malloc_maze(data)))
        return (0);
    if (!(fill_maze(data, buff)))
        return (0);
    return (1);
    
}