#ifndef LINKLIST_H
#define LINKLIST_H

// Definer en struct for en node i den dobbelt-hægtede liste
typedef struct Node {
    struct Node* nextNode;  // Pointer til næste node
    struct Node* prevNode;  // Pointer til forrige node
    void* data;             // Pointer til data
} Node;

// Definer en struct for selve den dobbelthægtede liste
typedef struct LinkList {
    Node* head;  // Pointer til første node i listen
    Node* tail;  // Pointer til sidste node i listen
} LinkList;

// Funktionsprototyper
LinkList* createList();               // Opretter en tom liste
Node* createNode(void* data);         // Opretter en node med data
void append(LinkList* list, void* data); // Tilføj en node bagerst i listen
void prepend(LinkList* list, void* data); // Tilføj en node forrest i listen
void insertAfter(Node* node, void* data); // Indsæt en node efter en given node
void removeNode(LinkList* list, Node* node); // Fjern en node fra listen
void swapNodes(LinkList* list, Node* node1, Node* node2); // Ombyt to nodes i listen
void dumpList(LinkList* list);         // Udskriv hele listen
void freeList(LinkList* list);         // Frigiv al hukommelse i listen

#endif // LINKLIST_H
