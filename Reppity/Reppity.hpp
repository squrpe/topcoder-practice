#ifndef REPPITY_HPP
#define REPPITY_HPP

#include <string>

using namespace std;

class Reppity {
  public:

  int longestRep(string input) {
    
    int res = 0;
    int length = input.size();

    for (int len = 1; len <= length; len++) {
      for (int i = 0; i + len <= length; i++) {

        string substr = input.substr(i, len);

        for (int j = i + len; j + len <= length; j++) {
          if (input.substr(j, len) == substr) {
            res = max(res, len);
          }
        }

      }
    }

    return res;
  }
};

#endif
