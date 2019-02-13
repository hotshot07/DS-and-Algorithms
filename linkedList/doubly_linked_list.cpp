#include<bits/stdc++.h>

using namespace std;

//Declaring the Node structure;
struct Node{
  int data;
  struct Node *next;
  struct Node *prev;
};

/*Code to display all the nodes in doubly linked List
When the last element would point to NULL, t would be NULL
hence the code will stop. This works in forward direction*/
void Displayf(struct Node* t){
    while(t!=NULL){
        cout << t->data <<" ";
        t=t->next;
    }
}

/*Code to display all the nodes in doubly linked List
When the last element would point to NULL, t would be NULL
hence the code will stop. This works in backward direction*/
void Displayb(struct Node* t){
    while(t!=NULL && t->data!=INT_MIN){
        cout << t->data <<" ";
        t=t->prev;
    }
}



/*createNode function creates new nodes and as the return value is
node*, it returns pointer to the newly created node. It would be helpful
to make next node.*/

Node* createNode(struct Node* ptr, int val){
    struct Node *temp= new Node;
    temp->data=val;
    temp->next=NULL;
    temp->prev=ptr;
    ptr->next=temp;

    return temp;
}

//Pretty straighforward actually. it creates a node after prevval

void insertNode(struct Node *ptr, int prevval, int val){
    while(true){
        if(ptr->data==prevval){
            struct Node *temp = new Node;
            struct Node *after = ptr->next;

            temp->data=val;
            temp->next=after;
            temp->prev=ptr;

            ptr->next=temp;

            after->prev=temp;
            break;
        }
        else{
            ptr=ptr->next;
        }

        if(ptr->next == NULL){
            cout<< "Element does not exist" <<"\n";
            break;
        }
    }
}

/*Here's something creative.
to delete node, we take two pointers t and p
t is the current active node and p is the next
if p has the value that we have to delete
then we'll do the t->next pointing to p->next
and delete p(hence freeing memory)
no seperate case for NULL node*/

void deleteNode(struct Node* t, int val){
    while(t!=NULL){
        struct Node *p = t->next;
        struct Node *q = p->next;
        if(p->data==val){
            t->next=q;
            q->prev=t;
            delete p;
            break;
        }
        t=t->next;
    }
}

int main() {
    // declared starting node
  struct Node* start = new Node;
  start->data=INT_MIN;
  start->next = NULL;
  start->prev = NULL;
  struct Node *temp2,*temp3;
  //we gave the value of temp2 to start
  temp2=start;

  cout<< "Enter the number of elements" << endl;
    int a;
    cin >>a;
    int i=1;
    while(a--){
        int val;
        cout << "Enter value " << i << "\n";
        cin>> val;
        temp3 = createNode(temp2,val);
        // temp 3 is the pointer of the new node created
        //create node works in this way that it takes the pointer
        //of prev node and returns the current node
        // the current node becomes prev for next node
        temp2=temp3;
        i++;
    }

    Displayf(start->next);
    //temp2 has value of the last created node
    cout << "\n";
    Displayb(temp2);

    insertNode(start, 20, 25);
    cout <<"\n";
    Displayf(start->next);
    //temp2 has value of the last created node
    cout << "\n";
    Displayb(temp2);

    deleteNode(start, 20);
    cout <<"\n";
    Displayf(start->next);
    //temp2 has value of the last created node
    cout << "\n";
    Displayb(temp2);


  return 0;
}
