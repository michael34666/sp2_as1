# 206917908
# michaeldadush12@gmail.com
# Michael dadush



# System Programming 2 - Assignment 1

For this assignment, i  implement various graph algorithms in C++. The assignment revolves around two main classes: `Graph` and `Algorithms`. The implementation use namespaces `ariel`.

## Graph

The `Graph` class represents a graph, which can be directed or undirected, and can have positive or negative weights. The graph is represented using an adjacency matrix.

### Functions:

#### loadGraph

This function initializes the graph with the given adjacency matrix. It performs validity checks on the input and sets the graph properties accordingly. If the input is invalid, the function throws an `invalid_argument` exception.

#### printGraph

This function prints information about the graph in the format: "Graph with n vertices and m edges." 

"""
In addition, I also wrote get functions that will give me access to the fields
"""

## Algorithms

The `Algorithms` class contains static functions that implement various graph algorithms.

### isConnected

This function checks if the graph is connected:

- Perform DFS on the entire graph.
- If all vertices are discovered, the graph is connected.

### shortestPath

This function finds the shortest path between two vertices in the graph. It uses one of three algorithms based on the type of graph and weights:

- If the graph is unweighted, it uses Breadth-First Search (BFS).
- If the graph has negative weights, it uses the Bellman-Ford algorithm.

If there is no path between the two vertices, the function returns "-1".

### isContainsCycle

This function checks if the graph contains a cycle. If a cycle exists, the function returns one of the cycles in the format. If no cycle exists, it returns "-1".

#### Helper Function

- `isContainsCycleUtil`: This is a modified version of DFS that runs until it finds a back edge in the graph. When it finds a back edge, it constructs the cycle path.

### isBipartite

This function checks if the graph is bipartite. If the graph is bipartite, it returns two sets of vertices. O therwise, it returns "The graph is not bipartite".

### negativeCycle

This function checks if the graph contains a negative cycle using the Bellman-Ford algorithm. If a negative cycle exists return true Otherwise, return false.

