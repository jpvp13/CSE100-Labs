//lab10
/*
Resources
(1) https://www.tutorialspoint.com/cplusplus/cpp_class_access_modifiers.htm
(2) https://www.programiz.com/dsa/strongly-connected-components
(3) http://www.cplusplus.com/reference/stack/stack/
(4) https://www.geeksforgeeks.org/difference-between-public-and-private-in-c-with-example/
(5) http://www.cplusplus.com/doc/tutorial/classes/
*/

#include <iostream>
#include <list>
#include <stack>

using namespace std;

//global variables
int v;
int w;
int v1;
int v2;


class Build{
  //public is a class modifier
  public:
  int VertexStart;
  list<int> *adjList;
  // void fillIn(int size, bool visitedVertex[], stack<int> &Stack);
  // void DFS(int size, bool visitedVertex[], int verticies);




    Build(int VertexStart){
      this->VertexStart = VertexStart;
      adjList = new list<int>[VertexStart];
    }
    // void addEdge(int v1, int v2);
    // int printPath(int v, int visitedVertex[]);
    //Build getTranspose();



// Build::Build(int Vertex){
//   this->Vertex = Vertex;
//   adjList = new list<list>[Vertex];
// };

void fillIn(int size, bool occupy[], stack<int> &Stack){
  occupy[size] = 1;
  //this is used since this is used for iteratoring lists
  list<int>::iterator i;
  for(i = adjList[size].begin(); i != adjList[size].end(); i++){
    if(occupy[*i] == false){
      fillIn(*i, occupy, Stack);
    }
  }
  Stack.push(size);
}


void DFS(int size, bool occupy[], int verticies, int visitedVertex[]){
  occupy[size] = 1;

  visitedVertex[size] = verticies;

  list<int>::iterator i;

  for(i = adjList[size].begin(); i != adjList[size].end(); i++){
    if(occupy[*i] == false){
      DFS(*i, occupy, verticies, visitedVertex);
    }
  }
}

void addEdge(int v1, int v2){
  adjList[v1].push_back(v2);
}

Build getTranspose(){
  Build G(VertexStart);

  list<int>::iterator i;
  for(int v = 0; v < VertexStart; v++){
    for(i = adjList[v].begin(); i != adjList[v].end(); i++){
    G.adjList[*i].push_back(v);
    }
  }
  return G;
}


//void printPath(list<int> G[], list<int> S[], list<int> U[]){
void printPath(int verticies, int visitedVertex[]){
  stack<int> Stack;
  bool *occupy = new bool[VertexStart];

  for(int i = 0; i < VertexStart; i++){
    // occupy[k] = false
    occupy[i] = false;
  }

  for(int k = 0; k < VertexStart; k++){
    // if(occupy[k] == false)
    if(occupy[k] == false){
      fillIn(k, occupy, Stack);
    }
  }

  Build G = getTranspose();

  for(int i = 0; i < VertexStart; i++){
    // occupy[k] = false
    occupy[i] = false;
  }
//  int count = 0;

  while(Stack.empty() == false){
    int V = Stack.top();
    Stack.pop();
    if(occupy[V] == 0){
      int min = V;
      G.DFS(V,occupy, V, visitedVertex);
      //cout << endl;

      for(int i = 0; i < verticies; i++){
        if(visitedVertex[i] == V){
          if(min > i){
            min = i;
          }
        }
      }
      for(int k = 0; k < verticies; k++){
        if(visitedVertex[k] == V){
          visitedVertex[k] = min;
          }
        }
      }
  //  count++;
    }
  //return count;
}
};


int main(){
  // cin >> v;
  // cin >> w;
  // cin >> v1;
  // cin >> v2;

  cin >> v >> w;
  Build graph(v);
  int visitedVertex[v];

  for(int i = 0; i < w; i++){
    cin >> v1;
    cin >> v2;

    graph.addEdge(v1, v2);
  }

  graph.printPath(v, visitedVertex);

  for(int i = 0; i < v; i++){
    cout << visitedVertex[i] << endl;
  }

return 0;
}
