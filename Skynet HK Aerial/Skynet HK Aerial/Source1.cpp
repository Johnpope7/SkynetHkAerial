/*Skynet HK-Aerial Proect
CSC215
John Pope*/

//theses are the declared libraries Id need, ctime is specifically for the random generator i will be using
#include <iostream>
#include <cstdlib>
#include <ctime>

//the standard namespace
using namespace std;

int main()
{
	//declared variables for setting the min and max grid numbers
	int searchGridLowNumber = 1;
	int searchGridHighNumber = 64;
	srand(static_cast<unsigned int>(time(0))); // seed for rng
	int secretNumber = rand() % 64 + 1;
		//this is the algorithm code for binary search
	int targetLocationPrediction = 
			((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
	int tries = 0;
	//begin program text
	cout << "Generate Random enemy location on 8x8 grid...\n";
	cout << "The enemy is located at location #" << secretNumber << " on 8x8 grid with 1-64 sectors.\m";
	cout << "Skynet HK-Aerial Initializing software...\n";

	//this do while loop runs the search algorithm and game test
	do
	{
		// Increment tries here so we can see "Ping 1"
		++tries; //adds 1 to "tries"
		cout << "--------------------------------------------------\n";
		cout << "HK-Aerial Radar sending out ping # " << tries << "\n"; // tells what try we are on
		// initialize search algorithm for this cycle
		targetLocationPrediction =
		((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
		// Begin conditional checking if guess is too high or too low
		if (targetLocationPrediction > secretNumber) /*if too high*/
		{
			cout << "The target location prediction of " << targetLocationPrediction << " was higher than the actual enemy location of " << secretNumber << "\n";
			searchGridHighNumber = targetLocationPrediction; //Assign the high number to this location
			cout << "The new searchGridHigherNumber -" << searchGridHighNumber << "\n"; //let the user know the true enemy location
		}
		else if (targetLocationPrediction < secretNumber) /*If too low*/
		{
			//Same as before but for searchGridLowNumber
			cout << "The target location prediction of " << targetLocationPrediction << " was lower than the actual enemy location of " << secretNumber << "\n";
			searchGridLowNumber = targetLocationPrediction; //Assign the low number to this location
			cout << "The new searchGridLowNumber -" << searchGridLowNumber << "\n"; //let the user know the true enemy location
		}
		else /*sets the win condition*/
		{
			cout << "Enemy was hiding at location # " << secretNumber << "\n";
			cout << "Target was found at location # " << targetLocationPrediction << "\n";
			cout << "Skynet HK-Aerial Software took " << tries << " prediction to find the enemy location.\n";
		}
	} while (targetLocationPrediction != secretNumber); //set loop condition
	//main() return statement
	return 0; 
}