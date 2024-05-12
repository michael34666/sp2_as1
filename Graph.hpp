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
    bool symmtric;//undirected graph==true
    
    public:
    void  loadGraph (const std::vector<std::vector<int> >& g1);
    void printGraph () ;
    vector<vector<int> > getGraph() const ;
    bool getSymmtricAdjMtrix() const;//undirected graph if true , false directed
    
   
 };


};
