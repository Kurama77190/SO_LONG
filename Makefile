# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/05 16:48:20 by sben-tay          #+#    #+#              #
#    Updated: 2024/05/17 22:55:35 by sben-tay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory

# Définitions de base

NAME = so_long
#NAME_BNS = so_long_bonus
#PRINTF = ./external/DPRINTF
MLX = ./mlx_linux
CC = cc
CFLAGS = -g -Wall -Wextra -Werror 
CPPFLAGS = -I./include -I/usr/include -I$(MLX) -c
#MLXFLAG = -lmlx -lXext -lX11
# Définitions de chemin

LIB = src/Mandatory/lib/
SOLONG = src/Mandatory/so_long/
SECURITY = src/Mandatory/security/
GARBAGE = $(SECURITY)garbage_collector/

#LIB_B = src/Bonus/lib/
#PIPEX_B = src/Bonus/so_long/
#SECURITY_B = src/Bonus/security/

BUILD = builder/

# Définitions des fichiers sources et objets

#=================================================__SRC__OF__PROJECT__=============================================================================
SRC = src/Mandatory/main.c \
	$(LIB)free_split.c $(LIB)ft_free.c $(LIB)ft_split.c $(LIB)ft_strlen.c $(LIB)ft_only_space.c $(LIB)ft_lstadd_back.c $(LIB)ft_lstnew.c $(LIB)ft_lstclear.c \
	$(LIB)ft_malloc.c \
	$(GARBAGE)ft_calloc.c $(GARBAGE)ft_free_all.c $(GARBAGE)ft_lstadd_back_garbage.c $(GARBAGE)ft_lstnew_garbage.c 
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

test:
	echo src $(SRC)
	echo 
	echo 
	echo obj $(OBJ)
	echo
	echo
	echo dep $(DEP)

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
	@echo "Checking include directory:"
	@ls -la ./include

	@echo "$(CYAN)Starting external projects $(MAGENTA)PRINTF$(CYAN) and $(MAGENTA)MLX42$(CYAN) compilations..."
	@sleep 2
	@$(MAKE) $(MAKEFLAGS) -C $(MLX)
	@echo "Starting project $(MAGENTA)ZELDA_LTM$(CYAN)..."
	$(CC) $(OBJ) -L$(MLX) -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

	@sleep 2
	@echo "Done !$(BLANC)"

#=============================================================================================


%.o:%.c
	echo toto
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