#ifndef YAHTCPP_H
#define YAHTCPP_H

#include <iostream>
#include <string>

using namespace std;



extern const char CHAR_YES;
extern const char CHAR_NO;
extern const int  TURNS_PER_GAME;
extern const int  SIDES_PER_DIE;


// MISSING:
//   BONUS for multiple YAHTZEES in a single game
//   BONUS for Upper Section
//   Constrain to only do each action once per game


/* This function takes a string as input, for example "Do you want to quit?"
and prompts the user "Do you want to quit? [Y/N]: " and keeps prompting until
either a Y or an N is entered.

The Y or N char that was entered is returned.
*/
char getYN(string prompt);

string getFullLine();

int rollDie();

void printStatus(int d1, int d2, int d3, int d4, int d5);

string getKeepPrompt(int nth, int value);

char getCharInRange(char min, char max);

int doTurn(int turnNum);

bool isValidOption_Aces(int die1, int die2, int die3, int die4, int die5);
bool isValidOption_Twos(int die1, int die2, int die3, int die4, int die5);
bool isValidOption_Threes(int die1, int die2, int die3, int die4, int die5);
bool isValidOption_Fours(int die1, int die2, int die3, int die4, int die5);
bool isValidOption_Fives(int die1, int die2, int die3, int die4, int die5);
bool isValidOption_Sixes(int die1, int die2, int die3, int die4, int die5);
bool isValidOption_3OfAKind(int die1, int die2, int die3, int die4, int die5);
bool isValidOption_4OfAKind(int die1, int die2, int die3, int die4, int die5);
bool isValidOption_FullHouse(int die1, int die2, int die3, int die4, int die5);
bool isValidOption_SmStraight(int die1, int die2, int die3, int die4, int die5);
bool isValidOption_LgStraight(int die1, int die2, int die3, int die4, int die5);
bool isValidOption_YAHTZEE(int die1, int die2, int die3, int die4, int die5);
bool isValidOption_Chance(int die1, int die2, int die3, int die4, int die5);

int pointsFor_Aces(int die1, int die2, int die3, int die4, int die5);
int pointsFor_Twos(int die1, int die2, int die3, int die4, int die5);
int pointsFor_Threes(int die1, int die2, int die3, int die4, int die5);
int pointsFor_Fours(int die1, int die2, int die3, int die4, int die5);
int pointsFor_Fives(int die1, int die2, int die3, int die4, int die5);
int pointsFor_Sixes(int die1, int die2, int die3, int die4, int die5);

int pointsFor_3OfAKind(int die1, int die2, int die3, int die4, int die5);
int pointsFor_4OfAKind(int die1, int die2, int die3, int die4, int die5);
int pointsFor_FullHouse(int die1, int die2, int die3, int die4, int die5);
int pointsFor_SmStraight(int die1, int die2, int die3, int die4, int die5);
int pointsFor_LgStraight(int die1, int die2, int die3, int die4, int die5);
int pointsFor_YAHTZEE(int die1, int die2, int die3, int die4, int die5);
int pointsFor_Chance(int die1, int die2, int die3, int die4, int die5);


#endif