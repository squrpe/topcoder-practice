#ifndef MATCH_NUMBERS_EASY_HPP
#define MATCH_NUMBERS_EASY_HPP

#include <string>
#include <vector>

using namespace std;

class MatchNumbersEasy {

public:

    vector<int> matches;
    vector<vector<string>> dp; // Memoization table fella

    string findMax(int n, int digit, bool hasNonZero) {

        if (n == 0) return ""; // No more matches to use
        if (digit < 0) return ""; // No valid digits left

        if (dp[n][digit] != "-") return dp[n][digit]; // Use memoized result

        string best = findMax(n, digit - 1, hasNonZero); // Trying without using this digit

        if (matches[digit] <= n) {

            string current = "";

            // Only allow '0' if already added a non-zero digit
            if (digit != 0 || hasNonZero) {
                current = char(digit + '0') + findMax(n - matches[digit], digit, true);
            }

            if (current.size() > best.size() || (current.size() == best.size() && current > best)) {
                best = current;
            }

        }

        return dp[n][digit] = best;
    }

    string maxNumber(vector<int> matches, int n) {

        this->matches = matches;

         // Initialise memoization table
        dp.assign(n + 1, vector<string>(matches.size(), "-"));
        
        // Start without having a non-zero digit
        string result = findMax(n, matches.size() - 1, false);

        return result.empty() ? "0" : result;
    }
};

#endif
