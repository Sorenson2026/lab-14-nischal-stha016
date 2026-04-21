/*Programming Challenge 3: Write a program that dynamically allocates an array large enough to hold a userdefined number of test scores. Once all the scores are entered, the array should be
passed to a function that sorts them in ascending order. Another function should be
called that calculates the average score. The program should display the sorted list of
scores and averages with appropriate headings. Use pointer notation rather than array
notation whenever possible.
Modify the program in such a way that the lowest test score is dropped. This score should not be
included in the calculation of the average.
Input Validation: Do not accept negative numbers for test scores.

By: Nischal Shrestha 
Date; 04/21/2026*/

#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
void getScores(double*& scores, int& size);
void sortScores(double* scores, int size);
void dropLowest(double*& scores, int& size);
double calculateAverage(double* scores, int size);
void displayScores(double* scores, int size);
void displayAverage(double average);

// Main function that calls other functions to execute the program
int main() 
{
	//Welcome the user to the program
	cout << "Welcome to the Test Score Analyzer!" << endl;
	double* scores = nullptr;
	int size = 0;
	getScores(scores, size);
	sortScores(scores, size);
	dropLowest(scores, size);
	double average = calculateAverage(scores, size);
	displayScores(scores, size);
	displayAverage(average);
	delete[] scores; // Free dynamically allocated memory
	return 0;
}

// Function that gets the user to enter test scores and dynamically allocates an array to hold them
void getScores(double*& scores, int& size) 
{
	cout << "Enter the number of test scores: ";
	cin >> size;
	while (size <= 0) 
	{
		cout << "Please enter a positive number for the size: ";
		cin >> size;
	}
	scores = new double[size];
	for (int i = 0; i < size; ++i) 
	{
		cout << "Enter score " << (i + 1) << ": ";
		cin >> scores[i];
		while (scores[i] < 0) 
		{
			cout << "Please enter a non-negative score: ";
			cin >> scores[i];
		}
	}
}

// Function that sorts the scores in ascending order using bubble sort algorithm
void sortScores(double* scores, int size) 
{
	for (int i = 0; i < size - 1; ++i) 
	{
		for (int j = 0; j < size - i - 1; ++j) 
		{
			if (scores[j] > scores[j + 1]) 
			{
				double temp = scores[j];
				scores[j] = scores[j + 1];
				scores[j + 1] = temp;
			}
		}
	}
}

// Function that drops the lowest score by creating a new array without the first element (lowest score) and updating the size
void dropLowest(double*& scores, int& size) 
{
	if (size > 0) 
	{
		double* newScores = new double[size - 1];
		for (int i = 1; i < size; ++i) 
		{
			newScores[i - 1] = scores[i];
		}
		delete[] scores; // Free old array
		scores = newScores; // Point to new array
		size--; // Decrease size
		}

}

// Function that calculates the average score by summing all scores and dividing by the size
double calculateAverage(double* scores, int size) 
{
	double sum = 0;
	for (int i = 0; i < size; ++i) 
	{
		sum += scores[i];
	}
	return sum / size;
}

// Function that displays the sorted scores with two decimal places
void displayScores(double* scores, int size) 
{
	cout << "Sorted Test Scores After Dropping the Lowest Score:" << endl;
	for (int i = 0; i < size; ++i) 
	{
		cout << fixed << setprecision(2) << scores[i] << endl;
	}
}

// Function that displays the average score with two decimal places
void displayAverage(double average) 
{
	cout << "Average Score: " << fixed << setprecision(2) << average << endl;
}


