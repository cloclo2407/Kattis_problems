#ifndef PRIMESIEVE_H
#define PRIMESIEVE_H

#include <vector>
#include <cstddef>
#include <cstdint>
#include <cmath>

template <typename T>
class PrimeSieve {
private:
    T n; // Maximum number in the sieve
    std::vector<uint64_t> bitset; // Bitset representing primality of numbers
    T total_primes; // Total number of primes found

    void clear_bit(T i) {
        bitset[i >> 6] &= ~(1ULL << (i & 63));
    }

    bool test_bit(T i) const {
        return (bitset[i >> 6] >> (i & 63)) & 1;
    }

public:
    PrimeSieve(T n) : n(n), bitset((n + 63) / 64, ~0ULL), total_primes(0) {
        if (n >= 0) clear_bit(0);
        if (n >= 1) clear_bit(1);

        T limit = static_cast<T>(std::sqrt(n));
        for (T i = 2; i <= limit; ++i) {
            if (test_bit(i)) {
                for (T multiple = i * i; multiple <= n; multiple += i) {
                    clear_bit(multiple);
                }
            }
        }
        
        for (T i = 0; i <= n; ++i) {
            if (test_bit(i)) total_primes++;
        }
    }

    bool is_prime(T x) const {
        return (x <= n) ? test_bit(x) : false;
    }

    T count_primes() const {
        return total_primes;
    }
};

#endif // PRIMESIEVE_H