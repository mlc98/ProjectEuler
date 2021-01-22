//
// Created by amate on 21/01/2021.
//

#include "Problems1-10.h"

int multiplesof3and5 (int lim) { //recursive function to determine if a given number is multiple of 3 or 5
    if (lim < 3) { //base case, no need to go below this point
        return 0;
    }
    if (lim % 3 == 0 || lim % 5 == 0) { //determine if the number is multiple of 3 or 5 (avoiding common multiples, like 15)
        return lim + multiplesof3and5(lim - 1);
    }
    return multiplesof3and5(lim - 1); //otherwise
}

long evenFib (int lim) {
    long res, i1, i2;
    i1 = 0;
    i2 = 2;
    while (i2 < lim) {
        res += i2;
        i2 = 4 * i2 + i1;
        i1 = (i2 - i1) / 4;
    }
    return res;
}