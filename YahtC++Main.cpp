#include <iostream>
#include <string>

#include "YahtC++.h"

using namespace std;



int main()
{
	// Ask for player's name
	cout << "Please enter your name: ";
	string playername = getFullLine();
	cout << endl;

	cout << "Welcome to YahtC++ version 1.42, " << playername << "!" << endl << endl;

	
	// Main Loop
	bool playing = true;
	while (playing)
	{
		int totalScore = 0;

		// Play one game
		cout << "This game will consist of " << TURNS_PER_GAME << " turns." << endl << endl;

		// Loop to take all turns
		for (int turn = 1; turn <= TURNS_PER_GAME; turn++)
		{
			int score = doTurn(turn);

			totalScore += score;
			cout << endl << "TOTAL SCORE AFTER " << turn << " TURN" << (turn==1?"":"S") << " = " << totalScore << "." << endl << endl;

		}


		// Ask if player wants to play again
		char choiceYN = getYN("Play again?");
		if (choiceYN == CHAR_NO)
		{
			playing = false; // so that program exits outermost while loop
		}
	}




	system("pause()");
	return 0;
}