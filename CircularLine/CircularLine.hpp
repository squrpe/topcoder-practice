#ifndef CIRCULARLINE_HPP
#define CIRCULARLINE_HPP

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class CircularLine
{
    public:
        int longestTravel(vector<int> t) {

            int maxTravelTime = -1;
            int totalTravelTime = accumulate(t.begin(), t.end(), 0);

            for (int start = 0; start < t.size(); ++start) {

                int travelTime = 0;

                for (int end = start + 1; end < t.size(); ++end) {
                    
                    travelTime += t[end - 1];
                    int shortestTravel = min(travelTime, totalTravelTime - travelTime);
                    maxTravelTime = max(maxTravelTime, shortestTravel);

                }
            }

            return maxTravelTime;
        }
};

#endif
