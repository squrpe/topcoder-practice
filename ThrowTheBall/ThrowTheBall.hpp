#ifndef THROWTHEBALL_HPP
#define THROWTHEBALL_HPP

#include <vector>

using namespace std;

class ThrowTheBall
{
    public:
        int timesThrown(int N, int M, int L)
        {
            vector<int> players(N, 0);

            int i = 0; // current
            int res = 0; // result

            while (true) {
            players[i]++;
            if (players[i] == M) {
                return res;
            }
            if (players[i] % 2 == 0) {
                i = (i + L) % N;
            } else {
                i = (i - L + N) % N;
            }
            res++;
            }

        }
};

#endif