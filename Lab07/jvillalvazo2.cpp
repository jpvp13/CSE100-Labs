//Lab07

//(1) https://www.geeksforgeeks.org/stdmax-in-cpp/
//(2) Introduction to algorithms 3rd edition
//(3) https://www.radford.edu/~nokie/classes/360/dp-rod-cutting.html
//(4) http://www.cs.ust.hk/mjg_lib/Classes/COMP3711H_Fall16/lectures/IntroDP_Handout.pdf

#include <iostream>
#include <vector> //potential use of vectos
#include <algorithm>   //using STL to use max()



using namespace std;

//global variables
int n;
int rodSize;



//combination of codes from book + trial and error

int cutRod(int price[],int rodSize,int r[], int cutOff[]){
  // int r[rodSize + 1]; //keeps track of optim value
  // int cutOff[rodSize + 1]; //keeps track of the cutoff value
  int q = -123456789;

  int maximum;
  r[0] = 0;
  //int i, j;

  if(rodSize == 0){ //checks to make sure that the there is an actual rod
    return 0;
  }

  for(int i = 1; i <= rodSize; i++){
    maximum = q; //maximum is a tracking variable for the length of the cuts
    //int q = -123456789;
    for(int j = 0; j < i; j++){
      if (maximum < price[j] + r[i - j - 1]){
          maximum = price[j] + r[i - j - 1];
          cutOff[i] = j + 1; //this tracks the place of the cut
      }
      //s[i] = Max + 1; //iterates optimal cut
    }
    r[i] = maximum;
  }

  cout << r[rodSize] << endl;

  return 0;
}




int main(){


  cin >> n;

  int price[n];
  int r[n + 1]; //keeps track of optim value
  int cutOff[n + 1]; //keeps track of the cutOff location

  //int cut[n];


  for(int i = 0; i < n; i++){
    cin >> rodSize;
    price[i] = rodSize;
  }


  //int cut[n + 1];

  cutRod(price, n, r, cutOff);  //this will find the max revenue and print it.


  while(n > 0){
    cout << cutOff[n] << " ";  //this will print out the optinal cuts
    n = n - cutOff[n];        //this will help iterate through all indicies to print the optimal cuts
  }

  cout << "-1" << endl;
  return 0;
}
/*
Code Graveyard
*******************

//#define max(x, y) (((x) > (y)) ? (x) : (y))
// int max(int price[], int n, int r[]){
//   int Max;
//
//   Max =
//
//
//
//   return Max;
// }

//this code also works to print out the maximum revenue,
//but is not updated to print the length of each cut

// int cutRod(int price[], int n){
//   if(n == 0){
//     return 0;
//   }
//   int q = -123456789;
//   for(int i = 1; i < n; i++){
//     q = max(q, price[i] + cutRod(price, n - i - 1));
//     rodSize = i;
//   }
//   return q;
// }



                                      //int r[]
// int memorizedCutRodAux(int price[], int n, int r[]){
//
//   int q;
//   cout << "Does this run?" << endl;
//   cout << r[n] << " <- Value of r" << endl;
//   cout << "Value of n -> " << n << endl;
//   if(r[n] >= 0){
//     return r[n];
//   }
//
//   cout << "Hellooooo?" << endl;
//
//   if(n == 0){
//     q = 0;
//     cout << "Test 1" << endl;
//   }
//   else{
//     cout << "Test 2" << endl;
//     cout << "WTF" << endl;
//     q = -123456789;
//       for(int i = 1; i < n; i++){
//         q = max(q, price[i] + memorizedCutRodAux(price, n - i, r));
//         cout << "hello, I am value of q -> " << q << endl;
//       }
//     }
//   r[n] = q;
//   return q;
// }




// int bottomUpCutRod(int price[], int n){
//   int r[n];
//   r[0] = 0;
//   int q;
//
//   for(int j = 1; j < n; j++){
//     q = -123456789;
//     for(int i = 1; i < j; i++){
//       q = std::max(q, price[i] + r[j - i]);
//       cout << "this is q  " << q << endl;
//     }
//     r[j] = q;
//   }
//   return r[n];
// }




//void cutRod(int p[],int n){
// int memorizedCutRod(int price[], int n){
//   int r[n];
//   for(int i = 0; i < n;i++){
//     r[i] = -123456789;
//   }
//   cout << "does it get here" << endl;
//   return memorizedCutRodAux(price, n, r);
//   // if(n == 0){
//   //   return 0;
//   // }
//   // int q = -123456789;
//   // for(int i = 1; i < n; i++){
//   //   q = max(q,p[i] + cutRod(p, n-1));
//   // }
//   // return q;
// }

// i = n;
// j = 0;
// while(rodSize > 0){       //transfers s[i] to cut that jumps adds 1 to itself for the idex
//   cout << cutOff[rodSize] << " ";  //continuingly updating the elements at which each peiece is cut
//   rodSize = rodSize - cutOff[rodSize];
// }
//cout << "It messes up here ?? -> " << r[n] << endl;
//rodSize = j; //will help with printing out the optimal cuts

*/
