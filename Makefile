# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/02/01 14:31:21 by xvoorvaa      #+#    #+#                  #
#    Updated: 2022/06/18 17:58:58 by xander        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
OBJ_DIR			=	OBJ
SRC_DIR			=	SRC
INC_DIR			=	INC
MLX_DIR			=	./lib/MLX42
MLX_H			=	$(MLX_DIR)/include/
MLX_A			=	$(MLX_DIR)/libmlx42.a
LIBFT_DIR		=	./lib/libft
LIBFT_H			=	$(LIBFT_DIR)/INC
LIBFT_A			=	$(LIBFT_DIR)/libft.a

SOURCES			=	$(shell find $(SRC_DIR) -type f -name "*.c")

HEADERS		:= $(MLX_H) INC/so_long.h INC/error.h $(LIBFT_H)
OBJS		:= $(SOURCES:.c=.o)
OBJECTS		:= $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(OBJS))

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

GLFW_LIB := $(shell brew --prefix glfw)

all:	$(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR) -I$(MLX_H) -I$(LIBFT_H)

$(OBJ_DIR):
	@mkdir $@

$(NAME): $(MLX_A) $(LIBFT_A) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) $(MLX_A) -lglfw \
		-L$(GLFW_LIB)/lib $(LIBFT_A)
	@echo $(START)
	@printf $(COMP_MESSAGE) $(SOURCES)
	@echo $(MESSAGE)

$(LIBFT_A): $(LIBFT_H)
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_A): $(MLX_H)
	$(MAKE) -C $(MLX_DIR)

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
	$(MAKE) -C $(MLX_DIR) $@
	$(MAKE) -C $(LIBFT_DIR) $@

re:			fclean all

.PHONY:		all clean fclean re
