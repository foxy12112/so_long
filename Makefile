NAME = dabloons

OBjS_DIR = objs/
SRCS_DIR = srcs
SRCS =  $(SRCS_DIR)/Placeholder.c	\
		$(SRCS_DIR)/Placeholder1.c	\

MLX_HEADER = ilb/MLX42/include/MLX42
MLX_LIB = lib/MLX42/build

LIBFT_DIR = libs/libft
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_DIR)/$(LIBFT_NAME)

FT_PRINTF_DIR = libs/ft_printf
FT_PRINTF_NAME = ft_printf.a
FT_PRINTF = $(FT_PRINTF_DIR)/$(FT_PRINTF_NAME) 

OBJS = $(SRCS:.c=.0)
OBJECTS_PREFIXED = $(addprefix $(OBjS_DIR))

COMPILER = cc

STRICT_FLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit

COMPILE_FLAGS = $(STRICT_FLAGS) $(MLX_FLAGS)

$(FT_PRINTF):
			make -C $(FT_PRINTF_DIR)
$(LIBFT):
			make -C $(LIBFT_DIR) $@

$(OBjS_DIR)%.o : %.c game.h
				@mkdir -p $(OBjS_DIR)
				@cc $(COMPILE_FLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF)
	$(COMPILER) $(OBJS:%.o=$(OBjS_DIR)%.o) $(LIBFT) $(FT_PRINTF) -I $(MLX_HEADER) -L $(MLX_LIB) -lmlx42 -lglfw -pthread -lm -o $(NAME)


mlx :
	cd lib && git clone https://github.com/codam-coding-college/MLX42.git
	cd lib/MLX42 && cmake -B build && cmake --build build -j4

mlx_clean: rm -rf lib/MLX42

all: $(NAME)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all, mlx, mlx_clean, clean, fclean, re