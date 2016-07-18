//******************************************************************************
// FILENAME: LevineShafferGreear-assn4-prog.cpp
// DESCRIPTION: Program compares sorting algorithms and calculates average runtimes
//              for each algorithm. Compares two algorithms at a time
// CLASS/TERM:  CS372 / 8 WK Spring 1, 2014
// DESIGNERS:	Josh Levine, Katherine Shaffer, Dew Greear
// FUNCTIONS: main() - takes user input, performs basic calculations (runtimes)
//				and calls other processing functions
// ASSC FILES: Shaffer-assn4-funcs.h - prototypes for Katherine Shaffer's functions
//             Shaffer-assn4-funcs.cpp - functions by Katherine Shaffer
//			   Greear-Assn4-funcs.h	- prototypes for Dew Greear's functions
// 			   Greear-Assn4-Funcs.cpp - functions for Dew Greear
//             Levine-assn4-funcs.h - prototypes for Josh Levine's functions
//             Levine-assn4-funcs.cpp - functions by Josh Levine
//			   LevineShafferGreear-assn4-prog.cpp - Main program
//			   LevineShafferGreear-assn4-common.h - Global constants and types
//******************************************************************************
#include <iostream>                                         // for I/O
#include <locale>											// ToUpper
#include <cstddef>											// NULL
#include <cstdlib>                                          // for srand seeding 
#include <ctime>                                            // for time function
#include "Levine-Assn4-Funcs.h"								// Josh Levine's function prototypes
#include "Greear-Assn4-Funcs.h"								// Matt "Dew" Greear's prototypes
#include "Shaffer-Assn4-Funcs.h"							// Katie Shaffer's prototypes
#include "LevineShafferGreear-Assn4-Common.h"				// Global constants and typedefs

using namespace std;

int main() 
{	
	bool failed = false;									// Did a sort fail to validate properly?
	int firstRun = ZERO;										// Is this the first run of the program? 
	int randArray1[MAX_INTS]; 								// Random Integer Array 1
	int randArray2[MAX_INTS]; 								// Random Integer Array 2
	int *resultsArray1,										// Store runtime results for array 1
		*resultsArray2;										// Store runtime results for array 2
	int startTime = ZERO,									// Start time of sort routine
		endTime = ZERO,										// End time of sort routine
		totalTime = ZERO;									// Total time of sort
	int returnVal = ZERO;									// Return value for main, 1 if failed sort
	int runCounter = ZERO;									// How many sort loops have we conducted out of
															// 						user entered numSorts?
	int numSorts = ZERO;									// How many sorting iterations?
	char choice1, 											// First menu choice
		 choice2;											// Second menu choice

	// Seed random timer
	srand(time(NULL));
	
	// Main processing loop (until EE)
	do
	{
		// Display the menu and read user choices
		getChoices(choice1, choice2, numSorts);
	
		if (choice1 != EXIT_CODE && choice2 != EXIT_CODE)
		{
			// Increment firstRun so we know we can safely delete results arrays
			firstRun++;
			
			// Read number of sort routines to perform
			do
			{
				cout << "\n  Enter the number of times to repeat each sort (1 or more): ";
				cin >> numSorts;
			
				if (numSorts < 1)
					cout << "Invalid entry. Please try again\n";
			} while (numSorts < 1);
			
			// Dynamically allocate arrays
			resultsArray1 = new (nothrow) int[numSorts];
			resultsArray2 = new (nothrow) int[numSorts];

			cout << "\n";
			
			// Process each sort routine
			while (runCounter < numSorts && !failed)
			{
				// Populate random arrays
				getRandomInt(randArray1, randArray2);
				
				// Start sort processing
				cout << "  Starting Sort #" << (runCounter + 1) << "..." << endl;
				
				// Sort algorithm 1 processing
				// Execute Sort and calculate runtime
				startTime = clock();
				executeSort(randArray1, convertMenuChoice(choice1));
				endTime = clock();//***********************************************
				totalTime = endTime - startTime;
			//	endTime = clock() - startTime;
				
				// Insert index into resultsArray1
				resultsArray1[runCounter] = totalTime;
				cout << "\t" << MENU_DESCRIPTIONS[convertMenuChoice(choice1)] << " Time: " << totalTime << "..." << endl;
				
				// Sort algorithm 2 processing
				// Execute Sort and calculate runtime
				startTime = clock();
				executeSort(randArray2, convertMenuChoice(choice2));
				endTime = clock();//***********************************************
				totalTime = endTime - startTime;
			//	endTime = clock() - startTime;
				
				// Insert index into resultsArray2
				resultsArray2[runCounter] = totalTime;
				
				cout << "\t" << MENU_DESCRIPTIONS[convertMenuChoice(choice2)] << " Time: " << totalTime << "..."  << endl;				

				// Validate the sorts completed properly
				if (isSorted(randArray1) && isSorted(randArray2))
				{
					cout << "\tSorts Validated\n";	
					runCounter++;
				}
				
				// Sorts failed - Set returnVal to 1, failed to true and exit program gracefully
				else
				{
					// *** We should never reach this point!! ***
					cout << "\n\t*** Sorts not validated ***\n\t*** Program terminates ***\n\n";
					runCounter = numSorts;
					failed = true;
					returnVal = RETURN_ERROR;
				}	
			}
			
			if (!failed)
			{
				// Display averages and reset runCounter
				displayAverage(resultsArray1, resultsArray2, convertMenuChoice(choice1), convertMenuChoice(choice2), numSorts);
				runCounter = ZERO;
				cout << "\n\n";
				system("pause");
				cout << "\n";
			}
		}	
	} while (choice1 != EXIT_CODE && choice2 != EXIT_CODE && !failed);
	
	// De-allocate memory for results arrays only if we aren't on first run
	// If we have not run through at least once, then the arrays have not been allocated
	// Thus, a deletion attempt will segfault the program
	if (firstRun != ZERO)
	{
		delete [] resultsArray1;
		delete [] resultsArray2;
	}

	return returnVal;
}
