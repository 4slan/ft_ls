# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/03 12:02:20 by amalsago          #+#    #+#              #
#    Updated: 2019/07/04 04:35:53 by amalsago         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# General

NAME		= ft_ls
LIBFTLS		= ft_ls.a
LIBNAME		= libft.a

# **************************************************************************** #
# GNU Compiler Collection

GCC			= /usr/bin/clang
WOPT		= -Wall -Wextra -Werror
OOPT		= -O2
IOPT		= -I $(INCDIR)

# **************************************************************************** #
# System commands

AR			= /usr/bin/ar -rc
MAKE		= /usr/bin/make -C
RANLIB		= /usr/bin/ranlib
NORMINETTE	= /usr/bin/norminette
MKDIR		= /bin/mkdir -p
RM			= /bin/rm -rf

# **************************************************************************** #
# Directories of source and object files

LIBDIR		= ./libft
SRCDIR		= ./sources
OBJDIR		= ./objects
INCDIR		= ./includes

# **************************************************************************** #
# List of source files

SRCNAME		= main.c	\
			  determine_max_width.c \
			  display_mode.c\
			  display_nlink.c\
			  display_ownername.c\
			  display_groupname.c\
			  display_size.c\
			  display_long.c\
			  display_mtim.c\
			  display_filename.c\
			  get_pwstruct.c\
			  get_grstruct.c\
			  get_mtime.c\
			  ft_inspect_entry.c\
			  ft_list_dir.c\
			  ft_ls.c\
			  ft_pathjoin.c\
			  ft_type.c\
			  get_permissions.c\
			  initialize_directory.c\
			  main.c\
			  modecat.c\
			  parse_entry.c\
			  parse_options.c\
			  usage.c\

# **************************************************************************** #
# Automatic variables where are listed the names of sources and objects files

SRC			= $(addprefix $(SRCDIR)/, $(SRCNAME))
OBJ			= $(addprefix $(OBJDIR)/, $(SRCNAME:.c=.o))
LFT			= $(addprefix $(LIBDIR)/, $(LIBNAME))
LFTLS		= $(addprefix $(PWD)/, $(LIBFTLS))
LFTOBJ		= $(LIBDIR)/objects/*/*.o

# **************************************************************************** #
# Extra

CR			= "\r"$(CLEAR)
CLEAR       = "\\033[0K"
EOC			= "\033[0;0m"
RED			= "\033[0;31m"
GREEN		= "\033[0;32m"
BASENAME	= `basename $(PWD)`

# **************************************************************************** #
# Rules

all: $(NAME) $(LFT)

$(NAME): $(LFT) $(OBJ)
	@$(AR) $(LIBFTLS) $(OBJ) $(LFTOBJ)
	@$(RANLIB) $(LIBFTLS)
	@$(GCC) $(LFTLS) $(LFT) -o $(NAME)
	@printf $(CR)$(GREEN)"✓ $(NAME) is created\n"$(EOC)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	-@$(MKDIR) $(OBJDIR)
	@$(GCC) $(WOPT) $(OOPT) $(IOPT) -c $< -o $@
	@printf $(CR)"[ $(BASENAME)/%s ]"$(CLEAR) $@

$(LFT):
	@$(MAKE) $(LIBDIR)

clean:
	@$(RM) $(OBJ) $(OBJDIR)
	@$(MAKE) $(LIBDIR) clean

fclean: clean
	@$(RM) $(NAME) $(LIBFTLS)
	@printf $(CR)$(RED)"✗ \"$(NAME)\" and \"$(LIBFTLS)\" are deleted\n"$(EOC)
	@$(MAKE) $(LIBDIR) fclean

re: fclean all

norm:
	$(NORMINETTE) $(SRCDIR) $(INCDIR) $(LIBDIR)/sources

.PHONY: all clean fclean re norm
