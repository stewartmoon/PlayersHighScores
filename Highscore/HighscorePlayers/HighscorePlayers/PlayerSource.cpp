/* Author: Stewart Moon
Class: CSC 223-100
Professor: Jeffrey Howard
Due Date: 10/10/2017
Page & Problem #: Page 243, #19
Description:  This program manages a list of up to 10 players, and their high scores.
There will be 4 functions that allow the user to interact with the program by managing (adding, deleting)
players and their highscores in the program.  This program will not utilize a struct or class.
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void FriendlyGreeting();
//Pre-condition: There is no pre-condition here.  This function only displays hardcoded outputs.
//Post-condition: No post condition

int UserSelection();
//Pre-condition: There is no pre-condtition here.  The user selects a number between 1 and 4
//Post-condition: This function returns the a variable type int, which is the user selected number

void PrintList(int array1[], int size1, string array2[]);
//Pre-condition: Two arrays are already initialized and defined.  One is type int, the other is type string.  Also a variable
//that contains the value's of the sizes of the arrays.
//Post-condition: This function does not return any values.

int CountList(int count, int scores[]);
//Pre-condition: An integer is initliazed and there is an array with type int.  
//Post-condition: This function returns the total count of elements within the Array

void ManageList(int scores[], int ArraySize, string players[], int userchoice, int count);
//Pre-condition: This function managess all interaction from the user to the Arrays of players and scores.
//In order to use this funciton properly you need 2 arrays defined , 1 type int and the other type string,
//and you also need 3 integers defined as well.
//Post-condition: There is no variable returned.  Just the output statements from the individual user selections.

int main()
{
	//Define variables
	int count = 0;
	int userchoice = 0;
	int scores[10] = { 92,87,94,99,96, };
	string players[10] = { "Garry","Roger","Winslow","Charles","Bubba" };

	//Call functions
	FriendlyGreeting();

	do {
		int ArraySize = CountList(count, scores);
		userchoice = UserSelection();
		ManageList(scores, ArraySize, players, userchoice, count);
	} while (userchoice != 5);

	return 0;
}

//Description: This function will print out a hardcoded friendy output to the user
void FriendlyGreeting()
{
	//Friendly greeting to program
	cout << "Hello and welcome to Program 19, from Chapter 5 Written by Stewart Moon. " << endl;
	cout << "This program allows the user to interact with a list of players and their ";
	cout << "highscores." << endl;
	cout << endl;//Empty Line
}

//Description: This function will print out the contents of the Arrays "players" and "scores"
void PrintList(int array1[], int size1, string array2[])
{
	cout << endl;//Empty Line
	cout << "List of Players and HighScores " << endl;

	for (int i = 0; i < 10; i++)
	{
		//Logic for displaying both Arrays
		if (array1[i] != 0)
		{
			cout << array2[i] << " ";
			cout << array1[i];
			cout << endl;
		}

	}
	cout << endl;//Empty Line
}

//Description: This function prompts a user for input and returns it in the variable userpick.
int UserSelection()
{
	//Define variables
	int userpick;

	//Prompt the user for input
	cout << "1. Add a new player and score. " << endl;
	cout << "2. Print all players & scores to the screen. " << endl;
	cout << "3. Search for a player and score." << endl;
	cout << "4. Remove a player and score from the list" << endl;
	cout << "5. To leave the Exit the Program" << endl;
	cout << "Please select options between 1-5: ";
	cin >> userpick;
	cout << endl;//Empty Line

	return userpick;
}

//Description:This function counts how many elements are within the array that is passed
int CountList(int counter, int scores[])
{
	//Logic for calcualting elements in array
	for (int i = 0; i < 10; i++)
	{
		if (scores[i] != 0)
		{
			counter++;
		}
	}
	return counter;
}

//Description: 
void ManageList(int scores[], int ArraySize, string players[], int userchoice, int count)
{
	string deletedplayer;

	//Logic for if user wants to add a player
	if (userchoice == 1)
	{
		//Count the Array size
		int newspot = ArraySize + 1;

		//Add a player and score to the array
		cout << "Enter the Players name: ";
		cin >> players[newspot];
		cout << "Enter the Players score: ";
		cin >> scores[newspot];

		//Print out the new array
		PrintList(scores, count, players);

	}
	else if (userchoice == 2)
	{
		//Print out the array
		PrintList(scores, count, players);
	}

	else if (userchoice == 3)
	{
		//Declare variables
		string userinput;

		//Prompt user for input
		cout << "Please enter a player to look up their score: " << endl;
		cin >> userinput;

		//Logic for searching for player
		for (int i = 0; i < 10; i++)
			if (userinput == players[i])
			{
				cout << userinput << " score is: " << scores[i];
			}
		cout << endl;//Empty Line
		cout << endl;//Empty Line
	}
	else if (userchoice == 4)
	{
		//Prompt user for input
		cout << "Please enter a player to delete them and their score: ";
		cin >> deletedplayer;

		//Logic for searching for player and deleting them
		for (int i = 0; i < 10; i++)
		{
			if (deletedplayer == players[i])
			{
				players[i] = "";
				scores[i] = 0;
			}
		}
		PrintList(scores, count, players);
	}
}//End function