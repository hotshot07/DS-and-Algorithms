#include<iostream>

using namespace std;

// Definig the structure of the Node
struct Node{
    int data;
    struct Node *next;
};

//Making head pointer NULL;
struct Node *head=NULL;

//This function created new nodes and inserts them at the end of the linked list.
void createNode(int val){
    //A new temp node is created
    struct Node *temp=new Node;
    struct Node *ptr;

    //tepm is given the data val(that we enetered)
    temp->data=val;

    //Base case when we're just starting with the linked list
    if(head==NULL){
        temp->next=NULL;
        head=temp;
    }
    else{
        //ptr is moved to the last of the LL
        ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=temp;
        temp->next=NULL;
    }
}

//This function inserts Node after the value we give
void insertNode(int val, int newdata){
    //val is the data of the node
    //after which we insert the new data

    struct Node *temp= new Node;
    struct Node *ptr;
    temp->data=newdata;
    ptr=head;
    // we basically traverse till val with help of ptr.
    while(ptr->data!=val){
        ptr=ptr->next;
    }
    //once we reach it, temp->next get's value of ptr->next
    //we change ptr->next=temp;
    temp->next=ptr->next;
    ptr->next=temp;
}

void deleteNode(int val){
    struct Node *ptr;
    ptr=head;
    //Base case if we have to delete the first node
    if(ptr->data==val){
        head=ptr->next;
        delete ptr;
    }
    else{
        //traversing with help of ptr and stopping before
        //the value we have to delete
        while(ptr->next->data!=val){
            ptr=ptr->next;
        }
        //tbd=to be deleted
        struct Node *tbd;
        tbd=ptr->next;
        ptr->next=tbd->next;
        delete tbd;
    }
}

//Function to displat the whole LL
void display(){
    //
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
    cout <<"\n";
    insertNode(3,7);
    display();
    cout <<"\n";
    deleteNode(1);
    deleteNode(4);
    deleteNode(6);
    display();
	cout <<"\n";
}

//OUTPUT of the code
/*Enter the number of elements
7
Enter Value: 1
Enter Value: 2
Enter Value: 3
Enter Value: 4
Enter Value: 5
Enter Value: 6
Enter Value: 7
1 2 3 4 5 6 7
1 2 3 7 4 5 6 7
2 3 7 5 7
*/
