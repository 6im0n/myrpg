##
## EPITECH PROJECT, 2023
## B-MUL-200-NAN-2-1-myrpg-thomas.quintin
## File description:
## Makefile
##


_SRC =			main.c \
				\
				app/app.c \
				app/event.c \
				app/rendering.c \
				app/component.c \
				app/component_menu.c \
				\
				ressources/ressources.c \
				ressources/textures.c \
				ressources/sounds.c \
				ressources/fonts.c \
				\
				components/free.c \
				components/misc/render.c \
				components/misc/effect_botton.c \
				components/misc/events_dispatch.c \
				components/misc/events_handlers.c \
				components/misc/events_handlers_keys.c \
				components/misc/events_default.c \
				components/misc/events_animation.c \
				components/misc/player_animation.c \
				components/misc/mobs_animation.c \
				components/misc/state.c \
				components/items/get.c \
				components/items/new.c \
				components/new/set.c \
				components/new/type.c \
				components/new/size.c \
				components/new/text.c \
				components/new/animation.c \
				components/cursor.c \
				\
				components/player/player.c \
				components/player/inventory.c \
				\
				components/mobs/mobs.c \
				\
				components/game/get.c \
				components/game/menu.c \
				components/menu/start/get.c \
				components/menu/start/menu.c \
				components/menu/load/get.c \
				components/menu/load/menu.c \
				components/menu/load/bouton.c \
				components/menu/help/get.c \
				components/menu/help/menu.c \
				components/menu/help/move.c \
				components/menu/help/command.c \
				components/inventory/get.c \
				components/inventory/menu.c \
				components/inventory/object.c \
				components/inventory/object_select.c \
				components/setting/get.c \
				components/setting/menu.c \
				components/setting/sound.c \
				components/setting/bouton.c \
				components/setting/screen.c \
				\
				components/view/manage.c \
				events/help.c \
				events/cursor.c \
				events/setting.c \
				events/animation.c \
				\
				events/setting/open.c \
				events/setting/screen.c \
				events/setting/volume.c \
				events/setting/framerate.c \
				events/setting/hover.c \
				events/menu/start/bouton.c \
				events/menu/help/bouton.c \
				events/menu/help/keypress.c \
				events/inventory/select.c \
				events/inventory/selector.c \
				events/game/player.c \
				\
				types/app/app.c \
				types/app/icon.c \
				types/app/mouse.c \
				types/app/state.c \
				\
				types/list/component/list.c \
				types/list/component/append.c \
				types/list/player/list.c \
				types/list/player/append.c \
				\
				types/node/component/node.c \
				\
				parsing/parsing.c \
				parsing/function.c \
				parsing/animation.c \
				parsing/position.c \
				parsing/utils.c \
				parsing/size.c \
				parsing/type.c \
				parsing/functions.c \
				\
				utils/file.c \
				types/list/player/switch.c \
				types/list/player/remove.c \

SRCDIR = 		src/

SRC =			$(addprefix $(SRCDIR), $(_SRC))
OBJ = 			$(SRC:.c=.o)

INC = 			-I./include -I. -I./lib
LIBS =			./libcommon.a

CFLAGS 	=		-W -Wall -Wextra -Werror -g

MODULES = -l csfml-graphics -l csfml-window -l csfml-audio -l csfml-system -lm

NAME = 			my_rpg

all: 			$(NAME) clean

$(NAME):
				@make -C lib -s
				@gcc -o $(NAME) $(SRC) $(INC) $(LIBS) $(MODULES) $(CFLAGS)
				@$(MAKE) clean -s

clean:
				@rm -f $(OBJ)
				@make -C lib fclean -s

fclean: 		clean
				@rm -f $(NAME)
				@make -C lib fclean -s

re: 			fclean all

color = /bin/echo -e "\x1b[33m $1\x1b[0m"

run: re
	clear
	@$(call color,"🚀:")
	@./$(NAME) $(ARGS)
