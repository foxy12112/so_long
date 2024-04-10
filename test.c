#include "libs/MLX42/include/MLX42/MLX42.h"
#include "libs/libft/libft.h"
#include "libs/ft_printf/ft_printf.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
}
