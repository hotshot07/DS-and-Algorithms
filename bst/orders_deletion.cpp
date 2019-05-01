#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *lchild;
    Node *rchild;
};

Node *root=NULL;

// Code to insert iteratively

void insert(int key){
    //p will help make the new node
    //t will traverse till it's null
    //r will be the parent Node of t in every step
    // see "r=t" statement in while, when t is NULL
    // r will be the node where you'll insert the new node.
    Node *p;
    Node *r=NULL;
    Node *t=root;

    //Base Case
    if(root==NULL){
        p=new Node;
        p->data=key;
        p->lchild=p->rchild=NULL;
        root=p;
    }
    else{ //iteratively reaching where we'll insert Node
        while(t!=NULL){
            r=t;
            if(key<t->data){
                t=t->lchild;
            }
            else if(key>t->data){
                t=t->rchild;
            }
            else{
                return;
            }
        }

        p=new Node;
        p->data=key;
        p->lchild=p->rchild=NULL;

        if(key<r->data){
            r->lchild=p;
        }
        else{
            r->rchild=p;
        }
    }

}

void inOrder(struct Node* node)
{
    if(node == NULL){
        return;
    }
    inOrder(node->lchild);
    cout << node->data << " ";
    inOrder(node->rchild);
}

void postOrder(struct Node* node){

    if(node == NULL){
        return;
    }
    postOrder(node->lchild);
    postOrder(node->rchild);
    cout << node->data << " ";
}

void preOrder(struct Node* node){

    if(node == NULL){
        return;
    }
    cout << node->data << " ";
    preOrder(node->lchild);
    preOrder(node->rchild);
}

/*  Tree structure
        20
       /  \
     10    30
     / \    \
    5   15   40
            /
           35

*/
int main(){
    insert(20);
    insert(10);
    insert(30);
    insert(40);
    insert(5);
    insert(15);
    insert(35);

    cout << "Preorder\n";
    preOrder(root);
    cout << "Postorder\n";
    postOrder(root);
    cout << "Inorder\n";
    inOrder(root);


}
