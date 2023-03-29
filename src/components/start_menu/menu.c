/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** set
*/

#include <SFML/Graphics.h>
#include "types/types.h"
#include "components/components.h"
#include "components/new.h"
#include "types/list.h"
#include "ressources/textures.h"
#include <stdio.h>

static void bouton_play(app_t *app, ressources_t ressources,
renderer_objects_t objects, list_components_t *mstart_menu)
{
    node_component_t *bottom = malloc(sizeof(node_component_t));
    sfVector2f position = {sfRenderWindow_getSize(app->window).x / 2,
        sfRenderWindow_getSize(app->window).y / 2};
    sfVector2f size = {350, 100};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};

    new_component_set(bottom, rect, C_TYPES_BUTTON, TX_MENU_ALL);
    new_component_type(ressources, bottom, objects, position);
    new_component_size(bottom, size,
        (sfIntRect){.height = 31, .left = 162, .top = 208, .width = 92});
    list_component_append(mstart_menu, bottom);
}

static void menu_board(app_t *app, ressources_t ressources,
renderer_objects_t objects, list_components_t *mstart_menu)
{
    node_component_t *bottom = malloc(sizeof(node_component_t));
    sfVector2f middle = {sfRenderWindow_getSize(app->window).x / 2,
        sfRenderWindow_getSize(app->window).y / 2};
    sfVector2f position = {middle.x, middle.y };
    sfVector2f size = {middle.x * 1.3 , middle.y * 1.3};
    sfFloatRect rect = {.height = size.y, .left = (position.x - size.x),
                        .top = (position.y - size.y), .width = size.x};

    bottom->events = (component_events_t) { NULL };
    new_component_set(bottom, rect, C_TYPES_RECTANGLE, TX_DIALOG_MENU_BGR);
    new_component_type(ressources, bottom, objects, position);
    new_component_size(bottom, size,
        (sfIntRect){.height = 122, .left = 139, .top = 12, .width = 106});
    list_component_append(mstart_menu, bottom);
}

list_components_t *components_start_menu(app_t *app,ressources_t ressources,
renderer_objects_t objects, list_components_t *mstart_menu)
{
    menu_board(app, ressources, objects, mstart_menu);
    bouton_play(app, ressources, objects, mstart_menu);
    return mstart_menu;
}