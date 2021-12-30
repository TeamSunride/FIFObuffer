/*
 * FIFO Buffer
 * Implementation uses arrays to conserve memory
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 Daniel Eisterhold
 *
 * Modified by Tom Danvers for TeamSunride -
 * added extra methods and converted the class into a template
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

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
void FIFObuffer<T, FIFOsize>::clear() {
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
    for (i = 0; i < numElements; i++) {
        total += get(i);
    }
    return total;
}

#endif //TEAMSUNRIDE_FIFOBUFFER_CPP