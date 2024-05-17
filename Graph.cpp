//206917908
//michaeldadush12@gmail.com
//Michael dadush

#include "Graph.hpp"
using namespace ariel;
using std::vector;


    void Graph::loadGraph(const vector<vector<int>> new_graph) {
    if (new_graph.size() != new_graph[0].size() || new_graph.empty() ) {
        throw std:: invalid_argument("Error in load this grap");
    }
    size=g.size();
    this->g = new_graph; // Assign the provided adjacency matrix to the graph
    this->graph_symmetric=true;
    this->graph_weighted=false;
        for (size_t i = 0; i < g.size(); i++) {
            for (size_t j = 0; j < g[i].size(); j++) {
                if(g[i][j] != g[j][i]){
                    this->graph_symmetric=false;//graph directed
                }
                if(g[i][j]!=0 && g[i][j]!=1){
                    this->graph_weighted=true;
                }
                if(this->graph_weighted==true && this->graph_symmetric==false){
                    return;
                }
            }
        }

    }


void const Graph::printGraph(){
    int edges=0;
    for (size_t i = 0; i < g.size(); ++i) {
        for (size_t j = 0; j < g[i].size(); ++j) {
            if(g[i][j] != 0){
                edges++;
            }
        
        }
    }
    if(getSymmetricAdjMat()){
        edges=edges/2;
    }
    std:: cout << "Graph with " << g.size() << " vertices and " << edges << " edges." << std :: endl;
        
    }

    vector <vector<int>> Graph ::getGraph() const{
        return this -> g;
    }
     bool Graph::getSymmetricAdjMat() const{
        return this -> graph_symmetric;

    }
     bool Graph::getWeight() const{
        return this -> graph_weighted;
     
    }

