#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>

class map{

  public:
    void input();
    void routeFinder();
    void output();

  private:
    std::vector< std::vector<int> > distance, path;
    std::vector< int > weight;
    std::vector< std::string > name;
    std::vector< bool > found;
    int n;

};

#endif
