#include <iostream>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

string first_last(string fbe, string fki);

int main(int argc, char *argv[]) {
    cout << "WriterNames" << endl;

    string result;
    if(argc != 2) {
        cout << "Need 2 arguments!" << endl;
        return 1;
    }
    string fbe = argv[1];
    string fki = argv[2];

    result = first_last(fbe, fki);

    cout << result << endl;
}

string first_last(string fbe, string fki) {
    cout << "Be: " << fbe << " Ki: " << fki << endl;

    if( ! fs::exists(fbe)) {
        return "Sikertelen file-nyitás!";
    }

    int sorokSzama = 4;

    string** sorok = new string*[sorokSzama];

    for (size_t i = 0; i < sorokSzama; i++)
    {
        int szavakSzama = 3;
        sorok[i] = new string[5];
        for (size_t j = 0; j < szavakSzama; j++)
        {
            sorok[i][j] = "asd";
        }
        
    }
    


    return "Hibátlan futás!";
}

