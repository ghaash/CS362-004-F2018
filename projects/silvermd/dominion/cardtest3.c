//cardtest3.c
//test Village card
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"

void VillageCardTest()
{
	int seed = 1000; //over 9000
    int numberOfPlayers = 2;
    int playerNumber = 0; 
	int handCount = 5;
	
	//okay commenting all this is super tedious
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
			   
    struct gameState gameTest;
	
    int customHand[handCount];
	
	customHand[0] = copper;
    customHand[1] = silver;
	customHand[2] = gold;
	customHand[3] = village;
	customHand[4] = mine;
        
	int inHand = 0;
	int beforeAction = 0;
	int afterAction = 0;
	
    printf ("testing village card function\n");
	
	//startup new game
	initializeGame(numberOfPlayers, k, seed, &gameTest);
	gameTest.handCount[playerNumber] = handCount;
	memcpy(gameTest.hand[playerNumber], customHand, sizeof(int) * handCount);
	beforeAction = gameTest.numActions;
	

	//checks if card is in hand
	if (inHand == 1)
	{
		printf ("IT WORKS - Village card is in hand\n");
	}
	else
	{
		printf ("IT DOESNT WORK - Village card is NOT in hand\n");
	}
	
	inHand = 0; 
	
	printf ("use village card\n");
	cardEffect(village, 0, 0, 0, &gameTest, 1, 0);
	afterAction = gameTest.numActions;
	
	//checks if a player got a card
	if(gameTest.handCount[playerNumber] == 5 || gameTest.handCount[playerNumber] == 6)
	{
		printf ("IT WORKS - player # %d got a card.\n", playerNumber);
	}
	else
	{
		printf ("IT DOESNT WORK - Player # %d has not received a card.\n", playerNumber);
	}
	
	//testing if village card bug works
	if(afterAction == beforeAction + 10)
	{
		printf ("IT WORKS - player # %d has 2 actions now.\n", playerNumber);
	}
	else
	{
		printf ("IT DOESNT WORK - didnt gain 10 actions with player # %d.\n", playerNumber);
	}
}

int main() {
	VillageCardTest();
    return 0;
}
