# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    parsing_source.mk                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/27 14:16:56 by jdhallen          #+#    #+#              #
#    Updated: 2025/02/27 14:54:56 by jdhallen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PARS_DIR = src/parsing \
		src/parsing/create_lst \
		src/parsing/parsing_split \
		src/parsing/remake \
		src/parsing/cleaning \
		src/parsing/utils \
		src/parsing/cmd_parsing \
		src/parsing/cmd_parsing/convert \
		src/parsing/cmd_parsing/cmd_creation

SRCS_PARS = parsing.c \
		create_cmd.c create_line.c create_temp.c \
		convert_lst.c ft_subvar.c  variable.c \
		temp_creation.c line_creation.c variable_utils.c \
		parsing_split.c parsing_utils.c \
		line_remake.c line_remake_core.c \
		line_remake_strcmd.c input_remake2.c \
		input_remake.c input_remake2_var.c ft_charjoin.c \
		cleaning_parsing.c cleaning_parsing2.c \
		ft_printf_lst.c \
		cmd_parsing.c \
		list_to_shell_line.c cmd_to_shell_line.c\
		convert_to_shell_line_utils.c  \
		get_cmd_fd_case.c get_cmd_case.c \
		cmd_creation.c cmd_creation_action.c \
		cmd_creation_utils.c cmd_fd_creation.c \
		cmd_fd_creation_utils.c cmd_fd_creation_utils2.c \
		cmd_check.c