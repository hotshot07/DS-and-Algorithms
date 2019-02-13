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
void Display(struct Node* t){
	while(t!=NULL){
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

void deleteNode(struct Node* t, int val){
    while(t!=NULL){
        struct Node *p = t->next;
        if(p->data==val){
            t->next=p->next;
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
  struct Node* temp2,*temp3;
  //we gave the value of temp2 to start;
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

    //TESTING CODE


	Display(start->next);
    insertNode(start,INT_MIN,5);
    cout <<"\n";
    Display(start->next);
    insertNode(start,60,30);
    cout <<"\n";
    Display(start->next);
    deleteNode(start, 5);
    cout <<"\n";
    Display(start->next);

    // WORKS FINE IN ALL CASES

  return 0;
}
