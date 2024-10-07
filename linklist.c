#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

// Opretter en ny tom linked liste
LinkList* createList() {
    LinkList* list = (LinkList*)malloc(sizeof(LinkList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// Opretter en ny node
Node* createNode(void* data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->nextNode = NULL;
    node->prevNode = NULL;
    return node;
}

// Tilføjer en node bagerst i listen
void append(LinkList* list, void* data) {
    Node* newNode = createNode(data);
    if (list->tail == NULL) { // Hvis listen er tom
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->prevNode = list->tail;
        list->tail->nextNode = newNode;
        list->tail = newNode;
    }
}

// Tilføjer en node forrest i listen
void prepend(LinkList* list, void* data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) { // Hvis listen er tom
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->nextNode = list->head;
        list->head->prevNode = newNode;
        list->head = newNode;
    }
}

// Indsætter en ny node efter en given node
void insertAfter(Node* node, void* data) {
    if (node == NULL) return;
    Node* newNode = createNode(data);
    newNode->nextNode = node->nextNode;
    newNode->prevNode = node;
    if (node->nextNode != NULL) {
        node->nextNode->prevNode = newNode;
    }
    node->nextNode = newNode;
}

// Fjerner en node fra listen
void removeNode(LinkList* list, Node* node) {
    if (node == NULL) return;
    if (node->prevNode != NULL) {
        node->prevNode->nextNode = node->nextNode;
    } else {
        list->head = node->nextNode;  // Hvis det er første node
    }

    if (node->nextNode != NULL) {
        node->nextNode->prevNode = node->prevNode;
    } else {
        list->tail = node->prevNode;  // Hvis det er sidste node
    }
    free(node);
}

// Ombytter to nodes i listen
void swapNodes(LinkList* list, Node* node1, Node* node2) {
    if (node1 == NULL || node2 == NULL || node1 == node2) return;

    // Ombytter de to nodes' positioner
    Node* tempNext = node1->nextNode;
    Node* tempPrev = node1->prevNode;

    if (node1->nextNode == node2) {
        node1->nextNode = node2->nextNode;
        node1->prevNode = node2;
        node2->nextNode = node1;
        node2->prevNode = tempPrev;
    } else if (node2->nextNode == node1) {
        node2->nextNode = node1->nextNode;
        node2->prevNode = node1;
        node1->nextNode = node2;
        node1->prevNode = tempPrev;
    } else {
        node1->nextNode = node2->nextNode;
        node1->prevNode = node2->prevNode;
        node2->nextNode = tempNext;
        node2->prevNode = tempPrev;
    }

    // Justerer eventuelle head- og tail-pointere
    if (node1->prevNode == NULL) list->head = node1;
    if (node2->prevNode == NULL) list->head = node2;
    if (node1->nextNode == NULL) list->tail = node1;
    if (node2->nextNode == NULL) list->tail = node2;
}

// Udskriver hele listen
void dumpList(LinkList* list) {
    Node* currentNode = list->head;
    while (currentNode != NULL) {
        printf("Node: %p, Data: %p, Next: %p, Prev: %p\n",
               currentNode, currentNode->data,
               currentNode->nextNode, currentNode->prevNode);
        currentNode = currentNode->nextNode;
    }
}

// Frigiver al hukommelse i listen
void freeList(LinkList* list) {
    Node* currentNode = list->head;
    while (currentNode != NULL) {
        Node* tempNode = currentNode;
        currentNode = currentNode->nextNode;
        free(tempNode);
    }
    free(list);
}
