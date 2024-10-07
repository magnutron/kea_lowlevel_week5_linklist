# Doubly Linked List Library

Dette library implementerer en dobbelt-hægtet (doubly linked) liste i C. Det giver funktionalitet til at oprette, tilføje, fjerne, og manipulere noder i en dynamisk liste.

## Installation

1. Kopier `linklist.h` og `linklist.c` til dit projekt.
2. Inkludér header-filen i din C-kode:
   ```
   #include "linklist.h"
   ```
3. Kompilér dit program sammen med linklist.c
   ```
   gcc -o program main.c linklist.c
   ```

## Funktioner

LinkList\* createList()  
 Opretter en ny, tom liste. Returnerer en pointer til listen.

void freeList(LinkList\* list)  
 Frigiver al hukommelse brugt af listen og dens noder.

void append(LinkList* list, void* data)  
 Tilføjer en node med data til slutningen af listen.

void prepend(LinkList* list, void* data)  
 Tilføjer en node med data til starten af listen.

void removeNode(LinkList* list, Node* node)  
 Fjerner en specifik node fra listen og frigiver dens hukommelse.

void insertAfter(Node* node, void* data)  
 Indsætter en ny node med data efter en given node.

void swapNodes(LinkList* list, Node* node1, Node\* node2)  
 Ombytter to noder i listen.

void dumpList(LinkList\* list)  
 Udskriver listen, inklusive pointere til næste og forrige node, for at debugge.

## Eksempel

```
#include "linklist.h"

int main() {

    LinkList* list = createList();

    int a = 10, b = 20, c = 30;
    append(list, &a);
    append(list, &b);
    prepend(list, &c);

    dumpList(list);  // Udskriv listen
    freeList(list);  // Frigiv hukommelse
    return 0;

}
```
