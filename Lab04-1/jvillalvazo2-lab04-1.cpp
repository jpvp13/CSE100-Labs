//Lab04-1
/*
Resources:
(1) https://stackoverflow.com/questions/12417786/invalid-types-intint-for-array-subscript


*/
#include <iostream>

using namespace std;


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
