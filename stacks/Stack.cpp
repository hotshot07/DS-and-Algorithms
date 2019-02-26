//Linked list implementation of stack
#include<bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	struct Node *next;
};

Node *ptr=NULL;
Node *head=NULL;

//It pushes the code into stack
//If it's the first node, then a new node is created and it's next is NULL
//if any other node is added, it takes the value of head(top of stack) and it's next
//point to the previous value
void push(){
	cout << "Enter the value:" << endl;
	int val;
	cin>>val;
	if(head==NULL){
		struct Node* temp=new Node;
		temp->data=val;
		temp->next=NULL;
		head=temp;
		return;
	}
	else{
		struct Node* temp=new Node;
		temp->data=val;
		temp->next=head;
		head=temp;
		return;
	}
}

//pops out the topmost element from the stack
void pop(){
	if(head==NULL){
		cout << "stack empty\n";
	}
	else{
		struct Node *temp=head;
        cout<< head->data << " popped out of stack \n";
		head=head->next;
		delete temp;
	}

}

// displays ALL elements in the stack
void display(){
    if(head==NULL){
        cout << " Stack Empty\n";
    }
    else{
    	ptr=head;
    	while(ptr!=NULL){
    		cout << ptr->data << " ";
    	    ptr=ptr->next;
    	}
    	cout << " \n";
    }
}

int main(){

	int k;
    do{
	   cout << "What the do you want to do?\n";
       cout << "1. Push\n";
       cout << "2. Pop\n";
       cout << "3. Display\n";
       cout << "4. Exit\n";

       int a;
       cin>>a;
	   k=a;

       switch(a){
            case 1:{
                push();
                break;
            }
            case 2:{
                pop();
                break;
            }
            case 3:{
                display();
                break;
            }
            default:{
            	cout<< "Exiting";
                break;
            }
       }
    }while(k<4);

return 0;
}
