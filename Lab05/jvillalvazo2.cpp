//Lab05
/*
Resources:
(1)http://www.cplusplus.com/reference/vector/vector/
(2)https://www.tutorialspoint.com/cplusplus-program-to-implement-counting-sort
(3)https://www.geeksforgeeks.org/2d-vector-in-cpp-with-user-defined-size/
(4)https://www.tutorialspoint.com/cplusplus-program-to-perform-matrix-multiplication#:~:text=A%20matrix%20is%20a%20rectangular,a%20matrix%20is%20as%20follows.&text=A%20program%20that%20performs%20matrix%20multiplication%20is%20as%20follows.
(5)Introduction to Algorithms 3rd edition
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int CountingSort(vector<int> Arr[], int arraySize, int column ,int digit){

  vector<int> Output[arraySize];  //this is the array that will store values within countingsort
  int count[10] = {0};  //initialize all indices of count[10] to elemenet 0
  //int rowSize[10] = {0};
  int k;  //iterative variable

  for(int i = 0; i < arraySize; i++){
    vector<int> x = Arr[i];
    //this initializes k with the value stored in vector x[index]
    k = x[digit];
    //cout << "this is the value of k " << k << endl;

    //count[k] is the value of count at index k and that gets added to 1
    count[k] += 1;
  }
  //keep track of the columns
  for(int i = 1; i < column; i++){
    count[i] += count[i - 1];
  }

  for(int i = arraySize - 1; i >= 0; i--){
    Output[count[Arr[i][digit]] - 1] = Arr[i];
    count[Arr[i][digit]] -= 1;
  }

  //places the output value from Output into Arr
  for(int i = 0; i < arraySize; i++){
    Arr[i] = Output[i];
  }
}

// Radix Sort to sort a[] of given size.
void radixsort(vector<int> Arr[], int column, int size){
  //this keeps on recursively calling countingSort until the last element in of column
  for (int i = column - 1; i >= 0; i--){
    //passes the vector (Arr) the size of the vector, the column and whatever digit it is on (i)
    CountingSort(Arr, size, column, i);
  }
}

void printRadix(vector<int> Arr[], int arraySize){
  for (int i = 0; i < arraySize; i++){
      for (int j = 0; j < Arr[i].size(); j++){
          cout << Arr[i][j] << ";";
      }

      cout << endl;
  }

}

int main (){
  int arraySize;
  cin >> arraySize;  //gets total size of array
  vector<int> Arr[arraySize]; //initialize vector Arr

  //initialized the amount of elements we are expecting to see and the value of columns
  int elements = 10;
  int column = 10;


  for(int i = 0; i < arraySize; i++){ //from lab00
    for(int j = 0; j < column; j++){
    cin >> elements;
    //this creates space within the created vector that is "elements" long
    Arr[i].push_back(elements);
    //cout << Arr[i] << " Array printout  " << endl;
  }
  }
    //possibly arraySize - 1
  radixsort(Arr, column, arraySize);
  printRadix(Arr, arraySize);

  return 0;
}

/*
**********************************
Code GraveYard:
**********************************

// int findMax(int Arr[], int num){
//   int max = Arr[0];
//   for(int i = 1; i < num; i++){
//     if(Arr[i] > max){
//       max = Arr[i];
//     }
//   }
//   return max;
// }

// void countingSort(int Arr[], int arraySize, int digit){
//   int Output[arraySize];
//   int count[arraySize];
//   int i = 0;
//
//
//   for(i = 0; i < arraySize;i++){
//     count[(Arr[i] / digit) % 10]++;
//   }
//
//   for(i = 1; i < 10; i++){
//     count[i] += count[i - 1];
//   }
//
//   for(i = arraySize - 1; i >= 0; i--){
//     Output[count[(Arr[i] / digit)% 10] - 1] = Arr[i];
//     count[(Arr[i] / digit)%10]--;
//   }
//   // cout << "Starting of counting Sort " << endl;
//   // cout << "Value of arraySize is " << arraySize<<  endl;
//   // for(int i = 0; i < arraySize; i++){
//   //   Output[i] = 0;
//   //   count[i] = 0;
//   //   cout << "The value of Output[i] is " << Output[i] << endl;
//   // }
//   //
//   // for(int i = 0; i < arraySize; i++){
//   //   count[Arr[i]]++;
//   //   cout << "LOL this is " << Output[Arr[i]] << endl;
//   // }
//   //
//   // for(int i = 1; i <= arraySize; i++){
//   //   cout << "Before " << Output[i] << endl;
//   //   count[i] += count[i - 1];
//   //   cout << "After " << Output[i] << endl;
//   // }
//   //
//   // for(int i = arraySize - 1; i >= 0; i--){
//   //   Output[count[Arr[i]] - 1] = Arr[i];
//   //   --count[Arr[i]];
//   // }
//
//
//
//   for(int i = 0; i < arraySize; ++i){
//     Arr[i] = Output[i];
//   }
//
// }
//
//
// void radixSort(int Arr[], int arraySize){
//   //int Barr[d];
//
//   for(int i = 1; i < arraySize;i++){
//     countingSort(Arr, arraySize, 1);
//   }
// }
print func
// for(int i = 0; i < arraySize; i++){
// 		cout << Arr[i] << ";";
//     while (i < 10){
//       cout << endl;
//     }
//
//   }
//     //cout << endl;




*/
