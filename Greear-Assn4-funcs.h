//***************************************************************************************************************
//Dewey Greear
//Filename - headerFiles.h
//Description - these are the prototypes for the function calls, included is a short description of each function
//***************************************************************************************************************

//displays a user menu
void displayMenu();

//sorts an array using bubble sort algorithm
void bubbleSort(int array[]);

//sorts an array using shell sort algorithm - halving method
void shellSort(int array[]);

//calls the correct sorting algorithm
void executeSort(int array[], int choice);

//displays the average time for the chosen sorts
void displayAverage(int resultsArray1[], int resultsArray2[], int choice1, int choice2, int numSorts);
