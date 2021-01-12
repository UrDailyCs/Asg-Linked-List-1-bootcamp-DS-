#include <stdio.h>
#include <stdlib.h>


struct Node {
    int score;
    Node *next;// next node

}*head,*tail;

// head : node pertama
// tail : node terakhir

Node *createNode(int score){
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->score=score;
    newNode->next=NULL;

    return newNode;
}

//push head, push tail

void pushHead(int score){
    // 1. buat dulu node
    // 2. cek kondisi
    //  jika tidak ada head, nodenya jadi head dan tail
    // jika ada head, node akan menjadi head baru dan node->next = head lama

    Node *temp = createNode(score);

    if(!head){ // jika gaada head
        head = tail= temp; // maka node samad dgn tail dan tmp
    } else {
        temp ->next = head; // node akan menunjuk ke head yang lama
        head = temp; // node akan menjadi head yg baru
    }

}

void pushTail(int score){


    Node *temp = createNode(score);

    if(!head){ 
        head = tail= temp; 
    } else {
        tail ->next = temp; 
        tail = temp; 
    }

}

void popHead(){

    if (!head) return ;  // kalo gaada head langsung return
    else if (head==tail){
        free (head);
        head = tail = NULL;
   }
    else{
        Node *temp = head->next;
        head->next= NULL;
        free (head);
        head = temp;
    }
}

void popTail(){

    if (!head) return ;  // kalo gaada head langsung return
    else if (head==tail){
        free (head);
        head = tail = NULL;
   }
    else{
        Node *temp = head;

        while (temp->next != tail){
            temp = temp->next;
        }
        temp->next= NULL;
        free (tail);
        tail = temp;
    }
}

void removeDuplicates(Node *head)
{
    
    Node *current = head;
 
    
    Node* temp; 
   
   
    if (current == NULL) 
       return; 
 
    
    while (current->next != NULL) 
    {
       
       if (current->score == current->next->score) 
       {
                       
           temp = current->next->next;
           free(current->next);
           current->next = temp;  
       }
       else
       {
          current = current->next; 
       }
    }
}

void printList(){
    Node *curr =head;

    while (curr){

    if (curr==head){
        printf("(head) ");
    }
    
    else if(curr==tail){
        printf (" (tail)");
    }
        printf("%d -> ",curr->score);
        curr=curr->next;
    }

    printf("NULL\n");

}
int main (){


    pushHead(30);
    pushTail(37);
    pushTail(37);
    pushTail(44);
    pushTail(45);
    pushTail(53);
    pushTail(53);
    pushTail(60);
    pushTail(90);
    pushTail(90);

    popHead();

    removeDuplicates(head);

    printList();

    return 0;
}
