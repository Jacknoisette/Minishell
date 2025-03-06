# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    source.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/27 14:20:43 by jdhallen          #+#    #+#              #
#    Updated: 2025/02/27 14:54:38 by jdhallen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include make_source/parsing_source.mk
include make_source/exec_source.mk
include make_source/global_source.mk

vpath %.c $(PARS_DIR) $(EXEC_DIR) $(GLOBAL_DIR)