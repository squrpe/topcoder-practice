#ifndef CUBE_STICKERS_HPP
#define CUBE_STICKERS_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

class CubeStickers {

public:

    string isPossible(vector<string>& sticker) {

        unordered_map<string, int> colorCounts;
        
        // Count occurrences of each color
        for (const auto& color : sticker) {
            colorCounts[color]++;
        }
        
        vector<int> counts;
        for (const auto& pair : colorCounts) {
            counts.push_back(pair.second);
        }
        
        // Sort counts in descending order
        sort(counts.begin(), counts.end(), greater<int>());
        
        // Check conditions
        if (counts.size() >= 6 ||
            (counts.size() == 5 && counts[0] >= 2) ||
            (counts.size() == 4 && counts[0] >= 2 && counts[1] >= 2) ||
            (counts.size() == 3 && counts[0] >= 2 && counts[1] >= 2 && counts[2] >= 2)) {
            return "YES";
        }
        
        return "NO";

    }

};

#endif 