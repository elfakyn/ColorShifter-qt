#include "hacks.h"

unsigned long GLOBAL_HACKS_DISABLE = 0x2;
unsigned long GLOBAL_HACKS = 0;

void SET_HACK_FLAG(int position)
{
    GLOBAL_HACKS |= 1 << position;
    GLOBAL_HACKS &= ~GLOBAL_HACKS_DISABLE;
}

void CLEAR_HACK_FLAG(int position)
{
    GLOBAL_HACKS &= ~(1 << position);
    GLOBAL_HACKS &= ~GLOBAL_HACKS_DISABLE;
}

void TOGGLE_HACK_FLAG(int position)
{
    GLOBAL_HACKS ^= 1 << position;
    GLOBAL_HACKS &= ~GLOBAL_HACKS_DISABLE;
}

bool HACK_FLAG(int position)
{
    return GLOBAL_HACKS >> position & 1;
}
