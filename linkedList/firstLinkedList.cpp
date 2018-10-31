#include<iostream>

using namespace std;

// Create a structure which holds data and pointer to next node

struct Node {
    int data;
    struct Node *next;
};

// Function to print the nodes

void printLinked(struct Node *n){

    while(n!=NULL){
        cout << n->data << endl;
        n=n->next;
    }

}

int main(){

    //Create three pointers and assign NULL

    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;

    //dynamically allocate memory

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    //assign data

    head->data=1;
    head->next=second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=NULL;

    printLinked(head);

    return 0;
}
