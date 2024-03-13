// #ifndef UTILS_H
// #define UTILS_H

#include <iostream>
using namespace std;

bool atkartot();
int ievads(string t);

bool slikts = false;
int a, b, c;

bool atkartot() {
  cout << "Vai atkārtot? (j,J - jā): ";
  char ievads;
  if (::slikts == true)
  {
    cout << "Slikts ievads. ";
    ::slikts = false;
  }
  cin >> ievads;
  if (ievads == 'j' or ievads == 'J')
    return true;
  return false;
}

int ievads(string t) {
  int a;
  cout << t;
  cin >> a;
  if (cin.fail() || (a <= 0))
  {
    cin.clear();
    cin.ignore(10000, '\n');
    ::slikts = true;
  };
  return a;
}

// #endif