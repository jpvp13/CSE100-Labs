//Lab03
//Created by John Paul Villalvazo on 7/4/2020
/*
Resources:
(1) Introduction to Algorithms 3rd edition Starting around page 72
(2) Use of slides from lecture (Lecture-04(1)-Max-Subarray-Matrix-Multiplication.pdf)
(3) https://www.geeksforgeeks.org/maximum-subarray-sum-using-divide-and-conquer-algorithm/

(4) https://stackoverflow.com/questions/22197030/what-is-an-undeclared-identifier-error-and-how-do-i-fix-it
(^^was given this error due to having mispelled functions and incorrect use of initialization^^^^)
*/

#include <iostream>
using namespace std;



// A utility funtion to find maximum of two integers
int max(int x, int y) { //refer to line 6
  return (x > y)? x : y; }

// A utility funtion to find maximum of three integers
int max(int x, int y, int z) { //refer to line 6
  return max(max(x, y), z); }

  int Max_Crossing_sum(int Arr[], int low, int mid, int high){
    int left_sum = -123456789;
    int sum = 0;

    int max_left;
    int max_right;

    for(int i = mid; i >= low; i--){
      sum = sum + Arr[i];
      if(sum > left_sum){
        left_sum = sum;
        max_left = i;
      }
    }
    int right_sum = -123456789;
    sum = 0;

    for(int j = mid + 1; j <= high; j++){
      sum = sum + Arr[j];
      if(sum > right_sum){
        right_sum = sum;
        max_right = j;
      }
    }
  return max(max_left, max_right, left_sum + right_sum);
  }

int find_Max_sum(int Arr[], int low, int high){

  int left_sum;
  int right_sum;
  int combined;



  if(high <= low){
    return max(Arr[low],low,high);
  }

  int mid = ((low + high)/2);

  left_sum = find_Max_sum(Arr, low, mid);
  right_sum = find_Max_sum(Arr, mid + 1, high);

  combined = Max_Crossing_sum(Arr, low, mid, high);


  if(left_sum >= right_sum && left_sum >= combined){
    return left_sum;
  }
  else if(right_sum >= left_sum && right_sum >= combined){
    return right_sum;
  }
  else{
    return combined;
  }
}

int main(){

int arraySize;
cin >> arraySize;  //from lab 00
int Arr[arraySize];

for(int i = 0; i < arraySize; i++){ //from lab00
  cin >> Arr[i]; //from lab00
  //cout << Arr[i] << " Array printout  " << endl;
}

int total = find_Max_sum(Arr, 0, arraySize - 1);

//cout << "Maximum contiguous sum is " << total << endl;
cout << total;
}

/*
Test Code
***********************************
  //try if(low == high)



*/
