#ifndef DOWNLOADINGFILES_HPP
#define DOWNLOADINGFILES_HPP

#include <vector>
#include <string>

using namespace std;

class DownloadingFiles {

public:

    double actualTime(vector<string> tasks) {

        vector<double> speeds;
        vector<double> times;

        for (int i = 0; i < tasks.size(); i++)  {

            int pos = tasks[i].find(' ');

            string stringS = tasks[i].substr(0, pos);
            string stringT = tasks[i].substr(pos + 1);

            double tempS = stoi(stringS);
            double tempT = stoi(stringT);

            speeds.push_back(tempS);
            times.push_back(tempT);

        }

        double totalSize = 0;
        double totalSpeed = 0;
        
        for (int i = 0; i < speeds.size(); i++) {

            totalSize += times[i] * speeds[i];
            totalSpeed += speeds[i];

        }

        return totalSize / totalSpeed;
    }
};

#endif

