# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 13:57:55 by agiguair          #+#    #+#              #
#    Updated: 2023/05/11 14:35:39 by agiguair         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minishell
CC				= cc
FLAG			= -Wall -Wextra -Werror -g3
LIBFT_PATH		= ./sources/libft/
LIBFT_FILE		= libft.a
LIBFT_LIB		= $(addprefix $(LIBFT_PATH), $(LIBFT_FILE))
SRC_DIR			= ./sources/
INC_DIR			= ./includes/
SRC				= $(addprefix $(SRC_DIR),$(C_FILE))
OBJ				= $(SRC:.c=.o)
C_FILE			=  minishell.c\
				minishell2.c\
				minishell3.c\
				builtins/builtins.c\
				builtins/env.c\
				builtins/pwd.c\
				builtins/echo.c\
				builtins/cd.c\
				builtins/export.c\
				builtins/export2.c\
				builtins/export3.c\
				builtins/exportsansopt.c\
				builtins/exportsansotp2.c\
				builtins/unset.c\
				builtins/unset2.c\
				builtins/exit.c\
				parsing/lex_parsing.c\
				parsing/parsing.c\
				parsing/utils.c\
				parsing/quote.c\
				parsing/expand.c\
				parsing/expand_2.c\
				parsing/syntax.c\
				parsing/free.c\
				exec/exec.c\
				exec/check_fd.c\
				exec/check_fdin.c\
				exec/check_fdout.c\
				exec/exec2.c\
				exec/exec3.c\
				signals/signals.c\
				heredoc/heredoc.c\
				heredoc/expand_heredoc.c\
				heredoc/expand2_heredoc.c\

.c.o:
	$(CC) $(FLAG) -c $< -o $@

all: $(NAME)

lib:
	@make -C $(LIBFT_PATH)

$(NAME): lib $(OBJ)
	@$(CC) $(FLAG) $(OBJ) $(LIBFT_LIB) -lreadline -o $(NAME)

leak :
	valgrind --suppressions=ignore_readline --trace-children=yes    \
    --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes    \
    ./minishell
bonus: lib $(OBJ_B)
	@$(CC) $(FLAG) $(OBJ_B) $(LIBFT_LIB) -o $(NAME_BONUS)

clean:
	@make clean -C $(LIBFT_PATH)
	@rm -f $(OBJ) $(OBJ_B)

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re
