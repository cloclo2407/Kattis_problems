#ifndef SUFFIX_ARRAY_HPP
#define SUFFIX_ARRAY_HPP

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
 * Structure to represent a suffix
 */
struct Suffix {
    int index;
    pair<int, int> rank;
};

/*
 * Return true if rank(a) < rank(b), false otherwise
 */
bool compareSuffix(const Suffix &a, const Suffix &b);

/*
 * Class to represent the suffix array of a string
 */
class SuffixArray {
private:
    string s; // The string from which we want the suffixes
    vector<int> suffixArray; // Array containing the starting positions of the suffixes sorted in lexicographical order

    void createSuffixArray(); // Function to create the suffix array

public:
    /*
    * Construct a suffixArray object from the string input
    * Build the suffixArray and stores it in vector<int> suffixArray
    * Time complexity : O(s (log s)^2) for a string s
    */
    SuffixArray(const string &input); // Constructor

    /*
    * Function to get the i'th smallest suffix in lexicographical order
    * Return an int that it the starting position of the suffix
    * Time complexity : O(1)
    */
    int getSuffix(int i); 
};

#endif // SUFFIX_ARRAY_HPP
