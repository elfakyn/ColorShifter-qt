#include "table.hpp"

#include "exitCodes.h"

#ifdef QT_DEBUG
#include <iostream>
#endif

template <class T> table<T>::table()
{
    n = 0;
}

template <class T> T* table<T>::at(int i)
{
    if (i >= n || i < 0) { // out of bounds
#ifdef QT_DEBUG
        std::cout<<"ERR: table<T>::at index out of bounds: "<<i<<" "<<n<<std::endl;
#endif
        exit(EXIT_TABLE_OUT_OF_BOUNDS);
    }

    return &elements[i];
}

template <class T> T table<T>::getAt(int i) const
{
    if (i >= n || i < 0) { // out of bounds
#ifdef QT_DEBUG
        std::cout<<"ERR: table<T>::getAt index out of bounds"<<std::endl;
#endif
        exit(EXIT_TABLE_OUT_OF_BOUNDS);
    }

    return elements[i];
}

template <class T> void table<T>::setAt(int i, T element)
{
    if (i >= n || i < 0) { // out of bounds
#ifdef QT_DEBUG
        std::cout<<"ERR: table<T>::setAt index out of bounds"<<std::endl;
#endif
        exit(EXIT_TABLE_OUT_OF_BOUNDS);
    }

    elements[i] = element;
}

template <class T> void table<T>::addAt(int i, T element)
{
    if (i > n || i < 0) { // out of bounds, note different condition
#ifdef QT_DEBUG
        std::cout<<"ERR: table<T>::addAt index out of bounds"<<std::endl;
#endif
        exit(EXIT_TABLE_OUT_OF_BOUNDS);
    }

    if (n >= TABLE_MAX_ELEMENTS) { // too many added
#ifdef QT_DEBUG
        std::cout<<"ERR: table<T>::addAt too many items"<<std::endl;
#endif
        exit(EXIT_TABLE_ADDED_TOO_MANY);
    }

    for (int j = n; j > i; j--) {
        elements[j] = elements[j-1];
    }
    n++;

    elements[i] = element;
}

template <class T> void table<T>::removeAt(int i)
{
    if (i >= n || i < 0) { // out of bounds
#ifdef QT_DEBUG
        std::cout<<"ERR: table<T>::removeAt index out of bounds"<<std::endl;
#endif
        exit(EXIT_TABLE_OUT_OF_BOUNDS);
    }

    n--;
    for (int j = i; j < n; j++) {
        elements[j] = elements[j+1];
    }
}

template <class T> void table<T>::moveInternal(int dest, int src)
{
    if (dest >= n || dest < 0 || src >= n || src < 0) { // out of bounds
#ifdef QT_DEBUG
        std::cout<<"ERR: table<T>::moveInternal index out of bounds"<<std::endl;
#endif
        exit(EXIT_TABLE_OUT_OF_BOUNDS);
    }

    T tmp = elements[src];

    if (dest > src) {
        for (int i = src; i < dest; i++) {
            elements[i] = elements[i+1];
        }
    } else {
        for (int i = src; i > dest; i--) {
            elements[i] = elements[i-1];
        }
    }

    elements[dest] = tmp;
}

template <class T> void table<T>::clear()
{
    /*
    for (int i = n-1; i >= 0; i--) {
        removeAt(i);
    }
    */
    n = 0;
}

template <class T> int table<T>::size() const
{
    return n;
}
