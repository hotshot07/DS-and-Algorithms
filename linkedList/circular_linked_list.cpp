#include<bits/stdc++.h>

using namespace std;

//Declaring the Node structure;
struct Node
{
  int data;
  struct Node *next;
};

/*Code to display all the nodes in singly linked List
When the last element would point to NULL, t would be NULL
hence the code will stop*/
void Display(struct Node* t,int a){
    int i=0;
    for(i=0;i<a;i++){
        cout << t->data <<" ";
        t=t->next;
    }
}

/*createNode function creates new nodes and as the return value is
node*, it returns pointer to the newly created node. It would be helpful
to make next node.*/

Node* createNode(struct Node* prev, int val){
    struct Node *temp= new Node;
    temp->data=val;
    temp->next=NULL;
    prev->next=temp;

    return temp;
}

//Pretty straighforward actually. it creates a node after prevval

void insertNode(struct Node *prev, int prevval, int val){
    while(true){
        if(prev->data==prevval){
            struct Node *temp = new Node;
            temp->data=val;
            temp->next=prev->next;
            prev->next=temp;
            break;
        }
        else{
            prev=prev->next;
        }

        if(prev->next == NULL){
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

void deleteNode(struct Node* ptr, int val){
    // as we're passing start pointer so..
    struct Node* start=ptr;
    struct Node* node1=ptr->next;

    //code to delete the first element(right after start)
    if(val==node1->data){
        //traverse to end of the list and then make changes
        struct Node *q=node1->next;
        while(q->next!= node1){
            q=q->next;
        }
        //q is the last element of the circular list
        q->next=node1->next;
        start->next=node1->next;
        delete node1;
    }
    else{
        // for any other case, pretty starighforward approach
        //q points to the node with val
        //ptr is the node at behind q;
        while(true){
            struct Node *q=ptr->next;
            if(q->data==val){
                ptr->next=q->next;
                delete q;
                break;
            }
            else{
                ptr=ptr->next;
            }
        }

    }

}

int main() {
    // declared starting node
  struct Node* start = new Node;
  start->data=INT_MIN;
  start->next = NULL;
  struct Node* temp2,*temp3;
  //we gave the value of temp2 to start;
  temp2=start;

  cout<< "Enter the number of elements" << endl;
    int a;
    cin >>a;
    int k=a+1;
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

    //TESTING CODE
    //temp2 is the last node
    temp2->next=start->next;
    //this makes this a circular linked list


    Display(start->next,k);

    insertNode(start,10,40);
    cout <<"\n";


    Display(start->next,k+1);

    deleteNode(start, 10);
    cout <<"\n";
    Display(start->next,k);
    cout <<"\n";
    deleteNode(start, 40);
    Display(start->next,k-1);


    /*insertNode(start,INT_MIN,5);
    cout <<"\n";
    Display(start->next,i);
    insertNode(start,60,30);
    cout <<"\n";
    Display(start->next);
    deleteNode(start, 5);
    cout <<"\n";
    Display(start->next);*/

    // WORKS FINE IN ALL CASES

  return 0;
}



