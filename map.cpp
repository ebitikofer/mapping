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

  //This loop cuts out repeated values at the bottom traingle of the matrix
  //EX: 0 1 2 0        0 1 2 0
  //    1 0 5 6   >>   0 0 5 6
  //    2 5 0 7   >>   0 0 0 7
  //    0 6 7 0        0 0 0 0
  for(int i = 1; i < n; i++){
    for(int j = 0; j < i; j++){
      distance[i][j] = 0;
    }
  }

}

void map::routeFinder(){

  int adder;

	adder = 0; //distance from last location to current (starts at 0)

  for(int i = 0; i < n; i++){ //long loop walks through row choosing shortest route each time (Breadth First)

    vector< int > checker;
    checker = distance[i]; //sets the checker to current row in matrix

    for(int j = i; j < n; j++){ //starts at current location and goes through the ones we haven't reached yet
      checker[j] += adder; //adds the shortest distance from first to current to each location that we havent reached yet
    }

    for(int j = i; j < n; j++){ //starts at current location and goes through the ones we haven't reached yet
      if(checker[j] < weight[j]){// && checker[j] != 0){ //if the compination tried is shorter than the direct route then swap as long a the chcker route isnt zero which would mean it didnt exist
        if(checker[j] != 0){
          weight[j] = checker[j];
        }
        path[j].push_back(i); //push back path taken value
      }
    }

    adder = weight[i+1]; //change the add

  }

  for(int i = 0; i < n; i++){
    int temp;
    temp = path[i][path[i].size()-1]; //set temp to last value in path
    if(temp != i){ //if last value doesnt equal the final destination, add it to the end (it doesn't for all but first path where the start and destination are the same)
      path[i].push_back(i); //push back the destination value
    }
  }

}

void map::output(){

  for(int i = 0; i < path[n-1].size(); i++){
    cout << name[path[n-1][i]] << " ";
  }

  cout << weight[n-1] << endl;

}
