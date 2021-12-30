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

#ifndef TEAMSUNRIDE_FIFOBUFFER_H
#define TEAMSUNRIDE_FIFOBUFFER_H

/**
 * A simple implementation of a FIFO buffer / queue.
 * @tparam T The data type to be stored within the buffer
 * @tparam FIFOsize The size of the buffer
 */
template <typename T, int FIFOsize>
class FIFObuffer {
private:
    T buffer[FIFOsize];
    int head;
    int tail;
    int numElements;
public:
    FIFObuffer();

    /**
     * Push a new value into the buffer regardless of whether it is full or not. If the buffer is full,
     * the value at the end will be removed.
     * @param data The data to push into the buffer
     */
    void push(float data);

    /**
     * Put a new value into the buffer if is empty.
     * @param data The value to insert into the buffer
     * @return Whether or not the value was inserted into the array (it will not be inserted if
     * the buffer is full)
     */
    bool put(float data);

    /**
     * Remove the next item from the FIFO buffer
     *
     * Before using this, check to see if the buffer is empty using isEmpty()
     *
     * @return The next item from the buffer. Returns 0 if the buffer is empty
     */
    T pop();

    /**
     * @return The amount of elements currently in the buffer
     */
    int count() const;

    bool isFull() const;
    bool isEmpty() const;

    /**
     * Reset the buffer. Empty the array of its elements and set the head/tail/numElements to 0
     */
    void clear();

    /**
     * Get an item from the buffer
     * @param index The index of the item to retrieve, where 0 corresponds to the newest inserted item
     */
    T get(int index);

    /**
     * @return The sum of elements within the buffer
     */
    T sum();
};

// https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file
#include "FIFObuffer.cpp"

#endif //TEAMSUNRIDE_FIFOBUFFER_H
