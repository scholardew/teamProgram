//*********************************************************************
// CODE FILENAME: 	LevineShafferGreear-assn4-common.h
// DESCRIPTION:   	Contains constant, type and enum definitions for the main
//					program
// CLASS/TERM: 		CS 372 - 2014 Spring 8 Week 1
// DESIGNER: 		Josh Levine, Katherine Shaffer, Dew Greear
// FUNCTIONS: 		NONE
//**********************************************************************
#ifndef LEVINESHAFFERGREEAR_ASSN4_COMMON_H
#define LEVINESHAFFERGREEAR_ASSN4_COMMON_H
#include <string>
#include "Shaffer-Assn4-Funcs.h"
#include "Greear-Assn4-Funcs.h"
#include "Levine-Assn4-Funcs.h"

const int MIN_INT_VALUE = 1; 								// Lower boundary for random integers 
const int MAX_INT_VALUE = 30000;							// Upper boundary for random integers 
const int MAX_INTS = 100000;								// Number of integers per array
const int NUM_ITER_SORTS = 4;								// Number of iterative sort functions
const int NUM_RECURS_SORTS = 2;								// Number of recursive sort functions
const int TOTAL_SORTS = NUM_ITER_SORTS + NUM_RECURS_SORTS;	// Total number of sorts
const int RETURN_ERROR = 1;									// Program terminating abnormally - Sort not valid

// When do the iterative functions stop on the menu?
const int ITERATIVE_BOUNDARY = 4;

const char EXIT_CODE = 'E';									// Exit menu choice

// Function pointer typedefs
typedef void (*iterSortPtrType)(int[]);  
typedef void (*recursSortPtrType)(int [], int, int);

// Function pointer array definitions
// Iterative sort function pointer array
const iterSortPtrType iterSortFuncs[NUM_ITER_SORTS] =		{&bubbleSort,
															 &insertionSort,
															 &selectionSort,
															 &shellSort};

// Recursive sort function pointer array
const recursSortPtrType recursSortFuncs[NUM_RECURS_SORTS] = {&mergeSort,
															 &quickSort};
															 
// ZERO
const int ZERO = 0;

// Menu choice constant array
const char MENU_ITEMS[TOTAL_SORTS + 1] = {'B', 'I', 'S', 'H', 'M', 'Q', 'E'};

// Used std:: to avoid using the "using namepsace std;" inside of a header file. 
// Doing so would force any other program to use that namespace by default
const std::string MENU_DESCRIPTIONS[TOTAL_SORTS + 1] = {"Bubble Sort", "Insertion Sort", "Selection Sort", "Shell Sort", "Merge Sort", "Quick Sort", "Exit program"};

#endif
