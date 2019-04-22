#include "deck-of-cards.hpp"

DeckOfCards::DeckOfCards() {
  for (int j = 0; j < 4; j++)
    for (int i = 0; i < 13; i++) {
      deck.push_back(Card(12 - i, 3 - j));
    }
}
Card DeckOfCards::dealCard() {
  Card current = deck.back();
  deck.pop_back();
  return (current);
}
bool DeckOfCards::moreCards() const { return (!deck.empty()); }