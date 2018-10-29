//unittest2.c
//testing ScoreFor function
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
#include <string.h>
#include "interface.h"

void testscoreFor()
{
	int seed = 1000; //over 9000
    int numberPlayer = 2; 
    int playerNumber = 0;
	int handCount = 5;
	
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
			   
    struct gameState gameTest;
	int score = 0;
	
    int customHand[handCount];
	customHand[0] = curse;
    customHand[1] = silver;
	customHand[2] = village;
	customHand[3] = gold;
	customHand[4] = duchy;
	
	int customDiscard[handCount];
	customDiscard[0] = village;
    customDiscard[1] = smithy;
	customDiscard[2] = silver;
	customDiscard[3] = copper;
	customDiscard[4] = gold;
	
    int customDeck[handCount];
	customDeck[0] = smithy;
    customDeck[1] = feast;
	customDeck[2] = village;
	customDeck[3] = gold;
	customDeck[4] = copper;
	
    printf ("testing score for function\n");
	
	//startup games with hand
	initializeGame(numberPlayer, k, seed, &gameTest);
	gameTest.handCount[playerNumber] = handCount;
	memcpy(gameTest.hand[playerNumber], customHand, sizeof(int) * handCount);
	memcpy(gameTest.discard[playerNumber], customDiscard, sizeof(int) * handCount); 
	memcpy(gameTest.deck[playerNumber], customDeck, sizeof(int) * handCount);

	score = scoreFor(playerNumber, &gameTest);
	
	printf("Score for Player's Hand is %d\n", score);
	

	//checks if score is correct with customhand
	if(score == 2)
	{
		printf ("IT WORK - score correctly totaled\n");
	}
	else
	{
		printf ("IT DOESNT WORK - score not correctly totaled\n");
	}
}

int main() {
   testscoreFor();
    return 0;
}