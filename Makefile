# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 11:12:41 by hmunoz-g          #+#    #+#              #
#    Updated: 2024/11/06 16:52:31 by hmunoz-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
DEF_COLOR = \033[0;39m
YELLOW = \033[0;93m
CYAN = \033[0;96m
GREEN = \033[0;92m
BLUE = \033[0;94m
RED = \033[0;91m

NAME = so_long
CC = cc
FLAGS = -Werror -Wall -Wextra -Wunreachable-code -Ofast -g
LIBFTDIR = lib/libft/
PRINTFDIR = lib/libft/ft_printf/
LIBMLX = lib/
SRC_DIR = src/

HEADERS := -I ./include
lib = -L$(LIBMLX) -lmlx42 -ldl -lglfw -pthread -lm
RM = rm -f

SRCS = src/so_long.c \
		src/initialisers/sl_game_initialiser.c \
		src/initialisers/sl_game_ender.c \
    	src/parser/sl_parser.c \
       src/checkers/sl_checker1.c \
       src/checkers/sl_checker2.c \
       src/checkers/sl_checker3.c \
       src/checkers/sl_checker4.c \
	   src/handlers/sl_collector_handler.c \
	   src/handlers/sl_image_handler.c \
	   src/handlers/sl_game_handler.c \
	   src/handlers/sl_render_handler.c \
	   src/handlers/sl_enemy_handler.c \
	   src/handlers/sl_bonus_handler.c

OBJS = $(SRCS:.c=.o)

all: $(LIBFTDIR)libft.a $(PRINTFDIR)ft_printf.a $(NAME)

%.o: %.c Makefile include/so_long.h include/MLX42.h
	$(CC) $(FLAGS) $(HEADERS) -c $< -o ${<:.c=.o}
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"

$(NAME): $(OBJS) $(LIBFTDIR)libft.a $(PRINTFDIR)ft_printf.a
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFTDIR)libft.a $(PRINTFDIR)ft_printf.a $(lib)
	@echo "$(GREEN)$(NAME) compiled!$(DEF_COLOR)"

lib/libft/libft.a:
	@echo "$(CYAN)Building libft.a!$(DEF_COLOR)"
	$(MAKE) -C $(LIBFTDIR)

lib/libft/ft_printf/ft_printf.a:
	@echo "$(CYAN)Building ft_printf.a!$(DEF_COLOR)"
	$(MAKE) bonus -C $(PRINTFDIR)

clean:
	$(MAKE) -C $(LIBFTDIR) clean || true
	$(MAKE) -C $(PRINTFDIR) clean || true
	$(RM) $(OBJS)
	@echo "$(BLUE)All object files cleaned!$(DEF_COLOR)"

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean || true
	$(MAKE) -C $(PRINTFDIR) fclean || true
	$(RM) $(NAME)
	@echo "$(CYAN)All executables cleaned!$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re bonus
