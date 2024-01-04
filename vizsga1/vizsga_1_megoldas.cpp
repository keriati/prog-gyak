#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

string first_last(string fbe, string fki) {
    ifstream inputFile(fbe);

    ofstream outputFile(fki);

    if (inputFile.is_open()) {

        if (outputFile.is_open()) {

            int sorokSzama, sorHossza, k;

            string vks, ent = "\n";

            inputFile >> sorokSzama;

            getline(inputFile, vks);

            string *sorok = new string[sorokSzama];

            for (int i = 0; i < sorokSzama; i++) {

                getline(inputFile, sorok[i]);

                sorHossza = sorok[i].length();

                char *keresztNev = new char[sorHossza];

                // szavakra bontas
                for (int j = 0; j < sorHossza; j++) {
                    keresztNev[j] = sorok[i][j];
                    if (sorok[i][j] == ' ')
                        k = j;
                }

                keresztNev[k] = '\0';

                char *vezetekNev = new char[sorHossza - k + 3];

                k++;

                int j;

                for (j = 0; k < sorHossza; j++, k++) {
                    vezetekNev[j] = sorok[i][k];
                }

                vezetekNev[j] = ',';
                vezetekNev[j + 1] = ' ';

                cout << vezetekNev << keresztNev << endl;

                outputFile.write(vezetekNev, strlen(vezetekNev));
                outputFile.write(keresztNev, strlen(keresztNev));
                outputFile.write(ent.c_str(), 1);

                for (int j = 0; j < sorHossza; j++) {
                    keresztNev[j] = '\0';
                }

                delete[] keresztNev;
                keresztNev = 0;
                delete[] vezetekNev;
                vezetekNev = 0;
            }
            delete[] sorok;
            sorok = 0;

            outputFile.close();
        } else {
            return "Háttértár hiba!";
        }

        inputFile.close();
    } else {
        return "Sikertelen file-nyitás!";
    }
    return "Hibátlan futás!";
}

int main(void) {
    string f_be = "Writers.txt", f_ki = "Sretirw.txt";
    cout << first_last(f_be, f_ki) << endl;
    return 0;
}