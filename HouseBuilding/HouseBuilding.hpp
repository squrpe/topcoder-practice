#ifndef HOUSEBUILDING_HPP
#define HOUSEBUILDING_HPP

#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class HouseBuilding {

public:

    int getMinimum(vector<string> area) {

        int minEffort = INT_MAX;
        
        for (int baseHeight = 0; baseHeight <= 9; baseHeight++) {

            int effort = 0;
            for (const string& row : area) {
                for (char c : row) {
                    int height = c - '0';
                    effort += min(abs(height - baseHeight), abs(height - (baseHeight + 1)));
                }
            }
            minEffort = min(minEffort, effort);

        }
        
        return minEffort;
    }

};

#endif