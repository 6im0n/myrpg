/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** components
*/

#ifndef COMPONENTS_H_
    #define COMPONENTS_H_
    #include <stdlib.h>
    #include <stdbool.h>
    #include <SFML/Graphics.h>
    #include "types/type.h"
    #include "ressources/textures.h"

typedef struct s_node_components node_component_t;

typedef enum e_component_type {
    C_UNDEFINED,
    C_TYPES_RECTANGLE,
    C_TYPES_BUTTON,
    C_TYPES_CIRCLE,
    C_TYPES_TEXT,
    C_TYPES_SPRITE,
    C_TYPES_LEN
} component_type_t;

typedef void (*component_handler_t)(node_component_t *component,
event_t *event, app_t *app);

typedef struct s_component_events {
    component_handler_t onclick;
    component_handler_t onhover;
    component_handler_t onmove;
    component_handler_t onnonclick;
    component_handler_t onkeypress;
} component_events_t;

typedef struct s_node_components {
    int state;
    component_type_t type;
    renderer_objects_t *object;
    texture_t texture;
    component_events_t events;
    sfFloatRect rendered_rect;
    struct s_node_components *next;
    struct s_node_components *prev;
} node_component_t;

typedef struct s_list_components {
    node_component_t *first;
    node_component_t *last;
    int len;
} list_components_t;

typedef struct s_main_components {
    list_components_t *start_menu;
    list_components_t *game;
} main_components_t;

/**
 * @brief Load component
 * @param app App
 * @param ressources ressources
 * @param objects objects
 * @return main_components_t
 */
main_components_t app_components_load(app_t *app, ressources_t ressources,
renderer_objects_t objects);

/**
 * @brief Free component
 * @param components main components structure
 */
void components_free(main_components_t *components);

/**
 * @brief Init pure component
 * @param size App size
 * @return node_component_t*
 */
node_component_t *component_pure_new(sfVector2u size);

/**
 * @brief Dispatch event
 * @param components
 * @param event
 * @param app
 */
void components_dispatch_event(list_components_t *components,
event_t *event, app_t *app);

//==================================================
// START MENU
//==================================================

/**
 * @brief get components start menu
 * @param app App
 * @param ressources ressources
 * @param objects objects
 * @param mstart_menu list start menu
 * @return main_components_t
 */
list_components_t *components_get_start_menu(app_t *app,
ressources_t ressources, renderer_objects_t objects,
list_components_t *mstart_menu);

/**
 * @brief components start menu
 * @param app App
 * @param ressources ressources
 * @param objects objects
 * @param mstart_menu list start menu
 * @return list_components_t*
 */
list_components_t *components_start_menu(app_t *app,ressources_t ressources,
renderer_objects_t objects, list_components_t *mstart_menu);

//==================================================
// STATE
//==================================================

    #define ST_SET(component, x) (component->state | (1 << x))
    #define ST_UNSET(component, x) (component->state & (~(1 << x)))

    #define ST_DISABLED 0
    #define ST_SET_DISABLED(component, x) (\
    x ? (ST_SET(component, ST_DISABLED)) : (ST_UNSET(component, ST_DISABLED)))
    #define ST_IS_DISABLED(component) (component->state & (1 << ST_DISABLED))

    #define ST_HOVER 1
    #define ST_SET_HOVER(component, x) (\
    x ? (ST_SET(component, ST_HOVER)) : (ST_UNSET(component, ST_HOVER)))
    #define ST_IS_HOVER(component) (component->state & (1 << ST_HOVER))

    #define ST_CLICKED 2
    #define ST_SET_CLICKED(component, x) (\
    x ? (ST_SET(component, ST_CLICKED)) : (ST_UNSET(component, ST_CLICKED)))
    #define ST_IS_CLICKED(component) (component->state & (1 << ST_CLICKED))

    #define ST_PRESSED 3
    #define ST_SET_PRESSED(component, x) (\
    x ? (ST_SET(component, ST_PRESSED)) : (ST_UNSET(component, ST_PRESSED)))
    #define ST_IS_PRESSED(component) (component->state & (1 << ST_PRESSED))

    #define ST_R_CLICKED 4
    #define ST_SET_R_CLICKED(component, x) (\
    x ? (ST_SET(component, ST_R_CLICKED)) : \
(ST_UNSET(component, ST_R_CLICKED)))
    #define R_CLICKED(component) (component->state & (1 << ST_R_CLICKED))

    #define ST_MOVED 5
    #define ST_SET_MOVED(component, x) (\
    x ? (ST_SET(component, ST_MOVED)) : (ST_UNSET(component, ST_MOVED)))
    #define ST_IS_MOVED(component) (component->state & (1 << ST_MOVED))

#endif /* !COMPONENTS_H_ */