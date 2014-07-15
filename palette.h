#ifndef PALETTE_H
#define PALETTE_H

#define PALETTE_MAX_NAME 50
#define PALETTE_MAX_COLORS 100

#include "exitCodes.h"
#include "colorTools.h"

#ifdef QT_DEBUG
#include <iostream>
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
    unsigned long getMergedAt(int i);
    void setColorAt(int i, int4 color);

    void moveInternal(int dest, int src);
    void add(int i, int4 color);
    void remove(int i);

    int getN(void);
};

#endif
