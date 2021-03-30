//
// Created by amate on 21/01/2021.
//

#include "Problems1-10.h"

int multiplesof3and5 (int lim) { //Problem 1 Recursive function to determine if a given number is multiple of 3 or 5
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


long evenFib (int lim) { //Problem 2 Returns the sum of all even Fibonacci numbers below given limit
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


int largestPrimeFactor (long long lim) { //Problem 3
    int factor, max; // Variables to store the factor we're testing, and the greatest factor found
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

int largestPalindromeProduct () {// Problem 4
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
    if (a == 2) {
        return true;
    }
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

long long largestProductSerie () {
    string string1 = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
    vector<short> vector1;
    long long res = 0;
    long long aux;
    int i, j;
    for (i = 0; i < string1.size(); i++) { //Converting a digit string into an integer array
        vector1.push_back(string1.at(i) - '0');
    }
    for (i = 0; i < vector1.size() - 12; i++) {
        aux = 1;
        for (j = i; j <= i + 12; j++) {
            if (vector1.at(j) == 0) {
                i = j;
                break;
            }
            aux *= vector1.at(j);
        }
        if (aux > res) {
            res = aux;
        }
    }
    return res;
}

long specialPythagoreanTriplet () { //a^2 + b^2 == c^2. a + b + c == 1000. Find abc. a < b < c
    long res = 0;
    for (int i = 0; i < 997; i++) {
        for (int j = i + 1; j < 998; j++) {
            for (int k = j + 1; k < 999; k++) {
                if (i + j + k == 1000) {
                    if (i * i + j * j == k * k) {
                        res = i * j * k;
                        break;
                    }
                }
            }
        }
    }
    return res;
}

long long summationOfPrimes () { //Problem 10
    long long res = 0;
    res += 2;
    for (int i = 3; i < 1999999; i += 2) {
        if (isPrime(i)) {
            res += i;
        }
    }
    return res;
}
