#include <iostream>
#include <list>
#include <stack>


class SCCGraph{
public:
    int vertexCount;
    std::list<int> *adjList;

SCCGraph(int vertexCount){
    this->vertexCount = vertexCount;
    adjList = new std::list<int>[vertexCount];
}

void DepthFirstSearch(int vertex, bool fill[], int numVertices, int block[]){
    fill[vertex] = 1;
    block[vertex] = numVertices;

    std::list<int>::iterator i;
    for (i = adjList[vertex].begin(); i != adjList[vertex].end(); i++){
        if (!fill[*i]){
                DepthFirstSearch(*i, fill, numVertices, block);
        }
    }
}

SCCGraph transpose(){
    SCCGraph check(vertexCount);
    
    for (int vertex = 0; vertex < vertexCount; vertex++){
        std::list<int>::iterator i;
        
        for(i = adjList[vertex].begin(); i != adjList[vertex].end(); i++){
            check.adjList[*i].push_back(vertex);
            }
        }
    return check;
}

void nodeEdge(int v1, int v2){
    adjList[v1].push_back(v2);
}

void color(int vertex, bool fill[], std::stack<int> &top){
    fill[vertex] = 1;

    std::list<int>::iterator i;
    
    for(i = adjList[vertex].begin(); i != adjList[vertex].end(); i++){
        if(!fill[*i]){
            color(*i, fill, top);
        }
    }

    top.push(vertex);
} 

void printGraph(int numVertices,int block[]){
    std::stack<int> top;
    
    bool *fill = new bool[vertexCount];
    
    for(int i = 0; i < vertexCount; i++){
        fill[i] = 0;
    }
    
    for(int i = 0; i < vertexCount; i++){
        if(fill[i] == 0)
            color(i, fill, top);
    }
    SCCGraph check = transpose();
    
    for(int i = 0; i < vertexCount; i++){
        fill[i] = 0;
    }
    while (top.empty() == 0){
        int vertex = top.top();
        top.pop();
        
        if (fill[vertex] == 0){
            int minimum = vertex;
            check.DepthFirstSearch(vertex, fill, vertex, block);
            
            for(int i = 0; i < numVertices; i++){
                if(block[i] == vertex){
                    
                    if(minimum > i){
                        minimum = i;
                }
            }
        }
            for(int i = 0; i < numVertices; i++){
                if(block[i] == vertex){
                    block[i] = minimum;
                    }
                }
            }
        }
    }
};
int main(){
    int vertices;
    int edge;
    int v1;
    int v2;
    
    std::cin >> vertices >> edge;
    
    SCCGraph graph(vertices);
    int block[vertices];
    
    for(int i = 0; i < edge; i++){
        std::cin >> v1;
        std::cin >> v2;
        
        graph.nodeEdge(v1,v2);
    }
    
    graph.printGraph(vertices,block);
    
    for(int i = 0; i < vertices; i++){
        std::cout << block[i] << std::endl;
    }
    
    return 0;
}
