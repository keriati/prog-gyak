#include <chrono>
#include <iostream>
#include <random>

using namespace std;

double area(string fbe);

void clearTerminal() {
  for (int i = 0; i < 25; ++i) {
    cout << endl;
  }
}

void shuffleCards(char *cards);

void printState(char *cards, bool *found);

int main(int argc, char *argv[]) {
  cout << "Memoriajatek:" << endl;

  bool torolj = false;

  cout << argv[1] << endl;

  if (strcmp(argv[1], "torles") == 0) {
    torolj = true;
  }

  char cards[7] = {};
  char cardTypes[3] = {'a', 'b', 'c'};
  bool found[6] = {false, false, false, false, false, false};

  for (int i = 0; i < sizeof cards - 1; ++i) {
    cards[i] = cardTypes[i % 3];
  }

  shuffleCards(cards);

  bool win = false;
  int rounds = 0;
  int foundCount = 0;

  while (!win) {
    printState(cards, found);

    int row, col;
    cout << "Megforditando kartya sora:";
    cin >> row;
    cout << "Oszlopa:";
    cin >> col;
    int index = ((row - 1) * 3) + col - 1;

    found[index] = true;
    printState(cards, found);

    int row2, col2;
    cout << "Megforditando kartya sora:";
    cin >> row2;
    cout << "Oszlopa:";
    cin >> col2;
    int index2 = ((row2 - 1) * 3) + col2 - 1;

    found[index2] = true;
    printState(cards, found);

    cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (cards[index2] == cards[index]) {
      cout << "Egyformak, a kartyak igy maradnak." << endl;
      foundCount++;
      cin.get();
    } else {
      found[index] = false;
      found[index2] = false;
      cout << "Nem egyeznek, visszaforditom a lapokat." << endl;
      cin.get();
    }

    if (foundCount == 3) {
      cout << "Gratulalok, On nyert " << rounds << " forditasbol." << endl;
      return 0;
    }

    if (torolj)
      clearTerminal();
    rounds++;
  }
}

void printState(char *cards, bool *found) {
  cout << " 123" << endl;
  cout << 1;
  for (int i = 0; i < 6; ++i) {

    if (found[i])
      cout << cards[i];
    else
      cout << "*";

    if (i == 2) {
      cout << endl;
      cout << "2";
    }
  }
  cout << endl;
}

void shuffleCards(char *cards) {
  unsigned seed = chrono::system_clock::now().time_since_epoch().count();
  default_random_engine engine(seed);

  shuffle(cards, cards + 6, engine);
}