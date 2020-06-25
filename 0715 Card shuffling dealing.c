#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include "F:\Programming\C\Deitel 08th Edition\Chapter 07\12\12\FiveCardDraw.h"

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

	int dealerHand[5] = { 0 };
	negDeck(dealerHand, 5);
	int dealerRank[6] = { 0 };
	negDeck(dealerRank, 6);
	int playerHand[5] = { 0 };
	negDeck(playerHand, 5);
	int playerRank[6] = { 0 };
	negDeck(playerRank, 6);

	drawFive(drawDeck, discDeck, dealerHand);
	drawFive(drawDeck, discDeck, playerHand);
	rankHand(dealerHand, dealerRank);
	rankHand(playerHand, playerRank);
	printHand(playerHand, "Player Hand", playerRank);
	drawRoundAuto(drawDeck, discDeck, dealerHand, dealerRank);
	drawRoundManual(drawDeck, discDeck, playerHand);
	rankHand(dealerHand, dealerRank);
	rankHand(playerHand, playerRank);
	printHand(dealerHand, "Dealer Final", dealerRank);
	printHand(playerHand, "Player Final", playerRank);
	if (rankWinner(dealerRank, playerRank)) {
		puts("Player Wins!");
	}
	else {
		puts("Dealer Wins Again...");
	}



}