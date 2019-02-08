#include "std_lib_facilities.h"
#include "Card.h"
#include "utilities.h"
#include "Blackjack.h"
//#include "CardDeck.h"

void testingCardStruct();
void testingCardDeck();
void testingCardHand();
void playBlackJack();



int main(){
	srand(static_cast<unsigned int>(time(nullptr)));
	playBlackJack();
	return 0;
}

void playBlackJack() {
	string answer = "Yes";
	do {
		CardDeck deck;
		deck.shuffle();
		vector<Card> hand;
		CardHand dealersHand = hand; CardHand yourHand = hand;
		BlackJack jack = { deck, yourHand, dealersHand };
		jack.gameInterFace();
		cout << "Type Stop/stop to stop playing. "; cin >> answer;
	} while (answer != "no" || answer != "No");
}











void testingCardStruct() {
	Suit si = Suit::diamonds; Rank ri = Rank::two;
	Suit s2 = Suit::spades; Rank r2 = Rank::three;
	Suit s3 = Suit::diamonds; Rank r3 = Rank::six;
	Suit s4 = Suit::hearts; Rank r4 = Rank::jack;

	CardStruct aceOfDiamonds = { si, ri };	CardStruct aceOfDiamonds2 = { s2, r2 };	CardStruct aceOfDiamonds3 = { s3, r3 };	CardStruct aceOfDiamonds4 = { s4, r4 };
	cout << "Two: "; cout << aceOfDiamonds.toStringShort(aceOfDiamonds) << endl; 
	cout << "Three: "; cout << aceOfDiamonds2.toStringShort(aceOfDiamonds2) << endl;
	cout << "Six: "; cout << aceOfDiamonds3.toStringShort(aceOfDiamonds3) << endl;
	cout << "Jack: "; cout << aceOfDiamonds4.toStringShort(aceOfDiamonds4) << endl;
}
void testingCardDeck() {
	CardDeck kortStokk;
	kortStokk.shuffle();
	kortStokk.printShort();
	Card oversteKort = kortStokk.drawCard();
	cout << "\n----------- overste kort:" << oversteKort.toStringShort() << endl;
}
void testingCardHand() {
	Suit si = Suit::diamonds; Rank ri = Rank::ace;
	Suit s2 = Suit::spades; Rank r2 = Rank::ace;
	Suit s3 = Suit::diamonds; Rank r3 = Rank::ace;
	Suit s4 = Suit::hearts; Rank r4 = Rank::two;
	Card test1 = { si, ri }; Card test2 = { s2, r2 }; Card test3 = { s3, r3 }; Card test4 = { s4, r4 };
	Card testKort;
	CardDeck kortstokk;
	kortstokk.shuffle();
	vector<Card> hand;
	CardHand dealersHand = hand;
	CardHand yourHand = hand;
	for (int k = 0; k < 0; ++k) {
		dealersHand.drawToHand(kortstokk);
	}
	dealersHand.printToScreen();
	//cout << "SCORE: " << dealersHand.calculateHandScore();
	BlackJack jack = { kortstokk, yourHand, dealersHand };
	jack.gameInterFace();
}
