# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 14:52:10 by antoda-s          #+#    #+#              #
#    Updated: 2023/07/13 14:44:23 by antoda-s         ###   ########.fr        #
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
DSRC_M		:= src/push_swap
DSRC_C		:= src/common
DSRC_B		:= src/checker
DBIN_M		:= bin
DINC		:= src/inc
DLIB		:= lib
# VPATH 		= $(DSRC)

#functions & variables libraries:
#LIBFT = $(DLIBS)/libft.a
LIBFT 		= libft.a
#Sources
M_SRCS 		= $(DSRC_M)/fm_0_start.c \
				$(DSRC_M)/fm_cost_best.c \
				$(DSRC_M)/fm_cost_dest.c \
				$(DSRC_M)/fm_cost_eval.c \
				$(DSRC_M)/fm_cost_get.c \
				$(DSRC_M)/fm_cost_min.c \
				$(DSRC_M)/fm_cost_optimizer.c \
				$(DSRC_M)/fm_cost_raw.c \
				$(DSRC_M)/fm_cost_rr.c \
				$(DSRC_M)/fm_cost_rrr.c \
				$(DSRC_M)/fm_cost_source.c \
				$(DSRC_M)/fm_cost_to_pa.c \
				$(DSRC_M)/fm_cost_to_pb.c \
				$(DSRC_M)/fm_max_int.c \
				$(DSRC_M)/fm_min_int.c \
				$(DSRC_M)/fm_move.c \
				$(DSRC_M)/fm_sort_3.c \
				$(DSRC_M)/fm_sort_machine.c \
				$(DSRC_M)/fm_stack_b_start.c

C_SRCS 		= $(DSRC_C)/fc_action_px.c \
				$(DSRC_C)/fc_action_rr.c \
				$(DSRC_C)/fc_action_rrr.c \
				$(DSRC_C)/fc_action_rrx.c \
				$(DSRC_C)/fc_action_rx.c \
				$(DSRC_C)/fc_action_ss.c \
				$(DSRC_C)/fc_action_sx.c \
				$(DSRC_C)/fc_args_build.c \
				$(DSRC_C)/fc_args_check.c \
				$(DSRC_C)/fc_sort_check.c \
				$(DSRC_C)/fc_stack_init.c \
				$(DSRC_C)/fc_stack_limits.c \
				$(DSRC_C)/fc_utils.c

B_SRCS		= $(DSRC_B)/fb_checker.c \
				# $(DSRC_B)/fb_check_machine.c

#Objects
M_OBJS		:= $(subst $(DSRC_M),$(DBIN_M),$(M_SRCS:.c=.o))
C_OBJS		:= $(subst $(DSRC_C),$(DBIN_M),$(C_SRCS:.c=.o))
B_OBJS		:= $(subst $(DSRC_B),$(DBIN_M),$(B_SRCS:.c=.o))

#Rules:

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
_INFO		=	[$(YLW)INFO$(WTH)]
_SUCCESS	=	[$(GRN)DONE$(WTH)]

#Rules:
# This is the GLOBAL target invoked with >make
all: m b
#$(M_NAME) $(B_NAME)

# This is the MANDATORY target invoked with >make m
m: $(M_NAME)

# This is the BONUS target invoked with >make b
b: $(B_NAME)

$(M_NAME): $(DLIB)/$(LIBFT) $(M_OBJS) $(C_OBJS)
#	@echo "$(_INFO)"
#	@echo "[$(BLU)Project MANDATORY : compile $(GRN)$(@) $(BLU)file$(WTH)]"
	$(CC) $(CFLAGS) $(M_OBJS) $(C_OBJS) $(DLIB)/$(LIBFT) -o $@
#	@echo "$(_SUCCESS)"
#	@echo

$(B_NAME): $(DLIB)/$(LIBFT) $(B_OBJS) $(C_OBJS)
#	@echo "$(_INFO)"
#	@echo "[$(BLU)Project BONUS : compile $(GRN)$(@) $(BLU)file$(WTH)]"
	$(CC) $(CFLAGS) $(B_OBJS) $(C_OBJS) $(DLIB)/$(LIBFT) -o $@
#	@echo "$(_SUCCESS)"
#	@echo


$(DLIB)/$(LIBFT):
	@echo "$(_INFO)"
	@echo "[$(BLU)Compile Libft$(WTH)]"
	@$(MAKE) --no-print-directory -C $(DLIB)
	@echo "$(_SUCCESS)"
	@echo

$(M_OBJS): $(DBIN_M)/%.o: $(DSRC_M)/%.c
#	@echo "$(_INFO)"
#	@echo "[$(BLU)Compile objects Project Mandatory$(WTH)]"
	$(CC) -c $(CFLAGS) $< -o $@
#	@echo "$(_SUCCESS)"

$(C_OBJS): $(DBIN_M)/%.o: $(DSRC_C)/%.c
#	@echo "$(_INFO)"
#	@echo "[$(BLU)Compile objects Project Common$(WTH)]"
	$(CC) -c $(CFLAGS) $< -o $@
#	@echo "$(_SUCCESS)"

$(B_OBJS): $(DBIN_M)/%.o: $(DSRC_B)/%.c
#	@echo "$(_INFO)"
	@echo "[$(BLU)Compile objects Project Bonus$(WTH)]"
	$(CC) -c $(CFLAGS) $< -o $@
#	@echo "$(_SUCCESS)"

clean:
	@echo "$(_INFO)"
	@echo "[$(RED)Project : Cleaning Libft objs$(WTH)]"
	@$(MAKE) clean --no-print-directory -C $(DLIB)
	@echo "$(_SUCCESS)"	@echo "$(_INFO)"
	@echo "[$(RED)Clean Project object files$(WTH)]"
	@$(RM) $(M_OBJS)
	@echo "$(M_OBJS) file removed!!"
	@$(RM) $(C_OBJS)
	@echo "$(C_OBJS) file removed!!"
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
.PHONY: all clean fclean re show m b #bonus

# .SILENT: