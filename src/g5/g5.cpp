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

Programma izveidota: 
*******************************************/

#include <iostream>
#include <list>
#include <memory>
#include <cstdlib>
#include <ctime>
#include "include/utils.h"

using namespace std;

/* Skaitļu ģenerators */
int skaitlu_generators();
/* Dinamiskā atmiņas funkcijas */
void push_front(Node*& head, int value);
void print_list(Node* head);
/* STL  funkcijas */
//

#define RANGE_MAX 10

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

int skaitlu_generators() {
  // Seed the random number generator with the current time to help ensure we 
  // may get a different sequence of random numbers generated each time the 
  // program runs.
  #define TOTAL_NUMBERS 6
  
  srand((unsigned int) time(NULL));
  
  // Stores each random number generated
  int number = 0;
  
  // Stores the unique lottery numbers generated
  int numbers[TOTAL_NUMBERS];
   
  // Outer loop generates TOTAL_NUMBERS amount of lottery numbers
  for (int i = 0; i < TOTAL_NUMBERS; i++)
  {
     // Generates a random integer in the range of 1-RANGE_MAX.  rand() will
      // return a random integer in the range of 0 ... RAND_MAX (a large 
      // positive integer), applying % RANGE_MAX will result in an integer in
      // the range of 0 ... RANGE_MAX-1 because those are the possible 
      // remainders when dividing by RANGE_MAX and the modulus operator % 
      // gives us the remainder of a division operation.  The +1 will shift 
      // this number into a value in the range 1-RANGE_MAX.
      number = (rand() % RANGE_MAX) + 1;
            
    // Once we have a unique number, store it into the array and output it
    numbers[i] = number;
    cout << "number " << (i+1) << ": " << number << endl;
  }
}
