#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "card_engine.h"
#include <array>
#include <vector>

struct Player {
  std::vector<Card> hand{};
  bool is_bust{};
};

int hand_value(const std::vector<Card> &hand);

bool is_bust(const std::vector<Card> &hand);

void hit(Player &player, std::vector<Card> &deck);

void reset(Player &player);

#endif
