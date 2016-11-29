#include <iostream>
#include "map.h"

using namespace std;

int main(){

  int t;

  map finder;

  cin >> t;

  for(int i = 0; i < t; i++){
    finder.input();
    finder.routeFinder();
    finder.output();
  }

}
