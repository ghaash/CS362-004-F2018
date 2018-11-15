#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"

//randomtestadventurer - test for adventurer card

int main(int argc, char** argv)
{
	int numberOfTests = atoi(argv[1]);
	srand(time(NULL));
	int passedTests = 0;
	
	for(int index = 0; index < numberOfTests; index++)
    {
		int tests = 0;
		int numberOfPlayers = rand() %(MAX_PLAYERS - 1) + 2;
		
		struct gameState game;

		int k[10] = {adventurer, gardens, embargo, village, steward, mine, cutpurse, sea_hag, tribute, smithy};
		
		initializeGame(numberOfPlayers, k, rand(), &game);
		
		int player = rand() % numberOfPlayers;
		game.whoseTurn = player;
		int bonus = rand() % 50;
        int choice1 = rand() % 50;
        int choice2 = rand() % 50;
        int choice3 = rand() % 50;
        int handPos = rand() % MAX_HAND;

        struct gameState gameTest;
        memcpy(&gameTest, &game, sizeof(struct gameState));
		
		cardEffect(adventurer, choice1, choice2, choice3, &game, handPos, &bonus);
		
		if(game.handCount[player] == gameTest.handCount[player] + 2)
        {
			tests++;
		}

		int firstCardDrawn = game.hand[player][game.handCount[player] - 1];

		if(firstCardDrawn == copper || firstCardDrawn == silver || firstCardDrawn == gold)
        {
            tests++;
        }
		int secondCardDrawn = game.hand[player][game.handCount[player] - 2];

        if(secondCardDrawn == copper || secondCardDrawn == silver || secondCardDrawn == gold)
        {         
            tests++;
        }

		if(tests >= 3)
        {
			passedTests++;
		}
	}
	printf("Adventurer Test = %d of %d tests have passed\n", passedTests, numberOfTests);
}