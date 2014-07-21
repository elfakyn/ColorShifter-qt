#pragma once

// C preprocessor hacks
//#define ARR_HACK

// Massive hacks
#define HACK_INHIBIT_COLOR_TABLE_UPDATE 0
#define HACK_INHIBIT_DWM_TABLE_UPDATE 1
#define HACK_INHIBIT_TIME_SLIDER 2

void SET_HACK_FLAG(int position);
void CLEAR_HACK_FLAG(int position);
void TOGGLE_HACK_FLAG(int position);
int HACK_FLAG(int position);
