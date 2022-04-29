# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/09/15 18:01:23 by xvoorvaa      #+#    #+#                  #
#    Updated: 2022/04/29 12:57:19 by xander        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
OBJ_DIR			=	OBJ
SRC_DIR			=	SRC
INC_DIR			=	INC
MLX_DIR			=	./minilibx
MLX_H			=	$(MLX_DIR)/
MLX_A			=	$(MLX_DIR)/libmlx.dylib
LIBFT_DIR		=	./libft
LIBFT_H			=	$(LIBFT_DIR)/INC
LIBFT_A			=	$(LIBFT_DIR)/libft.a

SOURCES			=	SRC/so_long.c \
					SRC/place_obj.c \
					SRC/check_map.c \
					SRC/map_utils.c \
					SRC/linkedlist.c \
					SRC/utils.c \
					SRC/my_mlx.c \
					SRC/locate_obj.c \
					SRC/movement.c \
					SRC/swap_list.c \
					SRC/get_next_line.c \

HEADERS		:=	$(MLX_H) INC/so_long.h $(LIBFT_H)
OBJS		:=	$(SOURCES:.c=.o)
OBJECTS		:=	$(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(OBJS))

ifdef DEBUG
	CFLAGS += -g3 -fsanitize=address
else
	CFLAGS += -Ofast
endif

GREEN			=	\033[1;32m
BLUE			=	\033[1;36m
RED				=	\033[0;31m
NC				=	\033[0m # No Color

START			= "$(BLUE)---\nStarting...!\n---$(NC)"
MESSAGE			= "$(BLUE)---\nCompiling done! Run ./$(NAME)\n---$(NC)"
COMP_MESSAGE	= "$(GREEN)Building C object... $(NC)%-33.33s\r\n"
REM_MESSAGE		= "$(RED)Removing files...$(NC)"

all:	$(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR) -I$(MLX_H) -I$(LIBFT_H)

$(OBJ_DIR):
	@mkdir $@

$(NAME): $(MLX_A) $(LIBFT_A) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) minilibx/libmlx.dylib $(LIBFT_A)
	@echo $(START)
	@printf $(COMP_MESSAGE) $(SOURCES)
	@echo $(MESSAGE)

$(LIBFT_A): $(LIBFT_H)
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_A): $(MLX_H)
	$(MAKE) -C $(MLX_DIR)
	cp $(MLX_A) .

clean:
	@echo "\n"
	@echo $(OBJECTS)
	@rm -rf $(OBJ_DIR)
	@printf $(REM_MESSAGE)
	@echo "\n"


fclean:	clean
	@rm -f $(NAME)
	@rm -rf $(NAME).dSYM
	@rm -f $(MLX_A)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) $@

re:			fclean all

.PHONY:		all clean fclean re
