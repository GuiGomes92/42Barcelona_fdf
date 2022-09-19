# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbraga-g <gbraga-g@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 20:33:29 by gbraga-g          #+#    #+#              #
#    Updated: 2022/09/13 20:36:05 by gbraga-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= fdf

SRC_DIR		:= src/
OBJ_DIR		:= obj/
CC			:= gcc
CFLAGS		:= -g -O3 -Wall -Werror -Wextra
#FSANITIZE	:= -fsanitize=address -g3
FSANITIZE	:= 
NOFLAGS		:= -g
RM			:= rm -f

INC		 		:= inc/
LIB				:= lib/
MINILIBX_DIR	:= minilibx_macos/
MINILIBX		:= $(MINILIBX_DIR)libmlx.a
MINILIBXCC		:= -I mlx -L $(MINILIBX_DIR) -lmlx
HEADER 			:= -I$(INC) -I$(LIBFT_DIR) -I$(MINILIBX_DIR)
OPENGL			:= -framework OpenGL -framework AppKit

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#Sources

SRC_FILES	=	main hooks

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))
INCS		= 	$(addprefix $(INCLUDE), $(addsuffix .h, $(INC_FILES)))
###

OBJF		=	.cache_exists

all:	makelibs
		@$(MAKE) $(NAME)

makelibs:	
	@$(MAKE) -C $(MINILIBX_DIR)

$(NAME):	$(OBJ)		
			@$(CC) $(CFLAGS) $(FSANITIZE) $(OBJ) $(LIBFT) $(MINILIBXCC) $(OPENGL) -o $(NAME)		
			@echo "👉 $(BLUE)$(CC) $(CFLAGS) $(FSANITIZE) $(OBJ) $(LIBFT) $(MINILIBXCC) $(OPENGL) -o $(NAME)$(DEF_COLOR)"
			@echo "$(GREEN)✨ FDF compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS) | $(OBJF)
			@echo "🍩 $(YELLOW)Compiling: $< $(DEF_COLOR)"
			$(CC) $(CFLAGS) -MMD -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

$(MINILIBX):
	@make -C $(MINILIBX_DIR)
	@echo "$(GREEN)Minilibx compiled!$(DEF_COLOR)"		

clean:
			@make clean -C $(MINILIBX_DIR)
			@echo "$(CYAN)Minilibx object files cleaned.$(DEF_COLOR)"	
			$(RM) -rf $(OBJ_DIR)
			@echo "$(CYAN)Fdf object files cleaned!$(DEF_COLOR)"

fclean:		clean
			$(RM) -f $(NAME)
			@echo "$(CYAN)Fdf executable files cleaned!$(DEF_COLOR)"
			$(RM) -f $(MINILIBX_DIR)libmlx.a
			@echo "$(CYAN)libmlx.a lib cleaned!$(DEF_COLOR)"

re:			fclean 
			@$(MAKE)	
			@echo "$(GREEN)Cleaned and rebuilt everything for Fdf!$(DEF_COLOR)"


.PHONY:		all clean fclean re
