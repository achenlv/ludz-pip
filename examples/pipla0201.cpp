#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

// PiPLa0201. Sastādīt C++ programmu, kas noskaidro, 
// vai dotajā skaitļu virknē ir sastopams lietotāja dots skaitlis. 
// Skaitļu virkne jārealizē divos veidos, 
// izmantojot STL::list konteineru un izmantojot STL::vector konteineru. 


int main() {
  // list<int> llist = { 1,3,5,7,9 };
  list<int> llist = { 1,3,3,5,7,3,9 };
  // vector<int> vlist = { 0,2,4,6,8 };
  vector<int> vlist = { 0,2,2,2,2,4,6,2,2,8 };

  int x;
  cout << "Ievadiet meklejamo skaitli: ";
  cin >> x;

  for (auto it = llist.begin(); it != llist.end(); ++it) {
    if (*it == x) {
      cout << " ir  sarakstaa " << *it << endl; 
      break;
    }
  }

  auto it2 = find (vlist.begin(), vlist.end(), x);
  if (it2 != vlist.end()) {
    cout << " ir vektoraa" << endl;
  }

  // Sastādīt C++ programmu, kas izdzēš no dotās skaitļu virknes lietotāja dotu skaitli visās tā vietās. 
  // Skaitļu virkne jārealizē divos veidos, izmantojot STL::list konteineru un izmantojot STL::vector konteineru. 

  // Pie v2 izdzesta elementa vietaa iespraust skaitli n:
  // Sastādīt C++ programmu, kas iesprauž dotajā skaitļu virknē lietotāja dotu skaitli kā n-to elementu. Lietotājs ievada gan skaitli, gan kārtas numuru n (n>=1).
  // Skaitļu virkne jārealizē divos veidos, izmantojot STL::list konteineru un izmantojot STL::vector konteineru.

  // v1
  // int vi = 0;
  // while (vi < vlist.size()) {
  //   if (vlist[vi] == x) {
  //     cout << "izdzeests " << vlist[vi] << endl;
  //     vlist.erase(vlist.begin() + vi);
  //   }
  //   else {
  //     vi++;
  //   }
  // }

  // v2
  // int vii = 0;
  // do {
  //   vii++;
  //   auto vi = find(vlist.begin(),vlist.end(), x);
  //   if (vi != vlist.end()) {
  //     cout << "izdzeests " << *vi << endl;
  //     vlist.erase(vi);
  //   }
  // } while ( vii  < vlist.size() );

  // v2` - Straujuma versija
  // bool irDzests = true;
  // do {
  //   auto vi find(vlist.begin(),vlist.end(),x);
  //   if (vi != vlist.end()) {
  //     vlist.erase[vi];
  //   }
  //   else {
  //     irDzests = true;
  //   }
  // } while (irDzests);

  // v3 - v2 kopaa ar PiPLa0203
  int vii = 0;
  int n;
  do {
    vii++;
    auto vi = find(vlist.begin(),vlist.end(), x);
    if (vi != vlist.end()) {
      cout << "izdzeests " << *vi << endl;
      vlist.erase(vi);
      cout << "ievadit jauno skaitli: ";
      cin >> n;
      vlist.insert( vi, n);
    }
  } while ( vii  < vlist.size() );



  cout << "Vektoraa ir:";
  // v1
  for (auto it=vlist.begin(); it < vlist.end(); it++)
    cout << ' ' << *it;
  cout << endl;

  // v2
  for (auto &it2: vlist) {
    cout << ' ' << it2;
  }
  cout << endl;
  return 0;
}