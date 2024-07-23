# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/05 16:48:20 by sben-tay          #+#    #+#              #
#    Updated: 2024/07/23 02:02:38 by sben-tay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory

# Définitions de base

NAME = so_long
#NAME_BNS = so_long_bonus
#PRINTF = ./external/DPRINTF
MLX = ./mlx_linux
CC = cc
CFLAGS = -g3 -Wall -Wextra -Werror 
CPPFLAGS = -I./include -I./external/GNL/include -I/usr/include -I$(MLX) -c
#MLXFLAG = -lmlx -lXext -lX11
# Définitions de chemin

LIB = src/Mandatory/lib/
SOLONG = src/Mandatory/so_long/
SECURITY = src/Mandatory/security/
GARBAGE = $(SECURITY)garbage_collector/
INIT = $(SECURITY)initializing/
PARS = $(SECURITY)parsing/
GNL = external/GNL/src/

#LIB_B = src/Bonus/lib/
#PIPEX_B = src/Bonus/so_long/
#SECURITY_B = src/Bonus/security/

BUILD = builder/

# Définitions des fichiers sources et objets

#=================================================__SRC__OF__PROJECT__=============================================================================
SRC = src/Mandatory/main.c src/Mandatory/draw.c src/Mandatory/update.c src/Mandatory/map.c src/Mandatory/is_walkable.c \
	$(LIB)free_split.c $(LIB)ft_free.c $(LIB)ft_split.c	 $(LIB)ft_only_space.c $(LIB)ft_lstadd_back.c $(LIB)ft_lstnew.c $(LIB)ft_lstclear.c \
	$(LIB)ft_tab_len.c $(LIB)load_animation.c $(LIB)read_map.c $(LIB)put_pixel_to_image.c \
	$(LIB)secure_exit.c $(LIB)update_animation.c $(LIB)putstr_fd.c $(LIB)ft_strlen_gnl.c \
	$(PARS)parsing.c $(PARS)is_double.c $(PARS)is_rectangle.c $(PARS)is_valid_char.c \
	$(INIT)init_game.c $(INIT)init_animations.c $(INIT)init_keys.c $(INIT)init_map.c $(INIT)init_img.c \
	$(GARBAGE)ft_calloc.c $(GARBAGE)ft_free_all.c $(GARBAGE)ft_lstadd_back_garbage.c $(GARBAGE)ft_lstnew_garbage.c $(GARBAGE)ft_free_img.c \
	$(GARBAGE)ft_lstclear_garbage.c \
	$(GNL)get_next_line.c $(GNL)get_next_line_utils.c
SRC_BNS = src/Mandatory/main_test.c
# Crée le dossier BUILD si nécessaire
$(shell mkdir -p $(BUILD))

OBJ = $(SRC:%.c=$(BUILD)%.o)
#OBJ_BNS = $(SRC_BNS:%.c=$(BUILD)%.o)
#==================================================================================================================================================

HEADER = ./include/so_long_h
DEP = $(OBJ:.o=.d)

# Règles des couleurs

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m
CYAN = \033[0;36m
YELLOW = \033[0;33m
MAGENTA = \033[0;35m
BLANC = \033[0;37m

all:	$(NAME)

$(NAME): $(OBJ)


#==================================ASCII_MOD_COMPILATION==================================

	@printf "$(YELLOW)"
	@printf " _                               _          __   $(RED) _____     _     _       $(YELLOW)\n"
	@printf "| |                             | |        / _|  $(RED)|__  /    | |   | |      $(YELLOW)\n"
	@printf "| |     ___  __ _  ___ _ __   __| |   ___ | |_     $(RED)/ /  ___| | __| | __ _ $(YELLOW)\n"
	@printf "| |    / _ \/ _  |/ _ \  _ \ / _  |  / _ \|  _|   $(RED)/ /  / _ \ |/ _  |/ _  |$(YELLOW)\n"
	@printf "| |___|  __/ |_| |  __/ | | | |_| | | |_| | |    $(RED)/ /__|  __/ | |_| | |_| |$(YELLOW)\n"
	@printf "\_____/\___|\__, |\___|_| |_|\__,_|  \___/|_|   $(RED)\_____/\___|_|\__,_|\__,_|$(YELLOW)\n"
	@printf "             __/ |                                     \n"
	@printf "            |___/                                                           ⢀⣴⡖⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	@printf "  ___    _     _       _      _         ___  ___ _     __   __ ⠀⠀⠀⠀⠀⠀⠀⠀⠈⢆⠀⠀⠀⠈⣹⣷⣀⣴⠀⢠⣤⣶⡦⠀⠀⠀⠀ \n"
	@printf " / _ \  | |   |_|     | |    | |        |  \/  || |    \ \ / / ⠢⣀⠀⠀⠀⠀⠀⢄⠀⠈⣆⣠⣼⣿⣿⣿⣿⣿⣦⣼⣏⡀⠀⠀⠀⠀⠀ \n"
	@printf "/ /_\ \ | |    _ _ __ | | __ | |_ ___   |      || |     \ V /  ⠀⠈⠻⣶⣄⡀⠀⣨⣷⡿⠟⠋⠉⠉⠉⠉⠛⠿⣿⣿⣿⣧⣀⠀⠀⠀⠀\n"
	@printf "|  _  | | |   | |  _ \| |/ / | __/ _ \  | |\/| || |     /   \  ⠀⠀⠀⠀⠙⢿⣿⡿⠋⠀⠀⠀⠀⢠⡄⠀⠀⠀⠈⠙⣿⣿⣏⠀⠀⠀⠀⠀⠀\n"
	@printf "| | | | | |___| | | | |   <  | || |_| | | |  | || |____/ /^\ \ ⠀⠀⠀⠀⠀⣼⡟⠀⠀⠀⠀⠀⣠⣿⣿⣆⠀⠀⠀⠀⠈⣿⣿⡁⠀⠀⠀⠀⠀\n"
	@printf "\_| |_/ \_____/_|_| |_|_|\_\  \__\___/  \_|  |_/\_____/\/   \/ ⠀⠀⠀⠒⢺⣿⠁⠀⠀⠀⠀⡰⠿⠿⠿⠿⢆⠀⠀⠀⠀⠸⣿⡿⠃⠀⠀⠀⠀\n"
	@printf "                                                                  ⢠⣾⣿⠀⠀⠀⠀⣴⣷⡀⠀⠀⢀⣼⣦⠀⠀⠀⠀⣿⣿⠆⠀⠀⠀⠀\n"
	@printf "                                                                  ⠀⣹⣿⠀⠀⠀⣼⣿⣿⣷⡀⢀⣾⣿⣿⣧⡀⠀⢠⣿⡧⠤⠀⠀⠀⠀\n"
	@printf "                                                               ⠀⠀⠀⠈⠛⢿⣆⠀⠈⠉⠉⠉⠉⠉⠈⠉⠉⠉⠉⠁⠀⣼⡿⠀⠀⠀⠀⠀⠀\n"
	@printf "                                                                 ⠀⠀⠀⠀⠻⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⣿⣷⣄⠀⠀⠀⠀⠀\n"
	@printf "                                                                ⠀⠀⠀⠀⠀⠚⢻⣿⣿⣦⣄⡀⠀⠀⠀⠀⢀⣠⣶⣿⡋⠀⠈⠙⠻⣦⡀⠀⠀\n"
	@printf "                                                                ⠀⠀⠀⠀⠀⠀⠀⢙⣿⠿⢿⣿⣿⣿⣿⣿⠛⠙⡁⠀⠁⠀⠀⠀⠀⠀⠉⠂⠄\n"
	@printf "                                                                ⠀⠀⠀⠀⠀⠰⣶⡾⠿⠀⠸⠋⠻⣿⣁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	@printf "                                                                ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠿⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"


	@echo "$(CYAN)Starting compilation..."
	@echo "$(GREEN)"

	@echo -n "Compilation progress: ["
	@for i in $$(seq 0.1 50); do \
		sleep 0.02; \
		echo -n "#"; \
	done
	@echo "] 100 %"

	@echo "$(CYAN)Starting $(MAGENTA)MLX$(CYAN) compilations..."
	@sleep 2
	@$(MAKE) $(MAKEFLAGS) -C $(MLX)
	@echo "Starting project $(MAGENTA)ZELDA_LTM$(CYAN)..."
	$(CC) $(OBJ) -L$(MLX) -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

	@sleep 2
	@echo "Done !$(BLANC)"

#=============================================================================================


%.o:%.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(BUILD)%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@ -MMD -MP


 # Règle pour créer l'exécutable so_long_BNS

bonus:

teste:

	cd mlx_linux && ./configure && cd .. && $(CC) $(CFLAGS) $(SRC_BNS) -L$(MLX) -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean: # Règles pour nettoyer les fichiers objets

	@echo "$(RED)Cleaning up...$(NC)"
	@printf "$(CYAN)configure$(NC) [$(GREEN)info$(NC)] : Execute make clean from Projet of so_long\n"
	@rm -rf $(BUILD)
	@$(MAKE) -C $(MLX) clean


fclean: clean # Règles pour nettoyer les fichiers objets et l'exécutable

	@$(MAKE) -C $(MLX) clean
	@rm -f $(NAME)
#	@rm -f $(NAME_BNS)


re: fclean all # Règle pour recompiler

.PHONY: all clean fclean re bonus teste # Pour éviter les conflits avec des fichiers du même nom

-include $(DEP)




# ------------------------------------------------------------------------------------------------------------- >
# 
# 				████████╗███████╗░██████╗████████╗███████╗██╗░░░██╗██████╗░
# 				╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝██╔════╝██║░░░██║██╔══██╗
# 				░░░██║░░░█████╗░░╚█████╗░░░░██║░░░█████╗░░██║░░░██║██████╔╝
# 				░░░██║░░░██╔══╝░░░╚═══██╗░░░██║░░░██╔══╝░░██║░░░██║██╔══██╗
# 				░░░██║░░░███████╗██████╔╝░░░██║░░░███████╗╚██████╔╝██║░░██║
# 				░░░╚═╝░░░╚══════╝╚═════╝░░░░╚═╝░░░╚══════╝░╚═════╝░╚═╝░░╚═╝

# 	COPY PASTE ALL OF THIS SOMEWHERE IN YOUR MAKEFILE

#	COPY THE 'map' FOLDER AT THE ROOT OF YOUR PROJECT

# 	MAKE SURE THE NAME OF THE PROJECT IS: so_long
# 	IF YOUR BONUS ISNT: so_long_bonus, change that below
#

# 	AVAILABLE: (see desccription below)
# 	make m

NAMEE = so_long
NAMEE_BONUS = so_long_bonus

IMG_SPRITE = img/player.xpm
# 	TESTING lots of BAD maps, and others break tests, with valgrind
# 		
# 		replace the first dependency $(NAMEE) with your $(NAME_BONUS) to test bonus
# 			<!>	give 'IMG_SPRITE' the path of one of YOUR sprite file	<!>
m: $(NAMEE)
	@for map in $(BAD_MAPS); do \
	$(call random_shmol_cat, teshting lots of bad miaps:, $$map shouldt run..., $(CLS), ); \
	$(VALGRIND) ./$(word 1, $^) map/map_bad/$$map; \
	echo "\t\033[5m~ Press Enter to continue...\033[0m"; \
	read -p "" key; \
	done
#
	@$(call shmol_cat_color, $(COLOR_5R_0G_5B), $(COLOR_5R_2G_3B), teshing with bad map name!, map_multiplayer.be, $(CLS), );
	-$(VALGRIND) ./$(word 1, $^) map/map_multiplayer.be
	@echo "\t\033[5m~ Press Enter to continue...\033[0m"
	@read -p "" key
	@$(call shmol_cat_color, $(COLOR_5R_0G_5B), $(COLOR_5R_2G_3B), teshing with bad map name!, mapzzzzz.ber, $(CLS), );
	-$(VALGRIND) ./$(word 1, $^) map/mapzzzzz.ber
	@echo "\t\033[5m~ Press Enter to continue...\033[0m"
	@read -p "" key
#
	@$(call random_shmol_cat, teshing too much args, "$(MAP1) $(MAP1)", $(CLS), );
	-$(VALGRIND) ./$(word 1, $^) map/$(MAP1) map/$(MAP1)
	@echo "\t\033[5m~ Press Enter to continue...\033[0m"
	@read -p "" key
#
	@$(call shmol_cat_color, $(COLOR_5R_0G_5B), $(COLOR_5R_2G_3B), teshing with empty file, map_blank.ber, $(CLS), );
	@echo "$(RED)"
	@rm -f ./map/map_blank.ber
	touch ./map/map_blank.ber
	@echo "$(COLOR_5R_0G_5B)"
	-$(VALGRIND) ./$(word 1, $^) map/map_blank.ber
	@echo "\t\033[5m~ Press Enter to continue...\033[0m"
	@read -p "" key
#
	@$(call shmol_cat_color, $(COLOR_5R_4G_0B), $(COLOR_5R_2G_3B), teshing with a sprite file renamed!!!, , $(CLS), );
	@echo "$(RED)"
	mv ./$(IMG_SPRITE) ./player_007.xpm
	@echo "$(COLOR_5R_4G_0B)"
	-$(VALGRIND) ./$(word 1, $^) map/$(MAP1)
	@echo "$(RED)"
	mv ./player_007.xpm ./$(IMG_SPRITE)
	@echo "\t\033[5m~ Press Enter to continue...\033[0m"
	@read -p "" key
#
	@$(call random_shmol_cat, "\'tis big biig biiig correct map", "try n break it.. にゃ?", $(CLS), );
	@echo "\t\033[5m~ Press Enter to continue...\033[0m"
	@read -p "" key
	-$(VALGRIND) ./$(word 1, $^) map/$(MAPG)

# ---------------------------------------------------------------------- >
# 	big map
MAPG = good_grand.ber
# 	medium map
MAP1 = map1.ber

BAD_MAPS = map_bad_not_rect1.ber map_bad_not_rect2.ber \
			map_no_collec.ber map_no_player.ber \
			map_no_exit.ber map_many_exit.ber \
			map_many_player.ber map_bad_wall.ber \
			map_bad_enclosed_e.ber map_bad_enclosed_c.ber \
			map_bad_tile.ber
# ---------------------------------------------------------------------- >
# ------------------------------------------------------------------------------------------------------------- >
# @$(call random_shmol_cat, text 1, text 2, $(CLS), $(RESET));
# $(1)= $(CLEAR); $(2)= text1; $(3)= text2; $(4)= $(RESET)
define random_shmol_cat
	COLOR=$$(printf "\033[38;5;%dm" $$(shuf -i 1-255 -n 1)); \
	COLOR2=$$(printf "\033[38;5;%dm" $$(shuf -i 0-255 -n 1)); \
	echo "$(3)$${COLOR2}\
	\tにゃ~$${COLOR}\t⠀╱|、\n\
	\t\t(˚ˎ。7⠀⠀⠀$${COLOR2}~ $(1) ~$${COLOR}\n\
	\t\t⠀|、˜\\\\\t\t$${COLOR2}~ $(2)$${COLOR}\n\
	\t\t⠀じしˍ)ノ\n$(4)"
endef

CLS = \033[2J\033[H
# - - - - - - - - - - - - - - - - - - - - - - - - - - - -  - -  - VALGRIIND
VALGRIIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s --track-fds=yes
# ------------------------------------------------------------------------------------------------------------- >
