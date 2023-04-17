/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** mobs
*/

#include "components/mobs.h"
#include "types/type.h"

static bool mob_intersect_player(app_t *app, node_mob_t *mob)
{
    sfFloatRect rect;
    sfFloatRect rectp = sfRectangleShape_getGlobalBounds(
            app->element->player->character->shape);
    bool on_me = false;
    rect = sfRectangleShape_getGlobalBounds(mob->shape);
    on_me = sfFloatRect_intersects(&rect, &rectp, NULL);
    return on_me;
}

static bool finish_animation(node_mob_t *mob)
{
    if (mob->annimation.index > mob->annimation.max){
        mob->annimation.index = 0;
        return true;
    }
    return false;
}
void mobs_attack(node_mob_t *mob,
app_t *app)
{
    if (mob_intersect_player(app, mob)) {
        if (mob->status != 1 && mob->annimation.index != 0){
            mob->status = 1;
        }
        mob->irect.top = 384 + 55;
        mob->annimation.max = 16;
        sfRectangleShape_setOutlineColor(mob->shape, sfRed);
        sfRectangleShape_setOutlineThickness(mob->shape, 2);
    } else {
        if (mob->status !=0 && !finish_animation(mob)){
            sfRectangleShape_setOutlineColor(mob->shape, sfYellow);
            sfRectangleShape_setOutlineThickness(mob->shape, 2);

        } else {
            mob->status = 0;
            mob->irect.top = 55;
            mob->annimation.max = 7;
            sfRectangleShape_setOutlineColor(mob->shape, sfGreen);
            sfRectangleShape_setOutlineThickness(mob->shape, 2);
        }
    }
}