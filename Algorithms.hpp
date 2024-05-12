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
using std::pair;
namespace ariel 
{

class Algorithms    
{
    public:
    static bool isConnected(const Graph& g);
    static void dfs(size_t v, vector<bool>& visited,const Graph& g);
    static std::string isContainsCycle(const Graph& g);
    static std::string isBipartite(const Graph& g);
    static bool isBipartiteUtil(const Graph& g, size_t src, vector<int>& color, vector<int>& verticesA, vector<int>& verticesB) ;
    static std::string containsCycleUtil(const Graph& g, size_t v, int parent, vector<bool>& visited);
    static std::string shortestPath(const Graph& g, size_t start, size_t end);
    static  void bfs(const Graph & graph, size_t start, vector<bool>& visited, vector<int>& distance, vector<int>& parent);
    static bool bellmanFord(const Graph& g,size_t source,vector<int> distance,vector<int> parent);
    static bool negativeCycle(const Graph& g, size_t src);

};

};