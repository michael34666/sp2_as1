//206917908
//michaeldadush12@gmail.com
//Michael dadush

#include "Graph.hpp"

using namespace ariel;  

void Graph::loadGraph(const std::vector<std::vector<int> >& g1)
{ 
     if (g1.empty() ) {
        throw std::invalid_argument("Invalid adjacency matrix: plase try again");
    }
    if(g1.size() != g1[0].size())
    {
      throw std::invalid_argument("Invalid graph: The graph is not a square matrix");
    }

    this->g = g1;
    this->symmtric=true;

     for (size_t i = 0; i < this->g.size(); i++) {

       for (size_t j = 0; j < this->g[i].size(); j++) {  
            if(i!=j){
            if(this->g[i][j]!=this->g[j][i])
            {
                this->symmtric=false;//directed graph
            }
            }
           
           
        }
    }
   

}
//maybe need const func
void Graph::printGraph () 
{   
    // Should print: "Graph with 5 vertices and 8 edges."
     this->size = this->g.size();
     int m = 0;
    
  for (size_t i = 0; i < this->size; ++i) {

       for (size_t j = 0; j < g[i].size(); ++j) {  
            if (this->g[i][j]!= 0) {
                m++;
            }  
        }
    }
    if(!getSymmtricAdjMtrix())//undirected graph
    {
      m=m/2;
    }
    std::cout<<"Graph with "<<this->size<<" vertices and "<<m<< " edges "<<std::endl;
}

std::vector<std::vector<int> > Graph::getGraph() const 
{ 
    return this->g;
}

//no directed graph if true
bool Graph:: getSymmtricAdjMtrix() const
{
 return this->symmtric;
}




