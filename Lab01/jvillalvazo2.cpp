//Lab01_ TEST


#include <iostream>

using namespace std;

int main(int argc,char **argv) {
	
	
	int* Arr;
	int arraySize, temp, b, i, z, num; //this initializes all the variables i will use in this code
	

  // Get the size of the sequence
	cin >> arraySize;	//from lab00
	Arr = new int[arraySize];	//from lab00
	
	
  // Read the sequence
  	for(i = 0; i < arraySize; i++){ //from lab00
	cin >> Arr[i];
		
	}
	
	cout << "Number :" << arraySize << endl;
	
	// Insertion
	
	for(i = 1; i < arraySize; i++){
		
		temp = Arr[i];
		b = i - 1;
		
		//cout << "Initial B: " << b << endl;
		//cout << "initial Temp: " << temp << endl;
		//cout << "Initial Arr[b] " << Arr[b] << endl;
		
		while (b >= 0 && Arr[b] > temp){
			//temp = Arr[b];
			Arr[b + 1] = Arr[b];
			
			b = b - 1;
		}
			
		Arr[b + 1] = temp; 
			
			
						//output
		for(z = 0; z <= i; z++){
			cout << Arr[z] << ";";
		}
			cout << endl;
			
	}
			
						
  	// Free allocated space
 	 delete[] Arr;
}



//Test Code
	/*
			if(b >= 0){
			Arr[b] = temp;
			temp = Arr[b];
			b = b+1;
			//cout << "Arr[b] " << Arr[b] << endl;
			
							//print
				for(i = 0; i < totSize; i++){
					cout << Arr[i] << ";" << endl;
				}	
				//cout << "Post B: " << b << endl;		
				//cout << "Post Arr[b] : " << Arr[b] << endl;	
				cout << "=======================================" << endl;
			
				} else{
					break;
					}
					*/
