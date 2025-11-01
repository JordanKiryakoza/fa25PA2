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
        if (size >= 64) {
            cout << "Heap is Full";
            return;
        }
        // TODO: insert index at end of heap, restore order using upheap()
        weightArr[size] = idx;
        upheap(size,weightArr);
        size++;
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        if (size == 0) {
            cout << "Heap Is Empty!";
            return 0;
        }
        int smallestVal = weightArr[0];
        weightArr[0] = weightArr[size - 1];
        size--;
        downheap(0, weightArr);
        return smallestVal; // placeholder
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        while (pos > 0) {
            int parent = (pos-1)/2;

            if (weightArr[pos] >= weightArr[parent]) {
                break;
            }
            swap(weightArr[pos], weightArr[parent]);
            pos = parent;
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        while (true) {
            int left = (pos*2)+1;
            int right = (pos*2)+2;
            int smallestVal = left;

            if (right < size && weightArr[right] < weightArr[left]) {
                smallestVal = right;
            }
            if (weightArr[pos] <= weightArr[smallestVal]) {
                break;
            }
            swap(weightArr[pos], weightArr[smallestVal]);
            pos = smallestVal;
        }
    }
};

#endif