//cardtest2.c
//test Adventurer card
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"

void AdventurerCardTest()
{
    int seed = 9000; //over
    int numberOfPlayers = 2;
    int playerNumber = 1;
	int handCount = 5;
	
	//cards to play with
    int k[10] = {adventurer, council_room, feast, gardens, mine, council_room, smithy, village, baron, great_hall};
			   
    struct gameState gameTest;
	
    int customHand[handCount];
	
	//custom hand
	customHand[0] = adventurer;
    customHand[1] = smithy;
	customHand[2] = gold;
	customHand[3] = copper;
	customHand[4] = silver;
    
	int inHand = 0;
	
	int z = 0;
	int drawnTreasure = 0;
	int temphand[MAX_HAND];

    printf ("testing adventurer card function\n");
	
	printf("test with one adventurer card with player %d and handcount %d as per the rules of adventurer card\n", playerNumber, handCount);

	//starting up a game
	initializeGame(numberOfPlayers, k, seed, &gameTest);
	gameTest.handCount[playerNumber] = handCount;
	memcpy(gameTest.hand[playerNumber], customHand, sizeof(int) * handCount);
	gameTest.deckCount[playerNumber] = 0;
	

	//check if it is in player hand
	if (inHand == 1)
	{
		printf ("IT WORKS - Adventurer card is in player's hand\n");
	}
	else
	{
		printf ("IT DOESNT WORK - Adventurer card is NOT in player's hand\n");
	}
	
	inHand = 0;
	
	printf ("use adventurer\n");
	
	AdventurerCard(&gameTest, drawnTreasure, playerNumber, temphand, z);
	
	//check if there is a shuffle
	if(gameTest.deckCount[playerNumber] == 0)
	{
		printf ("IT DOESN'T WORK - didnt shuffle %d\n", gameTest.deckCount[playerNumber]);
	}
	else
	{
		printf ("IT WORKS - shuffled %d\n", gameTest.deckCount[playerNumber]);
	}
	
	//check if player gets treasure, cards 5 for the bug
	if(gameTest.handCount[playerNumber] == 6 || gameTest.handCount[playerNumber] == 10)
	{
		printf ("IT WORKS - player # %d got cards.\n", playerNumber);
	}
	else
	{
		printf ("IT DOESN'T WORK - player # %d didnt get right cards.\n", playerNumber);
	}
}

int main() {
	AdventurerCardTest();
    return 0;
}