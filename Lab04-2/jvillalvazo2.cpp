//Lab04-2 created by John Villalvazo
/*
Resources:
(1) Introduction to Algorithms 3rd edition (Starting pg. 179)
(2) http://www.cplusplus.com/reference/cstdlib/rand/
(3) https://www.bogotobogo.com/cplusplus/RandomNumbers.php
(4) https://www.geeksforgeeks.org/quicksort-using-random-pivoting/
*/
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;


int Partition(int Arr[], int p, int r){
  //int random = (rand() % r); //this selects the pivot
  //cout << "Print random =" << random << endl;
  //pivot
  int x = Arr[r];
  //cout << "Print x =" << x << endl;
  int i = p;

  for(int j = p; j <= (r - 1); j++){
    if(Arr[j] <= x){
      swap(Arr[i], Arr[j]);
      i++;
    }
  }
  swap(Arr[i], Arr[r]);

  return (i);
}

int randomPartition(int Arr[], int p, int r){
  //starts at p so we know the smallest element and then (r-p) gives the
  //right hand side max that rand() can choose between
  int ran = p + rand() % (r - p) ;
  swap(Arr[ran], Arr[r]);
  return Partition(Arr, p, r);
}



void randomQuickSort(int Arr[], int p, int r){
  if(p < r){
    int q = randomPartition(Arr, p ,r);
    randomQuickSort(Arr, p, q -1 );
    randomQuickSort(Arr, q + 1, r);
  }
}



void printQuickSort(int Arr[], int size){
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
    //int random = rand()  % arraySize;
  randomQuickSort(Arr, 0, arraySize - 1);
  printQuickSort(Arr, arraySize);

  return 0;

}
