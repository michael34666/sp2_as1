//206917908
//michaeldadush12@gmail.com
//Michael dadush

#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}

TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0->1->2->0");
}


TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");
}

TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}");
}
TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
}


TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    g.loadGraph({{1, 0, 0},
                 {0, 1, 0},
                 {0, 0, 1}});
    CHECK(ariel::Algorithms::isConnected(g)==false); // Connected graph

}

TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
        g.loadGraph(
            {{1, 0, 0},
            {0, 0, 0},
            {0, 0, 1}});
     CHECK_FALSE(ariel::Algorithms::isConnected(g)==true); // Disconnected graph

}

TEST_CASE("Test dfs") {
    ariel::Graph g;

    g.loadGraph({{0, 1, 1},
                 {1, 0, 1},
                 {1, 1, 0}});

    vector<bool> visited(g.getGraph().size(), false);
    ariel::Algorithms::dfs(0, visited, g);
    for (bool v : visited) {
        CHECK(v);
    }
}



TEST_CASE("Test isBipartite") {
    ariel::Graph g;

    g.loadGraph({{0, 1, 0},
                 {1, 0, 1},
                 {0, 1, 0}});
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");

    g.loadGraph({{0, 1, 1, 0, 0},
                 {1, 0, 1, 0, 0},
                 {1, 1, 0, 1, 0},
                 {0, 0, 1, 0, 0},
                 {0, 0, 0, 0, 0}});
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    g.loadGraph({{0, 1, 2, 0, 0},
                 {1, 0, 3, 0, 0},
                 {2, 3, 0, 4, 0},
                 {0, 0, 4, 0, 5},
                 {0, 0, 0, 5, 0}});
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
}

TEST_CASE("Test shortestPath") {
    ariel::Graph g;

    g.loadGraph({{0, 1, 0},
                 {1, 0, 1},
                 {0, 1, 0}});
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    g.loadGraph({{0, 1, 1, 0, 0},
                 {1, 0, 1, 0, 0},
                 {1, 1, 0, 1, 0},
                 {0, 0, 1, 0, 0},
                 {0, 0, 0, 0, 0}});
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");
}



TEST_CASE("Test negativeCycle") {
    ariel::Graph g;

    g.loadGraph({{0, -1, 4, 0, 0},
                 {0, 0, 3, 2, 2},
                 {0, 0, 0, 0, 0},
                 {0, 1, 5, 0, 0},
                 {0, 0, 0, -3, 0}});

    CHECK(ariel::Algorithms::negativeCycle(g, 0)==false);
}





