#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cctype>
#include <string>
#include "LevineShafferGreear-Assn4-Common.h"
#include "Greear-Assn4-funcs.h"

using namespace std;

//*******************************************************************************************************************
//Dewey Greear
//FUNCTION:		displayMenu
//DESCRIPTION:  This function displays a menu listing the different sort functions for
//              the user to choose from.
//*******************************************************************************************************************
void displayMenu()
{
	cout << "  Choose two sorts you wish to compare:" << endl;
	for(int i = 0; i < TOTAL_SORTS + 1; i++) {
		cout << setw(10) << MENU_ITEMS[i] << " = " << MENU_DESCRIPTIONS[i] << endl;
	}//end for

	cout << endl << "  Enter two letter choices (or EE to exit) : " ;
	return;
}//end displayMenu

//****************************************************************************************************************************
//PROGRAMMER:	Dewey Greear
//FUNCTION:		bubbleSort
//DESCRIPTION:  This function takes in an array of 100000 random numbers and sorts the list in ascending order using
//              the bubble sort.
//PARAMETERS:   int array[] - This is the initial array passed in containing the unsorted list of 100000 numbers
//****************************************************************************************************************************
void bubbleSort(int array[])
{
	int temp;
	int currentIdx;
	bool sorted = false;
	int lastIdx = MAX_INTS;
	while(!sorted){
		sorted = true;
		currentIdx = 0;
		while(currentIdx < lastIdx - 1){
			if(array[currentIdx] > array[currentIdx + 1]){
				temp = array[currentIdx + 1];
				array[currentIdx + 1] = array[currentIdx];
				array[currentIdx] = temp;
				sorted = false;
			}//end if
			currentIdx++;
		}//end inner while
		lastIdx--;
	}//end outer while
	return;
}//end bubbleSort

//****************************************************************************************************************************
//PROGRAMMER:	Dewey Greear
//FUNCTION:		shellSort
//DESCRIPTION:  This function takes in an array of 100000 random numbers and sorts the list in ascending order using
//              the shellSort.
//PARAMETERS:   int array[] - This is the initial array passed in containing the unsorted list of 100000 numbers
//****************************************************************************************************************************
void shellSort(int array[])
{
	int temp,
		increment,
		currentIdx,
		nextIdx;	
		
	increment = MAX_INTS / 2;
	while(increment != 0){
		for(currentIdx = increment; currentIdx <= MAX_INTS - 1; currentIdx++){
			temp = array[currentIdx];
			nextIdx = currentIdx - increment;
			while(nextIdx >= 0 && temp < array[nextIdx]){
				array[nextIdx + increment] = array[nextIdx];
				nextIdx -= increment;
			}//end while
			array[nextIdx + increment] = temp;
		}//end for
		increment /= 2;
	}//end while
	return;		
}// end shellSort

//**************************************************************************************************
//PROGRAMMER  :	Dewey Greear
//FUNCTION    :	executeSort
//DESCRIPTION : This function takes in an unsorted array and calls the appropriate sort function
//              using function pointers to sort the array
//PARAMETERS  : int array[] - unsorted array containing 100000 numbers
//              int choice  - this is an int designated for the user selected sort function that 
//                            will be performed.
//CALLS TO:     bubbleSort, shellSort, insertionSort, mergeSort, quickSort, selectionSort
//**************************************************************************************************
void executeSort(int array[], int choice)
{
	recursSortPtrType recursivePtr;  	//creates pointer for recursive sorts
	iterSortPtrType iterativePtr;		//creates pointer for iterative sorts
	
	if(choice >= ITERATIVE_BOUNDARY){ 	//if true then sort is recursive
		recursivePtr = recursSortFuncs[choice - ITERATIVE_BOUNDARY]; //resets choice from 4 or 5 to be 0 or 1 in order to fit the typedef 0 = merge; 1 = quick
		recursivePtr(array, ZERO, MAX_INTS - 1);	  //calls the selected recursive sort
	}//end if
	
	else{									
		iterativePtr = iterSortFuncs[choice]; 
		iterativePtr(array);                  //calls the selected iterative sort
	}//end else

}//end executeSort

//**********************************************************************************************************************
//Dewey Greear
//FUNCTION:		displayAverage
//DESCRIPTION:	This function outputs the results of the time, and the average time, it took each sort
//              to put 100000 random integers into ascending order.
//INPUT:
//	PARAMETERS:
//				int resultsArray1 - this holds the elapsed time for the first sort that was selected
//			    int resultsArray2 - this holds the elapsed time for the second sort that was selected
//				int choice1		  - this holds an integer value that lets the function know which sort to perform first
//              int choice2       - this holds an integer value that lets the function know which sort to perform second
//              int numSorts      - this holds the number of sorts the user has chosen each sort to perform.
//CALLS TO:		getAverage
//**********************************************************************************************************************
void displayAverage(int resultsArray1[], int resultsArray2[], int choice1, int choice2, int numSorts)
{
	double average;

	average = getAverage(numSorts, resultsArray1);
	cout << endl << "  SORTING RESULTS" << endl << "  ---------------" << endl;
	cout << setw(20) << MENU_DESCRIPTIONS[choice1] << setw(12) << fixed << showpoint << setprecision(1) << average;
	average = getAverage(numSorts, resultsArray2);
	cout << endl << setw(20) << MENU_DESCRIPTIONS[choice2] << setw(12) << fixed << showpoint << setprecision(1) << average;
	return;
}
