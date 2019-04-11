#include "card.hpp"
#include <string>

Card::Card(int cardFace, int cardSuit) {
  face = cardFace;
  suit = cardSuit;
}
std::string Card::toString() const {
  std::string res("");
  res = res + faceNames[face];
  res = res + " of ";
  res = res + suitNames[suit];
  return res;
}

int Card::getFace() const { return face; }
int Card::getSuit() const { return suit; }

const char* Card::faceNames[Card::totalFaces] = {
    "Ace",   "Deuce", "Three", "Four", "Five",  "Six", "Seven",
    "Eight", "Nine",  "Ten",   "Jack", "Queen", "King"};

const char* Card::suitNames[Card::totalSuits] = {"Hearts", "Diamonds", "Clubs",
                                                 "Spades"};