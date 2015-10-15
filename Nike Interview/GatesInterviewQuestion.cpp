/*
 *  Andrew Gates
 * 	10/14/2015
 *	Nike Interview Question
 *
 *	This program contains a main function for testing. A maxMin function to return the maximum and minimum values and
 *	their indices from an array of floats. As well as a quadrantSplit function that will split the function into 4
 *	quadrants and it will calculate the maximum, minimum values and their indices for those quadrants.
 */

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//arraySize that can be altered based on the number of elements that will be in the array.
int arraySize = 7;

float* maxMin(float*, float*, int, int); //Function prototype to get the maximum and minimum values and their indices.
void quadrantSplit(float*); //Function prototype to split the array into 4 and then calculate their max and min values.

int main()
{
	float* dataArray = new float[arraySize];
	float* maxMinArray = new float[4];

	for(int i = 0; i < arraySize; i++)
	{
		cout << "Enter a value for index " << i << ": ";
		cin >> dataArray[i];
	}

	maxMinArray = maxMin(dataArray, maxMinArray, 0, arraySize);
	cout << endl << "Total values - " << endl;
	cout << "The largest element is " << maxMinArray[0] << " and it's index is " << maxMinArray[1] << endl;
	cout << "The smallest element is " << maxMinArray[2] << " and it's index is " << maxMinArray[3] << endl;

	quadrantSplit(dataArray);
}

//Function definition to get the maximum and minimum values and their indices.
float* maxMin(float* dataArray, float* maxMinArray, int start, int end)
{
	//Initializing the maxMinArray values to the starting value of dataArray and that index.
	maxMinArray[0] = dataArray[start];
	maxMinArray[1] = start;
	maxMinArray[2] = dataArray[start];
	maxMinArray[3] = start;

	for(int i = start; i <= end; i++)
	{
		//If the current element is greater than the previous maximum change the maximum to that current element.
		if(dataArray[i] > maxMinArray[0])
		{
			maxMinArray[0] = dataArray[i];
			maxMinArray[1] = i;
		}
		//If the current element is less than the previous minimum change the minimum to that current element.
		if(dataArray[i] < maxMinArray[2])
		{
			maxMinArray[2] = dataArray[i];
			maxMinArray[3] = i;
		}
	}
	return maxMinArray;
}

//Function definition to split the array into 4 and then calculate their max and min values.
void quadrantSplit(float* dataArray)
{
	float* quadrantOne = new float[4];
	float* quadrantTwo = new float[4];
	float* quadrantThree = new float[4];
	float* quadrantFour = new float[4];

	//Quadrant One from 0 to 1/4 of dataArray size.
	quadrantOne = maxMin(dataArray, quadrantOne, 0, floor(arraySize)/4 - 1);

	//Quadrant Two from 1/4 to 1/2 of dataArray size.
	quadrantTwo = maxMin(dataArray, quadrantTwo, floor(arraySize/4), floor(arraySize/2) - 1);

	//Quadrant Three from 1/2 to 3/4 of dataArray size.
	quadrantThree = maxMin(dataArray, quadrantThree, floor(arraySize/2), floor(3*arraySize/4) - 1);

	//Quadrant Four from 3/4 to dataArray size.
	quadrantFour = maxMin(dataArray, quadrantFour, floor(3*arraySize/4), arraySize - 1);

	cout << endl << "Quadrant One - " << endl;
	cout << "The largest element is " << quadrantOne[0] << " and it's index is " << quadrantOne[1] << endl;
	cout << "The smallest element is " << quadrantOne[2] << " and it's index is " << quadrantOne[3] << endl;

	cout << endl << "Quadrant Two - " << endl;
	cout << "The largest element is " << quadrantTwo[0] << " and it's index is " << quadrantTwo[1] << endl;
	cout << "The smallest element is " << quadrantTwo[2] << " and it's index is " << quadrantTwo[3] << endl;

	cout << endl << "Quadrant Three - " << endl;
	cout << "The largest element is " << quadrantThree[0] << " and it's index is " << quadrantThree[1] << endl;
	cout << "The smallest element is " << quadrantThree[2] << " and it's index is " << quadrantThree[3] << endl;

	cout << endl << "Quadrant Four - " << endl;
	cout << "The largest element is " << quadrantFour[0] << " and it's index is " << quadrantFour[1] << endl;
	cout << "The smallest element is " << quadrantFour[2] << " and it's index is " << quadrantFour[3] << endl;
}

