//Lab06
/*
Resources
(1)https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/
(2) https://www.geeksforgeeks.org/list-cpp-stl/
(3) http://www.cplusplus.com/reference/iterator/
(4) https://en.cppreference.com/w/cpp/container/list
(5) https://appdividend.com/2019/06/12/cpp-list-tutorial-with-example-list-in-c-standard-template-library-stl/

*/
#include <iostream>
#include <list>
#include <array>
#include <algorithm>


using namespace std;
list<int> *T; //this is initialized here because it needs to be a global variable

int m;    //int m holds number of elements




int hashfunc(int key){
      //from PDF and Book, returns h(k) = k % m
  return key % m;
}

void insertionHash(int key){
            //using the has hashfunc will give the position of T.
  T[hashfunc(key)].push_front(key);   //push_front(key) adds a new element
                                      //(value key) to the front of the list
}



void SearchHash(int key){
  int track = 0;
  //this creates a variable that is actually a pointer that we can use to help iterate our loop
  list<int>::iterator i;
          //begin() points to the first element in list T
  for(i = T[hashfunc(key)].begin(); i != T[hashfunc(key)].end(); i++){
                                          //end() points at the "last element" in the list
    //i used * with due to this being a pointer call towards i.
    if(*i == key){
      cout << key << ":FOUND_AT" << hashfunc(key) << "," << track << ";\n";
      return;
    }
    track++;
  }
  cout << key << ":NOT_FOUND;\n";

}

//T[<-hashfunc(key)]<-begin()

void deleteHash(int key){
  int track = 0;
  //this creates a variable that is actually a pointer that we can use to help iterate our loop
  list<int>::iterator i;
          //begin() points to the first element in list T
  for(i = T[hashfunc(key)].begin(); i != T[hashfunc(key)].end(); i++){
                                          //end() points at the "last element" in the list
    //i used * with due to this being a pointer call towards i.
    if(*i == key){
      i = T[hashfunc(key)].erase(i);  //erase(i) will erase the value at index i in the list
      cout << key << ":DELETED;\n";
      return;
    }
    track++;
//until T[j] == NULL || i == int m
}
cout << key << ":DELETE_FAILED;\n";
}


void printHash(){
  //since m is the size of the list, we can use as the length
  for(int i = 0; i < m; i++){
    cout << i << ":";
    //for(auto x : T[i]){
    //this allows the compiler to initialize T[i] to be used as a iterator in this loop
    //and will not throw a error by comparing a int to a pointer
    for(int x : T[i]){
      cout << x << "->";
    }
    cout << ";" << endl;
  }

}

int main(){

  //cout << "Enter a size: ";
  //int value;    //this is the value that goes with action


  cin >> m;  //gets total size of array
  int key;  //this is the location of action


  T = new list<int>[m]; //Declare list T by reference


  char letter;

  //we will only deal postive numbers
  while(m >= 0 && letter != 'e'){
    //cout << "Choose a action: ";
    cin >> letter;


  switch(letter){

      //Insertion
  case 'i':

        cin >> key;
        insertionHash(key);
        break;


      //Deletion
  case 'd':
        cin >> key;
        deleteHash(key);
        break;


      //Search
  case 's':
        cin >> key;
        SearchHash(key);
        break;


      //Output
  case 'o':
        printHash();
        break;

    }
  }
}


//printHash(T, m);


/*
****************************
Code Grave Yard:
****************************
//template < typename T > void printList( const std::list< T > &listRef );
// class HashTable{
//   public:
//     int key;
//     Node *Hash;
// };

// int i = 0;
// if(i == T.length()){
//   int j = hashFunc(int key, int i);
//   if(T[j].value() == NUll){
//     T[j] = key;
//     return j;
//   }
//   else{
//     i = i + 1;
//   }
// }
// HashFunction

// int i = 0;
// //repeat
// while(i >= 0){
//   int j = hashfunc(key,i);
//   if(T[j].value() == NULL){
//     T[j] = key;
//     return j;
//   }
//   else{
//     i = i + 1;
//   }
// }
//until i == m
//error "Hash table overflow"

// int Chained_Hash_Delete(list <int> T, int Key){
//    int i = T[T.head()]
//    if(T.head() != NULL){
//        T.(head().next) = i.next;
//    else{
//        T.head() = T.head() + 1;
//      }
//    }
//    return i;
// }
//
//

*/
