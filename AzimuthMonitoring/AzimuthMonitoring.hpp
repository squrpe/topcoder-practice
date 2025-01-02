#ifndef AZIMUTHMONITORING_HPP
#define AZIMUTHMONITORING_HPP

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class AzimuthMonitoring
{
    public:
        int getAzimuth(vector<string> instructions) {

            int angle = 0;

            for (int i = 0; i < instructions.size(); ++i) {

                string inst = instructions[i];

                if (inst== "TURN AROUND") {
                    angle += 180;
                } else if (inst == "HALT") {
                    break;
                } else if (inst == "RIGHT") {
                    angle += 90;
                } else if (inst == "LEFT") {
                    angle -= 90;
                } else {

                    // get the value from the instruction
                    size_t space = inst.find(' ');

                    // gets and converts the numeric value from the substring that comes after space
                    int value = stoi(inst.substr(space + 1));

                    if (inst[0] == 'R') {
                        angle += value;
                    } else if (inst[0] == 'L') {
                        angle -= value;
                    }
                }
            }

            angle %= 360;
            if (angle < 0) {
                angle += 360;
            }

            return angle;
        }
};

#endif