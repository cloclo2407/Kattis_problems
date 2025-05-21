#ifndef MODULAR_ARITHMETIC_HPP
#define MODULAR_ARITHMETIC_HPP

#include"arithmetic.hpp"

/* 
* Function to compute the modular inverse of a using Euclidean Algorithm
* O(log mod)
*/
template <typename T>
T mod_inverse(T a, T mod) {
    T t = 0;
    T new_t = 1;
    T r = mod;
    T new_r = a;

    if (a == 0) return 0; // Inverse doesn't exist

    while (new_r != 0) {
        T quotient = r / new_r;

        T temp_t = t;
        t = new_t;
        new_t = temp_t - quotient * new_t;

        T temp_r = r;
        r = new_r;
        new_r = temp_r - quotient * new_r;
    }

    if (r > 1) {
        return 0; // Inverse doesn't exist
    }

    // Ensure t is positive
    if (t < 0) {
        t = t + mod;
    }

    return t;
}

/*
* Computes the addition of a and b modulo mod
* O(1)
*/
template <typename T>
T add(T a, T b, T mod) {
    return (a + b) % mod;
}

/*
* Computes the substraction a - b modulo mod
* O(1)
*/
template <typename T>
T substract(T a, T b, T mod) {
    return (a - b + mod) % mod;
}

/*
* Computes the multiplication a*b modulo mod
* O(1)
*/
template <typename T>
T multiply(T a, T b, T mod) {
    return (a * b) % mod;
}

/*
* Computes the division a/b modulo mod
* O(log mod)
*/
template <typename T>
T divide(T a, T b, T mod) {
    T inverse = mod_inverse(b, mod);
    if (inverse == 0) return -1; // Division by zero or no inverse
    return multiply(a, inverse, mod);
}

/*
* Solves the congruence system:
* x = a (mod n)
* x = b (mod m)
* Works even if n and m are not relatively prime
*
* Returns true if the system has a solution, false otherwise
* If there is a solution it's returned in x
* 0 ≤ x < n · m / gcd(m,n)
*
* Comlexity : O(log m)
*/
template <typename T>
bool solve_congruence(T a, T n, T b, T m, T& x) {
    T gcd_nm = gcd(n, m);
    
    // Check if a solution exists
    if ((b - a) % gcd_nm != 0) {
        return false;  // No solution
    }

    // Reduce the problem by dividing by gcd(n, m)
    n /= gcd_nm;
    m /= gcd_nm;
    T k = (b - a) / gcd_nm;
    
    T inv_n = mod_inverse(n, m);
    if (inv_n == 0) {
        return false;  // No solution
    }

    x = multiply(k, inv_n, m);
    if (x < 0) x += m;
    
    // Rebuild the solution in the original modulo system
    x = a + x * n * gcd_nm;
    return true;
}

#endif // MODULAR_ARITHMETIC_HPP