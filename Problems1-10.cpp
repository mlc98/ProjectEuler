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
    int mirrored, exponent; //Variable to store our final result and one for an exponent (required for naturalPower())
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

long lcm (int a , int b) {
    int aux = a;
    while (a % b != 0) {
        a += aux;
    }
    return a;
}

long smallestMultiple (int a) { //Brute-forcing least common multiple
    int res = 1;
    for (int i = a / 2; i <= a; i++) {
        //cout << "i: " << i << "\tres: " << res << endl;
        res = lcm(i, res);
    }
    return res;
}

long sumSquareDifference (int lim) { //My first solution
    long a, b;
    a = 0;
    b = 0;
    for (int i = lim; i > 0; i--) {
        a += naturalPower(i, 2);
        b += i;
    }
    return b * b - a;
}

long sumSquareDifference_2 (int lim) { //Mathematical optimization explained in problem overview
    long a, b;
    a = lim * (lim + 1) / 2;
    b = (2 * lim + 1) * (lim + 1) * lim / 6;
    return naturalPower(a, 2) - b;
}

int squareRoot (int a) {
    int res = 1;
    while ((res + 1) * (res + 1) <= a) {
        res++;
    }
    return res;
}

bool isPrime (long a) {
    if (a % 2 == 0) {
        return false;
    }
    for (int i = 3; i < squareRoot(a) + 1; i += 2) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}

long prime10001 (int lim) {
    int counter = 0;
    int test = 3;
    while (counter != lim) {
        if(isPrime(test)) {
            counter++;
        }
        test += 2;
    }
    return test;
}
