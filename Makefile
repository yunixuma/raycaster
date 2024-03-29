# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 16:52:37 by ykosaka           #+#    #+#              #
#    Updated: 2023/02/26 14:54:33 by Yoshihiro K      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ********************** Section for Macros (Variables) ********************** #
# Product file
NAME			= cub3D

# Component names
LIBNAME_FT		= libft
LIBNAME_MLX		= libmlx

# Check the platform
OS				= $(shell uname)

# Enumeration of files
SRC				= c3d_main.c \
				  c3d_scene.c c3d_scene_def.c c3d_scene_def_color.c \
				  c3d_map_read.c c3d_map_trim.c c3d_map_chk.c \
				  c3d_lst2map_rect.c c3d_map_encode.c c3d_map_valid.c \
				  c3d_map_clear.c c3d_map2vectors.c c3d_idx2flag.c \
				  c3d_mlx.c c3d_win.c c3d_img.c c3d_print.c c3d_exit.c \
				  c3d_render_background.c c3d_render_visible.c \
				  c3d_render_intersect.c c3d_render_elevation.c \
				  c3d_render_rectangle.c c3d_render_line.c \
				  c3d_render_imgline.c c3d_render_imgpixel.c \
				  c3d_render_hud_init.c c3d_render_hud.c c3d_render_blend.c \
				  c3d_render_vision.c c3d_extend_ray.c c3d_get_hit_wall.c \
				  c3d_get_ray_vec.c c3d_create_gridmap.c c3d_rotate_view.c \
				  c3d_game_init.c c3d_game.c \
				  c3d_game_move.c c3d_game_turn.c \
				  c3d_game_keyhook.c c3d_game_keyhook_fire.c \
				  c3d_game_cursorhook.c c3d_game_clickhook.c \
				  ft_mapseek.c ft_mapsize.c ft_addr.c ft_coord.c \
				  ft_free.c ft_lstclear_seterr.c ft_seterr.c \
				  ft_prompt_clr.c ft_prompt_arg.c \
				  ft_hasflag.c ft_inrange.c ft_stris.c \
				  ft_math.c ft_math_distance.c ft_math_intersect.c \

SRC				+= debug_common.c \
				  debug_c3d.c debug_c3d_f.c debug_c3d_map.c debug_c3d_img.c

# Enumeration of directories
SRCDIR			= ./src
INCDIR			= ./include
LIBDIR			= ./lib
LIBDIR_FT		= $(LIBDIR)/libft
INCDIR_FT		= $(LIBDIR_FT)/include
LIBDIR_MLX		= $(LIBDIR)/minilibx-linux
OBJDIR			= ./obj

# Macros to replace and/or integrate
SRCS			= $(addprefix $(SRCDIR)/, $(SRC))
OBJS			= $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))
DEPS			= $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.d)))
LIB_FT			= $(LIBDIR_FT)/$(LIBNAME_FT).a
LIBS			= $(LIB_FT) -lm
ifeq ($(OS), Darwin)
#	LIB_MLX		= $(LIBNAME_MLX).dylib
#	LIBS		+= $(LIBDIR_MLX)/$(LIB_MLX)
	LIB_MLX		= $(LIBDIR_MLX)/$(LIBNAME_MLX)_Darwin.a
	LIBS		+= $(LIB_MLX)
else
	LIB_MLX		= $(LIBDIR_MLX)/$(LIBNAME_MLX).a
	LIBS		+= $(LIB_MLX)
endif

# Aliases of commands
CC				= cc
RM				= rm

# Command options (flags)
CFLAGS			= -MMD -Wall -Wextra -Werror
DEBUGCFLAGS		= -g -ggdb -fstack-usage -fno-omit-frame-pointer
DEBUGLDFLAGS	= -fsanitize=address
INCLUDES		= -I$(INCDIR) -I$(LIBDIR_MLX) -I$(INCDIR_FT)
ifeq ($(OS), Darwin)
#	LDFLAGS		= -L/usr/lib -L$(LIBDIR_MLX)
	LDFLAGS		= -L/usr/lib -L$(LIBDIR_MLX)/obj
	LIBS		+= -L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit
else
	LDFLAGS		= -L/usr/lib -L$(LIBDIR_MLX)/obj
	LIBS		+= -lXext -lX11
endif
RMFLAGS			= -r

# Redefination when the specific target
ifeq ($(MAKECMDGOALS), debug)
	ifneq ($(OS), Darwin)
		CFLAGS	+= $(DEBUGCFLAGS)
		LDFLAGS	+= $(DEBUGLDFLAGS)
	endif
	DEF		+= -D DEBUG_MODE=1
endif
ifeq ($(RC_MODE), 1)
	DEF		+= -D RC_MODE=1
endif

# ********************* Section for targets and commands ********************* #
# Phonies
.PHONY: all clean fclean re clean_partly debug_lib debug rk yk

# Mandatory targets
default:
	-$(MAKE) debug
all: $(LIBS) $(NAME)
clean:
	-$(MAKE) clean -C $(LIBDIR_FT)
	-$(MAKE) clean -C $(LIBDIR_MLX)
	-$(RM) $(RMFLAGS) $(OBJDIR)
fclean: clean
	-$(MAKE) fclean -C $(LIBDIR_FT)
	-$(MAKE) clean -C $(LIBDIR_MLX)
	-$(RM) $(RMFLAGS) $(NAME)
ifeq ($(OS), Darwin)
	-$(RM) $(LIB_MLX)
endif
re: fclean all

# Additional targets
clean_partly:
	$(MAKE) clean -C $(LIBDIR_FT)
	-$(RM) $(RMFLAGS) $(OBJDIR)
debug_lib: 
	$(MAKE) debug -C $(LIBDIR_FT)
debug: clean_partly debug_lib all
rk: 
	$(MAKE) debug RC_MODE=0
yk: 
	$(MAKE) debug RC_MODE=1

# Recipes
$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) $(INCLUDES) $(OBJS) $(LIBS) -o $(NAME)
$(LIBS):
	$(MAKE) -C $(LIBDIR_FT)
	$(MAKE) -C $(LIBDIR_MLX)
#ifeq ($(OS), Darwin)
#	cp -p $(LIBDIR_MLX)/$(LIB_MLX) ./
#endif
$(OBJDIR):
	@mkdir -p $@
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(DEF) $(INCLUDES) -o $@ -c $<

# Including and ignore .dep files when they are not found
-include $(DEPS)

# ******** ******** ******** ******** **** ******** ******** ******** ******** #
