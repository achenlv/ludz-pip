/*******************************************
Agris Pudāns, ap08426
F10. Dots teksta fails f. Uzrakstīt programmu, kura atrod failā f visus vārdus, kas ir simetriski. 
Izvadīt šos vārdus failā f1. Par vārdu uzskatīt patvaļīgu simbolu virkni, kas atdalīta ar tukšumiem 
vai pieturas zīmēm (punkts, komats, apaļās iekavas, izsaukuma zīme, jautājuma zīme.) 
Simetrisks ir vārds, kas no abām pusēm lasāms vienādi (aka, 1221). 
Drīkst uzskatīt, ka vārda garums nepārsniedz 40.

Programma izveidota: 2017/09/28
*******************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "include/utils.h"

using namespace std;

string stripped(const string& s);
bool palindroms(const string& s);

// Sagatavo vārdu atbilstoši uzdevuma nosacījumiem, tas ir,
// izņem no vārda definētos simbolus - vārda atdalītājus.
string stripped(const string& s) {
  string t;
  bool banned = false;
  char banned_chars[] = {' ', '(', ')', '.', ',', '!', '?'};

  for (char c : s) {
    // Atrod, vai simbols ir vārda atdalītājs
    for (char b : banned_chars) {
      if (c == b) {
        banned = true;
        break;
      }
    }
    // Funkcijas rezultātam pievieno tikai tādu simbolu, kas nav vārda atdalītājs
    if (banned == false) {
      t +=c;
    }
    else {
      banned = false;
    }
  }

  return t;
}

// Atrod, vai vārds ir simetrisks, tar ir, no abām pusēm lasāms vienādi.
// Tiek rādīti tikai vārdi.
bool palindroms(const string& s) {
  int left = 0;
  int right = s.length() - 1;
  while (left < right) {
    if (s[left] != s[right]) {
      return false;
    }
    left++;
    right--;
  }

  return true;
}


int main() {
  // setlocale(LC_CTYPE, "en_US.utf8");

  fstream fin;
  char c;
  string nfails = "input.txt";
  string fails = "input.txt";
  string vards;
  string apstradats_vards;

  do {
    cout << "Lūdzu saglabāt saturu failā input.txt!" << endl;

    fin.open(fails, ios::in);
 
    // Nolasa katru faila vārdu kā mainīgo
    fin >> vards;
    while (fin) {
      fin >> vards;
      apstradats_vards = stripped(vards);
      // Der tādi vārdi, kuru garums ir vairāk nekā 2 simboli
      if ( apstradats_vards.length() > 2 and palindroms(apstradats_vards)) {
        cout << apstradats_vards << endl;
      }
    }
    cout << endl;

    fin.close();
  } while (atkartot() == true);

  return 0;
}