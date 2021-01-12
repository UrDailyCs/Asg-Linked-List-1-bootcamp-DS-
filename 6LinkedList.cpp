#include<stdio.h> 
#include<stdlib.h> 
struct Node{ 
    int data; 
    struct Node *next; 
}; 

void insertAtTheBegin(struct Node **start_ref, int data){ 
    struct Node *ptr1 = (struct Node*)malloc(sizeof(struct Node)); 
    ptr1->data = data; 
    ptr1->next = *start_ref; 
    *start_ref = ptr1; 
} 

void swap(struct Node *a, struct Node *b){ 
    int temp = a->data; 
    a->data = b->data; 
    b->data = temp; 
} 
  
void bubbleSort(struct Node *start){ 
    int swapped, i; 
    struct Node *ptr1; 
    struct Node *lptr = NULL; 

    if (start == NULL) 
        return; 
  
    do{
        swapped = 0; 
        ptr1 = start; 
  
        while (ptr1->next != lptr){ 
            if (ptr1->data < ptr1->next->data){  
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while(swapped); 
} 

void printList(struct Node *start){ 
    struct Node *temp = start; 
    printf("\n"); 
    while (temp!=NULL){ 
        printf("%d ", temp->data); 
        temp = temp->next; 
    } 
} 
  
int main(){ 
    int arr[] = {3, 100, 1000, 10000, 100000, 1000000};
    int list_size, i; 
    struct Node *start = NULL; 
  
    for(i=0; i<6; i++){
    	insertAtTheBegin(&start, arr[i]);
	}

    bubbleSort(start); 
    printf("Linked list after sorting: "); 
    printList(start);
    printf("\n");
    return 0; 
}
