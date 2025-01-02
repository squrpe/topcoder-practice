#ifndef BLACKANDWHITESOLITAIRE_HPP
#define BLACKANDWHITESOLITAIRE_HPP

#include <string>
#include <algorithm>

using namespace std;

class BlackAndWhiteSolitaire {

private:

    int countFlips(const string& cardFront, char startColor) {

        int flips = 0;
        char expectedColor = startColor;
        
        for (char card : cardFront) {
            if (card != expectedColor) {
                flips++;
            }
            expectedColor = (expectedColor == 'B') ? 'W' : 'B';
        }
        
        return flips;
    }

public:

    int minimumTurns(string cardFront) {

        return min(countFlips(cardFront, 'B'), countFlips(cardFront, 'W'));

    }

};

#endif