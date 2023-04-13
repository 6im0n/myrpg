/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** event_game
*/

#include <math.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#include "app/app.h"
#include "components/view.h"
#include "components/player.h"
#include "event/game/global.h"
#include "components/misc/events.h"

bool component_next_to_player(node_component_t *component,
app_t *app)
{
    sfFloatRect rect;
    sfVector2f pos =
        sfRectangleShape_getPosition(app->element->player->character->shape);
    bool on_me = false;
    int radius = component->features.radius;

    if (component->features.radius == 0)
        return false;
    rect = sfRectangleShape_getGlobalBounds(component->object->rectangle);
    rect.top -= radius;
    rect.left -= radius;
    rect.width += radius * 3;
    rect.height += radius * 3;
    on_me = sfFloatRect_contains(&rect, pos.x, pos.y);
    return on_me;
}

void component_near(list_components_t *component,
app_t *app, event_t *event)
{
    (void) event;
    node_component_t *tmp = component->first;
    node_component_t *tmp2 = tmp;

    if (!component)
        return;
    while (tmp != NULL) {
        tmp2 = tmp->next;
        if (tmp->features.radius > 0 && component_next_to_player(tmp, app)) {
            tmp->state = ST_SET_NEAR(tmp, true);
            component_next_to(tmp, event, app);
        } else {
            tmp->state = ST_SET_NEAR(tmp, false);
            component_ondisabled(tmp, event, app);
        }
        tmp = tmp2;
    }
}

static float get_move(app_t *app)
{
    float move = (float)app->element->player->skills.speed * 10.F;
    sfTime time = sfClock_getElapsedTime(app->state->clock);
    float seconds = time.microseconds / 1000000.0;
    sfTime old_time = app->element->player->character->time;
    float seconds_old = old_time.microseconds / 1000000.0;
    app->element->player->character->time = time;
    float spend = seconds - seconds_old;
    printf("time spend %f\n",(spend));
    move *= spend;

    return move;
}

static sfVector2f move_player_diagonaly(float move,
sfVector2f position, app_t *app, bool *array)
{
    key_player_t key_tmp = app->element->player->character->key;

    if (key_tmp.up && key_tmp.right && array[0] && array[2]) {
        position.y -= sin(45) * move;
        position.x += cos(45) * move;
    }
    if (key_tmp.down && array[1] && array[2] && key_tmp.right) {
        position.y += cos(45) * move;
        position.x += cos(45) * move;
    }
    if (key_tmp.up && array[0] && array[3] && key_tmp.left) {
        position.y -= cos(45) * move;
        position.x -= cos(45) * move;
    }
    if (key_tmp.down && array[1] && array[3] && key_tmp.left) {
        position.y += cos(45) * move;
        position.x -= cos(45) * move;
    }
    return position;
}

void move_player(app_t *app)
{
    sfRectangleShape *player_rect = app->element->player->character->shape;
    sfVector2f position = sfRectangleShape_getPosition(player_rect);
    sfFloatRect tmp_rect = {0, 0, 0, 0};
    bool array[4] = {false, false, false, false};
    float move = get_move(app);
    key_player_t key_tmp = app->element->player->character->key;

    collisions(array, position, app->element->player);
    position = move_player_diagonaly(move, position, app, array);
    if (key_tmp.up && array[0] && !key_tmp.right && !key_tmp.left)
        position.y -= move;
    if (key_tmp.down && array[1] && !key_tmp.right && !key_tmp.left)
        position.y += move;
    if (key_tmp.right && array[2] && !key_tmp.up && !key_tmp.down)
        position.x += move;
    if (key_tmp.left && array[3] && !key_tmp.up && !key_tmp.down)
        position.x -= move;
    sfRectangleShape_setPosition(player_rect, position);
    tmp_rect = sfRectangleShape_getGlobalBounds(player_rect);
    app->element->player->character->frect = tmp_rect;
}
