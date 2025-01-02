#ifndef SQUAREOFDIGITS_HPP
#define SQUAREOFDIGITS_HPP

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class SquareOfDigits
{
  public:

  int getMax(vector<string> data) {
    
    int res = 1;
    int row = data.size();
    int col = data[0].size();

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        for (int k = 1; k < min(row, col); k++) {

          if (i + k < row && j + k < col) {
            if (data[i][j] == data[i][j + k] && data[i][j] == data[i + k][j] && data[i][j] == data[i + k][j + k]) {
              res = max(res, (k + 1) * (k + 1));
            }
          }

        }
      }
    }

    return res;
  }
};

#endif