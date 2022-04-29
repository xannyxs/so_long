# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/09/15 18:01:23 by xvoorvaa      #+#    #+#                  #
#    Updated: 2022/02/01 17:26:47 by xvoorvaa      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long
CFLAGS			=	-I minilibx -Wall -Wextra -Werror
OBJS			=	$(SRCS:.c=.o)
SRCS			=	so_long.c \
					SRC/place_obj.c \
					SRC/check_map.c \
					SRC/map_utils.c \
					SRC/linkedlist.c \
					SRC/utils.c \
					SRC/my_mlx.c \
					SRC/locate_obj.c \
					SRC/movement.c \
					SRC/swap_list.c \
					SRC/libft/ft_bzero.c \
					SRC/libft/ft_split.c \
					SRC/libft/ft_calloc.c \
					SRC/libft/ft_strlen.c \
					SRC/libft/ft_substr.c \
					SRC/libft/ft_strcmp.c \
					SRC/libft/ft_putnbr_fd.c \
					SRC/get_next_line/get_next_line.c \
					SRC/get_next_line/get_next_line_utils.c
ifdef LEAKS
	CFLAGS += -g3 -fsanitize=address
endif

GREEN			=	\033[1;32m
BLUE			=	\033[1;36m
RED				=	\033[0;31m
NC				=	\033[0m # No Color

START			= "$(BLUE)---\nStarting...!\n---$(NC)"
MESSAGE			= "$(BLUE)---\nCompiling done! Run ./$(NAME)\n---$(NC)"
COMP_MESSAGE	= "$(GREEN)Building C object... $(NC)%-33.33s\r\n"
REM_MESSAGE		= "$(RED)Removing files...$(NC)"

all:		$(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@clear
	$(MAKE) -C minilibx
	cp minilibx/libmlx.dylib .
	@echo $(START)
	@gcc $(CFLAGS) $(OBJS) libmlx.dylib -o $(NAME)
	@printf $(COMP_MESSAGE) $(SRCS)
	@echo $(MESSAGE)

clean:
	@echo "\n"
	@rm -f $(OBJS)
	@printf $(REM_MESSAGE)
	@echo "\n"


fclean:		clean
	@$(MAKE) clean -C minilibx
	@rm -f libmlx.dylib
	@rm -f $(NAME)
	@rm -rf $(NAME).dSYM

re:			fclean all

.PHONY:		all leaks clean fclean re
