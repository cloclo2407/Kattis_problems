#include "ahoCorasick.hpp"

using namespace std;

struct TrieNode {
    unordered_map<char, int> transitions; // outgoing edges based on next character
    int fail_links; // where to go when transition for next character doesn't exist
    vector<int> output; // indices of patterns that end at this node

    TrieNode() : fail_links(0) {}
};

vector<vector<int>> find_occurences(const vector<string>& patterns, const string& text) {
    // edge cases
    if (patterns.empty()) {
        return {};
    }

    vector<int> pattern_lengths;
    for (const auto& pattern : patterns) {
        pattern_lengths.push_back(pattern.length());
    }

    vector<vector<int>> result(patterns.size());

    // build trie
    vector<TrieNode> trie;
    trie.emplace_back(); // root is at idx 0

    for (int pattern_idx = 0; pattern_idx < patterns.size(); ++pattern_idx) {
        const string& pattern = patterns[pattern_idx];
        int current = 0;
        for (char ch : pattern) {
            if (trie[current].transitions.find(ch) == trie[current].transitions.end()) {
                // transition with character doesn't exist => create new
                int new_index = trie.size();
                trie.emplace_back();
                trie[current].transitions[ch] = new_index;
            }
            current = trie[current].transitions[ch];
        }
        trie[current].output.push_back(pattern_idx);
    }

    // create failure links
    deque<int> queue;

    for (const auto& transition : trie[0].transitions) {
        // every node after one step from the root has transition to root
        trie[transition.second].fail_links = 0;
        queue.push_back(transition.second);
    }

    // construct failure links with bfs
    while (!queue.empty()) {
        int state = queue.front();
        queue.pop_front();

        for (const auto& transition : trie[state].transitions) {
            char ch = transition.first;
            int next_state = transition.second;
            queue.push_back(next_state);

            // follow failure links until node is found with transition for character ch
            // (or until root is reached)
            int fail_candidate = trie[state].fail_links; // start with previous fail_link
            while (fail_candidate != 0 && trie[fail_candidate].transitions.find(ch) == trie[fail_candidate].transitions.end()) {
                fail_candidate = trie[fail_candidate].fail_links;
            }

            if (trie[fail_candidate].transitions.find(ch) != trie[fail_candidate].transitions.end()) {
                // found character transition => set fail link
                trie[next_state].fail_links = trie[fail_candidate].transitions[ch];
            } else {
                // didn't find anything (loop ended with fail_candidate == 0) => set to root
                trie[next_state].fail_links = 0;
            }

            // propagate output of fail link to self
            int fail_link = trie[next_state].fail_links;
            trie[next_state].output.insert(trie[next_state].output.end(), trie[fail_link].output.begin(), trie[fail_link].output.end());
        }
    }

    // search text
    int current = 0; // start at root
    for (int i = 0; i < text.length(); ++i) {
        char ch = text[i];
        // if there is no transition with character => follow fail links
        while (current != 0 && trie[current].transitions.find(ch) == trie[current].transitions.end()) {
            current = trie[current].fail_links;
        }
        if (trie[current].transitions.find(ch) != trie[current].transitions.end()) {
            // valid transition found => move on
            current = trie[current].transitions[ch];
        } else {
            current = 0;
        }

        for (int p_idx : trie[current].output) { // found those patterns
            int pat_len = pattern_lengths[p_idx];
            result[p_idx].push_back(i + 1 - pat_len); // push start position of pattern
        }
    }

    return result;
}