NAME	:= so_long

CC = cc
CFLAGS	:= -Wextra -Wall -Werror -g

LIBMLX	:= ./lib/MLX42
LIBFT	:= ./lib/libft

HEADERS	:=	-I ./inc \
			-I $(LIBMLX)/include \
			-I $(LIBFT)

LIBS	:=	$(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm \
			$(LIBFT)/libft.a 

SRC :=	src/main.c \
		src/ft_terminate.c \
		src/map_creation.c \
		src/map_creation_more.c \
		src/position.c \
		src/mlx_manager.c \
		src/hooks.c

B_SRC :=	bonus/main_bonus.c \
			bonus/ft_terminate_bonus.c \
			bonus/map_creation_bonus.c \
			bonus/map_parse_bonus.c \
			bonus/map_validation_bonus.c \
			bonus/position_bonus.c \
			bonus/mlx_manager_bonus.c \
			bonus/hooks_bonus.c

OBJ	= $(patsubst src%, obj%, $(SRC:.c=.o))
B_OBJ	= $(patsubst bonus%, obj%, $(B_SRC:.c=.o))

all: libmlx libft obj $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@make -C lib/libft all

$(NAME): $(OBJ)
	@echo "compiling ${NAME}"
	@$(CC) $(OBJ) $(LIBS) $(HEADERS) -o $(NAME)

bonus: libmlx libft obj ${B_OBJ}
	@$(CC) $(B_OBJ) $(LIBS) $(HEADERS) -o $(NAME) && printf "Compiling ${NAME} with bonus"

obj/%.o: src/%.c
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@ && printf "Compiling: $(notdir $<)\n"

obj/%.o: bonus/%.c
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@ && printf "Compiling: $(notdir $<)\n"

obj:
	@mkdir -p obj

clean:
	@rm -rf obj
	@make -C lib/libft clean
	@rm -rf $(LIBMLX)/build

fclean: clean
	@make -C lib/libft fclean
	@rm -f $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx, libft, obj
