#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node{
    int num;
    Node *next;
}*head1, *tail1, *head2, *tail2;

Node *createNode (int num) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->num = num;
    newNode->next = NULL;
    return newNode;
}

void pushHead1(int num){
    Node *temp1 = createNode(num);

    if(!head1){
        head1 = tail1 = temp1;
    } else {
        temp1->next = head1;
        head1 = temp1;
    }
}

void pushTail1(int num){
    Node *temp1 = createNode(num);

    if(!tail1){
        head1 = tail1 = temp1;
    } else {
        tail1->next = temp1;
        tail1 = temp1;
    }
}

void pushHead2(int num){
    Node *temp2 = createNode(num);

    if(!head2){
        head2 = tail2 = temp2;
    } else {
        temp2->next = head2;
        head2 = temp2;
    }
}

void pushTail2(int num){
    Node *temp2 = createNode(num);

    if(!tail2){
        head2 = tail2 = temp2;
    } else {
        tail2->next = temp2;
        tail2 = temp2;
    }
}

Node *merge (Node *h1, Node *h2){
    if(!h1){
        return h2;
    }
    if(!h2){
        return h1;
    }

    if(h1->num < h2->num){
        h1->next = merge(h1->next, h2);
        return h1;
    } else {
        h2->next = merge(h1, h2->next);
        return h2;
    }
}

void printList (Node *node){
    while (node){
        printf("%d ", node->num);
        node = node->next;
    }
}

int main(){
    pushHead1(1);
    pushTail1(3);
    pushTail1(5);
    printf("Linked list 1:\n");
    printList(head1);
    printf("\n");
    pushHead2(2);
    pushTail2(4);
    pushTail2(6);
    printf("Linked list 2:\n");
    printList(head2);
    printf("\n");
    
    Node *mergedhead = merge(head1, head2);

    printf("Merged Linked List:\n");
    printList(mergedhead);
    return 0;

    return 0;
}