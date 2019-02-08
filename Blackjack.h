#include "Card.h"
//#include "std_lib_facilities.h"

class CardHand {
	vector<Card> h;
public:
	CardHand(vector<Card> hand): h(hand) {}  
	int calculateHandScore() {					//Denne regner ut score uten å ta med ess
		int handScore = 0; int aces = 0;
		for (int cardIndex = 0; cardIndex < h.size(); ++cardIndex) {
			Card cardI = h[cardIndex];
			int cardValue = cardI.cardValue();
			if ((cardValue > 10) && (cardValue < 14)) {
				handScore += 10;
				continue;
			}
			if (cardValue <= 10) {
				handScore += cardValue;
				continue;
			}
			if (cardValue == 14) {
				aces += 1;
			}
		}
		if (aces != 0) {
			handScore = aceScore(handScore, aces);			//Tar med score til ess
		}
		return handScore;
	}	  
	int aceScore(int handScore, int aces) {       // Ess kan være både 11 og 1. Denne finner beste kombinasjon (rekursivt)
		if (aces == 0) {
			return handScore;
		}
		if (handScore <= (11 - aces)) {
			handScore += 11;
		}
		else {
			handScore += 1;
		}
		aceScore(handScore, (aces - 1));
	}
	vector<Card> drawToHand(CardDeck& deck) {
		Card thisDraw = deck.drawCard(); 
		h.push_back(thisDraw);							
		return h;
	}
	void printToScreen() {
		for (unsigned int cardIndex2 = 0; cardIndex2 < h.size(); ++cardIndex2) {
			Card cardToBePrinted = h[cardIndex2];
			cout << setw(4) << cardToBePrinted.toStringShort();
		}
	}
};

class BlackJack {
	CardDeck deck;
	CardHand yourHand;
	CardHand dealersHand;
public:
	BlackJack (CardDeck d, CardHand yH, CardHand dH) : deck(d), yourHand(yH), dealersHand(dH) {}
	CardHand dealersDraw() {
		int dealersScore = dealersHand.calculateHandScore();
		if (dealersScore < 17) {
			dealersHand.drawToHand(deck);
			return dealersHand;
		}
		else {
			return dealersHand;
		}
	}
	bool winner() {				//true if player wins
		int dealersScore = dealersHand.calculateHandScore();
		int yourScore = yourHand.calculateHandScore();
		
		if ((yourScore > 21) && (dealersScore <= 21)) {		// dersom spiller har over 21 og dealer har ikke
			return false;
		}
		if ((yourScore <= 21) && (dealersScore > 21)) {		// dersom dealer har over 21 og spiller har ikke
			return true;
		}
		else {												//Dersom begge har under, eller begge har over 21
			int dealersDiff = abs(dealersScore - 21); int yourDiff = abs(dealersScore - 21);
			if (dealersDiff <= yourScore) {					// Dersom du er like nærmere eller lengere fra 21 enn dealer, vinner dealer
				return false;
			}
			else {
				return true;
			}
		}
	}
	void gameInterFace() {
		string answer = "Yes"; int yourScore, dealersScore;
		cout << "---------------------- BLACKJACK ----------------------\n";
		do {
			cout << "\nDo you want to draw a card? (Yes/No): "; cin >> answer;
			if (answer == "Yes" || answer == "yes") {
				yourHand.drawToHand(deck);								//Du trekker kort
				dealersHand = dealersDraw();							//Funksjon bestemmer om dealer skal trekke
				yourScore = yourHand.calculateHandScore(); dealersScore = dealersHand.calculateHandScore();
				cout << "D:"; dealersHand.printToScreen(); cout << setw(38) << dealersScore << endl;
				cout << "P:"; yourHand.printToScreen(); cout << setw(38) << yourScore << endl;
				//printToScreen(yourHand);
			}
		} while (answer != "No" && answer != "no");
		if (winner()) {
			cout << "Congratulations, you won! \n";
		}
		else {
			cout << "Unfortuneatly you lost! \n";
		}
	}
};