/*
This is my attempt at full pseudo-code

Resource List:
~Introduction to Algorithms 3rd edition starting on pg.30
~https://stackoverflow.com/questions/12056912/how-to-implement-merge-sort-from-the-introduction-to-algorithms-by-cormen-and (assisted in a segmentation error due to wrong sized for loop in my code)
~https://www.softwaretestinghelp.com/merge-sort/
*/
#include <iostream>

using namespace std;



void merge(int** Arr[], int left, int mid, int right){

	int n1 = mid - left + 1;
	int n2 = right - mid;


//	cout << "******************* Print n1 :" << n1 << endl;

	int Larr[n1 + 1];
	int Rarr[n2 + 1];
	Larr[n1] = 123456789;
	Rarr[n2] = 123456789;

	for(int i = 0; i < n1; i++){
		Larr[i] = Arr[left + i];
//		cout << "left array: " << Larr[i] << endl;

		}
	for(int j = 0; j < n2; j++){

		Rarr[j] = Arr[mid + j + 1];
//		cout << "Right array: " << Rarr[j] << endl;
		}



	int i = 0;
	int j = 0;


	for(int k = left; k <= right; k++){
//		cout << " K Value " << k << endl;
		if(Larr[i] <= Rarr[j]){
			Arr[k] = Larr[i];
			i++;
			}
		else{
			Arr[k] = Rarr[j];
			j++;
			}
		//k++;
		}

	}

//mergeSort will recursively call itself and will be building the left and right hand side of the original array
void mergeSort(int Arr[] , int left, int right){

  if(left < right){
   int mid = ((left+right)/2);

    //cout << "Value of Mid " << mid << endl;
    //cout << "***************************";

    mergeSort(Arr, left, mid);

    mergeSort(Arr, mid + 1, right);

    merge(Arr, left, mid, right);

  }
}

void printArray(int Arr[], int size){
  for(int i = 0; i < size; i++){
  		cout << Arr[i];
  		cout << ";";
  }
}


int main(){

  int arraySize;
  //cout << "Step 1: " << endl;

  //p ->x
  //q ->y
  //r ->z

  // Get the size of the sequence
  cin >> arraySize;  //from lab 00
  int Arr[arraySize];

	//int size = sizeof(Arr)/sizeof(Arr[0]);

   // Read the sequence
    for(int i = 0; i < arraySize; i++){ //from lab00
      cin >> Arr[i]; //from lab00
      //cout << Arr[i] << " Array printout  " << endl;
    }

  //cout << "Post read sequence:  " << endl;
  //num = arraySize;

  mergeSort(Arr, 0, arraySize - 1);

  //cout << "Post mergeSort Call: " << endl;

  printArray(Arr, arraySize);
  return 0;


}


/*
Test Code
*************************************************
void merge(int Arr[], int left, int mid, int right){


  int n1 = mid - left + 1;
  int n2 = right - mid;

  int Larr[n1];
  int Rarr[n2];


  for(int i = 1; i < n1; i++){

    Larr[i] = Arr[left + i - 1 ];

    //cout << "Left Index: " << i << endl;
  }

  for(int j = 1; j < n2; j++){

    Rarr[j] = Arr[mid + j];
    //cout << "Right array: " << Rarr[j] << endl;
    //cout << "Right Index: " << j << endl;
  }

cout << "Left" << left << endl;
cout << "right" << right << endl;
  int i = 1;
  int j = 1;
  //int k = left;

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
      //cout << "Value of k " << k <<endl;
      k++;
	cout << "HELLO" << endl;
//
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
      //
    }
  }

  */
