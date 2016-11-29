#include <iostream>
#include "map.h"

using namespace std;

void map::input(){

  distance.clear();
  path.clear();
  weight.clear();
  name.clear();
  found.clear();

  cin >> n;

  for(int i = 0; i < n; i++){
    vector< int > empty;
//    for(int j = 0; j < n; j++){
//      empty.push_back(0);
//    }
    path.push_back(empty);
  }

  for(int i = 0; i < n; i++){
    weight.push_back(2000);
  }

  for(int i = 0; i < n; i++){
    string n_in;
    cin >> n_in;
    name.push_back(n_in);
  }

  for(int i = 0; i < n; i++){
    vector< int > d_row;
    for(int j = 0; j < n; j++){
      int d_in;
      cin >> d_in;
      d_row.push_back(d_in);
    }
    distance.push_back(d_row);
  }

  for(int i = 1; i < n; i++){
    for(int j = 0; j < i; j++){
      distance[i][j] = 0;
    }
  }

}

void map::routeFinder(){

  //vector< int > checker;
  int adder;

	adder = 0;

  for(int i = 0; i < n; i++){

    vector< int > checker;
    checker = distance[i];

    for(int j = i; j < n; j++){
      checker[j] += adder;
    }

    for(int j = i; j < n; j++){
      if(checker[j] < weight[j] && checker[j] != 0){
        weight[j] = checker[j];
        path[j].push_back(i);
      }
    }

    //found[i] = true;
	  //repeat till fall off and found all true

    adder = weight[i+1];

  }

}

void map::output(){

  //for(int i = 0; i < n; i++){
  //  cout << weight[i] << endl;//name[i] << endl;
  //}

  for(int i = 0; i < path[n-1].size(); i++){
    cout << name[path[n-1][i]] << " ";
  }

  cout << weight[n-1] << endl;

  //loop
  //print names according to path then weight

}
