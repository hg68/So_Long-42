/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:07:14 by hgill             #+#    #+#             */
/*   Updated: 2023/02/15 15:20:43 by hgill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//this is from the harm-smith tutorial//

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 1000, 1000, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
/*int	main(void)
{
	void *mlx;
	void *img;
	void *mlx_win;
	int	x;
	int	y;

	x = 1920;
	y = 1080;

	mlx = mlx_init();
	img = mlx_xpm_file_to_image(mlx, "github_so_long/wall.xpm", &x, &y);
	mlx_win = mlx_new_window(mlx, 1920, 1080, "So_Long");
	mlx_loop(mlx);
}*/
