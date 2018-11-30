//unittest4.c
//test discardCard function
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
#include <string.h>
#include "interface.h"

//tests if card is in hand for discard test function
void cardInHand(char cardName[20], struct gameState *gameTest, int playerNumber, char name[20] )
{
	int inHand = 0;
	int index;
	for(index = 0; index < (*gameTest).handCount[playerNumber]; index++)
	{
		cardNumToName((*gameTest).hand[playerNumber][index], name);
		printf("%s%s", name, ", ");
		if(strcmp(name, cardName) == 0)
		{
			inHand = 1;
		}
	}
	
	if (inHand == 0)
	{
		printf ("\nIT WORKS - card discarded\n");
	}
	else
	{
		printf ("\nIT DOESNT WORK - card not discarded\n");
	}
	
}

void discardCardTest()
{
	int seed = 9000; //over
    int numberOfPlayers = 2;
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
    
    char name[20];
	int beforePlayed = 0;
	int afterPlayed = 0;
	int beforeDiscardedCount = 0;
	int afterDiscardedCount = 0;
	
    printf ("testing discard card function\n");

	//settingup the game
	initializeGame(numberOfPlayers, k, seed, &gameTest);
	gameTest.handCount[playerNumber] = handCount;
	memcpy(gameTest.hand[playerNumber], customHand, sizeof(int) * handCount);
	beforePlayed = gameTest.playedCardCount;
	beforeDiscardedCount = gameTest.discardCount[playerNumber];
	
	printf ("attempting to discard card\n");
	discardCard(2, playerNumber, &gameTest, 0);
	afterPlayed = gameTest.playedCardCount;
	afterDiscardedCount = gameTest.discardCount[playerNumber];
	

	//checks if card added
	if(afterPlayed == beforePlayed + 1)
	{
		printf ("IT WORKS - card added to played pile.\n");
	}
	else
	{
		printf ("IT DOESNT WORK - card NOT added to played pile.\n");
	}
	
	//check if its in discard pile
	if(afterDiscardedCount == beforeDiscardedCount + 1)
	{
		printf ("IT WORKS - card added to discard pile.\n");
	}
	else
	{
		printf ("IT DOESNT WORK - card NOT added to discard pile.\n");
	}
	
	//checking if hand is in discard pile
	cardInHand("Village", &gameTest, playerNumber, name);
}

int main() {
    discardCardTest();
    return 0;
}