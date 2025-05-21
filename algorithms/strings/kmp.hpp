// kmp.hpp
#ifndef KMP_HPP
#define KMP_HPP

#include <vector>
#include <string>

std::vector<int> find(const std::string& pattern, const std::string& text);
std::vector<int> build_prefix_table(const std::string& pattern);

#endif // KMP_HPP