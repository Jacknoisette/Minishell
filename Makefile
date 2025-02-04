# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/15 09:01:08 by tgoudman          #+#    #+#              #
#    Updated: 2025/02/04 14:27:50 by jdhallen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR)
LFLAGS = -L$(LIBFT_DIR) -lft -lreadline
OBJ_DIR = build
NAME = minishell
PARS_DIR = src/parsing
EXEC_DIR = src/exec
SRC_DIR = src/global
LIBFT_DIR = Libft

SRCS =	main.c \
		$(SRC_DIR)/minishell.c  $(SRC_DIR)/signale.c \
		$(SRC_DIR)/init.c $(SRC_DIR)/init_env.c \
		$(SRC_DIR)/cleaning.c $(SRC_DIR)/utils.c \
		$(EXEC_DIR)/builtins.c $(EXEC_DIR)/export.c \
		$(EXEC_DIR)/echo.c $(EXEC_DIR)/execve.c \
		$(EXEC_DIR)/exec.c $(EXEC_DIR)/unset.c \
		$(PARS_DIR)/parsing.c $(PARS_DIR)/parsing_utils.c\
		$(PARS_DIR)/variable.c $(PARS_DIR)/cmd_creation.c\
		$(PARS_DIR)/temp_creation.c $(PARS_DIR)/line_creation.c\
		$(PARS_DIR)/ft_subvar.c $(PARS_DIR)/create_temp.c\
		$(PARS_DIR)/create_cmd.c $(PARS_DIR)/cleaning_parsing.c\

OBJS = $(OBJ_DIR)/main.o \
		$(OBJ_DIR)/minishell.o  $(OBJ_DIR)/signale.o \
		$(OBJ_DIR)/init.o $(OBJ_DIR)/init_env.o \
		$(OBJ_DIR)/cleaning.o $(OBJ_DIR)/utils.o \
		$(OBJ_DIR)/builtins.o $(OBJ_DIR)/export.o \
		$(OBJ_DIR)/echo.o $(OBJ_DIR)/execve.o \
		$(OBJ_DIR)/exec.o $(OBJ_DIR)/unset.o \
		$(OBJ_DIR)/parsing.o $(OBJ_DIR)/parsing_utils.o \
		$(OBJ_DIR)/variable.o $(OBJ_DIR)/cmd_creation.o \
		$(OBJ_DIR)/temp_creation.o $(OBJ_DIR)/line_creation.o \
		$(OBJ_DIR)/ft_subvar.o $(OBJ_DIR)/create_temp.o\
		$(OBJ_DIR)/create_cmd.o $(OBJ_DIR)/cleaning_parsing.o\

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LFLAGS)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(EXEC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(PARS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -f $(OBJS)
	echo "clean ok"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	echo "fclean ok"

re: fclean all

.PHONY: all clean fclean
