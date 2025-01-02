#ifndef HANDSSHAKING_HPP
#define HANDSSHAKING_HPP

#include <vector>

using namespace std;

class HandsShaking {

public:

    long countPerfect(int n) {

        vector<long> arr(n + 1, 0);

        arr[0] = 1;  // Base case: no businessmen = 1 way to have no handshakes
        
        for (int i = 2; i <= n; i += 2) {
            for (int j = 0; j <= i - 2; j += 2) {
                arr[i] += arr[j] * arr[i - 2 - j];
            }
        }
        
        return arr[n];
    }
    
};

#endif
