//testCount for village
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"

int main(int argc, char** argv)
{
	int numberOfTests = 1;
	srand(time(NULL));
	int passedTests = 0;
	
	for(int  index = 0; index < numberOfTests; index++)
    {
		int testCount = 0;

		int numberOfPlayers = rand() %(MAX_PLAYERS - 1);
		
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
		
		cardEffect(village, choice1, choice2, choice3, &game, handPos, &bonus);
		
		if(game.numActions > gameTest.numActions)
        {
			testCount++;
		}

        else if(game.numActions < gameTest.numActions)
        {
			printf("village card didnt give correct number of actions\n");
		}

		if(game.handCount[player] >= gameTest.handCount[player])
        {
			testCount++;
		}
        
        else if(game.handCount[player] > gameTest.handCount[player])
        {
			printf("Hand count is incorrect");
		}

		if(testCount >= 2)
        {
			passedTests++;
		}
	}
	printf("Village Test - %d of %d testCount passed\n", passedTests, numberOfTests);
}