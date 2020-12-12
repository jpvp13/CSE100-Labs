//Reference Material:
//https://www.softwaretestinghelp.com/merge-sort/
//Introduction to Algorithms 3rd edition psuedo starting on page 30

#include <iostream>

using namespace std;
//this is the final code, clean up, alter things and review the flow.

	//p -> x
	//q -> y
	//r -> z

		//merge(A, p, q, r)
void merge(int Arr[], int left, int y, int right) {


	int n1 = y - left + 1;
	int n2 = right - y;


	int LArr[n1], RArr[n2];


	for(int i = 0; i < n1; i++){
		LArr[i] = Arr[left + i];
	}

	for(int j = 0; j < n2; j++){

		RArr[j] = Arr[y + 1 + j];
	}


	int i = 0;
	int j = 0;

	int k = left;
	//this keeps track to of what index we are in within the length of the left or right array
	while (i < n1 && j < n2){

		//starting indecies for each of these sub-arrays
		if(LArr[i] <= RArr[j]){

			//if value at index Larr[i] is less than or equal to RArr[j] then the value of Arr[k] is updated to whatever LArr[i]
			Arr[k] = LArr[i];
			i++;
			}
		else{

			Arr[k] = RArr[j]; //complete opposite of above. Value of Arr[k] is updated with RArr[j]
			j++;
			//k++;
			}
			k++; //since we want to compare the second array with the first, we need to update k so that it iterates within the right sub-array
			}

		while(i < n1){
			//this fills in the left array with whatever the value is as long as i is less than the total length (total amount of elements)
			Arr[k] = LArr[i];
			i++;
			k++;

			}
			//this fills in the right array with whatever the value is as long as j is less than the total length (total amount of elements)

		while(j < n2){
			Arr[k] = RArr[j];
			j++;
			k++;


	}
}

//MERGE-SORT(A, p, r)
void mergeSort(int Arr[],int left, int right){
		//cout << "HELLOO " << endl;

	if(left < right){

		//cout << "Debug Step " << endl;
		//this gives us the middle of the array
		int y = (right + left) / 2;

		//this creates left subarray
		mergeSort(Arr, left, y);

		//this creates right subarray
		mergeSort(Arr, y + 1, right);

		//	adds the two sub-arrays togther
		merge(Arr, left, y ,right);

		//cout << "HELLO, Inside Mergesort loop " << endl;
	}
}

void printArray(int Arr[], int arraySize){
	for(int i = 0; i < arraySize; i++){
		cout << Arr[i] << ";";
	}
}


int main() {
//x, y, z are counting variables

	int arraySize;
	//cout << "Step 1: " << endl;

	//p ->x
	//q ->y
	//r ->z

	// Get the size of the sequence
	cin >> arraySize;  //from lab 00
	int Arr[arraySize];



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
}
