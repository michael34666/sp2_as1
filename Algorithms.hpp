//206917908
//michaeldadush12@gmail.com
//Michael dadush


#include "Graph.hpp" 
#include <unordered_set>
#include <iostream>
#include <vector>
#include <limits> 
#include <queue>
#include <string>
#pragma once
using std::vector;
using std::string;
using std::pair;
namespace ariel 
{

class Algorithms    
{
    public:
    static bool isConnected(const Graph& );
    static void dfs(size_t , vector<bool>& ,const Graph& );
    static string isContainsCycle(const Graph& );
    static string isBipartite(const Graph& );
    static bool isBipartiteUtil(const Graph& , size_t , vector<int>& , vector<int>& , vector<int>& ) ;
    static string containsCycleUtil(const Graph& , size_t , int , vector<bool>& );
    static string shortestPath(const Graph& , size_t , size_t );
    static  void bfs(const Graph & , size_t start, vector<bool>& , vector<int>& , vector<int>& );
    static bool bellmanFord(const Graph& ,size_t ,vector<int> &,vector<int> &);
    static bool negativeCycle(const Graph& , size_t );

};

};