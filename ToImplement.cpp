/* *****************************************************************************

CS 142 - Winter 2015
Midterm 1 - Yahtzee

Student Name (First and Last):	Jesse White
Student NetID:					whitej10
Section and Instructor:			Section 2 Prof. Farrell
Development Platform (e.g. Visual Studio Express 2013" or "XCode"): Visual Studio Express 2013

***************************************************************************** */



#include <iostream>
#include <string>

#include "YahtC++.h"

using namespace std;


// Some constants that you may find useful
const char CHAR_YES = 'Y';
const char CHAR_NO = 'N';
const int  TURNS_PER_GAME = 13;
const int  SIDES_PER_DIE = 6;





/* *****************************************************************************
GETYN()

DESCRIPTION - This function prompts the user for input in the form of either a
              'Y' or an 'N'.  Your program should accept either upper- or
			  lower-case Y and N.  Any other character that's given as input is
			  invalid and your program should continue to prompt the user until
			  a valid input character (a Y or an N) is received.

PARAMETERS/INPUTS:
    @PROMPT - This string parameter is used as the display prompt for the user.
	          For example, if prompt has the value "Do you want to quit?", then
			  the program will display "Do you want to quit? [Y/N]: " and wait
			  for user input.

RETURNS - Either an upper-case 'Y' or an 'N'

***************************************************************************** */

char getYN(string prompt)
{
	//getting rid of magic values for lowercase inputs by making them constants

	const char LOW_YES = 'y';
	const char LOW_NO = 'n';
	cout << prompt << " [Y/N]" << endl;
	char yesOrNo;
	cin >> yesOrNo;

	//The below while loop is looking for the valid inputs Y, y, N, n. While the input is invalid, it will loop. 
	
	while (yesOrNo != CHAR_YES && yesOrNo != LOW_YES && yesOrNo != CHAR_NO && yesOrNo != LOW_NO)
	{
		cout << "\nINVALID INPUT. \nPlease enter valid input [Y/N]: ";
		cin >> yesOrNo;
	}
	//the following if elseif statements check for lowercase and then capitalizes.
	if (yesOrNo == 'n')
	{
		yesOrNo = CHAR_NO;
	}
	else if (yesOrNo == 'y')
	{
		yesOrNo = CHAR_YES;
	}

	return yesOrNo;
}







/* *****************************************************************************
GETCHARINRANGE()

DESCRIPTION - This function prompts the user for input in the form of a single
              character in a specified range.  Your program should accept either
			  upper- or lower-case characters, but always return upper case.  If
			  the character that's given by the user is in the specified range
			  (you may assume that the input characters are upper-case), then
			  then it should return it (return the upper-case version if a
			  lower-case character was entered).  If the input is not in the
			  valid range, then your program should continue to prompt the user
			  until a valid input character (in the correct range) is received.

PARAMETERS/INPUTS:
    @MIN -    An upper-case character that begins the valid range.
	@MAX -    An upper-case character that ends the valid range.

RETURNS -     An upper-case character in the specified range.


***************************************************************************** */

char getCharInRange(char min, char max)
{
	/*
	I would like to start by saying that this code is influenced by the ability of char variables 
	to be incremented and decremented. As such, I used the table in the textbook (Appendix D, pg 494) 
	to help me know the proper number of decrements / increments needed in order to manipulate the 
	char value into an uppercase letter from a lowercase letter and vice versa.

	I know it is a rather unwieldy method, but I couldn't remember how to convert chars from uppercase
	to lowercase. I'm sure there is some method on the coding references website, but I'm not giving up 
	points if I can help it :)
	*/

	// This variable is the amount required to be decremented / incremented to make a char convert a char into upper or lowercase.
	const char CHAR_ALPHABET_DISTANCE = 32;

	// This loop increments the input range until it is the range in lowercase letters
	char lowercaseMin = min;
	char lowercaseMax = max;
	for (int counter = 0; counter < CHAR_ALPHABET_DISTANCE; counter++)
	{
		lowercaseMin++;
		lowercaseMax++;
	}

	//Take input
	char menuIn;
	cin >> menuIn;

	//Check to see if the input is with the range
	while (menuIn < min || menuIn > max)
	{
		//Check to see if the input is in the lowercase range
		if (menuIn >= lowercaseMin && menuIn <= lowercaseMax)
		{
			for (int counter = 0; counter < CHAR_ALPHABET_DISTANCE; counter++)
			{
				menuIn--;
			}
		}

		//Prompt for proper input if it is not within the upper or lowercase ranges
		else
		{
			cout << "\nINVALID INPUT "
				<< "\n Please enter valid input [" 
				<< min << "-" << max << "]: ";
			cin >> menuIn;
		}
	}
	return menuIn;
}







/* *****************************************************************************
ISVALIDOPTION_YAHTZEE()

DESCRIPTION - This function determines whether the values on the five dice
              passed in as parameters constitute a YAHTZEE (all five dice have
			  an identical value).  For example, the values 2 2 2 2 2 represent
			  a YAHTZEE.

PARAMETERS/INPUTS:
    @DIE1 -   This int parameter indicates the current value of the first die.
	          The range for this value is from 1 up to SIDES_PER_DIE.
    @DIE2 -   This int parameter has the value of the second die.  Same range.
	@DIE3 -   This int parameter has the value of the third die.  Same range.
	@DIE4 -   This int parameter has the value of the fourth die.  Same range.
	@DIE5 -   This int parameter has the value of the fifth die.  Same range.

RETURNS - Either TRUE (if the values are all identical) or FALSE (otherwise).

***************************************************************************** */

bool isValidOption_YAHTZEE(int die1, int die2, int die3, int die4, int die5)
{
	//create returning variable
	bool yatzee= false;

	//create an if to test for the desired case
	if (die1 == die2 && die1 == die3 && die1 == die4 && die1 == die5)
	{
		yatzee = true;
	}
	return yatzee;
}





/* *****************************************************************************
ISVALIDOPTION_SMSTRAIGHT()

DESCRIPTION - This function determines whether there is a small straight.  For
              example if the dice values were 2 5 4 3 4, there is a small
			  straight 2-3-4-5 present.  Any sequence of four consecutive
			  values (each in the range 1-6) is a small straight.

PARAMETERS/INPUTS:
    @DIE1 -   This int parameter indicates the current value of the first die.
	          The range for this value is from 1 up to SIDES_PER_DIE.
    @DIE2 -   This int parameter has the value of the second die.  Same range.
	@DIE3 -   This int parameter has the value of the third die.  Same range.
	@DIE4 -   This int parameter has the value of the fourth die.  Same range.
	@DIE5 -   This int parameter has the value of the fifth die.  Same range.

RETURNS -     Either TRUE (if a small straight is present in the dice) or
              FALSE (otherwise).

***************************************************************************** */

bool isValidOption_SmStraight(int die1, int die2, int die3, int die4, int die5)
{
	/*
	Initialize a boolean variable to hold the true/false values for the return variable.
	Initialize the value variables. The value variables will indicate if a given value is 
	present in any of the dice.
	*/
	bool smallStraight = false;
	bool value1Exists = false;
	bool value2Exists = false;
	bool value3Exists = false;
	bool value4Exists = false;
	bool value5Exists = false;
	bool value6Exists = false;

	/*
	The following if statements check the values of the dice. If any of the dice have the value 
	indicated by the value variable, the variable is set to true. 'Magic numbers' are eliminated
	by decrementing through testValue, which initially has the same value as SIDES_PER_DIE.

	This would have been better as a loop, but I don't really know how to do a loop that changes
	the target variable each time. I guess I could have done a boolean array, but I'm not even 
	sure that those exist.
	*/
	int testValue = SIDES_PER_DIE;
	if (die1 == testValue || die2 == testValue || die3 == testValue || die4 == testValue || die5 == testValue)
	{
		value6Exists = true;
	}
	testValue--;
	if (die1 == testValue || die2 == testValue || die3 == testValue || die4 == testValue || die5 == testValue)
	{
		value5Exists = true;
	}
	testValue--;
	if (die1 == testValue || die2 == testValue || die3 == testValue || die4 == testValue || die5 == testValue)
	{
		value4Exists = true;
	}
	testValue--;
	if (die1 == testValue || die2 == testValue || die3 == testValue || die4 == testValue || die5 == testValue)
	{
		value3Exists = true;
	}
	testValue--;
	if (die1 == testValue || die2 == testValue || die3 == testValue || die4 == testValue || die5 == testValue)
	{
		value2Exists = true;
	}
	testValue--;
	if (die1 == testValue || die2 == testValue || die3 == testValue || die4 == testValue || die5 == testValue)
	{
		value1Exists = true;
	}

	/* 
	The following if statements check to see if the combinations of values required for a
	small straight exist in the die values.
	*/
	if (value1Exists == true && value2Exists == true && value3Exists == true && value4Exists == true)
	{
		smallStraight = true;
	}
	else if (value2Exists == true && value3Exists == true && value4Exists == true && value5Exists == true)
	{
		smallStraight = true;
	}
	else if (value3Exists == true && value4Exists == true && value5Exists == true && value6Exists == true)
	{
		smallStraight = true;
	}
	
	return smallStraight;
}







/* *****************************************************************************
ISVALIDOPTION_3OFAKIND()

DESCRIPTION - This function determines whether there are 3 (or more) dice that
              have the same value.  For example if the dice values were
			  2 5 5 1 5, there is a 3-of-a-kind, the fives.

PARAMETERS/INPUTS:
    @DIE1 -   This int parameter indicates the current value of the first die.
	          The range for this value is from 1 up to SIDES_PER_DIE.
    @DIE2 -   This int parameter has the value of the second die.  Same range.
	@DIE3 -   This int parameter has the value of the third die.  Same range.
	@DIE4 -   This int parameter has the value of the fourth die.  Same range.
	@DIE5 -   This int parameter has the value of the fifth die.  Same range.

RETURNS -     Either TRUE (if 3 or more dice have the same value) or
              FALSE (otherwise).

***************************************************************************** */

bool isValidOption_3OfAKind(int die1, int die2, int die3, int die4, int die5)
{
	/*
	Initialize a boolean variable to hold the true/false values for the return variable.
	Initialize the value variables. The value variables will indicate the number of times 
	a value is present among the dice. Initialize dieArray.

	I wanted to make this move more smoothly than it would have with a TON of if else if 
	statements so I did some reading in the textbook in chapter 6 on arrays.
	*/
	bool threeOfAKind = false;
	int totalNumberOfOnes = 0;
	int totalNumberOfTwos = 0;
	int totalNumberOfThrees = 0;
	int totalNumberOfFours = 0;
	int totalNumberOfFives = 0;
	int totalNumberOfSixes = 0;
	const int NUM_OF_DICE = 5;
	int dieArray[] = { die1, die2, die3, die4, die5 };

	/*
	The following for loops check the values of the dice. If any of the dice have the value
	indicated by testValue, the variable is incremented. 'Magic numbers' are eliminated
	by decrementing through testValue, which initially has the same value as SIDES_PER_DIE.
	*/
	int testValue = SIDES_PER_DIE;
	for (int count = 0; count < NUM_OF_DICE; count++)
	{
		if (dieArray[count] == testValue)
			totalNumberOfSixes++;
	}
	testValue--;
	for (int count = 0; count < NUM_OF_DICE; count++)
	{
		if (dieArray[count] == testValue)
			totalNumberOfFives++;
	}
	testValue--;
	for (int count = 0; count < NUM_OF_DICE; count++)
	{
		if (dieArray[count] == testValue)
			totalNumberOfFours++;
	}
	testValue--;
	for (int count = 0; count < NUM_OF_DICE; count++)
	{
		if (dieArray[count] == testValue)
			totalNumberOfThrees++;
	}
	testValue--;
	for (int count = 0; count < NUM_OF_DICE; count++)
	{
		if (dieArray[count] == testValue)
			totalNumberOfTwos++;
	}
	testValue--;
	for (int count = 0; count < NUM_OF_DICE; count++)
	{
		if (dieArray[count] == testValue)
			totalNumberOfOnes++;
	}

	//check to see if there are at least three of a kind of any value
	if (totalNumberOfSixes >= 3 || totalNumberOfFives >= 3 
		|| totalNumberOfFours >= 3 || totalNumberOfThrees >= 3
		|| totalNumberOfTwos >= 3 || totalNumberOfOnes >= 3)
	{
		threeOfAKind = true;
	}
	return threeOfAKind;
}








/* *****************************************************************************
POINTSFOR_SIXES()

DESCRIPTION - This function computes the number of points for sixes.  If two
              dice show sixes, then this would return 12, if four dice show
			  sixes, then this function would return 24, and so forth.

PARAMETERS/INPUTS:
    @DIE1 -   This int parameter indicates the current value of the first die.
	          The range for this value is from 1 up to SIDES_PER_DIE.
    @DIE2 -   This int parameter has the value of the second die.  Same range.
	@DIE3 -   This int parameter has the value of the third die.  Same range.
	@DIE4 -   This int parameter has the value of the fourth die.  Same range.
	@DIE5 -   This int parameter has the value of the fifth die.  Same range.

RETURNS -     The total of all dice showing a six (an int).

***************************************************************************** */

int pointsFor_Sixes(int die1, int die2, int die3, int die4, int die5)
{
	/*
	Initialize the value6 variable. The value variable will indicate the number of times 
	a value is present among the dice. Also initialize the dieArray.
	*/
	int numberOfSixes = 0;
	const int POINTS_PER_DIE = 6;
	const int NUM_OF_DICE = 5;
	int dieArray[] = { die1, die2, die3, die4, die5 };

	/*
	The following for loop checks the values of the dice. If any of the dice have the value
	indicated by SIDES_PER_DIE (which has the value of interest- 6), the variable is incremented.
	*/
	for (int count = 0; count < NUM_OF_DICE; count++)
	{
		if (dieArray[count] == SIDES_PER_DIE)
			numberOfSixes++;
	}

	return numberOfSixes*POINTS_PER_DIE;
}




