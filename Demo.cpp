/*
 * Demo program for Exercise 2.
 * Author: Benjamin Saldman.
 */
//206917908
//michaeldadush12@gmail.com
//Michael dadush

#include "Graph.hpp"
#include "Algorithms.hpp"
using ariel::Algorithms;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main()
{
    ariel::Graph g;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph); // Load the graph to the object.
    
    cout<<"graph1_printing:"<<endl;
    g.printGraph();                                    // Should print: "Graph with 3 vertices and 4 edges."
    cout << Algorithms::isConnected(g) << endl;        // Should print: "1" (true).
    cout << Algorithms::shortestPath(g, 0, 2) << endl; ///~ Should print: 0->1->2.
    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "0" (false).
    cout << Algorithms::isBipartite(g) << endl;        /// Should print: "The graph is bipartite: A={0, 2}, B={1}."
    cout << Algorithms::negativeCycle(g,0) << endl;   //Should print:0

    // 5x5 matrix that represents a non-connected graph with a cycle.
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};

    g.loadGraph(graph2); // Load the graph to the object.

    cout<<"graph2_printing:"<<endl;
    g.printGraph();                                    // Should print: "Graph with 5 vertices and 8 edges."
    cout << Algorithms::isConnected(g) << endl;        // Should print: "0" (false).
    cout << Algorithms::shortestPath(g, 0, 4) << endl; ///~ Should print: "-1" (there is no path between 0 and 4).
    cout << Algorithms::isContainsCycle(g) << endl;    ///~ Should print: "The cycle is: 0->1->2->0".
    cout << Algorithms::isBipartite(g) << endl;        // Should print: "0" (false).
    cout << Algorithms::negativeCycle(g,0) << endl;   //Should print: "0"

    // 5x5 matrix that reprsents a connected weighted graph.
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 2},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3); // Load the graph to the object.


    cout<<"graph3_printing:"<<endl;
    g.printGraph();                                    // Should print: "Graph with 5 vertices and 8 edges."
    cout << Algorithms::isConnected(g) << endl;        // Should print: "1" (true).
    cout << Algorithms::shortestPath(g, 0, 4) << endl; ///~ Should print: 0->2->3->4.
    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "0" (false).
    cout << Algorithms::isBipartite(g) << endl;        // Should print: "The graph is bipartite: A={0, 2, 4}, B={1, 3}."
    cout << Algorithms::negativeCycle(g,0) << endl;   //Should print: "0" (false).


    // 5x4 matrix that reprsents invalid graph.
    vector<vector<int> > graph4 = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}
        };

    cout<<"graph4_printing:"<<endl;
    try
    {
        g.loadGraph(graph4); // Load the graph to the object.
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl; // Should print: "Invalid graph: The graph is not a square matrix."
    }
    
    vector<vector<int>> graph5 = {
    {0, -1, 0},
    {-1, 0, 1},
    {0, 1, 0}};
g.loadGraph(graph); // Load the graph with negative weight.

cout << "\ngraph5_printing:" << endl;
g.printGraph();                                    
cout << "Is connected? " << Algorithms::isConnected(g) << endl;        
cout << "Shortest path from 0 to 2: " << Algorithms::shortestPath(g, 0, 2) << endl; 
cout << "Contains cycle? " << Algorithms::isContainsCycle(g) << endl;   
cout << "Is bipartite? " << Algorithms::isBipartite(g) << endl;        
cout << "Has negative cycle from 0? " << Algorithms::negativeCycle(g,0) << endl;   
}









