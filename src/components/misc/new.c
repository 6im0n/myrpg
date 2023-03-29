/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** new
*/

#include "components/components.h"

static void init_rectangle(node_component_t *component, renderer_objects_t objects,
ressources_t ressources)
{
    sfVector2f origin = {
        (component->rendered_rect.width / 2),
        (component->rendered_rect.height / 2),};
    sfVector2f position = {
        (component->rendered_rect.width / 2) + component->rendered_rect.left,
        (component->rendered_rect.height / 2) + component->rendered_rect.top,};
    sfTexture *texture = ressources.textures[component->texture];
    sfVector2f size = {
        sfTexture_getSize(texture).x,
        sfTexture_getSize(texture).y};

    component->object->rectangle = objects.rectangle;
    sfRectangleShape_setOrigin(component->object->rectangle, origin);
    sfRectangleShape_setPosition(component->object->rectangle, position);
    sfRectangleShape_setTexture(component->object->rectangle, texture, sfFalse);
    sfRectangleShape_setSize(component->object->rectangle, size);
}

static void init_circle(node_component_t *component, renderer_objects_t objects,
ressources_t ressources)
{
    sfVector2f origin = {
        (component->rendered_rect.width / 2),
        (component->rendered_rect.height / 2),};
    sfVector2f position = {
        (component->rendered_rect.width / 2) + component->rendered_rect.left,
        (component->rendered_rect.height / 2) + component->rendered_rect.top,};
    sfTexture *texture = ressources.textures[component->texture];
    float size = (sfTexture_getSize(texture).x / 2);

    component->object->circle = objects.circle;
    sfCircleShape_setOrigin(component->object->circle, origin);
    sfCircleShape_setPosition(component->object->circle, position);
    sfCircleShape_setTexture(component->object->circle, texture, sfFalse);
    sfCircleShape_setRadius(component->object->circle, size);
}

static void init_sprite(node_component_t *component, renderer_objects_t objects,
ressources_t ressources)
{
    sfVector2f origin = {
        (component->rendered_rect.width / 2),
        (component->rendered_rect.height / 2),};
    sfVector2f position = {
        (component->rendered_rect.width / 2) + component->rendered_rect.left,
        (component->rendered_rect.height / 2) + component->rendered_rect.top,};
    sfTexture *texture = ressources.textures[component->texture];

    component->object->circle = objects.circle;
    sfSprite_setOrigin(component->object->sprite, origin);
    sfSprite_setPosition(component->object->sprite, position);
    sfSprite_setTexture(component->object->sprite, texture, sfFalse);
}

void new_component_type(app_t *app, ressources_t ressources,
node_component_t *component, renderer_objects_t objects)
{
    switch (component->type) {
        case C_TYPES_RECTANGLE:
            init_rectangle(component, objects, ressources);
            break;
        case C_TYPES_CIRCLE:
            init_circle(component, objects, ressources);
            break;
        case C_TYPES_TEXT:
            component->object->text = objects.text;
            break;
        case C_TYPES_SPRITE:
            init_sprite(component, objects, ressources);
            break;
        default:
            break;
    }
}
