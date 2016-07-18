//***************************************************************************************
// CODE FILENAME: 	Levine-assn4-funcs.h
// DESCRIPTION:   	Contains assigned sort and main function prototypes
// CLASS/TERM: 		CS 372 - 2014 Spring 8 Week 1
// DESIGNER: 		Josh Levine
// FUNCTIONS: 		selectionSort 		- Perform a selection sort
//					quickSort 			- Perform a quick sort
//					partition 			- Identify a pivot for the quick sort
//***************************************************************************************
#ifndef LEVINE_FUNCS_H
#define LEVINE_FUNCS_H

// Sorting Functions
void quickSort(int someData[], int low, int high);
void selectionSort(int someData[]);

// Sorting Utility Functions
int partition(int someData[], int low, int high);
void displayArray(int someData[]);

#endif
