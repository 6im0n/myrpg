/*
** EPITECH PROJECT, 2023
** FT-MyPaint
** File description:
** state
*/

#include "types/type.h"
#include "app/constants.h"
#include <stdlib.h>

state_t *state_new(void)
{
    state_t *state = malloc(sizeof(state_t));
    sfSound *sounds_old = sfSound_create();
    sfSound *sounds_new = sfSound_create();

    if (!state)
        return NULL;
    state->stage = S_START_MENU;
    state->sound = malloc(sizeof(sounds_t));
    state->sound->new = sounds_new;
    state->sound->old = sounds_old;
    state->sound->mute = false;
    state->sound->stage_level = 0;
    state->sound->volume = 50;
    state->transition = false;
    return state;
}

void state_free(state_t *state)
{
    sfSound_destroy(state->sound->old);
    sfSound_destroy(state->sound->new);
    free(state->sound);
    free(state);
}
