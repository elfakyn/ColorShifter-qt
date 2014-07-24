#pragma once

// C preprocessor hacks
//#define ARR_HACK

// Massive hacks
#define HACK_INHIBIT_COLOR_TABLE_UPDATE 0
#define HACK_INHIBIT_DWM_TABLE_UPDATE 1
#define HACK_INHIBIT_TIME_SLIDER 2
#define HACK_MAIN_BUTTON_ON 3
#define HACK_color_GROUP_ENABLED 4 // WARNING: case sensitive!
#define HACK_settings_GROUP_ENABLED 5 // WARNING: case sensitive!
#define HACK_palette_GROUP_ENABLED 6 // WARNING: case sensitive!
#define HACK_PREVIEW_ENABLED 7
#define HACK_PREVIEW_FIRST_PASS 8
#define HACK_PREVIEW_BUTTON_ON 9
#define HACK_saveLoad_GROUP_ENABLED 10 // WARNING: case sensitive!
#define HACK_plusMinus_GROUP_ENABLED 11 // WARNING: case sensitive!
#define HACK_INHIBIT_COLOR_CELL_CHANGE 12
#define HACK_INHIBIT_DWM_TABLE_UPDATE2 13
#define HACK_INHIBIT_START_WINDOWS_CHECKBOX 14

void SET_HACK_FLAG(int position);
void CLEAR_HACK_FLAG(int position);
void TOGGLE_HACK_FLAG(int position);
bool HACK_FLAG(int position);

// timer speed hacks
#define TSH_LENGTH 9

#define TSH_CRT_IDX 0
#define TSH_MAX_IDX 1 // maximum index between colors
#define TSH_PRV_CLR 2 // previous color, merged
#define TSH_NXT_CLR 3 // next color, merged
#define TSH_MAX_CLR 4
#define TSH_IS_RAND 5
#define TSH_CRT_PAL 6
#define TSH_CRT_CIX 7 // current color index
#define TSH_IS_AHSV 8

#define TSH(x) tsh[TSH_##x##]
