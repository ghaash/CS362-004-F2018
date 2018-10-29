//unittest3.c
//testing draw card function
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
#include <string.h>
#include "interface.h"

//function to test drawing cards
void drawCardTest()
{
	int seed = 1000;
    int numberPlayer = 2;
    int playerNumber = 0;
	int handCount = 5;

    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
			   
    struct gameState gameTest;
	
    int customHand[handCount];
	
	customHand[0] = copper;
    customHand[1] = silver;
	customHand[2] = village;
	customHand[3] = gold;
	customHand[4] = smithy;
    
	int beforeHandCount = 0;
	int afterHandCount = 0;

	int beforeDeckCount = 0;
	int afterDeckCount = 0; 
	
    printf ("testing draw card function");

	initializeGame(numberPlayer, k, seed, &gameTest);
	gameTest.handCount[playerNumber] = handCount;            
	memcpy(gameTest.hand[playerNumber], customHand, sizeof(int) * handCount);
	
	
	printf ("draw a card from the remanding cards\n");
	beforeHandCount = gameTest.handCount[playerNumber];
	beforeDeckCount = gameTest.deckCount[playerNumber];
	
	drawCard(playerNumber, &gameTest);
	
	afterHandCount = gameTest.handCount[playerNumber];
	afterDeckCount = gameTest.deckCount[playerNumber];
	
	//checks if card added to hand
	if(afterHandCount == beforeHandCount + 1)
	{
		printf ("IT WORKS - card added to hand.\n");
	}
	else
	{
		printf ("IT DOESNT WORK - card not added to hand.\n");
	}
	
	//checks if card removed from deck
	if(afterDeckCount == beforeDeckCount - 1)
	{
		printf ("IT WORKS - card removed from deck.\n");
	}
	else
	{
		printf ("IT DOESNT WORK - card  removed from deck.\n");
	}
}

int main() {
    drawCardTest();
    return 0;
}


