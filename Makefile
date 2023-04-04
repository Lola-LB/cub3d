SRCS		= main.c				\
			  init.c				\
			  file_parsing.c		\
			  read_data.c			\
			  read_map.c			\
			  validate_map.c		\
			  raycaster.c			\
			  raycaster_draw.c		\
			  vect_operations.c		\
			  events.c				\
			  end.c					\
			  debug.c				\

SRCS_BONUS	= main_bonus.c			\
			  map_check_bonus.c		\

OBJS		= $(addprefix srcs/, $(SRCS:.c=.o))

OBJS_BONUS	= $(addprefix srcs/bonus/, $(SRCS_BONUS:.c=.o))

MLX_DIR		= mlx 			# Linux
# MLX_DIR	= mlx_mac 		# Max

LIBFT_DIR	= libft

SUBDIRS		= $(MLX_DIR)			\
			  $(LIBFT_DIR)			\

INCLUDE		= $(LIBFT_DIR)/libft.h	\
			  $(MLX_DIR)/mlx.h		\

DEP			= $(OBJS:.o=.d)			\
			  $(OBJS_BONUS:.o=.d)

LIBFT		= $(LIBFT_DIR)/libft.a

INC_FLAGS	= -I include/ -I $(MLX_DIR)/ -I $(LIBFT_DIR)/

CC			= gcc

AR			= ar rcs

C_FLAGS		= -g3 -Wall -Wextra -Werror -MMD

# MLX_FLAGS	= -Lmlx_mac -lmlx -framework OpenGL -framework AppKit	# Mac
MLX_FLAGS	= -Lmlx -lmlx -lXext -lX11								# Linux

MATH_FLAG	= -lm

RM			= rm -f

NAME		= cub3d

%.o: %.c
	@$(CC) $(C_FLAGS) $(INC_FLAGS) -c $< -o $@

$(NAME):	subdirectory $(OBJS)
	@echo "\033[90mBuilding cub3d...\033[0m"
	@$(CC) $(C_FLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) $(MATH_FLAG) -o $(NAME)
	@echo "\033[92mDone !\033[0m"

all:		$(NAME)

subdirectory:
	@echo "\033[90mBuilding mlx...\033[0m"
	@$(MAKE) -s -C $(MLX_DIR)
	@echo "\033[90mBuilding libft...\033[0m"
	@$(MAKE) -s -C $(LIBFT_DIR)
		
bonus:		subdirectory $(OBJS_BONUS)
	@$(CC) $(C_FLAGS) $(OBJS_BONUS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

clean:
	@echo "\033[90mCleaning project...\033[0m"
	@$(RM) $(OBJS) $(OBJS_BONUS) $(OBJS_LIBFT) $(OBJS_PRINTF) $(DEP)
	@echo "\033[92mClean done !\033[0m"

clean_mlx:
	@echo "\033[90mCleaning mlx...\033[0m"
	@$(MAKE) -s clean -C $(MLX_DIR)
	@echo "\033[92mClean done !\033[0m"

clean_libft:
	@echo "\033[90mCleaning libft...\033[0m"
	@$(MAKE) -s clean -C libft
	@echo "\033[92mClean done !\033[0m"

fclean:		clean
	@echo "\033[90mRemoving binaries...\033[0m"
	@$(RM) $(NAME)
	@echo "\033[92mFclean done !\033[0m"

fclean_libft:		clean_libft
	@echo "\033[90mRemoving binaries...\033[0m"
	@$(MAKE) -s fclean -C libft
	@echo "\033[92mFclean done !\033[0m"

re:		fclean all

-include : $(DEP)

.PHONY:		all bonus clean fclean re
