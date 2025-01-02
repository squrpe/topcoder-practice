#ifndef CATGAME_HPP
#define CATGAME_HPP

#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class CatGame {

    private:

    int findMinPosition(vector<int>& positions) {

        int lowest = numeric_limits<int>::max();

        for (int pos : positions) {
            if (pos < lowest) {
                lowest = pos;
            }
        }

        return lowest;

    }

    int findMaxPosition(vector<int>& positions) {

        int highest = numeric_limits<int>::min();

        for (int pos : positions) {
            if (pos > highest) {
                highest = pos;
            }
        }

        return highest;

    }

    public:

    int getNumber(vector<int> coordinates, int X) {

        if (coordinates.size() == 1) {
            return 0;
        }

        sort(coordinates.begin(), coordinates.end());

        int initialSpread = coordinates.back() - coordinates.front();

        if (initialSpread <= X) {
            return initialSpread;
        }

        long smallestSpread = numeric_limits<long>::max();

        vector<int> movedPositions(coordinates.size());

        for (int i = 0; i < coordinates.size(); ++i) {
            movedPositions[i] = coordinates[i] - X;
        }

        for (int i = 0; i < coordinates.size(); ++i) {

            movedPositions[i] += 2 * X;
            
            int leftEdge = findMinPosition(movedPositions);
            int rightEdge = findMaxPosition(movedPositions);
            long currentSpread = rightEdge - leftEdge;

            if (currentSpread < smallestSpread) {
                smallestSpread = currentSpread;
            }

        }

        return smallestSpread;
        
    }
};

#endif