# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/21 15:17:46 by jdhallen          #+#    #+#              #
#    Updated: 2025/01/07 15:26:38 by jdhallen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
#CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR) -I$(PRINTF_DIR)
#LFLAGS = -L$(LIBFT_DIR) -L$(PRINTF_DIR) -lft
AR = ar
ARFLAGS = rcs
NAME = libft.a

LIBFT_DIR = ft_libft
PRINTF_DIR = ft_printf
GNL_DIR = get_next_line

executable = test

all: $(NAME)

$(NAME):
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(PRINTF_DIR)
	@$(MAKE) -C $(GNL_DIR)
	@$(AR) $(ARFLAGS) $(NAME) $(LIBFT_DIR)/*.o $(PRINTF_DIR)/*.o  $(GNL_DIR)/*.o
	echo "make ok"

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	@$(MAKE) -C $(GNL_DIR) clean
	echo "clean ok"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@$(MAKE) -C $(GNL_DIR) fclean
	@rm -f $(NAME)
	@rm -f *.out
	@rm -f $(executable)
	echo "fclean ok"

re: fclean all

.PHONY: all clean fclean re
