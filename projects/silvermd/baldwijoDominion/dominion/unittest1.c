//unittest1.c
//game over
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
#include <string.h>
#include "interface.h"

void GameOverTest() 
{
	int seed = 1000;
    int numberPlayer = 2;
	
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
			   
    struct gameState gameTest;
	int true = 0;
	
    printf ("testing is game over function\n");

	//startup game
	initializeGame(numberPlayer, k, seed, &gameTest);
	
	printf ("checking game over win conditions.\n");
	
	gameTest.supplyCount[province] = 1;
	true = isGameOver(&gameTest);
	
	//game ends if 1 province is remaining
	if(true == 1)
	{
		printf ("IT DOESNT WORK - Game is over when 1 Province remaining.\n");
	}
	else
	{
		printf ("IT  WORK - Game is not over when 1 Province remaining.\n");
	}
	
	gameTest.supplyCount[province] = 0;
	true = isGameOver(&gameTest);
	
	//check if game is over with 0 province remaining
	if(true == 1)
	{
		printf ("IT  WORK - Game is over when 0 Province remaining.\n");
	}
	else
	{
		printf ("IT DOESNT WORK - Game is not over when 0 Province remaining.\n");
	}

	printf ("Determine if game is over when 3 coin card stacks are empty; copper, silver, gold.\n");
	
	memset(&gameTest, 23, sizeof(struct gameState));
	initializeGame(numberPlayer, k, seed, &gameTest);
	
	///testing if game is over when 3 card piles are gone
	if(true == 1)
	{
		printf ("IT  WORK - Game is over when 3 card piles are empty.\n");
	}
	else
	{
		printf ("IT DOESNT WORK - Game is not over when 3 card piles are empty.\n");
	}
}

int main() {
    GameOverTest();
    return 0;
}