#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
  char name[255];
  int score;
  Node *next;
} *head, *tail;

Node *createNode(const char *name, int score) {
  Node *newNode = (Node*)malloc(sizeof(Node));
  strcpy(newNode->name, name);
  newNode->score = score;
  newNode->next = NULL;
  return newNode;
}

void pushHead(const char *name, int score) {
  Node *temp = createNode(name, score);

  if(!head) {
    head = tail = temp;
  } else {
    temp->next = head;
    head = temp;
  }
}

void pushTail(const char *name, int score) {

  Node *temp = createNode(name, score);

  if(!head) {
    head = tail = temp;
  } else {
    tail->next = temp;
    tail = temp;
  }
}

void popHead() {
  if(!head) {
    return;
  } else if(head == tail) {
    free(head);
    head = tail = NULL;
  } else {
    Node *temp = head->next;
    head->next = NULL;
    free(head);
    head = NULL;
  }
}

void popTail() {
  if(!head) {
    return;
  } else if(head == tail) {
    free(head);
    head = tail = NULL;
  } else {

    Node *temp = head;
    while(temp->next != tail) {
      temp = temp->next;
    }


    temp->next = NULL;
    free(tail);
    tail = temp;
  }
}

void printLinkedList() {
  Node *curr = head;

  while(curr) {
    printf("%s %d-> ", curr->name, curr->score);
    curr = curr->next;
  }
  puts("NULL");
}

void printMiddle()
{
    int count = 0;
    Node* mid = head;

    while (head)
    {

        if (count & 1)
            mid = mid->next;

        ++count;
        head = head->next;
    }

    if (mid != NULL)
        printf("The middle element is %s %d\n\n",
                mid->name, mid->score);
}

int main() {
int num;
   printf("Enter the number data: ");
   scanf("%d", &num);
   getchar();

    Node *dummy;
    char name[255];
    int score;



   for(int i=num;i>0;i--)
   {
       printf("Enter data(score,name): ");
       scanf("%d,%[^\n]", &score, &name);
       getchar();
       pushHead(name,score);
       printLinkedList();

   }
   printMiddle();
  return 0;
}
