#ifndef PREFIXFREESETS_HPP
#define PREFIXFREESETS_HPP

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class PrefixFreeSets {

public:

    bool isPrefix(const string& a, const string& b) {
        if (a.size() > b.size()) return false;  // a can't be a prefix if longer
        return b.substr(0, a.size()) == a;      // check if b starts with a
    }

    int maxElements(vector<string> words) {

        sort(words.begin(), words.end());
        
        int count = 0;
        for (int i = 0; i < words.size(); i++) {
            bool add = true;
            for (int j = i + 1; j < words.size(); j++) {
                if (isPrefix(words[i], words[j])) {
                    add = false;
                    break;
                }
            }
            if (add) {
                count++;
            }
        }
        return count;
    }

};


#endif