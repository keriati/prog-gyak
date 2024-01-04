#include <fstream>
#include <iostream>

using namespace std;
namespace fs = filesystem;

struct triathlete {
  string licence;
  int uszas_ido;
  int kerekpar_ido;
  int futas_ido;
  int depo_ido;
  int sum;
};

string tri_result(string fbe);

int main(int argc, char *argv[]) {
  cout << "TriResult" << endl;

  string filePath = argv[1];
  string result;

  result = tri_result(filePath);

  cout << result << endl;
}

string tri_result(string fbe) {

  ifstream file(fbe);

  if (!file.is_open()) {
    return "N/A!";
  }

  int entries;

  file >> entries;

  vector<triathlete> triathleteArray;
  triathleteArray.reserve(entries);

  string licence;
  int num1, num2, num3, num4;

  while (file >> licence >> num1 >> num2 >> num3 >> num4) {
    triathleteArray.push_back(
        {licence, num1, num2, num3, num4, num1 + num2 + num3 + num4});
  }

  file.close();

  int maxTime = 0;
  string maxLicense;

  for (auto &triathlete : triathleteArray) {
    if (triathlete.sum > maxTime) {
      maxTime = triathlete.sum;
      maxLicense = triathlete.licence;
    }
  }

  return maxLicense;
}
