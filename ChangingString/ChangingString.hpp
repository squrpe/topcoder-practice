#ifndef CHANGINGSTRING_HPP
#define CHANGINGSTRING_HPP

#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

class ChangingString {

    public:

    int distance(string A, string B, int K) {

        vector<int> differences;
        int totalDistance = 0;

        for (int i = 0; i < A.size(); i++) {
            int temp = abs(A[i] - B[i]);
            differences.push_back(temp);
            totalDistance += temp;
        }

        sort(differences.rbegin(), differences.rend());

        for (int i = 0; i < K; i++) {
            if (differences[i] > 0) {
                totalDistance -= differences[i];
                differences[i] = 0;
            } else {
                totalDistance += 1;
            }
        }

        return totalDistance;

    }
};

#endif
