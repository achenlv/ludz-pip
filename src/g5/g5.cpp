/*******************************************
Agris Pudāns, ap08426
G5. Uzrakstīt funkciju, kas pieliek sarakstam jaunu elementu saraksta sākumā, 
ja elements ar tādu vērtību neeksistē. Izveidot divas programmas valodā C++, 
kas strādā ar vērtību virkni divos dažādos veidos:
  1) to realizējot kā vienvirziena saistīto sarakstu, izmantojot dinamiskas datu struktūras,
  2) izmantojot STL::list konteineru.

Abās realizācijās ir jāizveido prasītā specifiskā vērtību virknes apstrādes 
funkcija un jānodemonstrē tā darbībā, cita starpā parādot gan sākotnējās,
gan rezultējošās vērtības.

Abās programmās:
  a) jābūt iespējai ievadīt saraksta elementus (izveidot patvaļīgu sarakstu),
  b) jāpielieto uzrakstītā funkcija sarakstam,
  c) jāizdrukā saraksts pēc funkcijas darbības.
  d) beigās jāiznīcina saraksts - korekti jāatbrīvo izdalītā atmiņa(lietojot delete vai clear).

P.S. Var neprogrammēt patvaļīga elementa ievadīšanu. Var aizpildīt sarakstu 
ar nejaušiem skaitļiem, intervālā no 1 līdz 10. Lietotājs ievada tikai saraksta garumu.

Programma izveidota: 01.04.2024.
*******************************************/

#include <iostream>
#include <list>
#include <memory>
#include <cstdlib>
#include <ctime>
#include "include/utils.h"

using namespace std;

/* Dinamiskā atmiņas funkcijas */
void push_front(Node*& head, int value);
void print_list(Node* head);
/* STL  funkcijas */
//

struct Node {
  int value;
  Node* next;

  Node(int value) {
    this->value = value;
    next = nullptr;
  }
};

int main() {

  /* Dinamiskā atmiņas funkcijas */

  Node* head = nullptr;
  // Pievieno elementus sarakstam.
  push_front(head, 10);
  push_front(head, 20);
  push_front(head, 30);
  push_front(head, 20); // Šis elements netiks pievienots, jo jau eksistē.
  // Izdrukā saraksta elementus.
  print_list(head);

  /* STL  funkcijas */

  list<int> my_list;

  // Pievieno elementus sarakstam.
  my_list.push_front(10);
  my_list.push_front(20);
  my_list.push_front(30);
  my_list.push_front(20); // Šis elements tiks pievienots, jo STL::list atļauj dubultātus elementus.

  // Izdrukā saraksta elementus.
  for (int value : my_list) cout << value << " ";
  cout << endl;

  return 0;
}

void push_front(Node*& head, int value) {
  // Ja sarakstā jau ir elements ar doto vērtību, nepievieno jaunu.
  Node* current = head;
  while (current != nullptr) {
    if (current->value == value) {
      return;
    }
    current = current->next;
  }

  // Izveido jaunu elementu un pievieno to saraksta sākumam.
  Node* new_node = new Node(value);
  new_node->next = head;
  head = new_node;
}

void print_list(Node* head) {
  while (head != nullptr) {
    cout << head->value << " ";
    head = head->next;
  }
  cout << endl;
}

