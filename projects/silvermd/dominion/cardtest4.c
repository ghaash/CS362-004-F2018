// //cardtest4.c
// //test greathall card
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
#include <string.h>
#include "interface.h"

void greatHallTest() 
{
    int seed = 1000;
    int numberOfPlayers = 2;
    int playerNumber = 0;
    int handCount = 5;
    
     int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

    struct gameState gameTest;
    
    int customHand[handCount];
	
	customHand[0] = copper;
    customHand[1] = silver;
	customHand[2] = gold;
	customHand[3] = village;
	customHand[4] = mine;
    
    int startingNumberOfActions = 1;

    printf ("testing great hall card\n");
    
    initializeGame(numberOfPlayers, k, seed, &gameTest);
	gameTest.handCount[playerNumber] = handCount;
	memcpy(gameTest.hand[playerNumber], customHand, sizeof(int) * handCount);
    gameTest.numActions = 1;
    

    //testing if number of cards in hand is correct
    if(gameTest.handCount[0] == playerNumber - 1 + 1)
    {
        printf("IT WORK - number of cards in hand is correct\n");
    }
    else
    {
        printf("IT DOESNT WORK - number of cards in hand is wrong\n");
    }
    
    //check if number of actions is correct, no bugs added here
    if(gameTest.numActions == (startingNumberOfActions + 1))
    {
        printf("IT WORK - number of actions is correct\n");
    } 
    else
    {
        printf("IT DOEST WORK - number of actions is wrong\n");
    }
}

int main()
{
    greatHallTest();
    return 0;
}