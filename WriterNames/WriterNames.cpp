#include <iostream>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

std::string first_last(std::string fbe, std::string fki);

int main(int argc, char *argv[]) {
    std::string result;
    std::string fbe = argv[1];
    std::string fki;

    result = first_last(fbe, fki);

    std::cout << result << std::endl;
}

std::string first_last(std::string fbe, std::string fki) {

    if( ! fs::exists(fbe)) {
        return "Sikertelen file-nyitás!";
    }

    int sorokSzama = 4;

    std::string** sorok = new std::string*[sorokSzama];

    for (size_t i = 0; i < sorokSzama; i++)
    {
        int szavakSzama = 3;
        sorok[i] = new std::string[5];
        for (size_t j = 0; j < szavakSzama; j++)
        {
            sorok[i][j] = "asd";
        }
        
    }
    


    return "Hibátlan futás!";
}

