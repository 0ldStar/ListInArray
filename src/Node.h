//
// Created by loki on 28.09.22.
//

#ifndef ASD_1_NODE_H
#define ASD_1_NODE_H

template<typename T>

struct node {
    int prevInd;
    int nextInd;
    T data;
     node():prevInd(-1),nextInd(-1){}
     explicit node(T t) : prevInd(-1), nextInd(-1), data(t) {}
};

#endif //ASD_1_NODE_H
