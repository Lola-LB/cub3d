SRCS		= ft_memset.c					\
		  	  ft_bzero.c					\
		  	  ft_memcpy.c					\
		  	  ft_memmove.c					\
		  	  ft_memchr.c					\
		  	  ft_memcmp.c					\
		  	  ft_strlen.c					\
		  	  ft_isalpha.c					\
		  	  ft_isdigit.c					\
		  	  ft_isalnum.c					\
		  	  ft_isascii.c					\
		  	  ft_isprint.c					\
		  	  ft_toupper.c					\
		  	  ft_tolower.c					\
		  	  ft_strchr.c					\
		  	  ft_strrchr.c					\
		  	  ft_strncmp.c					\
		  	  ft_strlcpy.c					\
		  	  ft_strlcat.c					\
		  	  ft_strnstr.c					\
		  	  ft_atoi.c						\
		  	  ft_strdup.c					\
		  	  ft_calloc.c					\
		  	  ft_substr.c					\
		  	  ft_strjoin.c					\
		  	  ft_strtrim.c					\
		  	  ft_split.c					\
		  	  ft_itoa.c						\
		  	  ft_strmapi.c					\
		  	  ft_striteri.c					\
		  	  ft_putchar_fd.c				\
		  	  ft_putstr_fd.c				\
		  	  ft_putendl_fd.c				\
		  	  ft_putnbr_fd.c				\
			  ft_uitoa.c					\
			  ft_strtoupper.c				\
			  ft_strstr.c					\
			  ft_strnew.c					\
			  ft_strncpy.c					\
			  ft_strncat.c					\
			  ft_strmap.c					\
			  ft_strdel.c					\
			  ft_strcpy.c					\
			  ft_strcmp.c					\
			  ft_strclr.c					\
			  ft_strcat.c					\
			  ft_min.c						\
			  ft_memfree.c					\
			  ft_memdel.c					\
			  ft_max.c						\
			  ft_memalloc.c					\
			  ft_memccpy.c					\
			  ft_itoa_ptr.c					\
			  get_next_line.c				\
			  get_next_line_utils.c			\
			  get_next_line_bonus.c			\
			  ft_free.c						\
			  ft_arlen.c 					\
			  ft_realloc.c 					\
			  ft_abs.c 						\
			  ft_lstnew.c					\
		  	  ft_lstadd_front.c				\
		  	  ft_lstsize.c					\
		  	  ft_lstlast.c					\
		  	  ft_lstadd_back.c				\
		  	  ft_lstdelone.c				\
		  	  ft_lstclear.c					\
		  	  ft_lstiter.c					\
		  	  ft_lstmap.c					\
		  	  ft_strdigit.c					\
			  ft_doubleAbs.c 				\

OBJS		= $(SRCS:.c=.o)

HEADER		= -I ../include

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

NAME		= libft.a

AR			= ar rcs

%.o: %.c
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(NAME):	$(OBJS)
	$(AR) $@ $^

all:		$(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
