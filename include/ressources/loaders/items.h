/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** quests
*/

#ifndef RESSOURCES_SPEECH_LOADERS_H
    #define RESSOURCES_SPEECH_LOADERS_H

    #include "types/type.h"

static int items_loaders[I_LEN][IS_LEN] = {
    [I_NONE][IS_SPEED] = 0,
    [I_NONE][IS_STRENGHT] = 1,
    [I_NONE][IS_RESISTANCE] = 0,
    [I_SWORD_LEV1][IS_SPEED] = 1,
    [I_SWORD_LEV1][IS_STRENGHT] = 2,
    [I_SWORD_LEV1][IS_RESISTANCE] = -1,
    [I_SWORD_LEV2][IS_SPEED] = 2,
    [I_SWORD_LEV2][IS_STRENGHT] = 3,
    [I_SWORD_LEV2][IS_RESISTANCE] = -1,
    [I_SWORD_LEV3][IS_SPEED] = 3,
    [I_SWORD_LEV3][IS_STRENGHT] = 4,
    [I_SWORD_LEV3][IS_RESISTANCE] = -2,
    [I_SWORD_LEV4][IS_SPEED] = 4,
    [I_SWORD_LEV4][IS_STRENGHT] = 5,
    [I_SWORD_LEV4][IS_RESISTANCE] = -2,
    [I_KNIFE_LEV1][IS_SPEED] = 2,
    [I_KNIFE_LEV1][IS_STRENGHT] = 1,
    [I_KNIFE_LEV1][IS_RESISTANCE] = 0,
    [I_KNIFE_LEV2][IS_SPEED] = 3,
    [I_KNIFE_LEV2][IS_STRENGHT] = 2,
    [I_KNIFE_LEV2][IS_RESISTANCE] = 0,
    [I_KNIFE_LEV3][IS_SPEED] = 4,
    [I_KNIFE_LEV3][IS_STRENGHT] = 5,
    [I_KNIFE_LEV3][IS_RESISTANCE] = 0,
    [I_KNIFE_LEV4][IS_SPEED] = 5,
    [I_KNIFE_LEV4][IS_STRENGHT] = 7,
    [I_KNIFE_LEV4][IS_RESISTANCE] = 0,
    [I_SPEAR_LEV1][IS_SPEED] = 0,
    [I_SPEAR_LEV1][IS_STRENGHT] = 1,
    [I_SPEAR_LEV1][IS_RESISTANCE] = 1,
    [I_SPEAR_LEV2][IS_SPEED] = 0,
    [I_SPEAR_LEV2][IS_STRENGHT] = 4,
    [I_SPEAR_LEV2][IS_RESISTANCE] = 2,
    [I_SPEAR_LEV3][IS_SPEED] = 0,
    [I_SPEAR_LEV3][IS_STRENGHT] = 6,
    [I_SPEAR_LEV3][IS_RESISTANCE] = 4,
    [I_SPEAR_LEV4][IS_SPEED] = 0,
    [I_SPEAR_LEV4][IS_STRENGHT] = 8,
    [I_SPEAR_LEV4][IS_RESISTANCE] = 5,
    [I_AXE_LEV1][IS_SPEED] = 0,
    [I_AXE_LEV1][IS_STRENGHT] = 2,
    [I_AXE_LEV1][IS_RESISTANCE] = 1,
    [I_AXE_LEV2][IS_SPEED] = 0,
    [I_AXE_LEV2][IS_STRENGHT] = 3,
    [I_AXE_LEV2][IS_RESISTANCE] = 2,
    [I_AXE_LEV3][IS_SPEED] = 1,
    [I_AXE_LEV3][IS_STRENGHT] = 5,
    [I_AXE_LEV3][IS_RESISTANCE] = 3,
    [I_AXE_LEV4][IS_SPEED] = 2,
    [I_AXE_LEV4][IS_STRENGHT] = 7,
    [I_AXE_LEV4][IS_RESISTANCE] = 4,
    [I_HAMMER_LEV1][IS_SPEED] = 3,
    [I_HAMMER_LEV1][IS_STRENGHT] = 3,
    [I_HAMMER_LEV1][IS_RESISTANCE] = 0,
    [I_HAMMER_LEV2][IS_SPEED] = 3,
    [I_HAMMER_LEV2][IS_STRENGHT] = 4,
    [I_HAMMER_LEV2][IS_RESISTANCE] = 0,
    [I_HAMMER_LEV3][IS_SPEED] = 3,
    [I_HAMMER_LEV3][IS_STRENGHT] = 5,
    [I_HAMMER_LEV3][IS_RESISTANCE] = 0,
    [I_HAMMER_LEV4][IS_SPEED] = 3,
    [I_HAMMER_LEV4][IS_STRENGHT] = 6,
    [I_HAMMER_LEV4][IS_RESISTANCE] = 0,
    [I_SWORD_PIG][IS_SPEED] = 5,
    [I_SWORD_PIG][IS_STRENGHT] = 5,
    [I_SWORD_PIG][IS_RESISTANCE] = 5,
    [I_HEALT_POTION][IS_SPEED] = 0,
    [I_HEALT_POTION][IS_STRENGHT] = 0,
    [I_HEALT_POTION][IS_RESISTANCE] = 0,
    [I_CHALICE][IS_SPEED] = 0,
    [I_CHALICE][IS_STRENGHT] = 0,
    [I_CHALICE][IS_RESISTANCE] = 0,
};

#endif /* !RESSOURCES_SPEECH_LOADERS_H */
