#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
  int arraySize;
  cin >> arraySize;  //from lab 00
  int Arr[arraySize];

  for(int i = 0; i < arraySize; i++){ //from lab00
    cin >> Arr[i]; //from lab00
    //cout << Arr[i] << " Array printout  " << endl;
  }

for(int i = 0; i < 10; i++){
int r = rand() % arraySize;
cout << "R:" << r << ";" << endl;
}
}
