#include <iostream>

#define SIZE 50

using namespace std;

int feltolt(char s_tb[50]);

void torol(char tomb[50], int len);

bool isLetter(char ch);

int main() {
  cout << "SecondChar" << endl;

  char tomb[SIZE] = {};
  int len;
  len = feltolt(tomb);
  cout << "You entered: " << tomb << endl;
  torol(tomb, len);
}

bool isLetter(char ch) {
  if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
    return true;
  }
  return false;
}

void torol(char tomb[SIZE], int len) {
  char torolt[25] = {};

  for (int i = 0; i < len; ++i) {
    if (i % 2 == 0) {
      torolt[i / 2] = tomb[i];
    }
  }
  cout << "Result: " << torolt << endl;
}

int feltolt(char s_tb[]) {
  int i = 0;
  char ch;

  while (i < SIZE) {
    ch = cin.get();

    if (ch == '\n')
      break;

    if (!isLetter(ch))
      continue;

    s_tb[i] = ch;
    i++;
  }

  return i;
}
