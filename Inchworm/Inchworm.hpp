#ifndef INCHWORM_HPP
#define INCHWORM_HPP

#include <iostream>

using namespace std;
 
class Inchworm
{
  public:

  // Simul - MoveStep
  int lunchtime(int branch, int rest, int leaf)
  {
    int res = 0;

    for (int i = 0; i <= branch; i += rest) {
      if (i % leaf == 0 ) {
        res++;
      }
    }

    return res;
  }

  // Math LCM
  // int lunchtime(int branch, int rest, int leaf)
  // {
  //   int a = leaf, b = rest;
    
  //   if (leaf > rest) {
  //     swap(a, b);
  //   }

  //   while (b > 0) {
  //     int c = a % b;
  //     a = b;
  //     b = c;
  //   }

  //   int lcm = (leaf * rest) / a;

  //   return (branch / lcm) + 1;
  // }

};

#endif