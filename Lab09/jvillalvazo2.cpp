//lab09
/*
Resources
(1) http://www.cplusplus.com/doc/tutorial/structures/
(2) https://www.geeksforgeeks.org/structures-in-cpp/
(3) http://www.cplusplus.com/reference/queue/priority_queue/
places I was stuck explained by Friend who took this class in previous years
*/
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <vector>
#include <string>

using namespace std;

//Global Variables
const int size = 6; //since we are only looking at the first 6 letters in the alphabet
int Q[size];
char letters[] = {'A', 'B', 'C', 'D', 'E', 'F'};
string letterArray[] = {"", "", "", "","", ""};


//creates a struct to help create a tree with given nodes
struct nodeLeaf{
  char letter;
  int Q;
  nodeLeaf *leftChild;
  nodeLeaf *rightChild;

  nodeLeaf(char letter, int Q){

    //this-> creates a pointer towards this type
    this->letter = letter;
    //this-> creates a pointer towards this type
    this->Q = Q;
    leftChild= NULL;  //sets left child to NULL
    rightChild = NULL;  //sets left child to NULL
  }
};

//used to compare leafs of children
struct compareBoth{

  bool operator()(nodeLeaf *leftChild, nodeLeaf *rightChild){ //const

  //returns the value of left child if it is larger than right child
  return (leftChild->Q > rightChild->Q);
  }
};

/*int ExtractMin(Q){

}
*/


void printHuffTree(int size){
  for(int i = 0; i < size; i++){
    cout << letterArray[i] << endl;
  }
}

void printCodes (struct nodeLeaf* root, string word){

  if(root == NULL){
    return;
  }


//this checks to what letter is at the root and the letter in the letters. If they math then it sets the letter equal to that letter and the bits
  if(root->letter == letters[0]){
    letterArray[0] = letterArray[0] + letters[0] + ":" + word;
  }else if(root->letter == letters[1]){
    letterArray[1] = letterArray[1] + letters[1] + ":" + word;
  }else if(root->letter == letters[2]){
    letterArray[2] = letterArray[2] +letters[2] + ":" + word;
  }else if(root->letter == letters[3]){
    letterArray[3] = letterArray[3] + letters[3] + ":" + word;
  }else if(root->letter == letters[4]){
    letterArray[4] = letterArray[4] + letters[4] + ":" + word;
  }else if(root->letter == letters[5]){
    letterArray[5] = letterArray[5] + letters[5] + ":" + word;
  }

  //this recursively builds left and right sides of the tree
  printCodes(root->leftChild, word + "0");
  printCodes(root->rightChild, word + "1");
}

void Huffman(char letter[], int Q[]){
  //n = |C|
  //Q = C
  struct nodeLeaf *leftChild, *rightChild, *root;

  priority_queue<nodeLeaf*, vector<nodeLeaf*>, compareBoth> Queue;

  for(int m = 0; m < size; m++){
    Queue.push(new nodeLeaf(letters[m],Q[m]));
  }

  //builds tree
  while(Queue.size() > 1){
    leftChild = Queue.top();
    Queue.pop();
    rightChild = Queue.top();
    Queue.pop();

    //root is given elements of the letter and the value of the node at hand
    root = new nodeLeaf('$', leftChild->Q + rightChild->Q);
    root->leftChild = leftChild;
    root->rightChild = rightChild;
    Queue.push(root);


  }
  //Queue.top is the top value of the queue
  //"" is the empty value of letter
  printCodes(Queue.top(),"");
}


int main (){

  //int Q[size];

  //gets all sizes
  for(int i = 0; i < size; i++){
    cin >> Q[i];
  }


  Huffman(letters, Q);
  printHuffTree(size);
  return 0;

}


// int i = 0;
// while (i != 6){
//   for(int k = 0; k < 6; k++){
//     cout << "Test " << endl;
//     if(c[k] == char(65 + i)){
//       cout << "Hello " << endl;
//       cout << c[k] << ":" << m[k] << endl;
//     }
//   }
//   i++;
// }

//new node Z
//z.left = x = ExtractMin(Q)
//z.right = y = ExtractMin(Q)
//z.freq = x.freq + y.freq
//Insert(Q, z);

//return ExtractMin(Q)
//printCodes(heap.top(), "");
