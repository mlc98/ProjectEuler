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

/*
Fibonacci numbers are built adding the previous two term in the series, with 0 and 1 as seeds.
F(n) = F(n - 1) + F(n - 2) --> F(2) = F(1) + F(0) = 1 + 0 = 1
F(3) = F(2) + F(1) = 1 + 1 = 2 {3, 5, 8, 13, 21, 34, ...}

Even Fibonacci numbers follow the ecuation EvF(n) = 4 * EvF(n - 1) + EvF(n - 2). Seeds are 0 and 2.
*/


long evenFib (int lim) { //Returns the sum of all even Fibonacci numbers below given limit
    long res, i1, i2;
    i1 = 0;
    i2 = 2;
    while (i2 < lim) {
        res += i2; //res variable stores the partial sum of even numbers
        i2 = 4 * i2 + i1; //Get new Fib number
        i1 = (i2 - i1) / 4; //Get previous i2 state and stores it
    }
    return res;
}