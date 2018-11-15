 #include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"

//randomtestcard2 - test for village card

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
		
		cardEffect(village, choice1, choice2, choice3, &game, handPos, &bonus);
		
		if(game.numActions > gameTest.numActions)
        {
			tests++;
		}

        else if(game.numActions < gameTest.numActions)
        {
			printf("Actions are messed up\n");
		}

		if(game.handCount[player] == gameTest.handCount[player])
        {
			tests++;
		}
        
        else if(game.handCount[player] != gameTest.handCount[player])
        {
			printf("Draw card mistake\n");
			printf("This many cards in hand - %d ", game.handCount[player]);
			printf("correct numbers of cards: %d ", gameTest.handCount[player]);
		}

		if(tests >= 2)
        {
			passedTests++;
		}
	}
	printf("Village Test - %d of %d tests passed\n", passedTests, numberOfTests);
}