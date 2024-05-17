//206917908
//michaeldadush12@gmail.com
//Michael dadush


#include "Algorithms.hpp"

using namespace ariel;

using std::queue;
using std::vector;
using std:: to_string;

void Algorithms::dfs(size_t v, vector<bool> &visit, const Graph &g)
{
    // Mark the vertex in true ==we visit in the vertex
    visit[v] = true;
    // Run on all adjacent vertices of v
    for (size_t u = 0; u < visit.size(); ++u)
    {
        if (g.getGraph()[v][u] != 0 && !visit[u])
        {
            dfs(u, visit, g); // Recursive DFS call 
        }
    }
}

bool Algorithms::isConnected(const Graph &g)
{
    // Check if the graph has been loaded
    if (g.getGraph().empty())
    {
        std::cout << "Error: Graph is not loaded,plase chack it" << std::endl;
        return false;
    }

    // vector that store who vertex vistied and who not
    vector<bool> visit(g.getGraph().size(), false);

    // Perform depth-first search (DFS) starting from the first vertex
    dfs(0, visit, g);

    // Check if all vertices are visited
    for (bool v : visit)
    {
        if (!v)
        {
            return false; // The graph is not connected becuse one vertex not visited
        }
    }

    return true; //all vertex visited== the graph is connected
}

string Algorithms::isContainsCycle(const Graph &g)
{  
  // vector that store who vertex vistied and who not
    vector<bool> visited(g.getGraph().size(), false);

    for (size_t i = 0; i < g.getGraph().size(); i++)
    {
        if (!visited[i])
        {   
           //calling helping function
            string cycle = containsCycleUtil(g, i, -1, visited);
            if (!cycle.empty())
            {
                return cycle;
            }
        }
    }
    return "0";// if there is no cycle
}

string Algorithms::containsCycleUtil(const Graph &g, size_t v, int parent, vector<bool> &visit)
{
    visit[v] = true;
    for (size_t u = 0; u < g.getGraph().size(); ++u)
    {
        if (g.getGraph()[v][u] != 0)
        {
            if (!visit[u])
            {
                string cycle = containsCycleUtil(g, u, v, visit);
                if (!cycle.empty())
                {
                    // Append the vertex to the cycle
                    return (v == stoi(cycle.substr(0, cycle.find("->"))) ? cycle : to_string(v) + "->" + cycle);
                }
            }
            else if (u != parent)
            {
                // return the cycle
                return to_string(v) + "->" + to_string(u);
            }
        }
    }
    visit[v] = false; // change the state of visited vertex to backtracking
    return "";
}

string Algorithms::isBipartite(const Graph &g)
{
    vector<int> color(g.getGraph().size(), -1);
    vector<int> verticesSetA, verticesSetB;
    verticesSetA.push_back(0);//first vertex

    for (size_t i = 0; i < g.getGraph().size(); ++i)
    {
        if (color[i] == -1)
        {   //sending to helping function
            if (!isBipartiteUtil(g, i, color, verticesSetA, verticesSetB))
            {
                return "0";
            }
        }
    }

    // create the result of first group
    string result = "The graph is bipartite: A={";
    for (size_t i = 0; i < verticesSetA.size() - 1; i++)
    {
        result += to_string(verticesSetA[i]);
        result += ", ";
    }
    if (!verticesSetA.empty())
        result += to_string(verticesSetA.back());
    
    // create the result of second group
    result += "}, B={";
    for (size_t i = 0; i < verticesSetB.size() - 1; i++)
    {
        result += to_string(verticesSetB[i]);
        result += ", ";
    }
    if (!verticesSetB.empty())
        result += to_string(verticesSetB.back());

    result += "}";
    return result;
}

bool Algorithms::isBipartiteUtil(const Graph &g, size_t src, vector<int> &color, vector<int> &verticesSetA, vector<int> &verticesSetB)
{
    color[src] = 1; // Color the first vertex in color 1
    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        size_t u = (size_t)q.front();
        q.pop();

        for (size_t v = 0; v < g.getGraph().size(); ++v)
        {
            if (g.getGraph()[u][v] != 0)
            {
                if (color[v] == -1)
                {
                    color[v] = 1 - color[u]; // trying to put new color to the vertex
                    q.push(v);
                    if (color[v] == 0)
                        verticesSetB.push_back(v);
                    else
                        verticesSetA.push_back(v);
                }
                else if (color[v] == color[u])
                {
                    return false; // The graph is not bipartite,If to vertices Neighbors have the same color
                }
            }
        }
    }
    return true;//The graph is bipartite
}

bool Algorithms::negativeCycle(const Graph &g, size_t start)
{   int size=g.getGraph().size();
    //two vectors:one for distance and one for parent
    vector<int> dist(size, std::numeric_limits<int>::infinity());
    vector<int> parent(size, -1);
    return !bellmanFord(g, start, dist, parent);//calling to BF to check if there is neg cycle
}

bool Algorithms::bellmanFord(const Graph &g, size_t src, vector<int> &dist, vector<int> &parent)
{

    dist[src] = 0;
    // Relax all edges in the graph
    for (size_t i = 0; i < g.getGraph().size() - 1; ++i)
    {
        for (size_t u = 0; u < g.getGraph().size(); ++u)
        {
            for (size_t v = 0; v < g.getGraph().size(); ++v)
            {
                if (g.getGraph()[u][v] != 0 && dist[u] != std::numeric_limits<int>::infinity() && dist[u] + g.getGraph()[u][v] < dist[v])
                {
                    dist[v] = dist[u] + g.getGraph()[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    // Check negative-weight for
    for (size_t u = 0; u < g.getGraph().size(); ++u)
    {
        for (size_t v = 0; v < g.getGraph().size(); ++v)
        {
            if (g.getGraph()[u][v] != 0 && dist[u] != std::numeric_limits<int>::infinity() && dist[u] + g.getGraph()[u][v] < dist[v])
            {
                std::cout << "There is negative-weight cycle\n";
                return false;
            }
        }
    }

    return true;
}
void Algorithms::bfs(const Graph &graph, size_t start, vector<bool> &visited, vector<int> &dist, vector<int> &parent)
{
    size_t size = graph.getGraph().size();
    queue<int> q;
    q.push(start);
    visited[start] = true;
    dist[start] = 0;

    while (!q.empty())
    {
        size_t u = (size_t)q.front();
        q.pop();

        for (size_t v = 0; v < size; v++)
        {
            if (graph.getGraph()[u][v] != 0 && !visited[v])
            {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                parent[v] = u; // Update the parent of v
                q.push(v);
            }
        }
    }
}
string Algorithms::shortestPath(const Graph &g, size_t start, size_t end)
{   int size=g.getGraph().size();
    //3 vectors that
    vector<bool> visit(size, false);
    vector<int> dist(size, std::numeric_limits<int>::infinity()); // 
    vector<int> parent(size, -1);   // The shortest path will shoe the path

    // If the graph is not weighted, use BFS 
    if (!g.getWeight())
    {
        //using bfs func
        bfs(g, start, visit, dist, parent);

        if (dist[end] != std::numeric_limits<int>::infinity()) // TODO change to INF
        {
            string path = to_string(end);
            int p = parent[end];
            while (p != -1)
            {
                path.insert(0, to_string(p) + "->");
                p = parent[(size_t)p];
            }
            return path;
        }
        else
        {
            return "-1";
        }
    }
    else
    {   //if the weighted,use bellmanford
        if (bellmanFord(g, start, dist, parent))
        {

                if(dist[end]==std::numeric_limits<int>::infinity())
                {
                    return "-1";//there is no path
                }

            string path = to_string(end);
            int p = parent[end];
            while (p != -1)
            {
                path.insert(0, to_string(p) + "->");
                p = parent[(size_t)p];
            }
            return path;
        }

        else
        {
            return "-1";
        }
    }
}

bool Algorithms::bellmanFord(const Graph &g, size_t src, vector<int> &dist, vector<int> &parent)
{

    dist[src] = 0;
    // Relax all edges in the graph
    for (size_t i = 0; i < g.getGraph().size() - 1; ++i)
    {
        for (size_t u = 0; u < g.getGraph().size(); ++u)
        {
            for (size_t v = 0; v < g.getGraph().size(); ++v)
            {
                if (g.getGraph()[u][v] != 0 && dist[u] != std::numeric_limits<int>::infinity() && dist[u] + g.getGraph()[u][v] < dist[v])
                {
                    dist[v] = dist[u] + g.getGraph()[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    // Check negative-weight for
    for (size_t u = 0; u < g.getGraph().size(); ++u)
    {
        for (size_t v = 0; v < g.getGraph().size(); ++v)
        {
            if (g.getGraph()[u][v] != 0 && dist[u] != std::numeric_limits<int>::infinity() && dist[u] + g.getGraph()[u][v] < dist[v])
            {
                std::cout << "There is negative-weight cycle\n";
                return false;
            }
        }
    }

    return true;
}