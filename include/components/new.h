/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** New component
*/

#ifndef NEW_H_
    #define NEW_H_

    #include <stdbool.h>
    #include <SFML/Graphics.h>
    #include "types/type.h"
    #include "ressources/textures.h"
    #include "components/components.h"

/**
 * @brief New component type
 * @param ressources ressources
 * @param component components
 * @param objects objects
 * @param position position object
 */
void new_component_type(ressources_t ressources,
node_component_t *component, renderer_objects_t objects,
sfVector2f position);

/**
 * @brief New component size
 * @param component components
 * @param size size
 * @param rect rect
 * @param e_size e_size
 */
void new_component_size(node_component_t *component,
sfVector2f size, sfIntRect rect, component_size_t e_size);

/**
 * @brief New component set
 * @param component components
 * @param rect rect
 * @param type type
 * @param style texture sound and font
 */
void new_component_set(node_component_t *component,
sfFloatRect rect, component_type_t type, component_styles style);

/**
 * @brief Set string if components type == text
 * @param component components
 * @param string string to draw
 * @param color color
 * @param size size
 */
void set_component_text(node_component_t *component,
char *string, sfColor color, int size);

#endif /* !NEW_H_ */
