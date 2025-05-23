#include "blackjack.h"
#include "card_engine.h"

bool is_bust(const std::vector<Card> &hand) {
  int value{};

  for (const Card &temp : hand) {
    const int temp_value{static_cast<int>(temp.value)};
    if (temp_value == 0)
      value += 1;
    else if (temp_value < 9)
      value += temp_value + 1;
    else
      value += 10;
  }
  return (value > 21);
}

void hit(Player &player, std::vector<Card> &deck) {
  player.hand.push_back(draw_card(deck));
  player.is_bust = is_bust(player.hand);
}

int hand_value(const std::vector<Card> &hand) {
  int value{};
  int aces{};
  for (const Card &temp : hand) {
    const int current{static_cast<int>(temp.value)};
    if (current == 0)
      aces++;
    else if (current < 9)
      value += current + 1;
    else
      value += 10;
  }
  while (true) {
    if (value + aces * 11 <= 21) {
      value += aces * 11;
      break;
    } else {
      if (aces == 0)break;
      value++;
      aces--;
    }
  }
  return value;
}

void reset(Player& player)
{
  player.is_bust = false;
  player.hand.clear();
}





