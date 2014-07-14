#pragma once
#define PALETTE_MAX_NAME 50
#define PALETTE_MAX_COLORS 100

#include "exitCodes.h"
#include "colorTools.h"

// DELETE ME
#ifdef QT_DEBUG
#include <iostream>
#define private public // cutting corners
#endif

class Palette
{
private:
    char name[PALETTE_MAX_NAME];
    int4 colors[PALETTE_MAX_COLORS]; // argb
    int n; // number of colors

public:
    Palette();

    void getName(char* name_);
    void setName(char* name_);

    int4 getColorAt(int i);
    void setColorAt(int i, int4 color);

    void moveInternal(int dest, int src);
    void add(int i, int4 color);
    void remove(int i);

    int getN(void);
};
