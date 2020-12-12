/*
This is my attempt at full pseudo-code
*/
#include <iostream>

using namespace std;


//merge function that will do all the heavy lifting with the arraySize
void merge(int Arr[], int left, int mid, int right){


  int n1 = mid - left + 1;
  int n2 = right - mid;

  int Larr[n1];
  int Rarr[n2];


  for(int i = 0; i < n1; i++){

    Larr[i] = Arr[left + i ];
    //cout << "left array: " << Larr[i] << endl;
    //cout << "Left Index: " << i << endl;
  }

  for(int j = 0; j < n2; j++){

    Rarr[j] = Arr[mid + 1 + j];
    //cout << "Right array: " << Rarr[j] << endl;
    //cout << "Right Index: " << j << endl;
  }


  int i = 1;
  int j = 1;
//while(i < n1 && j < n2){
  //while (i < n1 && j < n2){

    for(int k = left; k < right; k++){

      cout << "Value of left: " << left << endl;
      if(Larr[i] <= Rarr[j]){
        Arr[k] = Larr[i];
        i++;
      }
      else{
        Arr[k] = Rarr[j];
        j++;
      }
      cout << "Value of k " << k <<endl;
      left++;

/*
    while(i < n1){
    //this fills in the left array with whatever the value is as long as i is less than the total length (total amount of elements)
      Arr[k] = Larr[i];
      i++;
      k++;

      }

    while(j < n2){

      Arr[k] = Rarr[j];
      j++;
      k++;
      }
      */
    }
  }
//}
//mergeSort will recursively call itself and will be building the left and right hand side of the original array
void mergeSort(int Arr[] , int left, int right){
  if(left < right){
    int mid = ((right + left)/2);

    mergeSort(Arr, left, mid);
    mergeSort(Arr, mid + 1, right);
    merge(Arr, left, mid, right);

  }
}


void printArray(int Arr[], int arraySize){
  for(int i = 0; i < arraySize; i++){
  		cout << Arr[i];
  		cout << ";";
  }
}


int main(){

  int arraySize;
  cout << "Step 1: " << endl;

  //p ->x
  //q ->y
  //r ->z

  // Get the size of the sequence
  cin >> arraySize;  //from lab 00
  int Arr[arraySize];



   // Read the sequence
    for(int i = 0; i < arraySize; i++){ //from lab00
      cin >> Arr[i]; //from lab00
      cout << Arr[i] << " Array printout  " << endl;
    }

  //cout << "Post read sequence:  " << endl;
  //num = arraySize;

  mergeSort(Arr, 0, arraySize - 1);

  //cout << "Post mergeSort Call: " << endl;

  printArray(Arr, arraySize);


}
