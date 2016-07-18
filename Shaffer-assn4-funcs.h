//*************************************************************************************** 
// CODE FILENAME:   Shaffer-assn4-funcs.h 
// DESCRIPTION:     Contains assigned sort and main utility function prototypes 
// CLASS/TERM:      CS 372 - 2014 Spring 8 Week 1 
// DESIGNER:        Katherine Shaffer 
// FUNCTIONS:       insertionSort - Performs an insertion sort
//					mergeSort - Performs a merge sort
//					merge - The merge operation of the merge sort
//					getChoices - Reads in and validates user menu choices
//					isSorted - Returns true/false if the array is sorted
//					getAverage - Returns the average for a passed results array
//					convertMenuChoice - Converts menu choice from char to integer for passing
//										to executeSort and displayAverages.
//                  getRandomInt - Generates 100,000 random numbers between 1
//								   and 30,000 and places them into two 100,000 
//								   element arrays.
//*************************************************************************************** 
#ifndef SHAFFER_FUNCS_H 
#define SHAFFER_FUNCS_H 
  
// Main Utility Functions
void getChoices(char &choice1, char &choice2, int &numSorts);
bool isSorted(int array[]);
double getAverage(int arraySize, int resultsArray[]);
int convertMenuChoice(char characterChoice);
void getRandomInt(int array1[], int array2[]);

// Sorting Functions 
void insertionSort(int array[]);
void mergeSort(int array[], int low, int high);


// Sorting Utility Functions 
void merge(int array[], int temp[], int low, int mid, int high);
  
#endif
