//
// Created by loki on 28.09.22.
//

#ifndef ASD_1_LISTINARRAY_H
#define ASD_1_LISTINARRAY_H

#include <optional>
#include <iterator>
#include <algorithm>
#include <iterator>
#include <cstddef>
#include <cstdlib>
#include "Node.h"

#define START_LENGTH 5

template<typename T>

class ListInArray {
public:

    template<typename E>
    struct MyIterator {
        using iterator_category = std::bidirectional_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = node<E>;
        using pointer = node<E> *;  // or also value_type*
        using reference = node<E> &;  // or also value_type&

        MyIterator(pointer _ptr, int _ind) {
            ptr = _ptr;
            ind = _ind;
        }

        E &operator*() const { return ptr[ind].data; }

        pointer operator->() { return &ptr[ind]; }

        const MyIterator &operator++() {
            ind = ptr[ind].nextInd;
            return *this;
        }

        const MyIterator &operator--(int) {
            ind = ptr[ind].prevInd;
            return *this;
        }

        const MyIterator operator++(int) {
            ind = ptr[ind].nextInd;
            return *this;
        }

        int getInd() { return ind; }

        friend bool operator==(const MyIterator &a, const MyIterator &b) { return a.ind == b.ind; };

        friend bool operator!=(const MyIterator &a, const MyIterator &b) { return a.ind != b.ind; };
    private:
        int ind;
        pointer ptr;
    };

    T operator[](unsigned ind);

    ListInArray();

    ListInArray(ListInArray &);

    ~ListInArray();

    unsigned getLength();

    void clear();

    bool isEmpty();

    int findElement(T elem);

    bool changeValue(T data, unsigned ind);

    bool push(T _data);

    int push(T _data, unsigned ind);

    bool pop(T _data);

    bool popInd(unsigned ind);

    MyIterator<T> begin() { return MyIterator<T>(array, sBegin); }

    MyIterator<T> end() { return MyIterator<T>(array, -1); }

    unsigned getLaboriousness();

    void print();

    void printArray();

private:
    node<T> *getElementById(unsigned id);

    void changeLinks(MyIterator<T> &i);

    void resize();

    node<T> *getNextElement(node<T> *node);

    T getDefaultValue();

    unsigned laboriousness;
    int sBegin;
    int sEnd;
    int fBegin;
    node<T> *array;
    unsigned arrayLen;
    unsigned elementCount;
};

#endif //ASD_1_LISTINARRAY_H
