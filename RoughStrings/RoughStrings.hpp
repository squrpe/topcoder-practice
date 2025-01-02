#ifndef ROUGHSTRINGS_HPP
#define ROUGHSTRINGS_HPP

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>

using namespace std;

class RoughStrings {
private:

    // function to calc roughness from letter frequencies
    int calculateRoughness(const vector<int>& freq) {

        int maxFreq = *max_element(freq.begin(), freq.end());

        int minFreq = *min_element(freq.begin(), freq.end(), [](int a, int b) {
            return (a > 0 && a < b) || (b == 0);  // ignore 0 frequencies
        });

        return maxFreq - minFreq;
    }

public:

    int minRoughness(string s, int n) {
        unordered_map<char, int> freqMap;

        // Counter for frequency of each character
        for (char c : s) {
            freqMap[c]++;
        }

        // Storing frequencies in vector
        vector<int> frequencies;

        for (auto& entry : freqMap) {
            frequencies.push_back(entry.second);
        }

        // Sort frequencies for easier calc
        sort(frequencies.begin(), frequencies.end());

        vector<int> freqCount(51, 0);  // max frequency is 50
        for (int freq : frequencies) {
            freqCount[freq]++;
        }

        int result = INT_MAX;

        for (int low = 1; low <= 50; ++low) {

            for (int high = low; high <= 50; ++high) {

                int totalRemovals = 0;

                // Remove characters from frequencies smaller than low
                for (int i = 1; i < low; ++i) {
                    totalRemovals += freqCount[i] * i;  // remove all occurrences
                }

                // Remove characters from frequencies larger than high
                for (int i = high + 1; i <= 50; ++i) {
                    totalRemovals += freqCount[i] * (i - high);
                }

                // If total num of removals needed is within the allowed n
                if (totalRemovals <= n) {
                    result = min(result, high - low);
                }

            }

        }

        return result;
    }
};

#endif
