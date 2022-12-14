//
// Created by loki on 28.09.22.
//

#include <iostream>
#include "ListInArray.h"

template<typename T>
ListInArray<T>::ListInArray() {
    array = new node<T>[START_LENGTH];
    arrayLen = START_LENGTH;
    clear();
}

template<typename T>
void ListInArray<T>::print() {
    for (auto l = begin(); l != end(); l++)
        std::cout << *l << " ";
    std::cout << std::endl;
}

template<typename T>
void ListInArray<T>::printArray() {
    std::cout << "sBegin = " << sBegin << " sEnd = " << sEnd << " fBegin = " << fBegin << std::endl;
    for (unsigned i = 0; i < arrayLen; ++i) {
        std::cout << array[i].data << " ";
    }
    std::cout << std::endl;
    for (unsigned i = 0; i < arrayLen; ++i) {
        std::cout << array[i].nextInd << " ";
    }
    std::cout << std::endl;
    for (unsigned i = 0; i < arrayLen; ++i) {
        std::cout << array[i].prevInd << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

template<>
int ListInArray<int>::getDefaultValue() { return 0; }

template<>
char ListInArray<char>::getDefaultValue() { return ' '; }

template<>
float ListInArray<float>::getDefaultValue() { return 0.0; }

template<typename T>
ListInArray<T>::ListInArray(ListInArray<T> &list) {
    sBegin = list.sBegin;
    sEnd = list.sEnd;
    fBegin = list.fBegin;
    arrayLen = list.arrayLen;
    elementCount = list.elementCount;
    array = new node<T>[arrayLen];
    for (unsigned i = 0; i < list.arrayLen; ++i)
        array[i] = list.array[i];
}

template<typename T>
ListInArray<T>::~ListInArray() {
    delete array;
}

template<typename T>
bool ListInArray<T>::isEmpty() {
    return elementCount == 0;
}

template<typename T>
void ListInArray<T>::clear() {
    elementCount = 0;
    sBegin = -1;
    sEnd = -1;
    fBegin = 0;
    laboriousness = 0;
    for (unsigned i = 0; i < arrayLen; ++i) {
        array[i].nextInd = i + 1;
        array[i].prevInd = i - 1;
        array[i].data = getDefaultValue();
    }
    array[0].prevInd = -1;
    array[arrayLen - 1].nextInd = -1;
}

template<typename T>
unsigned ListInArray<T>::getLength() { return elementCount; }

template<typename T>
int ListInArray<T>::findElement(T elem) {
    int foundedInd = -1;
    unsigned j = 0;
    laboriousness = 0;
    for (auto i = begin(); i != end(); i++, j++) {
        laboriousness++;
        if (i->data == elem) {
            foundedInd = j;
            break;
        }
    }
    return foundedInd;
}

template<typename T>
bool ListInArray<T>::push(T _data) {
    if (fBegin != -1) {
        int tmp = array[fBegin].nextInd;
        int curInd = fBegin;
        array[array[fBegin].nextInd].prevInd = -1;
        if (sBegin != -1) {
            array[sBegin].prevInd = fBegin;
        }

        array[curInd].data = _data;
        array[curInd].nextInd = sBegin;

        if (sEnd == -1) sEnd = curInd;
        array[curInd].prevInd = -1;
        sBegin = curInd;
        fBegin = tmp;
        elementCount++;
        resize();
        return curInd;
    } else {
        return -1;
    }

}


template<typename T>
int ListInArray<T>::push(T _data, unsigned ind) {
    laboriousness = 0;
    if (ind == 0) {
        laboriousness++;
        return push(_data);
    }
    if (fBegin != -1 && ind < elementCount) {
        int tmp = array[fBegin].nextInd;
        int curInd = fBegin;
        array[curInd].data = _data;
        unsigned j = 0;
        for (auto it = begin(); it != end(); it++, j++) {
            laboriousness++;
            if (j == ind) {
                array[curInd].nextInd = it.getInd();
                array[curInd].prevInd = it->prevInd;
                array[it->prevInd].nextInd = curInd;
                it->prevInd = curInd;
                break;
            }
        }
        fBegin = tmp;
        elementCount++;
        resize();
        return ind;
    } else {
        return -1;
    }
}

template<typename T>
void ListInArray<T>::resize() {
    if (elementCount == arrayLen - 1) {
        node<T> *tmpArr = new node<T>[arrayLen * 2];
        for (unsigned i = 0; i < arrayLen; ++i)
            tmpArr[i] = array[i];
        delete[] array;
        array = tmpArr;

        for (unsigned i = arrayLen; i < 2 * arrayLen; ++i) {
            array[i].nextInd = i + 1;
            array[i].prevInd = i - 1;
        }
        array[arrayLen - 1].nextInd = arrayLen;
        array[2 * arrayLen - 1].nextInd = -1;
        arrayLen *= 2;
    }
}

template<typename T>
void ListInArray<T>::changeLinks(MyIterator<T> &i) {
    int nInd = i->nextInd;
    int pInd = i->prevInd;
    int cInd = i.getInd();
    if (pInd != -1)
        array[pInd].nextInd = nInd;
    else
        sBegin = nInd;
    if (nInd != -1)
        array[nInd].prevInd = pInd;

    array[cInd].prevInd = -1;
    array[cInd].nextInd = fBegin;
    fBegin = cInd;
    elementCount--;

}

template<typename T>
bool ListInArray<T>::pop(T _data) {
    for (auto i = begin(); i != end(); i++) {
        if (*i == _data) {
            changeLinks(i);
            return true;
        }
    }
    return false;
}

template<typename T>
bool ListInArray<T>::popInd(unsigned ind) {
    unsigned j = 0;
    laboriousness = 0;
    for (auto i = begin(); i != end(); i++, j++) {
        laboriousness++;
        if (j == ind) {
            changeLinks(i);
            return true;
        }
    }
    return false;
}

template<typename T>
T ListInArray<T>::operator[](unsigned ind) {
    T data = getDefaultValue();
    unsigned j = 0;
    for (auto i = begin(); i != end(); i++, j++) {
        if (j == ind) {
            return *i;
        }
    }
    return data;
}

template<typename T>
bool ListInArray<T>::changeValue(T data, unsigned ind) {
    unsigned j = 0;
    for (auto i = begin(); i != end(); i++, j++) {
        if (j == ind) {
            i->data = data;
            return true;
        }
    }
    return false;
}

template<typename T>

node<T> *ListInArray<T>::getNextElement(node<T> *node) {
    int ind = node->nextInd;
    if (!node || ind == -1)return nullptr;
    return &array[ind];
}

template<typename T>
unsigned ListInArray<T>::getLaboriousness() { return laboriousness; }

template
class ListInArray<int>;

template
class ListInArray<char>;

template
class ListInArray<float>;
