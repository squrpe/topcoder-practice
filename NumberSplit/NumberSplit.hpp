#ifndef NUMBER_SPLIT_HPP
#define NUMBER_SPLIT_HPP

#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class NumberSplit {

private:

    int findLongest(int number, unordered_map<int, int>& memo) {

        if (number < 10) return 1;
        if (memo.find(number) != memo.end()) return memo[number];

        string num_str = to_string(number);
        int max_length = 1;

        for (int i = 1; i < num_str.length(); ++i) {
            for (int j = i; j < num_str.length(); ++j) {
                vector<int> parts;
                if (!splitNum(num_str, i, j, parts)) continue;

                int product = 1;
                for (int part : parts) {
                    product *= part;
                }

                int sub_length = 1 + findLongest(product, memo);
                max_length = max(max_length, sub_length);
            }
        }

        memo[number] = max_length;
        return max_length;

    }

    bool splitNum(const string& num_str, int i, int j, vector<int>& parts) {

        parts.clear();
        string part1 = num_str.substr(0, i);
        string part2 = num_str.substr(i, j-i);
        string part3 = num_str.substr(j);

        if ((part1.length() > 1 && part1[0] == '0') ||
            (part2.length() > 1 && part2[0] == '0') ||
            (part3.length() > 1 && part3[0] == '0')) {
            return false;
        }

        parts.push_back(stoi(part1));
        if (!part2.empty()) parts.push_back(stoi(part2));
        if (!part3.empty()) parts.push_back(stoi(part3));

        return parts.size() > 1;

    }

public:

    int longestSequence(int start) {

        unordered_map<int, int> memo;
        return findLongest(start, memo);
        
    }

};

#endif 
