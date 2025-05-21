#ifndef ARITHMETIC_HPP
#define ARITHMETIC_HPP

/*
 * Computes the greatest commun divisor of two integers a and b
 * Uses : Euclidean algorithm
 */
template <typename T>
T gcd(T a, T b) {
    while (b != 0) {
        T temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

/*
 * Computes the least common multiple of two integers a and b
 * Uses the formula: LCM(a,b) = (a / GCD(a,b)) * b
 */
template <typename T>
T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}

#endif