// ahoCorasick.h
#ifndef AHO_CORASICK_H
#define AHO_CORASICK_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <deque>
#include <string>
#include <sstream>

// Declare the function
std::vector<std::vector<int>> find_occurences(const std::vector<std::string>& patterns, const std::string& text);

#endif // AHO_CORASICK_H