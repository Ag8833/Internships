/*
 * Andrew Gates
 * 9/28/2015
 * Quora Challenge Upvotes
 *
 * This program contains the declarations of functions and testing to be used to retrieve data from the user for
 * amount of daily upvotes and then based on given parameters it will calculate the number of non-decreasing and
 * non-increasing subranges within those parameters.
 *
 * I believe there may be an error in the instructions given on your website https://www.quora.com/challenges#upvotes.
 * Using the logic of evaluating subranges like in processData1 I get the correct answer for sample output lines 1 and
 * 3 but not 2. Using the logic of evaluating subranges like in processData2 I get the correct answer for sample output
 * line2, but not for sample output lines 1 and 3. I'm not sure which evaluation technique you intended to be used so I
 * included functions to process the subranges both ways just in case.
 */

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int* getData();
void processData1(int*);
void processData2(int*);

//Main function definition to call various functions associated with calculating upvotes.
int main()
{
	int* upvoteArray = getData();
	processData1(upvoteArray);
	processData2(upvoteArray);
}

//Function definition to retrieve the data to be used in calculating upvotes. It will prompt the user to enter
//a value for N and a value for K and then depending on the size of N will ask the user to enter upvote data for
//that many days.
int* getData()
{
	int nValue = 0, kValue = 0, tempValue = 0;
	int* upvoteArray = NULL;
	string upvoteData;

	//Capturing the value for N.
	while(nValue < 1 || nValue > 100000)
	{
		cout << "Enter the value for N (1 <= N <= 100,000): ";
		cin >> nValue;
	}

	upvoteArray = new int[nValue + 2];

	//Capturing the value for K.
	while(kValue < 1 || kValue > nValue)
	{
		cout << "Enter the value for K (1 <= K <= " << nValue << "): ";
		cin >> kValue;
	}

	//Storing the nValue at index 0 and kValue at index 1 to be used later.
	upvoteArray[0] = nValue;
	upvoteArray[1] = kValue;

	//Capturing the values for daily upvote data.
	for(int i = 2; i < nValue + 2; i++)
	{
		do
		{
			cout << "Day " << i - 1 << ": ";
			cin >> tempValue;
		}
		while(tempValue > pow(10,9));

		upvoteArray[i] = tempValue;
	}

	return upvoteArray;
}

//Function definition to process the upvote data stored in upvoteArray. This function evaluates subranges by comparing
//all adjacent values, then all values 1 index apart, then all values 2 indices apart and so on until it compares all
//subranges of values. For example on the subset [1,2,3] it will compare 1,2 then 2,3 then 1,3 resulting in 3
//non-decreasing subranges and 0 non-increasing.
void processData1(int* upvoteArray)
{
	cout << endl << "Answers using processData1: " << endl << endl;

	int nonDecreasing = 0, nonIncreasing = 0, incrementNumber = 0;

	//For loop to iterate through the array N-K+1 times.
	for(int i = 0; i < (upvoteArray[0] - upvoteArray[1] + 1); i++)
	{
		//Increment number used to adjust the distance between indices to compare.
		incrementNumber = 0;

		//While loop to make sure that the increment does not go past the bounds of the array.
		while((2 + incrementNumber) < (upvoteArray[1] + 1))
		{
			//For loop to iterate through the subrange at the current increment number.
			for(int j = 0; j < (upvoteArray[1] - incrementNumber) - 1; j++)
			{
				if((3 + j + i + incrementNumber) > (upvoteArray[0] + 1))
				{
					break;
				}
				else if(upvoteArray[j + i + 2] < upvoteArray[3 + j + i + incrementNumber])
				{
					nonDecreasing++;
				}
				else if(upvoteArray[j + i + 2] > upvoteArray[3 + j + i + incrementNumber])
				{
					nonIncreasing++;
				}
				else
				{
					nonDecreasing++;
					nonIncreasing++;
				}
			}

			incrementNumber++;
		}

		//Outputting the current subrange answer and then resetting the values.
 		cout << "Subrange " << i + 1 << " answer is: " << nonDecreasing - nonIncreasing << endl;
		nonDecreasing = 0;
		nonIncreasing = 0;
	}
}

//Function definition to process the upvote data stored in upvoteArray. This function evaluates subranges by comparing
//all adjacent values. For example on the subset [2,3,1] it will compare 2,3 and then 3,1 resulting in 1 non-decreasing
//subranges and 1 non-increasing.
void processData2(int* upvoteArray)
{
	cout << endl << "Answers using processData2: " << endl << endl;

	int nonDecreasing = 0, nonIncreasing = 0;

	//For loop to iterate through the array N-K+1 times.
	for(int i = 0; i < (upvoteArray[0] - upvoteArray[1] + 1); i++)
	{
		//For loop to iterate through the subrange K-1 amount of times.
		for(int j = 0; j < upvoteArray[1] - 1; j++)
		{
			if(upvoteArray[2 + j + i] < upvoteArray[3 + j + i])
			{
				nonDecreasing++;
			}
			else if(upvoteArray[2 + j + i] > upvoteArray[3 + j + i])
			{
				nonIncreasing++;
			}
			else
			{
				nonDecreasing++;
				nonIncreasing++;
			}
		}

		//Outputting the current subrange answer and then resetting the values.
		cout << "Subrange " << i + 1 << " answer is: " << nonDecreasing - nonIncreasing << endl;
		nonDecreasing = 0;
		nonIncreasing = 0;
	}
}
