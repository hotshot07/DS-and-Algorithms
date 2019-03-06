#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* head=NULL;

void createNode(int val){
    struct Node *temp=new Node;
    temp->data=val;
    if(head==NULL){
        temp->prev=NULL;
        temp->next=NULL;
        head=temp;
    }
    else{
        struct Node *ptr;
        ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=temp;
        temp->prev=ptr;
        temp->next=NULL;
    }
}

void insertNode(int val, int newData){
    struct Node *temp=new Node;
    struct Node *ptr,*ptr2;
    temp->data=newData;
    ptr=head;
    ptr2=head->next;

    while(ptr->data!=val){
        ptr=ptr->next;
        ptr2=ptr2->next;
    }

    ptr->next=temp;
    ptr2->prev=temp;
    temp->next=ptr2;
    temp->prev=ptr;
}

void deleteNode(int val){

    struct Node *ptr,*ptr2;
    ptr=head;

    if(head->data==val){
        head=ptr->next;
        ptr->next->prev=NULL;
        ptr->next=NULL;
        delete ptr;
    }
    else{
        while(ptr->next->data!=val){
            ptr=ptr->next;
        }
        
        ptr2=ptr->next;
        
        if(ptr2->next!=NULL){
            ptr->next=ptr2->next;
	        ptr2->next->prev=ptr;
	        ptr2->next=NULL;
	        ptr2->prev=NULL;
	        delete ptr2;
		}
		else{
			ptr->next=NULL;
			ptr2->prev=NULL;
			delete ptr2;
		}
        
    }
}
void display(){
    struct Node *ptr=head;
    while(ptr!=NULL){
        cout << ptr->data << " ";
        ptr=ptr->next;
    }
}
int main(){
    int n;
    cout << "Enter the number of elements\n";
    cin>> n;
    while(n--){
        int val;
        cout << "Enter Value: ";
        cin >> val;
        createNode(val);
    }

    display();

    insertNode(3,4);
    insertNode(1,8);
    cout <<"\n";
    display();

    deleteNode(1);
    cout <<"\n";
    display();
    deleteNode(3);
    cout <<"\n";
    display();
    deleteNode(5);
    cout <<"\n";
    display();



}
