#include "suffixArray.hpp"

bool compareSuffix(const Suffix &a, const Suffix &b) {
    return a.rank < b.rank;
}

SuffixArray::SuffixArray(const string &input) : s(input) {
    createSuffixArray();
}

void SuffixArray::createSuffixArray() {
    int n = s.size();
    vector<int> rank(n);
    vector<Suffix> suffixes(n);

    for (int i = 0; i < n; i++) {
        int firstRank = s[i];
        int secondRank = (i + 1 < n) ? s[i + 1] : -1;
        suffixes[i] = {i, {firstRank, secondRank}};
    }
    sort(suffixes.begin(), suffixes.end(), compareSuffix);

    for (int k = 2; k < 2 * n; k *= 2) {
        int rankCounter = 0;
        pair<int, int> prevRank = suffixes[0].rank;
        rank[suffixes[0].index] = rankCounter;

        for (int i = 1; i < n; i++) {
            if (suffixes[i].rank == prevRank) {
                rank[suffixes[i].index] = rankCounter;
            } else {
                prevRank = suffixes[i].rank;
                rank[suffixes[i].index] = ++rankCounter;
            }
        }

        for (int i = 0; i < n; i++) {
            int currentIndex = suffixes[i].index;
            int nextIndex = currentIndex + k / 2;
            int nextRank = (nextIndex < n) ? rank[nextIndex] : -1;
            suffixes[i] = {currentIndex, {rank[currentIndex], nextRank}};
        }
        sort(suffixes.begin(), suffixes.end(), compareSuffix);
    }

    suffixArray.resize(n);
    for (int i = 0; i < n; i++) {
        suffixArray[i] = suffixes[i].index;
    }
}

int SuffixArray::getSuffix(int i) {
    if (i < 0 || i >= suffixArray.size()) {
        cout << "Invalid index" << endl;
        return -1;
    }
    return suffixArray[i];
}