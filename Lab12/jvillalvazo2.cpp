//Lab12
/*
Resources
(1) https://stackoverflow.com/questions/3794236/difference-between-the-int-i-and-int-i/3794246
(2) https://www.techiedelight.com/single-source-shortest-paths-bellman-ford-algorithm/#:~:text=The%20idea%20is%20to%20use,vertices%20in%20given%20weighted%20digraph.&text=The%20algorithm%20initializes%20the%20distance,all%20other%20nodes%20to%20infinity.
(3) https://courses.csail.mit.edu/6.006/spring11/rec/rec14.pdf

*/
#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;


//Global variables
int verticies = 0;
int edges = 0;
int source = 0;
int weight = 0;
int LEFT = 0;
int RIGHT = 0;


//will check if a leaf has been reached
bool withinReach;



//this finds the shortest path within the graph and initialized it to right leaf
 void initializeSS(int verticies, int **theGraph, int weight, int DISTANCE[]){
   for(int k = 0; k <= verticies; k++){
     for(int j = 0; j < edges; j++){
       LEFT = theGraph[0][j];
       RIGHT = theGraph[1][j];
       weight = theGraph[2][j];

       if(DISTANCE[LEFT] != 123456789 && DISTANCE[LEFT] + weight < DISTANCE[RIGHT]){
         DISTANCE[RIGHT] = DISTANCE[LEFT] + weight;
       }
     }
   }
 }


//this will check if the left leaf is smaller, returns false if not shorter
 void relax(int **theGraph, int verticies, int edges, int weight, int DISTANCE[]){
   for(int i = 0; i < edges; i++){
     LEFT = theGraph[0][i];
     RIGHT = theGraph[1][i];
     weight = theGraph[2][i];

     if(DISTANCE[LEFT] != 123456789 && DISTANCE[LEFT] + weight < DISTANCE[RIGHT]){
       cout << "FALSE" << endl;
       withinReach = false;
     }
   }
}



void bellmanFord(int **theGraph,int source, int verticies, int edges, int DISTANCE[]){

  withinReach = true;

//  int DISTANCE[];


for(int i = 0; i < verticies; i++){
  DISTANCE[i] = 123456789;
}

DISTANCE[source] = 0;






  //initialized DISTANCE
  initializeSS(verticies, theGraph, weight, DISTANCE);


  relax(theGraph,verticies, edges,weight, DISTANCE);


//this is used to print the output, will check if distance is not infinite
//if not, prints the distance, if infinite, prints out "inifinity" for each index of Distance
  if((withinReach)){
    cout << "TRUE" << endl;
    for(int l = 0; l < verticies; l++){
      if(DISTANCE[l] != 123456789){
        cout << DISTANCE[l] << endl;
      } else {
        cout << "INFINITY" << endl;
      }
    }
  }
}


int main(){

 int i;
 int j;
  cin >> verticies >> edges;

  //a pointer to a pointer to a int
  int **theGraph;

  int DISTANCE[verticies];


  //sets the size of the pointer to a pointer to a int to size 3
  theGraph = new int *[3];
  for(i = 0; i < verticies; i++){
    theGraph[i] = new int [edges];

    //possibly not this!
    for(j = 0; j < verticies; j++){
      //initializes both sides of a node to 0
      theGraph[i][j] = 0;
    }
    //addEdge(LEFT,RIGHT, weight, theGraph)
  }


//this grows the graph which each input of left, right, weight
for(i = 0; i < edges; i++){
  cin >> LEFT >> RIGHT >> weight;
  theGraph[0][i] = LEFT;
  theGraph[1][i] = RIGHT;
  theGraph[2][i] = weight;
  }

bellmanFord(theGraph, 0, verticies, edges, DISTANCE);

  // if(bellmanFord(theGraph, 0, verticies, edges, DISTANCE) == true){
  //   //printBell(DISTANCE,verticies);
  // }


//printBell(vertiies);
return 0;
}


/*

// for(int m = 0; m < edges; m++){
//   if(DISTANCE[RIGHT] > DISTANCE[LEFT] + weight){
//     return false;
//   }
// }
// return true;
//DISTANCE[i] = 1234567890;



//   cout << "TRUE" << endl;
//   for(int i = 0; i < verticies; i++){
//     if(DISTANCE[i] != 1234567890){
//       cout << DISTANCE[i] << endl;
//     } else {
//       cout << "INFINITY" << endl;
//       }
//   }
// }
//
//   //return True;
// }

// void printBell(int DISTANCE[], int vertices){
// //  if((withinReach)){
//       cout << "TRUE" << endl;
//       for(int i = 0; i < verticies; i++){
//         if(DISTANCE[i] != 1234567890){
//           cout << DISTANCE[i] << endl;
//         } else {
//           cout << "INFINITY" << endl;
//         }
//   }
// }

// void initalizeSS(int **theGraph, int source, int verticies, int DISTANCE[]){
//   for(int i = 0; i < verticies; i++){
//     DISTANCE[i] = 123456789;
//     DISTANCE[verticies] = NULL;
//   }
//   DISTANCE[source] = 0;
// }

// void relax(int LEFT, int RIGHT, int weight, int DISTANCE[],int verticies, int edges){
//   for(int i = 1; i <= verticies - 1; i++){
//     for(int j = 0; j < edges; j++){
//
//   if(DISTANCE[RIGHT] > DISTANCE[LEFT] + weight){
//     DISTANCE[RIGHT] = DISTANCE[LEFT] + weight;
//     DISTANCE[RIGHT] = LEFT;
//   }
//   }
//   }
// }

//DISTANCE[source] = 0;

*/
