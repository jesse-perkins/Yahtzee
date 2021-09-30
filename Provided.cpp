#include <iostream>
#include <string>

#include "YahtC++.h"

using namespace std;


/*  ROLLDIE()

DESCRIPTION - This function produces a die roll, a value between 1 and the number of sides
    on the die (defined with the constant SIDES_PER_DIE)
PARAMETERS/INPUTS - NONE
RETURNS - an integer representing the value rolled on the die
*/
int rollDie()
{
	return (rand() % SIDES_PER_DIE + 1);
}


// This function prints out the values of the five dice (taking 5 integers as input)
void printStatus(int d1, int d2, int d3, int d4, int d5)
{
	cout << d1 << " " << d2 << " " << d3 << " " << d4 << " " << d5 << endl;
}





/* This is the primary function for the whole program, it calls all of the other necessary functions
   in order to complete a turn.
   */
int doTurn(int turnNum)
{
	cout << "BEGINNING TURN " << turnNum << "..." << endl << endl;

	int  die1, die2, die3, die4, die5; // variables to store the value on each die
	bool roll1 = true, roll2 = true, roll3 = true,
		roll4 = true, roll5 = true; // boolean variables indicating whether to roll the dice;

	int nrolls = 0;
	while (nrolls < 3)
	{
		if (roll1)
			die1 = rollDie();
		if (roll2)
			die2 = rollDie();
		if (roll3)
			die3 = rollDie();
		if (roll4)
			die4 = rollDie();
		if (roll5)
			die5 = rollDie();
		nrolls++;

		cout << "After " << nrolls << " roll" << (nrolls == 1 ? ":" : "s:") << endl;
		printStatus(die1, die2, die3, die4, die5);
		cout << endl;

		if (nrolls == 3)
			break;

		bool confirmed = false;
		while (!confirmed)
		{
			roll1 = getYN(getKeepPrompt(1, die1)) != CHAR_YES;
			roll2 = getYN(getKeepPrompt(2, die2)) != CHAR_YES;
			roll3 = getYN(getKeepPrompt(3, die3)) != CHAR_YES;
			roll4 = getYN(getKeepPrompt(4, die4)) != CHAR_YES;
			roll5 = getYN(getKeepPrompt(5, die5)) != CHAR_YES;
			cout << "You plan to reroll: ";
			if (roll1)
				cout << "Die1[" << die1 << "] ";
			if (roll2)
				cout << "Die2[" << die2 << "] ";
			if (roll3)
				cout << "Die3[" << die3 << "] ";
			if (roll4)
				cout << "Die4[" << die4 << "] ";
			if (roll5)
				cout << "Die5[" << die5 << "] ";
			cout << endl;
			confirmed = getYN("Is this correct?") == CHAR_YES;
		}
		if (!roll1 && !roll2 && !roll3 && !roll4 && !roll5)
			break;
	}

	cout << "Final values for turn " << turnNum << ":" << endl;
	printStatus(die1, die2, die3, die4, die5);
	cout << endl;


	// Now let's determine what options the player has
	bool isOptionAces = isValidOption_Aces(die1, die2, die3, die4, die5); // A
	bool isOptionTwos = isValidOption_Twos(die1, die2, die3, die4, die5); // B
	bool isOptionThrees = isValidOption_Threes(die1, die2, die3, die4, die5); // C
	bool isOptionFours = isValidOption_Fours(die1, die2, die3, die4, die5); // D
	bool isOptionFives = isValidOption_Fives(die1, die2, die3, die4, die5); // E
	bool isOptionSixes = isValidOption_Sixes(die1, die2, die3, die4, die5); // F

	bool isOption3OfAKind = isValidOption_3OfAKind(die1, die2, die3, die4, die5); // G
	bool isOption4OfAKind = isValidOption_4OfAKind(die1, die2, die3, die4, die5); // H
	bool isOptionFullHouse = isValidOption_FullHouse(die1, die2, die3, die4, die5); // I
	bool isOptionSmStraight = isValidOption_SmStraight(die1, die2, die3, die4, die5); // J
	bool isOptionLgStraight = isValidOption_LgStraight(die1, die2, die3, die4, die5); // K
	bool isOptionYAHTZEE = isValidOption_YAHTZEE(die1, die2, die3, die4, die5); // L
	bool isOptionChance = isValidOption_Chance(die1, die2, die3, die4, die5); // M

	int pts_Aces, pts_Twos, pts_Threes, pts_Fours, pts_Fives, pts_Sixes;
	int pts_3OfAKind, pts_4OfAKind, pts_FullHouse;
	int pts_SmStraight, pts_LgStraight, pts_YAHTZEE, pts_Chance;

	if (isOptionAces)
		pts_Aces = pointsFor_Aces(die1, die2, die3, die4, die5);
	if (isOptionTwos)
		pts_Twos = pointsFor_Twos(die1, die2, die3, die4, die5);
	if (isOptionThrees)
		pts_Threes = pointsFor_Threes(die1, die2, die3, die4, die5);
	if (isOptionFours)
		pts_Fours = pointsFor_Fours(die1, die2, die3, die4, die5);
	if (isOptionFives)
		pts_Fives = pointsFor_Fives(die1, die2, die3, die4, die5);
	if (isOptionSixes)
		pts_Sixes = pointsFor_Sixes(die1, die2, die3, die4, die5);

	if (isOption3OfAKind)
		pts_3OfAKind = pointsFor_3OfAKind(die1, die2, die3, die4, die5);
	if (isOption4OfAKind)
		pts_4OfAKind = pointsFor_4OfAKind(die1, die2, die3, die4, die5);
	if (isOptionFullHouse)
		pts_FullHouse = pointsFor_FullHouse(die1, die2, die3, die4, die5);
	if (isOptionSmStraight)
		pts_SmStraight = pointsFor_SmStraight(die1, die2, die3, die4, die5);
	if (isOptionLgStraight)
		pts_LgStraight = pointsFor_LgStraight(die1, die2, die3, die4, die5);
	if (isOptionYAHTZEE)
		pts_YAHTZEE = pointsFor_YAHTZEE(die1, die2, die3, die4, die5);
	if (isOptionChance)
		pts_Chance = pointsFor_Chance(die1, die2, die3, die4, die5);


	char optionChosen;
	int ptsChosen = 0;

	bool validSelection = false;
	while (!validSelection)
	{
		cout << "Options available with these dice:" << endl;
		if (isOptionAces)
			cout << "A) Aces   [scores " << pts_Aces << "]" << endl;
		if (isOptionTwos)
			cout << "B) Twos   [scores " << pts_Twos << "]" << endl;
		if (isOptionThrees)
			cout << "C) Threes [scores " << pts_Threes << "]" << endl;
		if (isOptionFours)
			cout << "D) Fours  [scores " << pts_Fours << "]" << endl;
		if (isOptionFives)
			cout << "E) Fives  [scores " << pts_Fives << "]" << endl;
		if (isOptionSixes)
			cout << "F) Sixes  [scores " << pts_Sixes << "]" << endl;
		if (isOption3OfAKind)
			cout << "G) 3 of a kind  [scores " << pts_3OfAKind << "]" << endl;
		if (isOption4OfAKind)
			cout << "H) 4 of a kind  [scores " << pts_4OfAKind << "]" << endl;
		if (isOptionFullHouse)
			cout << "I) Full House  [scores " << pts_FullHouse << "]" << endl;
		if (isOptionSmStraight)
			cout << "J) Sm. Straight  [scores " << pts_SmStraight << "]" << endl;
		if (isOptionLgStraight)
			cout << "K) Lg. Straight  [scores " << pts_LgStraight << "]" << endl;
		if (isOptionYAHTZEE)
			cout << "L) YAHTZEE  [scores " << pts_YAHTZEE << "]" << endl;
		if (isOptionChance)
			cout << "M) Chance  [scores " << pts_Chance << "]" << endl;

		cout << "Please select one of the options above (enter the single letter):";
		optionChosen = getCharInRange('A', 'M');
		//cout << "You chose: " << optionChosen << endl << endl;

		switch (optionChosen)
		{
		case 'A':
			validSelection = isOptionAces;
			if (validSelection)
				ptsChosen = pts_Aces;
			break;
		case 'B':
			validSelection = isOptionTwos;
			if (validSelection)
				ptsChosen = pts_Twos;
			break;
		case 'C':
			validSelection = isOptionThrees;
			if (validSelection)
				ptsChosen = pts_Threes;
			break;
		case 'D':
			validSelection = isOptionFours;
			if (validSelection)
				ptsChosen = pts_Fours;
			break;
		case 'E':
			validSelection = isOptionFives;
			if (validSelection)
				ptsChosen = pts_Fives;
			break;
		case 'F':
			validSelection = isOptionSixes;
			if (validSelection)
				ptsChosen = pts_Sixes;
			break;
		case 'G':
			validSelection = isOption3OfAKind;
			if (validSelection)
				ptsChosen = pts_3OfAKind;
			break;
		case 'H':
			validSelection = isOption4OfAKind;
			if (validSelection)
				ptsChosen = pts_4OfAKind;
			break;
		case 'I':
			validSelection = isOptionFullHouse;
			if (validSelection)
				ptsChosen = pts_FullHouse;
			break;
		case 'J':
			validSelection = isOptionSmStraight;
			if (validSelection)
				ptsChosen = pts_SmStraight;
			break;
		case 'K':
			validSelection = isOptionLgStraight;
			if (validSelection)
				ptsChosen = pts_LgStraight;
			break;
		case 'L':
			validSelection = isOptionYAHTZEE;
			if (validSelection)
				ptsChosen = pts_YAHTZEE;
			break;
		case 'M':
			validSelection = isOptionChance;
			if (validSelection)
				ptsChosen = pts_Chance;
			break;
		}
		if (!validSelection)
		{
			cout << "Can\'t do that with this set of dice values!!" << endl << endl;
		}
	}

	cout << "You selected " << optionChosen << " which scores " << ptsChosen << " points." << endl;

	return ptsChosen;
}
