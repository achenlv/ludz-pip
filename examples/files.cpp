#include<fstream>
#include<iostream>
using namespace std;

int main_start() {
  fstream f;
  char c;
  int garums = 0;
  f.open("lab19.txt", ios::in);
  f.get(c);
  while (f) {
    cout << c;
    garums++;
    f.get(c);
  }
  f.close();
  cout << "\nSimbolu skaits failā:  " << garums << endl;

  return 0;
}

int oops() {
  fstream f;
  char c;
  int garums = 0;
  f.open("lab19.txt", ios::in);
  f >> i;
  while (f) {
    garums++;
    f >> i;
    cout << i << endl;
  }
  f.close();
  return 0;
}


int readchars() {
  fstream f1;
  fstream f2;
  char c;
  f1.open("lab19.txt", ios::in);
  f2.open("lab20.txt", ios::app);
  return 0;
}

// Ja vārds sākas ar mazo burtu, pārvērst par lielo
int uzd8() {
  fstream f1;
  fstream f2;
  char c;
  int garums = 0;
  f1.open("lab19.txt", ios::in);
  f2.open("lab20.txt", ios::app);
  f2<< "faila kopija!" << endl;
  f1.get(c);
  while (f1) {
    if (garums == 0) {
      c = 33 + c;
      cout << c;
    }
    f2.put(c);
    f1.get(c);
  }
  f1.close();
  f2.close();


  return 0;
}

int main() {
  uzd8();


  return 0;
}