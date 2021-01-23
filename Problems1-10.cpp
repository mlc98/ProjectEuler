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


int largestPrimeFactor (long long lim) {
    int factor, max; // Variables to store the factor we're testing, and the maximum factor found
    max = 1;
    factor = 2;
    while (factor == 2) { //We test out 2, to be able to increment by 2 (making odd numbers) in the next bucle
        if (lim % factor == 0) {
            lim = lim / factor;
        }
        factor++;
    }
    factor = 3;
    while (factor <= lim) {
        if (lim % factor == 0) {
            lim = lim / factor; //we divide by the smallest prime factor
        }
        if (factor > max) {
            max = factor; //is this factor greater than our current max value?
        }
        factor += 2; //test next prime factor
    }

    /*
     * Since we test out small factors firsts, we are sure that our program will discard any multiple
     * of these small prime factors. Thus, we can increment out test case by 2 each iteration, and we
     * will be accepting prime numbers ONLY.
     * We're capable of returning all prime factors by storing them in an array
     * */

    return max;
}

long naturalPower (int base, short exp) { //Returns exponentiation of natural numbers recursively
    if (exp < 0) {
        cerr << "Function only works on natural numbers set" << endl;
        exit(0);
    }
    if (exp == 0) {
        return 1;
    }
    return base * naturalPower(base, exp - 1);
}

short naturalNumberLenght (int a) { //Recursive function to determine a given number's lenght
    if (a == 0) { //Work for both positive and negative numbers
        return 0;
    }
    return 1 + naturalNumberLenght(a / 10);
}

int Reverse (int a) { //Returns a number's digits flipped
    int mirrored, exponent; //Variable to store our final result and an exponent to use naturalPower properly
    mirrored = 0;
    exponent = naturalNumberLenght(a) - 1; //To perform exponentiation in the next step, we reduce this value by 1
    while (a > 0) {
        mirrored += a % 10 * naturalPower(10, exponent);
        a = a / 10;
        exponent--;
        /*
         * Take number's last digit (with modulo) and multiplies it by 10 ^ exponent.
         * That's why we reduced exponent variable value by 1
         * */
    }
    return mirrored;
}

bool isPalindrome (int a) {
    if (a == Reverse(a)) {
        return true;
    }
    return false;
    //It can get any simpler
}

int largestPalindromeProduct () {//Actual exercise
    int max = 0;
    for (int i = 999; i > 500; i--) {
        for (int j = 999; j > 500; j--) {
            if (isPalindrome(i * j)) {
                if (i * j > max) {
                    max = i * j;
                }
            }
        }
    }
    return max;
}