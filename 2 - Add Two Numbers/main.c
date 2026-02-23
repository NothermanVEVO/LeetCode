#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *result = malloc(sizeof(struct ListNode));
    struct ListNode *currentNode = result;
    currentNode->val = 0;
    
    struct ListNode *currentNode1 = l1;
    struct ListNode *currentNode2 = l2;

    int rest = 0;

    while (currentNode1 != NULL || currentNode2 != NULL){
        int value = rest;

        if(currentNode1 != NULL){
            value += currentNode1->val;
            currentNode1 = currentNode1->next;
        }
        if(currentNode2 != NULL){
            value += currentNode2->val;
            currentNode2 = currentNode2->next;
        }

        if(value > 9){
            currentNode->val = value - 10;
            rest = 1;
        } else{
            currentNode->val = value;
            rest = 0;
        }

        if(currentNode1 != NULL || currentNode2 != NULL){
            struct ListNode *nextNode = malloc(sizeof(struct ListNode));
            nextNode->val = 0;
            nextNode->next = NULL;
            currentNode->next = nextNode;
            currentNode = nextNode;
        } else{
            currentNode->next = NULL;
        }
    }
    
    if(rest > 0){
        struct ListNode *nextNode = malloc(sizeof(struct ListNode));
        nextNode->val = rest;
        nextNode->next = NULL;
        currentNode->next = nextNode;
    }

    return result;
}

// Função para criar um nó
struct ListNode* createNode(int val) {
    struct ListNode* node = malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Função para imprimir a lista
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d", head->val);
        if (head->next != NULL) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

// Função para liberar memória
void freeList(struct ListNode* head) {
    struct ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(){

    // l1 = 8 -> 9 -> 9 -> 9 -> 0 -> 0 -> 0 -> 1
    struct ListNode* l1 = createNode(9);
    l1->next = createNode(9);
    l1->next->next = createNode(9);
    l1->next->next->next = createNode(9);
    l1->next->next->next->next = createNode(9);
    l1->next->next->next->next->next = createNode(9);
    l1->next->next->next->next->next->next = createNode(9);

    // l2 = 9 -> 9 -> 9 -> 9
    struct ListNode* l2 = createNode(9);
    l2->next = createNode(9);
    l2->next->next = createNode(9);
    l2->next->next->next = createNode(9);

    printf("Lista 1: ");
    printList(l1);

    printf("Lista 2: ");
    printList(l2);

    // Chama sua função
    struct ListNode* result = addTwoNumbers(l1, l2);

    printf("Resultado: ");
    printList(result);

    // Libera memória
    freeList(l1);
    freeList(l2);
    freeList(result);

    return 0;
}