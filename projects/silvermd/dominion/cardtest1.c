//cardtest1.c
//testing smithy card
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
#include <string.h>
#include "interface.h"

void SmithyCardTest()
{
    int seed = 1000; //over 9000!
    int numberOfPlayers = 2;
    int playerNumber = 1;
	int handCount = 5;
	
	//cards being played with
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
			   
    struct gameState gameTest;
	
	//hand to test with
    int customHand[handCount];
	
	customHand[0] = copper;
    customHand[1] = silver;
	customHand[2] = village;
	customHand[3] = smithy;
	customHand[4] = mine;
    
	int inHand = 0;

    printf ("testing the smithy card function\n");
	
	//starting a new game
	initializeGame(numberOfPlayers, k, seed, &gameTest);
	gameTest.handCount[playerNumber] = handCount;
	memcpy(gameTest.hand[playerNumber], customHand, sizeof(int) *handCount);
	
	//testing if smithy card is in hand
	if (inHand == 1)
	{
		printf ("IT WORKS - smithy card is in player's hand\n");
	}
	else
	{
		printf ("IT DOESNT WORK - smithy card is not in the player's hand\n");
	}
	
	//testing use of smithy card and it fails because i d
	inHand = 0;
	printf ("Use smithy card\n");
	SmithyCard(&gameTest, 2, 4);
	
	//add 50 cards! and it doesn't test correctly, possibly broken from bug i introduced into dominion c function
	if(gameTest.handCount[playerNumber] == 55 || gameTest.handCount[playerNumber] == 56)
	{
		printf ("IT WORKS - player # %d has a smithy\n", playerNumber);
	}
	else
	{
		printf ("IT DOESNT WORK - player # %d does not have a smithy\n", playerNumber);
	} 

	//checks if smithy card is discarded
	if (inHand == 0)
	{
		printf ("IT WORKS - smithy card was discarded\n");
	}
	else
	{
		printf ("IT DOESNT WORK - smithy card was not discarded.\n");
	}
}

//int main to run smithy card test function
int main() 
{
    SmithyCardTest();
    return 0;
}