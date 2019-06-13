//Created by Brandon Barnes

//Find the leftmost subarray of an array that provides the given sum
//Leftmost considered to be array which has starting element farthest to the left
//Array may have positive only
//subarray may be of length [1,array.size()]



#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>


using namespace std;


void subarraySum(){
	int sizeArray = 1;
	int inputSum = 1;
	
	while(sizeArray && inputSum){
		cout << "Provide size of array as an int" << endl;
		cout << "Input 0 as value to exit" << endl;
		cin >> sizeArray;
		cout << "Your input: " << sizeArray << endl;
		
		cout << "Provide sum to search for" << endl;
		cout << "Input 0 as value to exit" << endl;
		cin >> inputSum;
		cout << "Your input: " << inputSum << endl;
		
		if(sizeArray < 0 || inputSum < 0){ //in a proper end user program, would include max int/min int checks 
			cout << "invalid input, please have non-negative values for inputs" << endl;
			continue;
		}
		if(sizeArray == 0 || inputSum == 0){
			cout << "Input of 0 given, now exiting" << endl;
		}
		else{
			int* testArray = (int*) malloc(sizeArray);
			int* sumArray = (int*) malloc(sizeArray);
			string arrayInput;
			stringstream ss;
			bool sumFound = false; //Need a false for reseting purposes
			
			getline(cin, arrayInput); //this is used to clear out cin for array input
			
			cout << "please enter array data as space seperated integers" << endl;
			getline(cin, arrayInput);
			ss << arrayInput;
			cout<<endl;
			int temp = 0;
			int iterator = 0;
			
			//set to -1 for debugging purposes
			int startingElement = -1; 
			int endingElement = -1;
			
			while(ss>>temp && iterator < sizeArray){
				testArray[iterator] = temp;
				iterator++;
			}
			
			//run time is O(n^2) because of having to check each subarray in worst case
			for(int i = 0; i<sizeArray && (!sumFound); i++){ 
			//Only positive numbers, so can truncate computation
			//Because there is no defined window, must check subarrays of all sizes
				sumArray[i] = testArray[i];
				if(sumArray[i]==inputSum){
					sumFound=true;
					startingElement = i;
					endingElement = i;
				}
				if(sumArray[i]>inputSum){
					continue;
				}
				for(int j=i+1; j<sizeArray &&(!sumFound);j++){
					sumArray[j] = sumArray[j-1]+testArray[j];
					if(sumArray[j]==inputSum){
						sumFound=true;
						startingElement = i;
						endingElement = j;
					}
					if(sumArray[j] > inputSum){
						break;
					}
				}
			}
			if(sumFound){
				cout << "Sum found" << endl;
				cout << "Starting element at index: " << startingElement << endl;
				cout << "Ending element at index: " << endingElement << endl << endl;
			}
			else{
				cout << "no such subarray found" << endl << endl;
			}
			
			
			
			
			
			
			//Eventually
			delete testArray;
			delete sumArray;
		}
		
	}
}

int main(){
	subarraySum();
	return 0;
}