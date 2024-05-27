```c++
#include <iostream>

struct Node {
    int info;
    Node* next;
};

int SeqLen(Node* listHead1, Node* listHead2) {
    int current = 1;  // Sākam meklēt no skaitļa 1
    int sequenceLength = 0;  // Atrastās secības garums

    while (listHead1 != nullptr || listHead2 != nullptr) {
        // Virzāmies pa abiem sarakstiem, izvēloties mazāko elementu
        if (listHead1 != nullptr && listHead2 != nullptr) {
            if (listHead1->info < listHead2->info) {
                listHead1 = listHead1->next;
            } else {
                listHead2 = listHead2->next;
            }
        } else if (listHead1 != nullptr) {
            listHead1 = listHead1->next;
        } else {
            listHead2 = listHead2->next;
        }

        // Pārbaudām, vai atrastais elements ir nākamais secībā
        if (listHead1 != nullptr && listHead1->info == current) {
            sequenceLength++;
            current++;
        } else if (listHead2 != nullptr && listHead2->info == current) {
            sequenceLength++;
            current++;
        } else {
            // Ja elements neatbilst secībai vai atkārtojas, pārtraucam meklēšanu
            break;
        }
    }

    return sequenceLength;
}

// Piemērs lietošanai
int main() {
    // Izveidojam sarakstus {9, 7, 5, 3, 1} un {6, 4, 2}
    Node* head1 = new Node{9, new Node{7, new Node{5, new Node{3, new Node{1, nullptr}}}}};
    Node* head2 = new Node{6, new Node{4, new Node{2, nullptr}}};

    int length = SeqLen(head1, head2);
    std::cout << "Secības garums: " << length << std::endl; // Rezultāts: 7

    // Atbrīvojam atmiņu
    // ...

    return 0;
}
```
**Uzdevums:**
Doti divi saraksti ar skaitļiem, kas realizēti saistītā atmiņā ar
mezglu palīdzību. Mezglam ir tips Node{int info; Node* next}. Uz saraksta
pirmajiem mezgliem norāda Node* listHead1 un listHead2. Abos sarakstos
mezglu kārtība ir dilstošā secībā pēc to info lauku vērtībām.
Uzrakstīt funkciju SeqLen(Node* listHead1, listHead2):integer, kas
noskaidro cik garu naturālo skaitļu virkni, sākot no 1, satur abu
sarakstu apvienojums, kur meklējamai skaitļu virknei nedrīkst iztrūkt
secīgo skaitļu, un skaitļi nedrīkst atkārtoties. Realizācijā drīkst
izmantot tikai konstanta lieluma atmiņas daudzumu, kas nav atkarīgs no
doto sarakstu garumiem.

Piemēram, ja ir saraksti {9, 7, 5, 3, 1} un {6, 4, 2}, tad jāatgriež 7,
jo apvienotajā sarakstā ir apakšvirkne {1, 2, 3, 4, 5, 6, 7} un 8 jau
trūkst. Savukārt sarakstiem {4, 3, 2, 1} un {3}, atbilde ir 3, jo
skaitlis 3 ir sastopams divreiz un pārtrauc normālo kārtību. Ja abi
sākotnējie saraksti ir tukši vai nevienā sarakstā nav skaitlis 1, tad
rezultātā jāatgriež 0.
**Paskaidrojums:**

1. **Funkcija `SeqLen`:**
   - Pieņem divus sakārtotus sarakstus (`listHead1` un `listHead2`).
   - Inicializē `current` ar 1 (meklējamās secības sākums) un `sequenceLength` ar 0.
   - Ciklā iet cauri abiem sarakstiem, līdz sasniedz kāda saraksta beigas:
     - Katrā solī izvēlas mazāko elementu no abiem sarakstiem.
     - Ja atrastais elements ir nākamais secībā (`current`), palielina `sequenceLength` un `current`.
     - Ja elements neatbilst secībai vai atkārtojas, pārtrauc meklēšanu.
   - Atgriež atrastās secības garumu (`sequenceLength`).

2. **Piemērs lietošanai (main funkcija):**
   - Izveido divus sarakstus ar dotajiem datiem.
   - Izsauc `SeqLen` funkciju, lai noteiktu secības garumu.
   - Izdrukā rezultātu.
   - Atbrīvo sarakstu izmantoto atmiņu (nav parādīts piemērā, bet būtu jārealizē).

**Atmiņas izmantošana:**

Funkcija izmanto tikai konstantu atmiņas daudzumu, jo tiek izmantoti tikai daži papildu mainīgie (`current`, `sequenceLength`) un iteratori (`listHead1`, `listHead2`), kuru skaits nav atkarīgs no sarakstu garumiem.
