#ifndef STREETPARKING_HPP
#define STREETPARKING_HPP

#include <string>

using namespace std;

class StreetParking
{
    public:
        int freeParks(string street)
        {
            int num = street.length();

            // Mark illegal parking spots
            for (int i = 0; i < num; i++) {
                if (street[i] == 'B') {
                    if (i > 0 && street[i - 1] == '-') street[i - 1] = 'X';
                    if (i > 1 && street[i - 2] == '-') street[i - 2] = 'X';
                }

                if (street[i] == 'S') {
                    if (i > 0 && street[i - 1] == '-') street[i - 1] = 'X';
                    if (i < num - 1 && street[i + 1] == '-') street[i + 1] = 'X';
                }
            }

            // Count legal parking spots
            int res = 0;
            for (int i = 0; i < num; i++) {
                if (street[i] == '-') res++;
            }

            return res;
        }
};

#endif
