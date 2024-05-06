# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/05 16:48:20 by sben-tay          #+#    #+#              #
#    Updated: 2024/05/06 02:56:53 by sben-tay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory

# Définitions de base

NAME = so_long
#NAME_BNS = so_long_bonus
#PRINTF = ./external/DPRINTF
MLX = ./MLX42
CC = cc
CFLAGS = -g -Wall -Wextra -Werror 
#CPPFLAGS = -I./include

# Définitions de chemin

#LIB = src/Mandatory/lib/
#PIPEX = src/Mandatory/so_long/
#SECURITY = src/Mandatory/security/

#LIB_B = src/Bonus/lib/
#PIPEX_B = src/Bonus/so_long/
#SECURITY_B = src/Bonus/security/

BUILD = builder/

# Définitions des fichiers sources et objets

#=================================================__SRC__OF__PROJECT__=============================================================================
SRC = src/Mandatory/main.c
#SRC_BNS = #
# Crée le dossier BUILD si nécessaire
$(shell mkdir -p $(BUILD))

OBJ = $(SRC:%.c=$(BUILD)%.o)
#OBJ_BNS = $(SRC_BNS:%.c=$(BUILD)%.o)
#==================================================================================================================================================



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

	@echo "$(CYAN)Starting external projects $(MAGENTA)PRINTF$(CYAN) and $(MAGENTA)MLX42$(CYAN) compilations..."
	@sleep 2
	@$(MAKE) $(MAKEFLAGS) -C $(MLX)
	@echo "Starting project $(MAGENTA)ZELDA_LTM$(CYAN)..."
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJ) -o $(NAME)

	@sleep 2
	@echo "Done !$(BLANC)"

#=============================================================================================


%.o:%.c   
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(BUILD)%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@


 # Règle pour créer l'exécutable pipex_BNS

bonus: $(NAME_BNS)

$(NAME_BNS): $(OBJ_BNS)
	@echo "$(CYAN)Starting compilation of bonus part..."
	@$(MAKE) $(MAKEFLAGS) -C $(PRINTF)
	@echo "$(MAGENTA)Compiling $(NAME_BNS)..."
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJ_BNS) -L$(PRINTF) -lftprintf -o $(NAME_BNS)
	@echo "$(GREEN)Compilation complete: $(NAME_BNS)$(NC)"



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


.PHONY: all clean fclean re bonus # Pour éviter les conflits avec des fichiers du même nom