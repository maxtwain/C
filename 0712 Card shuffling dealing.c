#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "FiveCardDraw.h"

int main(void) {
	
	// this code is needed for most functions to work
	srand((unsigned)time(NULL));
	int drawDeck[53] = { 0 };
	int discDeck[53] = { 0 };
	initDeck(discDeck);
	shuffleDiscard(drawDeck, discDeck);
	int hand[5] = { 0 };
	negDeck(hand, 5);
	int rank[6] = { 0 };
	negDeck(rank, 6);
	// ********************************* //
	
	// all of this and more is already written into this testing function I made.
	rankTest();

}