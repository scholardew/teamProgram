//********************************************************************* 
// CODE FILENAME:   Shaffer-assn4-funcs.cpp 
// DESCRIPTION:     Contains assigned sort and main utility functions 
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
//********************************************************************** 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "Shaffer-Assn4-funcs.h" 
#include "LevineShafferGreear-Assn4-Common.h" 
#include "Greear-Assn4-funcs.h"

using namespace std; 
 
///////////////////////////// MAIN UTILITY FUNCTIONS /////////////////////////////
  
/* ****************************************************************************** 
FUNCTION:        getChoices
IMPLEMENTED BY:  Katherine Shaffer 
DESCRIPTION:     
INPUT:  
Parameters: 
	int choice1 - user sort choice 1 as an int.
	int choice2 - user sort choice 2 as an int.
	int numSorts - The total number of sorts.
RETURNS:
Parameters: 
	bool goodInput - confirms valid input was received.
By Reference: 
	char choice1 - user sort choice 1 as a valid char.
	char choice2 - user sort choice 2 as a valid char.
	int numSorts - The total number of times to repeat the sorts.
CALLS TO: N/A

// ****************************************************************************** */
void getChoices(char &choice1, char &choice2, int &numSorts)
{
	bool validChoice1, validChoice2;
	
	while ((!validChoice1) || (!validChoice2))
	{
		validChoice1 = false;
		validChoice2 = false;
		displayMenu();
		cin >> choice1;
		cin >> choice2;
		
		choice1 = toupper(choice1);
		choice2 = toupper(choice2);
		
		for (int index = 0; index < TOTAL_SORTS; index++)
		{
			if (choice1 == MENU_ITEMS[index])
			{
				validChoice1 = true;
			}
			if (choice2 == MENU_ITEMS[index])
			{
				validChoice2 = true;
			}	
		}
		
		if ((choice1 == EXIT_CODE) && (choice2 == EXIT_CODE))
		{
			validChoice1 = true;
			validChoice2 = true;
		}
				
		if ((!validChoice1) && (!validChoice2))
		{
			cout << endl << "Those are not valid choices. Please try again. " << endl << endl;
		}		
			
	}	
}

/* ****************************************************************************** 
FUNCTION:        convertMenuChoice
IMPLEMENTED BY:  Katherine Shaffer 
DESCRIPTION: Converts menu choice from char to integer for passing to executeSort and displayAverages.
INPUT:
Parameters: char characterChoice - holds the character value of the user's menu choice.
RETURNS:
Parameters: int integerChoice - holds the integer value of the user's menu choice.
By Reference:  N/A
CALLS TO:  N/A
// ****************************************************************************** */
int convertMenuChoice(char characterChoice)
{	
	int returnValue = -1;

	for (int index = 0; index < TOTAL_SORTS; index ++)
	{
		if (characterChoice == MENU_ITEMS[index])
		{
			returnValue = index;
		}
	}	
	return returnValue;
}
/* ****************************************************************************** 
FUNCTION:        convertMenuChoice
IMPLEMENTED BY: Katherine Shaffer
DESCRIPTION: Generates 100,000 random numbers between 1 and 30,000 and places them
into two 100,000 element arrays.	
INPUT:
Parameters: 
int array1[]- to hold list of 100,000 random numbers.
int array2[]- to hold list of 100,000 random numbers, identical to int array1[].
RETURNS:
Parameters:
By Reference: array1[], array2[]
CALLS TO: N/A

// ****************************************************************************** */
void getRandomInt(int array1[], int array2[])
{
	int tempRandomInteger = 0;
	int counter = 0;
		
	for(int arrayPlace = 0; arrayPlace < MAX_INTS; arrayPlace++)
	{
		array1[arrayPlace] = rand() % MAX_INT_VALUE + MIN_INT_VALUE; // randomIntegerArray & the range
		array2[arrayPlace] = array1[arrayPlace];
	}
}
/* ****************************************************************************** 
FUNCTION: getAverage
IMPLEMENTED BY: Katherine Shaffer
DESCRIPTION: This function calculates the average time it took a sort to put 100000 random
integers into ascending order.
INPUT:
Parameters: 
int resultsArray -  This is the array that stores the time elapsed for each sort to complete.
int runCount- This holds the int amount of iterations the user chose each sort to perform.
RETURNS:
Parameters: int average - This is the average time that elapsed for each sort to complete.
By Reference: N/A
CALLS TO: N/A
// ****************************************************************************** */
double getAverage(int arraySize, int resultsArray[])
{
	double returnAverage = 0;
	
	for (int index = 0; index < arraySize; index++)
	{
		returnAverage = returnAverage + resultsArray[index];
	}
	returnAverage = returnAverage / arraySize;
	
	return returnAverage;
	
}
/* ****************************************************************************** 
FUNCTION: isSorted
IMPLEMENTED BY: Katherine Shaffer
DESCRIPTION: Determines if an int array sorted and returns true/false for sorted/not-sorted.
INPUT:
Parameters: int array[] - array being checked for valid sorting.
RETURNS:
Parameters: bool sorted - Boolean of true for sorted and false for not-sorted.
By Reference: N/A
CALLS TO: N/A
// ****************************************************************************** */
bool isSorted(int array[])
{
	bool returnValue = true;
	
	for (int index = 0; index < MAX_INTS - 1; index++)
	{
		if (array[index] > array[index+1])
		{	
			returnValue = false;
		}			
	}	
	

	return returnValue;	
}

///////////////////////////// SORTING FUNCTIONS ///////////////////////////// 

/* ****************************************************************************** 
FUNCTION: insertionSort
IMPLEMENTED BY: Katherine Shaffer
DESCRIPTION: This function takes in an array of 100000 random numbers and sorts the 
list in ascending order using the insertion sort.
INPUT:
Parameters: int array[] - This is the initial array passed in containing the unsorted
list of 100000 numbers.
RETURNS:
Parameters: 
By Reference: int array[] sorted in ascending order by insertion sort.
CALLS TO: N/A
// ****************************************************************************** */
void insertionSort(int array[])
{
	int count = 0;
	int tempCount;
	int tempTrailCount;
	int temp;
    
    for (count; count < MAX_INTS; count ++)
    {
		tempTrailCount = count - 1;
    	tempCount = count;
    	
    	while ((array[tempCount] <= array[tempTrailCount]) && (tempTrailCount >= 0))
    	{
    		
    	temp = array[tempCount];
    	array[tempCount] = array[tempTrailCount];
    	array[tempTrailCount] = temp;
    	
    	tempCount--;
    	tempTrailCount--;	
    	}  	
	}	
}
/* ****************************************************************************** 
FUNCTION: mergeSort
IMPLEMENTED BY: Katherine Shaffer
DESCRIPTION: This function takes in an array of 100000 random numbers and sorts the list 
in ascending order using the merge sort.
INPUT:
Parameters: int array[] - This is the initial array passed in containing the unsorted list
 of 100000 numbers.
int low - the lower bound of the array.
int high - the upper bound of the array.
RETURNS:
Parameters: 
By Reference: int array[] sorted in ascending order by merge sort.
CALLS TO: merge()
// ****************************************************************************** */
void mergeSort(int array[],  int low, int high)
{

  static int temp[MAX_INTS];
  int mid;

  if (high > low)
{
    mid = (low + high) / 2;
    mergeSort(array, low, mid);
    mergeSort(array, (mid+1), high);
    merge(array, temp, low, (mid+1), high);			
}	
}

///////////////////////////// SORTING UTILITY FUNCTIONS ///////////////////////////// 

/* ****************************************************************************** 
FUNCTION: merge
IMPLEMENTED BY: Katherine Shaffer
DESCRIPTION: Takes in an array with both the lower and upper half of the array sorted 
in ascending order and merges them into one final, sorted array. It does this by comparing 
the smallest elements of each half and inserting the smaller of the two into the new array first.
INPUT:
Parameters: 
int array[] - the array (with both halves sorted) to be merged.
int low - the lower bound of the array.
int mid - the pivot point of the array that separated the (sorted) lower half from the (sorted) upper half.
int high - the upper bound of the array.
RETURNS:
Parameters: 
By Reference: int array[] - the final array, sorted and merged with merge sort.
CALLS TO: N/A
// ****************************************************************************** */
void merge(int array[], int temp[], int low, int mid, int high)
{
  int i;	
  int lowEnd = (mid - 1);
  int tempPosition = low;
  int numberOfIntegers = (high - low + 1);

  while ((low <= lowEnd) && (mid <= high))
  {
    if (array[low] <= array[mid])
    {
      temp[tempPosition] = array[low];
      tempPosition += 1;
      low += 1;
    }
    else
    {
      temp[tempPosition] = array[mid];
      tempPosition += 1;
      mid += 1;
    }
  }

  while (low <= lowEnd)
  {
    temp[tempPosition] = array[low];
    low += 1;
    tempPosition += 1;
  }

  while (mid <= high)
  {
    temp[tempPosition] = array[mid];
    mid += 1;
    tempPosition += 1;
  }

  for (i=0; i < numberOfIntegers; i++)
  {
    array[high] = temp[high];
    high -= 1;
  }
	
}
