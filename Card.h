#pragma once
//#include "std_lib_facilities.h"
#include "utilities.h"

enum class Suit { hearts, diamonds, clubs, spades };
enum class Rank { two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace };

string suitToString(Suit s) {					// Map?
	switch (s) {
	case Suit::clubs:	return "Clubs";
	case Suit::diamonds:	return "Diamonds";
	case Suit::hearts:	return "Hearts";
	case Suit::spades:	return "Spades";
	default: cout << "Don't recognize suit.";
	}
}
string rankToString(Rank r) {
	switch (r) {
	case Rank::two:		return "Two";
	case Rank::three:	return "Three";
	case Rank::four:	return "Four";
	case Rank::five:	return "Five";
	case Rank::six:		return "Six";
	case Rank::seven:	return "Seven";
	case Rank::eight:	return "Eight";
	case Rank::nine:	return "Nine";
	case Rank::ten:		return "Ten";
	case Rank::jack:	return "Jack";
	case Rank::queen:	return "Queen";
	case Rank::king:	return "King";
	case Rank::ace:		return "Ace";
	default: cout << "Don't recognize rank.";
	}
}

struct CardStruct {
	Suit s; Rank r;
//private:
	string toString(CardStruct card) {
		return rankToString(card.r) + " of " + suitToString(card.s);
	}
	string toStringShort(CardStruct card) {
		string cardSuit = suitToString(card.s);			// Henter Suit
		int intCardRank = static_cast<int>(card.r) +2 ;	 //Converterer rank fra "Two, three" osv til en integer. (Får verdi etter posisjon i class)
		stringstream sso; sso << intCardRank;			 //(2): Converterer fra integer til string 
		string cardRank; sso >> cardRank;
		return cardSuit[0] + cardRank;
	}
};

class Card {
	Suit s; Rank r; bool valid;
public:
	Card() : valid(false) {}
	Card(Suit suit) : s(suit), valid(false) {} 
	Card(Rank rank) : r(rank), valid(false) {}
	Card(Suit suit, Rank rank) : s(suit), r(rank), valid(true) {}			// Hva betyr denne syntaksen? Egentlig det etter : frem til {}

	Suit suit() const{		// Const betyr at den ikke får forandre private verdier
		return s;			
	}		
	Rank rank() {
		return r;
	}
	bool isValid() const{
		return valid;
	}
	string toString() {
		if (isValid()) {
			return rankToString(r) + " of " + suitToString(s);
		}
		else {
			return "Invalid card";
		}
	}
	string toStringShort() const{
		if (isValid()) {
			string cardSuit = suitToString(s);
			int intCardRank = static_cast<int>(r) + 2;  // FRA RANK TIL INT
			stringstream sso; sso << intCardRank;		// FRA INT TIL STRING (2)
			string cardRank; sso >> cardRank;			// kunne også bruke sso.str() for å få den som en string
			return cardSuit[0] + cardRank;
		}
		else {
			return "Invalid card";
		}
	}		// Hva er Invariant? isValid da eller?
	int cardValue() {
		int cardValue = (static_cast<int>(r) + 2);
		return cardValue;
	}
};
 
class CardDeck {
	vector<Card> cards;
	int currentCardIndex;
	
	void swap(int indexCardOne, int indexCardTwo) {
		Card temp;
		temp = cards[indexCardOne];
		cards[indexCardOne] = cards[indexCardTwo];
		cards[indexCardTwo] = temp;
	}
	void resetIndex(void) {			//void unngår at den blir overload / omdefinert type void resetIndex(int k).
		currentCardIndex = 0;
	}
public:
	CardDeck() {
		resetIndex();
		for (int suit = 0; suit < 4; ++suit) {					//Clubs/Diamonds/Hearts/Spades
			for (int rank = 0; rank < 13; ++rank) {
				cards.push_back(Card(static_cast<Suit>(suit), static_cast<Rank>(rank)));
			}
		}
	}
	void print() const{
		for (int cardIndex = 0; cardIndex < 52; ++cardIndex) {
			Card printThisCard = cards[cardIndex];
			cout << printThisCard.toString() << endl;
		}
	}
	void printShort() const{
		for (int cardIndex = 0; cardIndex < 52; ++cardIndex) {
			Card printThisCard = cards[cardIndex];
			cout << printThisCard.toStringShort() << endl;
		}
	}
	void shuffle() {
		int randNumber, cardIndexOne, cardIndexTwo; int countNumber = 0;
		do {
			cardIndexOne = randomWithLimits(0, 51);
			cardIndexTwo = randomWithLimits(0, 51);
			swap(cardIndexOne, cardIndexTwo);
			randNumber = randomWithLimits(0, 59); ++countNumber; //Gjør det tilfeldig når stokkingen slutter
		} 
		while (((randNumber < 1) || (countNumber < 600)));
	}
	Card drawCard() {
		return cards[currentCardIndex++];
	}
};





