#include "game.h"
#include "blackjack.h"
#include "card_engine.h"
#include <iostream>
#include <limits>

void user_input(int &wager, const int &money) {

  system("clear");
  std::cout << "You have £" + std::to_string(money) + "\n";
  std::cout << "how much would you like to wager: ";

  std::cin >> wager;

  if (std::cin.fail()) {
    wager = money;
    std::cout << "\nUnclean input means you're all in lol\n"
              << "\npress enter to continue... ";

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
  }

  else if (wager < 1 || wager > money) {
    std::cout << "\nYou can't do that so you're all in lol\n"
              << "\npress enter to continue... ";
    wager = money;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
  }
}

void game(int &wager) {

  system("clear");
  std::vector<Card> deck{};
  init_deck(deck);
  shuffle(deck);

  Player player;
  Player dealer;

  reset(player);
  reset(dealer);

  hit(dealer, deck);
  std::cout << "DEALER:\n";
  display(dealer.hand);
  

  while (!player.is_bust) {
    std::cout << "\ntype 'stand' or hit enter: ";
    std::string input;
    std::cin >> input;
    std::cout << std::endl;
    if (input == "stand")
      break;
    hit(player, deck);
    system("clear");
    std::cout << "DEALER:\n";
    display(dealer.hand);
    std::cout << "\nYOU:\n";
    display(player.hand);
  }
  if (player.is_bust) std::cout << "BUST";

  const int player_value{hand_value(player.hand)};

  while (!player.is_bust && !dealer.is_bust && hand_value(dealer.hand) < 17) {
    hit(dealer, deck);
  }

  std::cout << std::endl << "---------------\n";
  if (player.is_bust) {
    wager = wager * -1;
    std::cout << "\nYOU LOSE!\n";
  } else  {
    std::cout << "\n";
    display(dealer.hand);

    if (dealer.is_bust) {
      std::cout << "BUST\n";
      wager = wager * 2;
      std::cout << "\nYOU WIN!\n";
    } else if (hand_value(player.hand) < hand_value(dealer.hand)) {
      wager = wager * -1;
      std::cout << "\nYOU LOSE\n";
    } else if (hand_value(player.hand) == hand_value(dealer.hand)) {
      wager = 0;
      std::cout << "\nDRAW\n";
    }
    else {
      wager = wager * 2;
      std::cout << "\nYOU WIN\n";
    }
  }


    std::cout << "\nPress enter... ";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
  }
