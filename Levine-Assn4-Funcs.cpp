//*********************************************************************
// CODE FILENAME: 	Levine-assn4-funcs.cpp
// DESCRIPTION:   	Contains assigned sort and main functions
// CLASS/TERM: 		CS 372 - 2014 Spring 8 Week 1
// DESIGNER: 		Josh Levine
// FUNCTIONS: 		selectionSort - Perform a selection sort
//					quickSort - Perform a quick sort
//					partition - Identify a pivot for the quick sort
//**********************************************************************
#include <iostream>
#include "Levine-Assn4-Funcs.h"
#include "LevineShafferGreear-Assn4-Common.h"
using namespace std;

// ******************************************************************************
// FUNCTION: 		partition
// IMPLEMENTED BY: 	Joshua Levine
// DESCRIPTION: 	Partitions an array and returns a pivot for the quickSort
//
// INPUT:
//  Parameters: 	someData[] - The array to find a pivot for
//	   		    	low - integer indicating the low end of the range
//              	High - integer indicating the high end of the range
// 
// RETURNS:
//
// Parameters: 		high - The selected pivot point
//
// Calls to: 		NONE
// ******************************************************************************
int partition(int someData[], int low, int high)
{
	int pivot = someData[high];
	
	while (low < high)
	{
		while (someData[low] < pivot)
			low++;
		
		while (someData[high] > pivot)
			high--;
		
		if (someData[low] == someData[high])
			low++;
		else if (low < high)
		{
			int temp = someData[low];
			someData[low] = someData[high];
			someData[high] = temp;
		}
	}
	
	return high;
}

// ******************************************************************************
// FUNCTION: 		quickSort
// IMPLEMENTED BY: 	Joshua Levine
// DESCRIPTION: 	Performs a quick sort on someData[]
//
// INPUT:
//  Parameters: 	someData[] - The array to sort (quickly)
//	   		    	low - integer indicating the low end of the range
//              	High - integer indicating the high end of the range
// 
// RETURNS:
//
// Parameters: 		NONE
//
// Calls to: 		Partition, Recursively to quickSort
// ******************************************************************************
void quickSort(int someData[], int low, int high)
{			
	if (low < high)
	{
		int mid = partition(someData, low, high); 
		quickSort(someData, low, mid - 1);
		quickSort(someData, mid + 1, high);
	}
}

// ******************************************************************************
// FUNCTION: 		selectionSort
// IMPLEMENTED BY: 	Joshua Levine
// DESCRIPTION: 	Performs a selection sort on someData[]
//
// INPUT:
//  Parameters: 	someData[] - The array to sort (selectionally)
// 
// RETURNS BY REFERENCE:
//
// Parameters: 		someData[] - Sorted
//
// RETURNS:
//
// Parameters: 		NONE
//
// Calls to: 		NONE
// ******************************************************************************
void selectionSort(int someData[])
{
	int 	first = 0,
	  		temp = 0,
	  		length = MAX_INTS;
	  	
    for (int r = length - 1; r > 0; r--)
    {
        first = 0;
    	for (int s = 1; s <= r; s++)
        {
        	if (someData[s] > someData[first])
            	first = s;
        }
        temp = someData[first];
        someData[first] = someData[r];
        someData[r] = temp;
     }

}

// ******************************************************************************
// FUNCTION: 		displayArray
// IMPLEMENTED BY: 	Joshua Levine
// DESCRIPTION: 	Displays an array for validation purposes (NOT ACTIVELY USED)
//
// INPUT:
//  Parameters: 	someData[] - The array to display
// 
// OUTPUT:			The output for the current form of someData[] array
//  				
// RETURNS:
//
// Parameters: 		NONE
//
// Calls to: 		NONE
// ******************************************************************************
void displayArray(int someData[])
{
	for (int k = 0; k < MAX_INTS; k++)
		cout << someData[k] << "\t";
	cout << "\n";
}
