#include <iostream>
#include <random>
#include <vector>

using namespace std;

int ROWS = 5;
int COLS = 5;
int LIGHT_PERCENT = 36;

void printMap(vector<vector<bool>> map);
void fillMap(vector<vector<bool>> &map, int rows, int cols,
             vector<bool> &mapEntries);
void shuffleMap(vector<bool> &mapEntries);
void updateMap(vector<vector<bool>> &map, int row, int col);
array<pair<int, int>, 4> getNeighbours(int row, int col);
bool isWin(vector<vector<bool>> &map);

int main(int argc, char *argv[]) {
  cout << "Lights out" << endl;

  if (argc == 3) {
    ROWS = stoi(argv[1]) >= 3 ? stoi(argv[1]) : 3;
    COLS = stoi(argv[2]) >= 3 ? stoi(argv[2]) : 3;
    cout << "Rows: " << ROWS << " Cols: " << COLS << endl;
  } else {
    cout << argc << endl;
  }

  int lightCount = (ROWS * COLS * LIGHT_PERCENT) / 100;

  vector<bool> mapEntries;

  for (int i = 0; i < ROWS * COLS; ++i) {
    mapEntries.push_back((lightCount > 0));
    lightCount--;
  }
  shuffleMap(mapEntries);

  vector<vector<bool>> map;
  map.reserve(ROWS);
  fillMap(map, ROWS, COLS, mapEntries);

  bool win = false;
  int rounds = 0;
  while (!win) {
    int row;
    int col;

    printMap(map);
    cout << "Mezo sora: ";
    cin >> row;
    cout << "Oszlopa: ";
    cin >> col;

    updateMap(map, row - 1, col - 1);

    if (isWin(map)) {
      cout << "Gratulalaok, az osszes lampat lekapcsolta " << rounds + 1
           << " atkapcsolassal!" << endl;
      return 0;
    }

    rounds++;
  }
}

bool isWin(vector<vector<bool>> &map) {
  unsigned long rows = map.size();

  for (int i = 0; i < rows; ++i) {
    unsigned long cols = map[i].size();
    for (int j = 0; j < cols; ++j) {
      if (map[i][j])
        return false;
    }
  }

  return true;
}

void printMap(vector<vector<bool>> map) {
  unsigned long rows = map.size();
  unsigned long cols = map[0].size();

  cout << " ";
  for (int i = 1; i <= cols; ++i) {
    cout << i % 10;
  }
  cout << endl;

  for (int i = 0; i < rows; ++i) {
    vector<bool> row = map[i];
    cout << i + 1;
    for (int j = 0; j < cols; ++j) {
      cout << (map[i][j] ? "#" : ".");
    }
    cout << endl;
  }
}

void fillMap(vector<vector<bool>> &map, int rows, int cols,
             vector<bool> &mapEntries) {

  int l = 0;

  for (int i = 0; i < rows; ++i) {
    vector<bool> row;
    row.reserve(cols);
    for (int j = 0; j < cols; ++j) {
      row.push_back(mapEntries[l]);
      l++;
    }
    map.push_back(row);
  }
}

void shuffleMap(vector<bool> &mapEntries) {
  random_device rd;
  mt19937 g(rd());

  shuffle(mapEntries.begin(), mapEntries.end(), g);
}

void updateMap(vector<vector<bool>> &map, int row, int col) {
  int maxRow = map.size();
  int maxCol = map[0].size();

  if (row < 0 || col < 0 || row >= maxRow || col >= maxCol)
    return;

  map[row][col] = !map[row][col];

  array<pair<int, int>, 4> neighbours = getNeighbours(row, col);

  for (auto &neighbour : neighbours) {
    int nRow = neighbour.first;
    int nCol = neighbour.second;

    if (nRow >= 0 && nCol >= 0 && nRow < maxRow && nCol < maxCol) {
      map[nRow][nCol] = !map[nRow][nCol];
    }
  }
}

array<pair<int, int>, 4> getNeighbours(int row, int col) {
  array<pair<int, int>, 4> result;

  result[0] = {row + 1, col};
  result[1] = {row - 1, col};
  result[2] = {row, col + 1};
  result[3] = {row, col - 1};

  return result;
}
