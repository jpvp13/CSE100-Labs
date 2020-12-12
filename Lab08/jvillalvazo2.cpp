//Lab08
/*Resources
(1) https://thispointer.com/different-ways-to-initialize-a-list-in-c/
(2) https://www.cs.upc.edu/~jordicf/Teaching/programming/pdf4/IP10_Matrices-4slides.pdf
(3) https://www.geeksforgeeks.org/vector-in-cpp-stl/
(4) https://www.geeksforgeeks.org/vector-of-vectors-in-c-stl-with-examples/
(5) https://www.geeksforgeeks.org/passing-vector-function-cpp/#:~:text=N%20natural%20numbers-,Passing%20vector%20to%20a%20function%20in%20C%2B%2B,because%20function%20has%20a%20copy.
(6) Introduction to Algorithms 3rd edition
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;
//global variable will be used in all functions
int size;
vector<vector<int> > m; //creates vector of vector m
vector<vector<int> > s; //creates vector of vector s

                                      //use of & is used when passing as reference, quicker than making new copy of the vector in this func
void matrix_Chain_Order(int A[],vector<vector<int> > &m, vector<vector<int> > &s){
  int n = m.size(); //sets n to the length of p


  for(int i = 1; i < n; i++){
    m[i][i] = 0;  //initialized matrix in [i][i] to 0
  }
  for(int x = 2; x < n; x++){   //chain length
    for(int i = 1; i < (n - x + 1); i ++){
      int j = i + x - 1;
      m[i][j] = 123456789;  //max value
      for(int k = i; k <= (j - 1); k++){
        int q = m[i][k] + m[k + 1][j] + (A[i-1]*A[k]*A[j]);  //max number of multiplications
        if(q < m[i][j]){
          m[i][j] = q;
          s[i][j] = k;
        }
      }
    }
  }
  //can not return anything since return can only take 1 input
  //return p[m[i,j],s[i,j]];
}







void print_Opt_Parens(vector<vector<int> > s,int i,int j){
  if(i == j){
    cout << "A" << (i - 1);
  } else{
    cout << "(";
    print_Opt_Parens(s, i, s[i][j]);
    print_Opt_Parens(s, s[i][j] + 1, j);
    cout << ")";
  }

}




int main(){
  cin >> size;

  int A[size];

  if(size >= 1){
  for(int i = 0; i <= size; i++){
    cin >> A[i];  //reads the values after size if established
  }

  //creating matricies by use of a vector of a vector with the sizes of the matricies (used these in CSE30 project, but with 2D Arrays)
  vector<vector<int> > m(size + 1, vector<int>(size + 1, 0));
  vector<vector<int> > s(size + 1, vector<int>(size + 1, 0));
  //vector<int> p(size + 1);


  // if(size >= 1){
  //     for(int i = 0; i < size; i++){
  //       for(int j = 0; j < size; j++){
  //      p.push_back(i,j);
  //    }
  // }

  matrix_Chain_Order(A, m, s);
  cout << m[1][size] << endl;

  print_Opt_Parens(s, 1, size);
  cout << endl;

  }
}



/*
*************************
Code Graveyard
*************************






*/
