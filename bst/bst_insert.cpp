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
    if(r==NULL){
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

//Recursive inserting in a BST
//Each recursion function is made of two parts
//->a base case (here where no node is present)
//->recursivce calls to the function
Node* recursiveInsert(Node *p, int key){
    Node *t=NULL;
    //Base Case
    if(p==NULL){
        t= new Node;
        t->data=key;
        t->lchild=t->rchild=NULL;
        return t;
    }

    //Recursive call
    if(key<p->data){
        p->lchild=recursiveInsert(p->lchild,key);
    }
    else if(key>p->data){
        p->rchild=recursiveInsert(p->rchild, key);
    }

    return p;
}

//Printing inorder to check because inorder
//of a BST always gives ascending order
void inorder(struct Node* node)
{
    if(node == NULL){
        return;
    }
    inorder(node->lchild);
    cout << node->data << " ";
    inorder(node->rchild);
}

int main(){
    root=recursiveInsert(root,10);
    Node* node1 =recursiveInsert(root,60);
    Node* node2 =recursiveInsert(root,30);
    Node* node3 =recursiveInsert(root,80);
    inorder(root);

}
