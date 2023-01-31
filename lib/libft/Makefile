# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 16:52:37 by ykosaka           #+#    #+#              #
#    Updated: 2023/01/21 21:20:03 by Yoshihiro K      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ********************** Section for Macros (Variables) ********************** #
# Product file
NAME		= libft.a

# Component names
NAME_LIBFT	= libft
NAME_GNL	= gnl

# Enumeration of files
SRC_LIBFT	= ft_isalpha.c ft_isdigit.c ft_isalnum.c \
			  ft_isascii.c ft_isprint.c \
			  ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			  ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
			  ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
			  ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
			  ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
			  ft_strmapi.c ft_striteri.c \
			  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			  ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			  ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
			  ft_lstiter.c ft_lstmap.c
SRC_GNL		= get_next_line.c get_next_line_utils.c

# Enumeration of directories
SRCDIR		= ./src
INCDIR		= ./include
OBJDIR		= ./obj

# Macros to replace and/or integrate
SRCS_LIBFT	= $(addprefix $(SRCDIR)/$(NAME_LIBFT)/, $(SRC_LIBFT))
SRCS_GNL	= $(addprefix $(SRCDIR)/$(NAME_GNL)/, $(SRC_GNL))
SRCS		= $(SRCS_LIBFT) $(SRCS_GNL)
OBJS		= $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))
DEPS		= $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.d)))

# Aliases of commands
CC			= cc
AR			= ar
RM			= rm

# Command options (flags)
CFLAGS		= -MMD -Wall -Wextra -Werror
DEBUGFLAGS	= -g -ggdb -fstack-usage -fno-omit-frame-pointer
INCLUDES	= -I$(INCDIR)
ARFLAGS		= rcs
RMFLAGS		= -r

# Redefination when the specific target
ifeq ($(MAKECMDGOALS), debug)
	ifneq ($(shell uname), Darwin)
		CFLAGS	+= $(DEBUGFLAGS)
	endif
	DEF		= -D DEBUG_MODE=1
endif

# ********************* Section for targets and commands ********************* #
# Phonies
.PHONY: all clean fclean re debug

# Mandatory targets
all: $(NAME)
clean:
	-$(RM) $(RMFLAGS) $(OBJDIR)
fclean: clean
	-$(RM) $(RMFLAGS) $(NAME)
re: fclean $(OBJDIR) all
debug: all

# Recipes
$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
$(OBJDIR):
	@mkdir -p $@
$(OBJDIR)/%.o: $(SRCDIR)/$(NAME_LIBFT)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(DEF) $(INCLUDES) -o $@ -c $<
$(OBJDIR)/%.o: $(SRCDIR)/$(NAME_GNL)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(DEF) $(INCLUDES) -o $@ -c $<

# Including and ignore .dep files when they are not found
-include $(DEPS)

# ******** ******** ******** ******** **** ******** ******** ******** ******** #
