#include <iostream>
#include <vector>
#include <random>
#include <string>

//#define NYOMKOVETES
using namespace std;
using LightMap = vector<vector<bool>>;


void shuffleMap(vector<bool>& mapEntries);
void printMap(LightMap map);
void createMap(LightMap& map, int row, int col);
void flip(LightMap& map, int row, int col);
bool didWin(LightMap& map);



int main(int argc, char* argv[])
{
    std::cout << "Lights Out\n";
    
    LightMap map;

    int row = 5;
    int col = 5;

    if (argc == 3) {
        row = stoi(argv[1]);
        col = stoi(argv[2]);
    }

    createMap(map, row, col);
    
    bool win = false;

    int rounds = 0;

    do {
        printMap(map);

        int row;
        int col;

        cout << "Mezo sora: ";
        cin >> row;

        cout << "Oszlopa: ";
        cin >> col;

        flip(map, row, col);

        win = didWin(map);

        rounds++;
    } while (!win);


    printMap(map);

    cout << "Gratulalaok, az osszes lampat lekapcsolta " << rounds << " atkapcsolassal!" << endl;
}



bool didWin(LightMap &map) {

    int rows = map.size();
    int cols = map[0].size();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (map[i][j]) {
                return false;
            }
        }
            
    }

    return true;
}

//megkeveri a már meglévő elemeket
void shuffleMap(vector<bool>& mapEntries) {
    random_device rd;
    mt19937 g(rd());

    shuffle(mapEntries.begin(), mapEntries.end(), g);
}

void printMap(LightMap map) {

    int rows = map.size(); //itt meg a sorok számának a nagyságát kapom meg
    int cols = map[0].size(); //map[0], hogy egy random sort ad, aminek a hossza adja meg az oszlopok számát
    cout << ' ';
    for (int i = 1; i < cols + 1; i++) {
        cout << i;
    }
    cout << endl;
    for (int i = 0; i < rows; i++) {
        cout << i + 1;
        for (int j = 0; j < cols; j++) {
            cout << (map[i][j] ? "*": "."); //? shorthand if, az első az igaz masodik a hamis
        }
        cout << endl;
    }
}

void createMap(LightMap &map, int row, int col) {
    int vilagos = (col * row) * 0.36;

    vector<bool> elemek;
    elemek.reserve(col * row);

#ifdef NYOMKOVETES

    elemek = {
            false, false, false, false, false,
            false, true, false, true, false,
            true, true, false, true, true,
            false, true, false, false, true,
            false, false, true, false, false
    };

#else
        
    for (int i = 0; i < col * row; i++) {
        elemek.push_back(i < vilagos);
    }

    shuffleMap(elemek);

#endif

    int e = 0;

    for (int i = 0; i < row; i++) {
        vector<bool> mapRow;
        for (int j = 0; j < col; j++) {
            mapRow.push_back(elemek[e]);
            e++;
        }
        map.push_back(mapRow);
    }
}

void flip(LightMap &map, int row, int col) {
    int y = row - 1;
    int x = col - 1;
    
    pair<int, int> szomszedok[5] = {
        {y, x},
        {y + 1, x}, 
        {y - 1, x},
        {y, x + 1},
        {y, x - 1}
    };

    for(auto pos : szomszedok)
    {
        int posy = pos.first;
        int posx = pos.second;

        if (posy < 0 || posx < 0 || posy >= map.size() || posx >= map[0].size()) {
            continue;
        }

        map[posy][posx] = !map[posy][posx];
    }

}