//lab11 Minimim spanning tree
/*
Resources
(1) https://stackoverflow.com/questions/15516654/compilation-error-left-ambiguous-right-ambiguous
(2) https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/

Good Visuals to figure out what is going on
(3) https://www.codespeedy.com/minimum-spanning-tree-for-graph-in-cpp/
*/

#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;
//STD already has a 'left' & 'right', had to all caps these variables


//global variables
int verticies;
int edgeLine;
int LEFT; //left child
int RIGHT;  //right child
int weight; //edge weight

//these are used throughout the code to remember what these values are
vector<int> key;
vector<int> parent;


//this func adds edges to the tree
void edges(int LEFT, int RIGHT, int weight, vector<pair<int,int> > theGraph[]){
  theGraph[LEFT].push_back(make_pair(RIGHT,weight));
  theGraph[RIGHT].push_back(make_pair(LEFT, weight));
}

// void DecreaseKey(){
//
// }
//
// int extractMin(){
//
// }

// void MSTprim(int Graph[], int w, int r){
void MSTprim(int verticies, vector< pair<int,int> > theGraph[]){

  // priority_queue <pairs<int, int> , vector<pairs<int,int> >, compareGreater<pairs<int, int> > > Q;


  priority_queue<pair<int, int>, vector<pair<int, int> > , greater<pair<int, int> > > Q;
  //int source = 0;

  // vector<int> key;
  // vector<int> parent;
  vector<bool> visitedInside(verticies, false);


  Q.push(pair<int, int>(0,0));


  //this is equivalent to u∈V do
  for(int i = 0; i < verticies; i++){
    key.push_back(123456789);
    parent.push_back(0);
  }


//this checks to see if a parent is empty and builds the trees
  while(Q.empty() == false){
    int LEFT = Q.top().second;
    Q.pop();

    visitedInside[LEFT] = true;

    // list<Pair<int, int> >::iterator i;
    for(int i = 0; i < theGraph[LEFT].size(); i++){
      int RIGHT = theGraph[LEFT][i].first;
      int weight = theGraph[LEFT][i].second;

      if(visitedInside[RIGHT] == false && key[RIGHT] > weight){
        key[RIGHT] = weight;
        Q.push(pair<int,int>(weight, RIGHT));
        parent[RIGHT] = LEFT;
      }
    }

  }
  //return parent[vertecies];
}



void printPrim(int verticies) {
  for(int i = 1; i < verticies; i++){
    cout << parent[i] << endl;
  }
}

int main(){

  cin >> verticies >> edgeLine;
  vector<pair<int, int> > theGraph[edgeLine];
  //priority_queue <int, vector<int>, compare<int> > minheap;

  for(int i = 0; i < edgeLine; i++){
    cin >> LEFT >> RIGHT >> weight;
    edges(LEFT, RIGHT, weight, theGraph);
  }


  MSTprim(verticies, theGraph);

  //prints all parents of the tree
  printPrim(verticies);

  return 0;
}
/*
//vector<pair<int, int> > theGraph[edgeLine];

//typedef pair<int, int> pairs;
//typedef <int> theGraph[edgeLine];
//
// class Graph{
//   int V;
//
//   list< pair<int, int> > *adjecent;
//
//   public:
//     Graph(int V);
//
//     void edge(int left, int right, int weight);
//
//     void MSTprim();
//
//     void DecreaseKey();
// };
//
// Graph(int V){
//   this->V = V;
//   adjcent = new list<Pair> [V];
// }


MST-PRIM.G; w; r/
for each u G:V
  u.key = infinity
  u.pi = NIL
r.key = 0
Q = G.V
while Q != 0;
  u = EXTRACT-MIN(Q)
  for each 􏰁 2 G:AdjŒu􏰀
if 􏰁 2 Q and w.u;􏰁/ < 􏰁:key 􏰁:􏰄 D u
􏰁:key D w.u;􏰁/
*/
