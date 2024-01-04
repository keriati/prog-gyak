#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;
namespace fs = filesystem;

double area(string fbe);

int main(int argc, char *argv[]) {
  string filePath = argv[1];
  double result;

  result = area(filePath);

  cout << "Atlag:" << result << endl;
}

double area(string fbe) {
  ifstream file(fbe);

  if (!file.is_open()) {
    cout << "N/A" << endl;
    return -1;
  }

  double elsoOldal;
  double masodikOldal;
  double hegyesSzog;

  double elsoOldalak[10];
  double masodikOldalak[10];
  double hegyesSzogek[10];
  double teruletek[10];

  int i = 0;

  while (file >> elsoOldal >> masodikOldal >> hegyesSzog) {
    elsoOldalak[i] = elsoOldal;
    masodikOldalak[i] = masodikOldal;
    hegyesSzogek[i] = hegyesSzog;
    teruletek[i] = (elsoOldal * masodikOldal * sin(hegyesSzog * (M_PI / 180))) / 2;
    i++;
  }

  for (double j : teruletek) {
    if(j >= 2000 && j <= 8000) {
      cout << j << endl;
    } else {
//      cout << "not: " << teruletek[j] << endl;
    }
  }

  double sum = 0;

  for (double j : teruletek) {
    sum += j;
  }

  return sum / 10;
}