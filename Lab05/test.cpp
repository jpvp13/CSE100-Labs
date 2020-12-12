#include <iostream>
#include <numeric>


using namespace std;

void countingSort(int *Arr[], int k, int numbers){
  int *Carr[k];
  int rowSize = 10;
  int count[10] = {0};

  for(int i = 0; i < k; i++){
    Carr[i] = 0;

    cout << "Initialize Carr to " << Carr[i] << " for idex " << i << endl;
  }




  for(int j = 1; j < k; j++){
    //int arr = Arr[j];
    //cout << "Value of arr: " << arr << endl;
    Carr[Arr[j] [numbers] % rowSize]++;
    //Carr[Arr[j]] = Carr[Arr[j]] + 1;
    //Carr[(Arr[j]/10) % 10]++;
    //cout << Carr[Arr[j]] << " is the value for Carr[Arr[]] for index " << j << endl;
  }





  for(int i = 1; i < rowSize; i++){
    count[i] = count[i] + count[i - 1];
    cout << "Carr[] is " << Carr[i] << endl;
  }




  for(int j = k - 1; j >= 0; j--){
    //Carr[Barr[(Arr[j] / 10) % 10] - 1] = Arr[j];

    Carr[count[Arr[j][numbers]% rowSize] - 1] = Arr[j];
    count[Arr[j][numbers] % rowSize]--;


    // Barr[Carr[Arr[j]]] = Arr[j];
    // Carr[Arr[j]] = Carr[Arr[j]] - 1;
    //Barr[Carr[Arr[j]]] = Arr[j];
    //Barr[(Arr[j] / 10) % 10]--;
    //Carr[Arr[j]]--;
    cout << "Output Carr" << endl;
  }

  for(int i = 0; i < k; i++){
    Arr[i] = Carr[i];
  }
}

void radixSort(int *Arr[], int d){
  //checks to see if inputted array is 0
  // if(d == 0){
  //   return;
  // }

  //int Barr[d];
  cout << "The size of Barr is " << Barr[d] << endl;
  //cout << "What is d here: " << d << endl;
  for(int i = 1; i <= d; i++){
    countingSort(Arr, d, i);

  }
}



void printRadix(int *Arr[], int arraySize){
  for(int i = 0; i < arraySize; i++){
    //for(int j = 0; j < Arr[i].size(); j++){
  		  cout << Arr[i] << ";";
        }
      //cout << "This is the " << i << " i have printed :(" << endl;
      cout << endl;
      }
      //cout << endl;
  //  }

int main (){
//   int arraySize;
//   cin >> arraySize;  //from lab 00
//   //vector<int> *Arr[arraySize];
//   int values;
//   for(int i = 0; i < arraySize; i++){
//     for(int j = 0; j < 10; j++){ //from lab00
//       cin >> values; //from lab00
//       Arr[i].push_back(values);
//       //cout << Arr[i] << " Array printout  " << endl;
//     }
// }

int arraySize;
cin >> arraySize;  //from lab 00
int Arr[arraySize];

for(int i = 0; i < arraySize; i++){ //from lab00
  cin >> Arr[i]; //from lab00
  //cout << Arr[i] << " Array printout  " << endl;
}

    //possibly arraySize - 1
  radixSort(Arr, arraySize);
  printRadix(Arr, arraySize);

  return 0;
}


//3 3 3 3 3 2 2 2 2 2
