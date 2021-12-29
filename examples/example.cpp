//
// Created by Tom Danvers on 29/12/2021.
// 2021 TeamSunride.
//

#include "FIFObuffer.h"
#include "iostream"

int main(int args, char **argv) {
    FIFObuffer<int, 3> buffer;
    buffer.put(1);
    buffer.put(2);
    buffer.put(3);
    std::cout << buffer.sum() << "\n";  // outputs 6
}