#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

string first_last(string fbe, string fki);

int main(void) {
  string f_be = "Writers.txt", f_ki = "Sretirw.txt";
  cout << first_last(f_be, f_ki) << endl;
  return 0;
}

string first_last(string fbe, string fki) {
  ifstream inputFile(fbe);

  ofstream outputFile(fki);

  if (!inputFile.is_open())
    return "Sikertelen file-nyitás!";

  if (!outputFile.is_open())
    return "Háttértár hiba!";

  int sorokSzama, sorHossza, keresztnevek;

  string sor, ent = "\n";

  inputFile >> sorokSzama;

  getline(inputFile, sor);

  string *sorok = new string[sorokSzama];

  for (int i = 0; i < sorokSzama; i++) {

    getline(inputFile, sorok[i]);

    sorHossza = sorok[i].length();

    char *keresztNev = new char[sorHossza];

    // szavakra bontas
    for (int j = 0; j < sorHossza; j++) {
      keresztNev[j] = sorok[i][j];

      if (sorok[i][j] == ' ')
        keresztnevek = j;
    }

    keresztNev[keresztnevek] = '\0';

    char *vezetekNevek = new char[sorHossza - keresztnevek + 3];

    keresztnevek++;

    int j;

    for (j = 0; keresztnevek < sorHossza; j++, keresztnevek++) {
      vezetekNevek[j] = sorok[i][keresztnevek];
    }

    vezetekNevek[j] = ',';
    vezetekNevek[j + 1] = ' ';

    cout << vezetekNevek << keresztNev << endl;

    outputFile.write(vezetekNevek, strlen(vezetekNevek));
    outputFile.write(keresztNev, strlen(keresztNev));
    outputFile.write(ent.c_str(), 1);

    for (int j = 0; j < sorHossza; j++) {
      keresztNev[j] = '\0';
    }

    delete[] keresztNev;
    keresztNev = 0;
    delete[] vezetekNevek;
    vezetekNevek = 0;
  }

  delete[] sorok;
  sorok = 0;

  outputFile.close();

  inputFile.close();

  return "Hibátlan futás!";
}
