# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 14:52:10 by antoda-s          #+#    #+#              #
#    Updated: 2023/06/11 00:26:27 by antoda-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Binary Names:
M_NAME = push_swap
B_NAME = push_swap_bonus

#Compiling Variables:
CC 			= cc
CFLAGS 		= -Wall -Werror -Wextra -g
RM			= rm -rf

#Directory paths when compiling and required:
DBIN		:= bin
DSRC		:= src
DINCS		:= inc
DLIBS		:= lib
VPATH 		= $(DSRC)
#functions & variables libraries:
LIBFT = $(DLIB)/libft.a

#Sources
M_SRCS		:= 	push_swap.c \
				push_swap_a_rx.c push_swap_a_rrx.c \
				push_swap_a_sx.c push_swap_a_px.c\
				push_swap_u_1.c push_swap_u_2.c
#B_SRCS		:= 	push_swap_bonus.c push_swap_action_1_bonus.c push_swap_action_2_bonus.c \
				push_swap_utils1_bonus.c push_swap_utils2_bonus.c
#Objects
M_OBJS		:= $(M_SRCS:.c=.o)
#B_OBJS		:= $(B_SRCS:.c=.o)

#Colors:
GRN		=	\e[38;5;118m
YLW		=	\e[38;5;226m
RED		=	\e[38;5;196m
BLU		=	\e[38:5:31m
WTH		=	\e[0m
_SUCCESS	=	[$(GRN)DONE$(WTH)]
_INFO		=	[$(YLW)INFO$(WTH)]

#SRCS		:= $(wildcard $(SRC)/*.c)

#COMPILE = $(CC) $(CFLAGS) $(INCLUDES)

all: $(M_NAME)

$(M_NAME): $(LIBFT) $(M_OBJS)
	@echo "$(_INFO)"
	@echo "[$(BLU)Project MANDATORY : compile $(GRN)$(@) $(BLU)file$(WTH)]"
	@$(CC) $(CFLAGS) $(M_OBJS) $(DLIBS)/$(LIBFT) -o $@
	@echo "$(_SUCCESS)"
	@echo

$(LIBFT):
	@echo "$(_INFO)"
	@echo "[$(BLU)Compile Poject Libft$(WTH)]"
	@$(MAKE) --no-print-directory -C $(DLIBS)
	@echo "$(_SUCCESS)"
	@echo

clean:
	@echo "$(_INFO)"
	@echo "[$(RED)Clean Project Libs Objs$(WTH)]"
	@$(MAKE) clean --no-print-directory -C $(DLIBS)
	@echo "$(_SUCCESS)"
	@echo
	@echo "$(_INFO)"
	@echo "[$(RED)Clean Project object files$(WTH)]"
	@$(RM) $(M_OBJS)
	@echo "$(M_OBJS) file removed!!"
#	@$(RM) $(B_OBJS)
#	@echo "$(B_OBJS) file removed!!"
	@echo "$(_SUCCESS)"
	@echo

fclean: clean
	@echo "$(_INFO)"
	@echo "[$(RED)Project : Cleaning Libft.a$(WTH)]"
	@$(MAKE) fclean --no-print-directory -C $(DLIBS)
	@echo "$(_SUCCESS)"
	@echo
	@echo "$(_INFO)"
	@echo "[$(RED)Clean Project executables files$(WTH)]"
	@$(RM) $(M_NAME)
	@echo "$(M_NAME) file removed!!"
	@$(RM) $(B_NAME)
	@echo "$(B_NAME) file removed!!"
	@echo "$(_SUCCESS)"
	@echo

re: fclean all

#bonus: $(B_NAME))

#$(B_NAME): $(LIBFT) $(B_OBJS)
#	@echo "$(_INFO)"
#	@echo "[$(BLU)Project BONUS : compile $(GRN)$(@) file$(WTH)]"
#	@$(CC) $(CFLAGS) $(B_OBJS) $(LIBFT) -o $@
#	@echo "$(_SUCCESS)"
#	@echo

.PHONY: all clean fclean re
#bonus

.SILENT: