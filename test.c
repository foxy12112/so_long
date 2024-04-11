#include "MLX42/include/MLX42/MLX42.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int	main(void)
{
	void	*mlx;
	t_data	img;

	mlx = mlx_init(1920, 1080, "MLX", 0);
	mlx_loop(mlx);
}
