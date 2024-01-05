#include <iostream>

#define SIZE 10

using namespace std;

int beker(int be_tb[], int *min, int *max);

void kiir(int szum, int min, int max);

int main() {
  cout << "SignedIntSum" << endl;

  int tomb[SIZE] = {};
  int min_odd, max_even, sum;
  sum = beker(tomb, &min_odd, &max_even);
  kiir(sum, min_odd, max_even);
  return 0;
}

bool isSignedInteger(const string &input) {
  if (input.empty() || input == "-" || input == "+") {
    return false;
  }

  int start = 0;
  if (input[0] == '-' || input[0] == '+') {
    start = 1;
  }

  for (int i = start; i < input.length(); i++) {
    if (input[i] < '0' || input[i] > '9') {
      return false;
    }
  }
  return true;
}

int beker(int be_tb[], int *min, int *max) {
  int sum = 0;
  char ch;

  string input;

  *min = INT_MAX;
  *max = INT_MIN;
  for (int i = 0; i < SIZE; i++) {
    bool validInput = false;

    while (!validInput) {
      input.clear();

      while ((ch = cin.get()) != '\n') {
        input.push_back(ch);
      }

      if (!isSignedInteger(input))
        continue;

      int integerFromInput = stoi(input);

      if (i == 0 && integerFromInput == 0 ||
          i % 2 != 0 && integerFromInput % 2 != 0 ||
          i % 2 == 0 && integerFromInput % 2 == 0) {

        be_tb[i] = integerFromInput;

        validInput = true;
        sum += be_tb[i];

        if (i % 2 != 0 && be_tb[i] < *min)
          *min = be_tb[i];
        if (i % 2 == 0 && be_tb[i] > *max)
          *max = be_tb[i];
      }
    }
  }
  return sum;
}

void kiir(int szum, int min, int max) {
  cout << "Sum: " << szum << ", Min odd: " << min << ", Max even: " << max
       << endl;
}
