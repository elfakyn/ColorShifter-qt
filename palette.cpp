#include <string>

#include "palette.h"

Palette::Palette()
{
    strcpy(name, "New palette");
    n = 0;
}

void Palette::getName(char* name_)
{
    strcpy(name_, name);
}

void Palette::setName(char* name_)
{
    strcpy(name, name_);
}

unsigned long Palette::getMergedAt(int i)
{
    if (i >= n || i < 0) { // out of bounds
#ifdef QT_DEBUG
        std::cout<<"ERR: Palette::getMergedAt index out of bounds"<<std::endl;
#endif
        exit(EXIT_TABLE_OUT_OF_BOUNDS);
    }

    return (elements[i].w << 24) |
        (elements[i].x << 16) |
        (elements[i].y << 8) |
        elements[i].z;
}
