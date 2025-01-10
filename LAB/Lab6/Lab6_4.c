#include<stdlib.h>
#include<stdio.h>
#include<string.h>
// Define the number of elements in the array
#define NUMELEMS 7
// Function prototype for finding the lexicographically smallest string
char* findMin(char** arrP,int arrSize);

int main(){
	// Initialize an array of string pointers
	char *a[] = {"Alona","Nir","Amina","Yosef","alice","Amos","bob"};
	int i;
    // Print each string in the array
	for(i=0; i<NUMELEMS; i++){
	   printf("%s\n", a[i]);
	}
	// Find and print the lexicographically smallest string
	printf("\n%s", findMin(a, NUMELEMS));

	return 0;
}
// Function to finds the lexicographically smallest string in an array of strings.
char* findMin(char** arrP,int arrSize){
	// Initialize temp to the first element of the array
	char *temp = arrP[0];

	  // Loop through the array starting from the second element
	  for (int i=0;i<arrSize;i++){
		// If the current element is smaller than temp, update temp
		if (strcmp(arrP[i], temp)<0){
		temp = arrP[i];
		}
	  }
	  // Return the smallest string found
	  return temp;

}


