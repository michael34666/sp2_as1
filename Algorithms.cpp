//206917908
//michaeldadush12@gmail.com
//Michael dadush

#include "Algorithms.hpp"

using namespace ariel;

using  std::vector;
using std::queue;
using std::to_string;

void Algorithms::dfs(size_t v, vector<bool>& visited, const Graph& g) {
  // Mark the current vertex as visited to avoid revisiting it
  visited[v] = true;
  // run in for through all adjacent vertices of the current vertex
  for (size_t u = 0; u < g.getGraph().size(); ++u) {
    // Check if there's an edge from the current vertex (v) to its neighbor (u)
    // and if the neighbor (u) hasn't been visited yet
    if (g.getGraph()[v][u] != 0 && !visited[u]) {
      // If there's an edge and the neighbor hasn't been visited, perform DFS recursively on the neighbor
      dfs(u, visited, g);
    }
  }
}

bool Algorithms::isConnected(const Graph& g) {
  // Check if the graph is empty (not loaded)
  if (g.getGraph().empty()) {
    throw std::string ("Error: Graph is not loaded.\n") ;// Use cerr for error messages
    return false;
  }
  // Create a visited vector to track explored vertices
  vector<bool> visited(g.getGraph().size(), false);

  // Perform DFS traversal starting from an arbitrary vertex (e.g., vertex 0)
  dfs(0, visited, g);

  // Check if all vertices are visited (indicating a connected graph)
  for (const bool& v : visited) { // Use const reference for efficiency
    if (!v) {
      return false; // Unvisited vertex implies disconnected graph
    }
  }
  return true; // All vertices visited, graph is connected
}


std::string Algorithms::isContainsCycle(const Graph& g) {
  // Create a visited vector to track explored vertices
  vector<bool> visited(g.getGraph().size(), false);
  // try to find for cycles using DFS from each unvisited vertex
  for (size_t i = 0; i < g.getGraph().size(); ++i) {
    if (!visited[i]) {
      // Perform DFS utility and check if it finds a cycle
      std::string cycle = containsCycleUtil(g, i, -1, visited);
      if (!cycle.empty()) {
        return cycle; // Cycle found, return the cycle path
      }
    }
  }
  // No cycle found in any DFS exploration
  return "0";
}

std::string Algorithms::containsCycleUtil(const Graph& g, size_t v, int parent, vector<bool>& visited) {
  // Mark the current vertex as visited
  visited[v] = true;

  // Iterate through adjacent vertices of the current vertex
  for (size_t u = 0; u < g.getGraph().size(); ++u) {
    // Check if there's an edge from the current vertex (v) to its neighbor (u)
    if (g.getGraph()[v][u] != 0) {
      // If the neighbor (u) is not visited, explore it recursively
      if (!visited[u]) {
        std::string cycle = containsCycleUtil(g, u, v, visited); // Recursive DFS call
        if (!cycle.empty()) {
          // Cycle found in the subtree, construct and return the full cycle path
          return (v == std::stoi(cycle.substr(0, cycle.find("->"))) ? cycle : std::to_string(v) + "->" + cycle);
        }
      // If the neighbor (u) is visited and it's not the parent (v -> u back edge)
      } else if (u != parent) {
        // Cycle detected, return the back edge as part of the cycle path
        return to_string(v) + "->" + to_string(u);
      }
    }
  }
  //  unmark the current vertex (v) as visited for future DFS calls
  visited[v] = false;
  // No cycle found in this branch of DFS exploration, return empty string
  return "";
}

std::string Algorithms::shortestPath(const Graph& g, size_t start, size_t end) {
    
    vector<bool> visit(g.getGraph().size(), false);
    vector<int> distance(g.getGraph().size(), -1);
    vector<int> parent(g.getGraph().size(), -1); // This is will be the path that we will print to see the shortest path

    // If the graph is not weighted, use BFS to find the shortest path
    if (g.getSymmtricAdjMtrix()){
       
        bfs(g, start, visit, distance, parent);

        if (distance[end] != -1) 
        {  
            std::string path;
            size_t v = end; 
            while(v != start){
            path = to_string(parent[v]) + "->" + path;
                v = (size_t)parent[v];
            }
            path = path + to_string(end);
            return path;
        }
        else 
        {
            return "-1";
        }
   }
   else{
        if(bellmanFord(g,start,distance,parent))
        { 
            std::string path = to_string(start);
            int parents = parent[start];
            while (parents != -1) 
            {
                path.insert(0, to_string(parents) + "->");
                parents = parent[(size_t)parents];
            }
         return path;
        }
           
     
        else
        {
            return "-1";
        }
   }
}


void Algorithms::bfs(const Graph & graph, size_t src, vector<bool>& visited, vector<int>& distance, vector<int>& parent) {
    size_t size = graph.getGraph().size();
    queue<int> q;
    q.push(src);
    visited[src] = true;
    distance[src] = 0;

    while (!q.empty()) {
        size_t u =(size_t) q.front();
        q.pop();

        for (size_t v = 0; v < size; v++) {
            if (graph.getGraph()[u][v] != 0 && !visited[v]) {
                visited[v] = true;
                distance[v] = distance[u] + 1;
                parent[v] = u; // Update the parent of v
                q.push(v);
            }
        }
    }
}



bool Algorithms::bellmanFord(const Graph& g,size_t source,vector<int> distance,vector<int> parent) {
    
        distance[source] = 0;
        // Relax edges repeatedly
        for (size_t i = 0; i < g.getGraph().size() - 1; ++i) {
            for (size_t  u = 0; u < g.getGraph().size(); ++u) {
                for (size_t  v = 0; v < g.getGraph().size(); ++v) {
                    if (g.getGraph()[u][v] != 0 && distance[u] != std::numeric_limits<int>::infinity() && distance[u] + g.getGraph()[u][v] < distance[v]) {
                        distance[v] = distance[u] + g.getGraph()[u][v];
                        parent[v]=u;
                    }
                }
            }
        }

        // Check for negative-weight cycles
        for (size_t  u = 0; u < g.getGraph().size(); ++u) {
            for (size_t  v = 0; v < g.getGraph().size(); ++v) {
                if (g.getGraph()[u][v] != 0 && distance[u] != std::numeric_limits<int>::infinity() && distance[u] + g.getGraph()[u][v] < distance[v]) {
                    std::cout << "Graph contains negative-weight cycle\n";
                    return false;
                }
            }
        }

        return true;
}

std::string Algorithms::isBipartite(const Graph& g) {
    vector<int> verticesA, verticesB;//two group of vertex
    vector<int> color(g.getGraph().size(), -1);//vetor of color
    verticesA.push_back(0);//start with 0
    

    for (size_t i = 0; i < g.getGraph().size(); ++i) {
        if (color[i] == -1) {
            if (!isBipartiteUtil(g, i, color, verticesA, verticesB)) {
                return "0";
            }
        }
    }
    // create the result string of the two group
    std::string result = "The graph is bipartite: A={";
    for (size_t i = 0; i < verticesA.size() - 1; i++) {
        result += to_string(verticesA[i]);
        result += ",";
    }
    if (!verticesA.empty())
        result += to_string(verticesA.back());
    
    result += "}, B={";
    for (size_t i = 0; i < verticesB.size() - 1; i++) {
        result += to_string(verticesB[i]);
        result += ",";
    }
    if (!verticesB.empty())
        result += to_string(verticesB.back());

    result += "}";
    return result;
}

bool Algorithms::isBipartiteUtil(const Graph& g, size_t src, vector<int>& color, vector<int>& verticesA, vector<int>& verticesB) 
{
    color[src] = 1; // Color the source vertex with 1
    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        size_t u = (size_t)q.front();
        q.pop();

        for (size_t v = 0; v < g.getGraph().size(); ++v) {
            if (g.getGraph()[u][v] != 0) {
                if (color[v] == -1) {
                    color[v] = 1 - color[u]; // Assign alternate color to this adjacent vertex
                    q.push(v);
                    if (color[v] == 0)
                        verticesB.push_back(v);
                    else
                        verticesA.push_back(v);
                } else if (color[v] == color[u]) {
                    return false; // If adjacent vertices have the same color it return false becuse the graph is not Bipartite
                }
            }
        }
    }
    return true;
}


bool Algorithms::negativeCycle(const Graph& g, size_t src) {
   
vector<int> distance(g.getGraph().size(), std::numeric_limits<int>::infinity());//distance vector
vector<int> parent(g.getGraph().size(), -1);//parent vector
return !bellmanFord(g,src,distance,parent);
 
} 


