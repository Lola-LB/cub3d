SRCS		= main.c				\
			  map_check.c			\

SRCS_BONUS	= main_bonus.c			\
			  map_check_bonus.c		\

OBJS		= $(addprefix srcs/mandatory/, $(SRCS:.c=.o))

OBJS_BONUS	= $(addprefix srcs/bonus/, $(SRCS_BONUS:.c=.o))

MLX_DIR		= mlx_mac

LIBFT_DIR	= libft

SUBDIRS		= $(MLX_DIR)			\
			  $(LIBFT_DIR)			\

INCLUDE		= $(LIBFT_DIR)/libft.h	\
			  $(MLX_DIR)/mlx.h		\

LIBFT		= $(LIBFT_DIR)/libft.a

INC_FLAGS	= -I include/ -I mlx/

CC			= cc

AR			= ar rcs

C_FLAGS		= -g3 -Wall -Wextra -Werror -MMD

MLX_FLAGS	= -Lmlx_mac -lmlx -framework OpenGL -framework AppKit	# Mac
#MLX_FLAGS	= -Lmlx -lmlx -lXext -lX11								# Linux

RM			= rm -f

NAME		= cub3d

%.o: %.c
	$(CC) $(C_FLAGS) $(INC_FLAGS) -c $< -o $@

$(NAME):	$(SUBDIRS) $(OBJS)
	$(CC) $(C_FLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME) 

all:		$(NAME)

$(SUBDIRS):
	$(MAKE) -C $@
		
bonus:		$(SUBDIRS) $(OBJS_BONUS)
	$(CC) $(C_FLAGS) $(OBJS_BONUS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

clean:
	@echo "\033[94mCleaning libft...\033[0m"
	@$(MAKE) -s clean -C libft
	@echo "\033[94mCleaning mlx...\033[0m"
	@$(MAKE) -s clean -C $(MLX_DIR)
	@echo "\033[94mCleaning project...\033[0m"
	@$(RM) $(OBJS) $(OBJS_BONUS) $(OBJS_LIBFT) $(OBJS_PRINTF)
	@echo "\033[92mClean done !\033[0m"

fclean:		clean
	@echo "\033[95mRemoving binaries...\033[0m"
	@$(MAKE) -s fclean -C libft
	@$(RM) $(NAME) $(LIBFT)
	@echo "\033[92mFclean done !\033[0m"

re:		fclean all

.PHONY:		all bonus clean fclean re
