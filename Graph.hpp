//206917908
//michaeldadush12@gmail.com
//Michael dadush

#include <vector>
#include <iostream>
#pragma once
using std::vector;

namespace ariel{
 class Graph
 {
    private:
    vector<vector<int> > g;
    int size;
    bool graph_weighted;//undirected graph==true
    bool graph_symmetric;
    
    public:
    void  loadGraph (const vector<vector<int> >);
    void const printGraph();
    vector<vector<int> > getGraph() const ;
    bool getSymmetricAdjMat() const;
    bool getWeight() const;
   
 };


};
