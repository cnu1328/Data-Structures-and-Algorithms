#include<iostream>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
    node(int x){
    	data = x;
    	left=right = NULL;
    }
};


void inorderprint(node *root){
    if(root == NULL)
    	return;
    inorderprint(root->left);
    cout<<root->data<<" ";
    inorderprint(root->right);
}


int calcHeight(node *root){
    if(root == NULL)
    	return 0;
    int lHeight = calcHeight(root->left);
    int rHeight = calcHeight(root->right);
    
    return max(lHeight,rHeight)+1;
}


int main(){
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    root->left->left->left = new node(8);
    root->left->left->left->right = new node(9);
    
    struct node *root1 = new node(1);
    root1->left = new node(2);
    root1->right = new node(4);
    root1->left->left = new node(3);
    
    inorderprint(root1);
    cout<<endl<<"Maximum hight of the Binary Tree : ";
    cout<<calcHeight(root1)<<endl;
}
