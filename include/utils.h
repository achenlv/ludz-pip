#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

bool atkartot();
int ievads(string t);
int skatlagenerators(int start, int end);

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


int skatlagenerators(int start, int end) {
  int a;
  int b;
  // Tests
  if (end < start) {
    a = end;
    b = start;
  } else {
    a = start;
    b = end;
  } 

  srand(static_cast<unsigned int>(time(nullptr)));

  return rand() % (b - a + 1) + a;
}

void skatlagenerators(int start, int end, int* arr) {
  int a;
  int b;
  int c = sizeof(arr) / sizeof(arr[0]);
  // Tests
  if ( arr == nullptr || c < 1 ) return;
  if ( end < start ) {
    a = end;
    b = start;
  } else {
    a = start;
    b = end;
  } 

  // static bool seeded = false;
  // if (!seeded) {
  //   srand(time(0));
  //   seeded = true;
  // }
  srand(static_cast<unsigned int>(time(nullptr)));

  for (int i = 0; i < c; i++) arr[i] = rand() % (b - a + 1) + a;
}

// #endif