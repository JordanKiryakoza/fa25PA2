//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        return -1; // placeholder
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        while (pos > 0) {
            int parent = (pos-1)/2;

            if (weightArr[pos] < weightArr[parent]) {
                int temp = weightArr[pos];
                // weightArr[pos] = weightArr[parent];
                // weightArr[parent] = temp;
                // pos = parent;
                swap(weightArr[pos], weightArr[parent]);
            } else {
                return;
            }
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        while (true) {
            int left = (pos*2)+1;
            int right = (pos*2)+2;
            int smallestVal = pos;

            if (left < size && weightArr[left] < weightArr[smallestVal]) {
                smallestVal = left;
            }
            if (right < size && weightArr[right] < weightArr[smallestVal]) {
                smallestVal = right;
            }
            if (smallestVal == pos) {
                return;
            }
            swap(weightArr[smallestVal], weightArr[pos]);
            pos = smallestVal;
        }
    }
};

#endif