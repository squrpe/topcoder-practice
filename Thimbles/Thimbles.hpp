#ifndef THIMBLES_HPP
#define THIMBLES_HPP

#include <string>
#include <vector>

using namespace std;

class Thimbles {

public:

    int thimbleWithBall(vector<string> swaps) {
        int ballPosition = 1;

        // Loop through each swap
        for (string swap : swaps) {

            // Get X and Y from the format "X-Y"
            int posX = swap[0] - '0';
            int posY = swap[2] - '0';

            // Check if ball is involved in the swap
            if (ballPosition == posX) {
                ballPosition = posY;
            } else if (ballPosition == posY) {
                ballPosition = posX;
            }

        }

        return ballPosition;
    }

};

#endif
