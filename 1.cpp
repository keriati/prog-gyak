/*
feladat: Írjon egy programot, amely 2 db felhasználói függvényt használ. Az egyik az int beker(int be_tb[], int *min, int
*max), amely 10 db előjeles egész számot kér be úgy, hogy azokat egy tömbbe tárolja le.A tömb hosszát szimbolikus
állandóval állítsa be. A tárolás csak akkor jöjjön létre, ha az alábbi feltételek teljesülnek. A tömb 0. indexén csak a nulla
érték, a páratlan indexein csak páratlan értékek és a páros indexein csak páros számok szerepelhetnek! Ha az adott érték
nem teljesíti a rá vonatkozó feltételt, akkor új számot kell bekérni. Bekérési információk és hibaüzenetek kiírása nem kell!
A feltételek teljesülése esetén a beker függvény határozza meg és tárolja el a legkisebb páratlan, illetve a legnagyobb
páros számokat. Ezen értékek a függvény 2. és 3. paraméterei, amíg az 1. paraméter a tároló tömb. A függvény
visszatérési értéke a 10 db szám összege legyen. A mási függvény a void kiir(int szum, int min, int max), pedig írja ki a
beker függvény visszatérési értékét illetve a 2. és 3. paraméterek értékeit a példában látott szövegezéssel. 
*/

#include <iostream>

#define NUM 10

int beker(int be_tb[], int *min, int *max);


int main(void){

  //nem tudom sose mit kell ide beirni a mainbe
  // tudom h a main adja az "eszközöket" a többi függvénynek de miutánmegirtam a fuggvenyt sose tudom mit kell a mainbe irni
  
  
  return 0;
}

int beker(int be_tb[], int *min, int *max){
  int i = 0, sum = 0;
  do{
    std::cin >> be_tb[i];
    if(i == 0){
      if(be_tb[i] == 0) i++;
    }
      
    else if(i % 2 == 1){
      if(be_tb[i] % 2 == 1){
        sum += be_tb[i];
        if(be_tb[i] < *min){ // nem pontosan tudom miért kell a csillag (tudom pointer elmm de csak mondom :D)
          *min = be_tb[i];
        }
        i++;
      }
    }
      
    else if(i % 2 == 0){
      if(be_tb[i] % 2 == 0){
        sum += be_tb[i];
        if(be_tb[i] > *max){
          *max = be_tb[i];
        }
        i++;
      }
    }
  } while (i < NUM);
  return sum;
}

void kiir(int sum, int min, int max){
  std::cout << "Összeg:" << sum <<  "\nParatlan min: " << min << "\nParos max: " << max              << std::endl; //itt nem tudtam hogy van a mintában ezért magamtol igy irtam
}
