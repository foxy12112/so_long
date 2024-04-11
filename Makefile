NAME = dabloons

SRCS_DIR = srcs
USER = $(shell whoami)
OS = $(shell uname)

SRCS =  Placeholder.c	\
		Placeholder1.c	

COMPILER = cc
OBjS_DIR = objs/

STRICT_FLAGS = -Wall -Wextra -Werror
ifeq ($(OS),Linux)
	MLX_FLAGS = MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm
else
	MLX_FLAGS = -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
endif
COMPILE_FLAGS = $(STRICT_FLAGS) $(MLX_FLAGS)

$(FT_PRINTF):
			make -C $(FT_PRINTF_DIR)
$(LIBFT):
			make -C $(LIBFT_DIR)

$(OBjS_DIR)%.o : %.c game.h
			@mkdir -p $(OBjS_DIR)
			@$(COMPILER) $(COMPILE_FLAGS) -c $< -o $@

all: MLX42 $(NAME)

$(NAME): $(OBJS)
	@cd libs && make
	@$(COMPILER) $(CFLAGS) -o $(NAME) $(OBJS) ./libs/lib.a ./MLX42/build/libmlx42.a $(MLXFLAGS)

MLX42:
	@if [ ! -d "MLX42" ]; then git clone https://github.com/codam-coding-college/MLX42.git; fi
	@cd MLX42 && cmake -B build && cmake --build build -j4

clean:
	@rm -rf MLX42
	@cd libs && make fclean
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re