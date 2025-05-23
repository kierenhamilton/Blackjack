#include "game.h"

int main() {

  int money{10};
  int wager{};

  while (true) {

    user_input(wager, money);

    game(wager);


    money = money + wager;

    if (money == 0) {
      break;
    }
  }

  return 0;
}
