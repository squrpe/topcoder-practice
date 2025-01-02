#ifndef EGGCARTONS_HPP
#define EGGCARTONS_HPP

using namespace std;

class EggCartons {
  public:

  int minCartons(int n) {

    int res = -1;

    for (int i = 0; i <= n / 6; i++) {
      if ((n - 6 * i) % 8 == 0) {
        res = i + (n - 6 * i) / 8;
        break;
      }
    }

    return res;
    
  }
};

#endif