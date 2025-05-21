// kmp.cpp
#include "kmp.hpp"
#include <vector>
#include <string>

std::vector<int> build_prefix_table(const std::string& pattern) {
    int m = pattern.length();
    std::vector<int> prefix_table(m, 0);
    int j = 0;

    for (int i = 1; i < m; ++i) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = prefix_table[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            ++j;
            prefix_table[i] = j;
        }
    }
    return prefix_table;
}

std::vector<int> find(const std::string& pattern, const std::string& text) {
    std::vector<int> result;
    if (pattern.empty()) return result;
    
    int n = text.length();
    int m = pattern.length();
    std::vector<int> prefix_table = build_prefix_table(pattern);
    int j = 0;

    for (int i = 0; i < n; ++i) {
        while (j > 0 && text[i] != pattern[j]) {
            j = prefix_table[j - 1];
        }
        if (text[i] == pattern[j]) {
            ++j;
        }
        if (j == m) {
            result.push_back(i + 1 - m);
            j = prefix_table[j - 1];
        }
    }
    return result;
}
