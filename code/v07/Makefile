# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 14:52:10 by antoda-s          #+#    #+#              #
#    Updated: 2023/06/17 12:17:19 by antoda-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable File Name(s):
M_NAME = push_swap
B_NAME = checker

#Compiling Variables:
CC 			= cc
# without the debug flag -g
CFLAGS 		= -Wall -Werror -Wextra
# with debug flag -g
# CFLAGS 		= -Wall -Werror -Wextra -g
RM			= rm -rf

# Decide whether the commands will be shwon or not
VERBOSE = TRUE

#Directory paths when compiling and required:
# If Makefile if 1 folder belowproject directory
# PROJDIR 	:= $(realpath $(CURDIR)/..)
# If Makefile if in the same folder as the project directory
PROJDIR 	:= $(realpath $(CURDIR))
DSRC		:= src
DBIN		:= bin
DINC		:= inc
DLIB		:= lib
VPATH 		= $(DSRC)

#functions & variables libraries:
#LIBFT = $(DLIBS)/libft.a
LIBFT 		= libft.a

#Sources
# Multiple directories with *c *.h files
#M_SRCS = $(foreach dir,$(SOURCEDIRS),$(wildcard $(dir)/*.c))
#M_SRCS = $(wildcard $(DSRC)/*.c)
M_SRCS = $(shell find $(DSRC) -name *.c)
#M_SRCS		= 	push_swap.c \
				push_swap_a_rx.c push_swap_a_rrx.c \
				push_swap_a_sx.c push_swap_a_px.c\
				push_swap_u_1.c push_swap_u_2.c
#B_SRCS		:= 	push_swap_bonus.c push_swap_action_1_bonus.c push_swap_action_2_bonus.c \
				push_swap_utils1_bonus.c push_swap_utils2_bonus.c

#Objects
M_OBJS		:= $(subst $(DSRC),$(DBIN),$(M_SRCS:.c=.o))
#M_OBJS		:= $(M_SRCS:%.c=%.o)
#B_OBJS		:= $(B_SRCS:.c=.o)

# Hide or not the calls depending of VERBOSE
ifeq ($(VERBOSE),TRUE)
    HIDE =
else
    HIDE = @
endif

#Colors:
GRN		=	\e[38;5;118m
YLW		=	\e[38;5;226m
RED		=	\e[38;5;196m
BLU		=	\e[38:5:31m
WTH		=	\e[0m
_SUCCESS	=	[$(GRN)DONE$(WTH)]
_INFO		=	[$(YLW)INFO$(WTH)]

all: $(M_NAME)

$(M_NAME): $(LIBFT) $(M_OBJS)
	@echo "$(_INFO)"
	@echo "[$(BLU)Project MANDATORY : compile $(GRN)$(@) $(BLU)file$(WTH)]"
	@$(CC) $(CFLAGS) $(M_OBJS) $(DLIB)/$(LIBFT) -o $@
	@echo "$(_SUCCESS)"
	@echo
#	@echo "$(_INFO)"
#	@echo "[$(RED)Clean Project Libs Objs$(WTH)]"
#	@$(MAKE) clean --no-print-directory -C $(DLIB)
#	@echo "$(_SUCCESS)"
#	@echo

$(LIBFT):
	@echo "$(_INFO)"
	@echo "[$(BLU)Compile Poject Libft$(WTH)]"
	@$(MAKE) --no-print-directory -C $(DLIB)
	@echo "$(_SUCCESS)"
	@echo

$(M_OBJS): $(DBIN)/%.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	@echo "$(_INFO)"
	@echo "[$(RED)Clean Project object files$(WTH)]"
	@$(RM) $(M_OBJS)
	@echo "$(M_OBJS) file removed!!"
	@$(RM) $(B_OBJS)
	@echo "$(B_OBJS) file removed!!"
	@echo "$(_SUCCESS)"
	@echo

fclean: clean
	@echo "$(_INFO)"
	@echo "[$(RED)Project : Cleaning Libft.a$(WTH)]"
	@$(MAKE) fclean --no-print-directory -C $(DLIB)
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

# This is the bonus target invoked with >make bonus
#bonus: $(B_NAME))
#	$(B_NAME): $(LIBFT) $(B_OBJS)
#	@echo "$(_INFO)"
#	@echo "[$(BLU)Project BONUS : compile $(GRN)$(@) file$(WTH)]"
#	@$(CC) $(CFLAGS) $(B_OBJS) $(LIBFT) -o $@
#	@echo "$(_SUCCESS)"
#	@echo
# Show the paths taht are used by this project
show:
	@echo "$(YLW)[ALL PATHS  ]$(WTH) *make show*"
	@echo "*******************************************"
	@echo "$(YLW)[LIB DIR  = ]$(WTH)$(BLU)$(DLIB)$(WTH)"
	@echo "$(YLW)[LIB FILE = ]$(WTH)$(BLU)$(DLIB)$(WTH)/$(LIBFT)"
	@echo "*******************************************"
	@echo "$(YLW)[SRC DIR  = ]$(WTH)$(BLU)$(DSRC)$(WTH)"
	@echo "$(YLW)[SRC FILE = ]$(WTH)$(M_SRCS)"
	@echo "*******************************************"
	@echo "$(YLW)[OBJ DIR  = ]$(WTH)$(BLU)$(DBIN)$(WTH)"
	@echo "$(YLW)[OBJ FILE = ]$(WTH)$(M_OBJS)"
	@echo "*******************************************"
	@echo "$(YLW)[TARGET   = ]$(WTH)"$(PROJDIR)/$(M_NAME)

# Every target that's not a file is identified on .PHONY
.PHONY: all clean fclean re show #bonus

.SILENT: