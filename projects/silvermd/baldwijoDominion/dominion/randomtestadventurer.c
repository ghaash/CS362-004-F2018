//randomtestadventurer - test for adventurer card

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"

int main(int argc, char** argv)
{
	int numberOfTests = 1000;
	srand(time(NULL));
	int passedTests = 0;
	 
	for(int index = 0; index < numberOfTests; index++)
    {
		int testCount = 0;
		int numberOfPlayers = rand() %(MAX_PLAYERS - 1) + 2;
		
		struct gameState game;

  		int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
		
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
			testCount++;
		}

		int firstCardDrawn = game.hand[player][game.handCount[player] - 1];

		if(firstCardDrawn == copper || firstCardDrawn == silver || firstCardDrawn == gold)
        {
            testCount++;
        }

		int secondCardDrawn = game.hand[player][game.handCount[player] - 2];

        if(secondCardDrawn == copper || secondCardDrawn == silver || secondCardDrawn == gold)
        {         
            testCount++;
        }

		if(testCount >= 3)
        {
			passedTests++;
		}
	}
	printf("Adventurer Test = %d of %d testCount have passed\n", passedTests, numberOfTests);
}