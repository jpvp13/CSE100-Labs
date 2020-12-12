//Lab04-1
/*
Resources:
(1) Introduction to Algorithms 3rd edition (Starting Pg.152)
(2) https://www.programiz.com/dsa/heap-sort
  (Great visual of what is going on during each func.)
(3) https://fullyunderstood.com/pseudocodes/heap-sort/




*/
#include <iostream>
#include <cmath>
using namespace std;


int Left(int i){
  return ((2*i) + 1);
}

int Right(int i){
  return ((2*i) + 2);
}
// n is size of heap
// i is the node

void maxHeapify(int Arr[], int n, int i){ //int x){ //int i){

  int left = Left(i);

  int right = Right(i);
  //Bug testing code:
  //cout << "Left " << left << endl;
  //cout << "Right " << right << endl;

  int largest = i;
  //Bug testing code:
  //cout << "Inside maxHeapify" << endl;

  //int heapSize = sizeof(Arr)/sizeof(Arr[0]);

  //checking left child larger than root
  if((left < n) && (Arr[left] > Arr[largest])){
    largest = left;
  }
  else{
    largest = i;
  }
  //checking right child larger than root
  if(right < n && Arr[right] > Arr[largest]){
    largest = right;
  }

  if(largest != i){
    swap(Arr[i], Arr[largest]);
    maxHeapify(Arr,n, largest);
  }
}



void buildMaxHeap(int Arr[], int n){
//  int heapSize = sizeof(Arr)/sizeof(Arr[0]);
  //cout << "Inside buildMaxHeap" << endl;
  //floor is used in "rounding" to the largest number
  for(int i = floor(n/2)- 1 ; i >= 0; i--){
    maxHeapify(Arr, n, i);
  }
}





void heapSort(int Arr[], int n){
  buildMaxHeap(Arr, n);
  //int heapSize = sizeof(Arr)/sizeof(Arr[0]);
  //cout << "Inside heapSort" << endl;

  for(int i = n - 1; i >= 1; i--){
    swap(Arr[0], Arr[i]);
    //n = n - 2;
    maxHeapify(Arr, i, 0);
  }
}



void printHeap(int Arr[], int size){
  //cout << "Inside print" << endl;
  for(int i = 0; i < size; i++){
  		cout << Arr[i] << ";";
  }
}


int main (){
  int arraySize;
  cin >> arraySize;  //from lab 00
  int Arr[arraySize];

  for(int i = 0; i < arraySize; i++){ //from lab00
    cin >> Arr[i]; //from lab00
    //cout << Arr[i] << " Array printout  " << endl;
  }
  //int heapSize = sizeof(Arr)/sizeof(Arr[0]);

  heapSort(Arr,arraySize);
  printHeap(Arr, arraySize);

  return 0;

}


/*
************************************************
Code Graveyard:
************************************************
int left = ((2*i)+1) ;
cout << "Left " << left << endl;
int right = ((2*i) + 2);
cout << "Right " << right << endl;


int Parent(int n){
  return (n/2);
}


int Left(int n){
  return 2*n;
}


int Right(int n){
  return (2*n + 1);
}


void maxHeapify(int Arr[], int n){
  int L = Left(n);
  int R = Right(n);

  int largest;
  cout << "Inside maxHeapify" << end;

  int arraySize = sizeof(Arr)/sizeof(Arr[0]);

  if(L <= arraySize && Arr[L] > Arr[n]){
    largest = L;
  }
  else{
    largest = n;
  }

  if(R <= arraySize && Arr[R] > Arr[largest]){
    largest = R;
  }

  if(largest != n){
    Arr[n] = Arr[largest];
    //Arr[largest + 1] = Arr[n];  would this be a exchange of Arr[largest] with Arr[n]
    maxHeapify(Arr, largest);
  }


}

int buildMaxHeap(int Arr[]){
  int heapSize = sizeof(Arr)/sizeof(Arr[0]);
  cout << "Inside buildmaxHeapify" << endl;
  for(int i = (heapSize/2);i >= 1; i--){
      maxHeapify(Arr, i);
  }
}

int heapSort(int Arr[]){
  int heapSize = sizeof(Arr)/sizeof(Arr[0]);
  buildMaxHeap(Arr);
  for(int i = heapSize; i >= 2; i--){
    Arr[1] = Arr[i];
    heapSize = heapSize - 1;
    maxHeapify(Arr, 1);
  }
}

void printHeap(int Arr[], int size){
  cout << "Inside print" << endl;
  for(int i = 0; i < size; i++){
  		cout << Arr[i] << ";";
  }
}


int main (){
  int arraySize;
  cin >> arraySize;  //from lab 00
  int Arr[arraySize];

  for(int i = 0; i < arraySize; i++){ //from lab00
    cin >> Arr[i]; //from lab00
    //cout << Arr[i] << " Array printout  " << endl;
  }

  heapSort(Arr);
  printHeap(Arr, arraySize);

  return 0;

}




*/
