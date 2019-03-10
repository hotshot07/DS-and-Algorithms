#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct Node *front=NULL;
struct Node *rear=NULL;



void enqueue(int val){
    if(front==NULL){
        struct Node *temp=new Node;
        temp->data=val;
        temp->next=NULL;
        front=temp;
        rear=temp;
    }
    else{
        struct Node *temp=new Node;
        temp->data=val;
        temp->next=NULL;
        rear->next=temp;
        rear=temp;
    }
}

void dequeue(){
    if(front==NULL){
        cout << "Queue is empty\n";
    }
    else{
        struct Node *ptr=front;
        front=front->next;
        delete ptr;
        if(front==NULL){
            rear=NULL;
        }
    }
}

void display(){
    struct Node *ptr=front;
    while(ptr!=NULL){
        cout << ptr->data <<" ";
        ptr=ptr->next;
    }
    cout <<"\n";
}

int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();
    dequeue();
    display();
    dequeue();
    display();
    dequeue();
    display();
    dequeue();
}
