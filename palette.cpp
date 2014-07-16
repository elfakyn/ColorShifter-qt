#include "palette.h"
#include <string>

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

int4 Palette::getColorAt(int i)
{
    if (i >= n || i < 0) { // out of bounds
#ifdef QT_DEBUG
        std::cout<<"ERR: Palette::getColorAt index out of bounds"<<std::endl;
#endif
        exit(EXIT_PALETTE_OUT_OF_BOUNDS);
    }

    return colors[i];
}

unsigned long Palette::getMergedAt(int i)
{
    if (i >= n || i < 0) { // out of bounds
#ifdef QT_DEBUG
        std::cout<<"ERR: Palette::getMergedAt index out of bounds"<<std::endl;
#endif
        exit(EXIT_PALETTE_OUT_OF_BOUNDS);
    }

    return (colors[i].w << 24) |
        (colors[i].x << 16) |
        (colors[i].y << 8) |
        colors[i].z;
}

void Palette::setColorAt(int i, int4 color)
{
    if (i >= n || i < 0) { // out of bounds
#ifdef QT_DEBUG
        std::cout<<"ERR: Palette::setColorAt index out of bounds"<<std::endl;
#endif
        exit(EXIT_PALETTE_OUT_OF_BOUNDS);
    }

    colors[i] = color;
}

void Palette::add(int i, int4 color)
{
    if (i > n || i < 0) { // out of bounds, note different condition
#ifdef QT_DEBUG
        std::cout<<"ERR: Palette::add index out of bounds"<<std::endl;
#endif
        exit(EXIT_PALETTE_OUT_OF_BOUNDS);
    }

    if (n >= PALETTE_MAX_COLORS) { // too many added
#ifdef QT_DEBUG
        std::cout<<"ERR: Palette::add too many items"<<std::endl;
#endif
        exit(EXIT_PALETTE_ADDED_TOO_MANY);
    }

    for (int j = n; j > i; j--) {
        colors[j] = colors[j-1];
    }
    n++;

    colors[i] = color;
}

void Palette::remove(int i)
{
    if (i >= n || i < 0) { // out of bounds
#ifdef QT_DEBUG
        std::cout<<"ERR: Palette::remove index out of bounds"<<std::endl;
#endif
        exit(EXIT_PALETTE_OUT_OF_BOUNDS);
    }

    n--;
    for (int j = i; j < n; j++) {
        colors[j] = colors[j+1];
    }
}

void Palette::moveInternal(int dest, int src)
{
    // TODO: out of bounds check

    int4 tmp = colors[src];

    if (dest > src) {
        for (int i = src; i < dest; i++) {
            colors[i] = colors[i+1];
        }
    } else {
        for (int i = src; i > dest; i--) {
            colors[i] = colors[i-1];
        }
    }

    colors[dest] = tmp;
}

int Palette::size(void)
{
    return n;
}
