//
// Created by Tom Danvers on 27/12/2021.
// 2021 TeamSunride.
//

#ifndef TEAMSUNRIDE_FIFOBUFFER_CPP
#define TEAMSUNRIDE_FIFOBUFFER_CPP

#include "FIFObuffer.h"

template<typename T, int FIFOsize>
FIFObuffer<T, FIFOsize>::FIFObuffer() {
    head = 0;
    tail = 0;
    numElements = 0;
}

template<typename T, int FIFOsize>
bool FIFObuffer<T, FIFOsize>::put(float data) {
    if (numElements == FIFOsize) {
        // buffer is full
        return false;
    }
    // Increment count
    numElements++;

    // Only move the tail if there is more than one element
    if (numElements > 1) {
        tail++;

        // Make sure the tail is within the bounds of the array
        tail %= FIFOsize;
    }

    // Store data into array
    buffer[tail] = data;
    return true;
}

template<typename T, int FIFOsize>
T FIFObuffer<T, FIFOsize>::pop() {
    if (numElements == 0) {  // buffer is empty
        return 0;
    }
    numElements--;

    float data = buffer[head];

    if (numElements >= 1) {
        // Move head up one position
        head++;

        //Make sure head is within the bounds of the array
        head %= FIFOsize;
    }

    return data;
}

template<typename T, int FIFOsize>
int FIFObuffer<T, FIFOsize>::count() const {
    return numElements;
}

template<typename T, int FIFOsize>
bool FIFObuffer<T, FIFOsize>::isFull() const {
    return numElements == FIFOsize;
}

template<typename T, int FIFOsize>
void FIFObuffer<T, FIFOsize>::push(float data) {
    if (isFull()) {
        pop();
    }
    put(data);
}

template<typename T, int FIFOsize>
bool FIFObuffer<T, FIFOsize>::isEmpty() const {
    return numElements == 0;
}

template<typename T, int FIFOsize>
void FIFObuffer<T, FIFOsize>::resetFIFO() {
    head = 0;
    tail = 0;
    numElements = 0;
}

template<typename T, int FIFOsize>
T FIFObuffer<T, FIFOsize>::get(int index) {
    int actual_index = (tail - index) % FIFOsize;
    return buffer[actual_index];
}

template<typename T, int FIFOsize>
T FIFObuffer<T, FIFOsize>::sum() {
    T total = 0;
    int i;
    for (i = 0; i < FIFOsize; i++) {
        total += get(i);
    }
    return total;
}

#endif //TEAMSUNRIDE_FIFOBUFFER_CPP