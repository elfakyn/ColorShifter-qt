#ifndef TABLE_H
#define TABLE_H

#define TABLE_MAX_ELEMENTS 50

template <class T> class table
{
public: // FIXME
    T elements[TABLE_MAX_ELEMENTS];
    int n;

public:
    table();

    T* at(int i);
    T getAt(int i) const;
    void setAt(int i, T element);

    void moveInternal(int dest, int src);
    void addAt(int i, T element);
    void removeAt(int i);

    void clear(void);

    int size(void) const;
};

#endif // TABLE_H
