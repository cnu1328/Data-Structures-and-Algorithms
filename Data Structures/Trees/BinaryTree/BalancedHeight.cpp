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

int height(node *root){
    if(root == NULL)
    	return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    
    return max(lh,rh)+1;
    
    
}

bool isBalanced(node *root){
    if(root == NULL)
    	return true;
    if(isBalanced(root->left) == false)
    	return false;
    if(isBalanced(root->right)== false)
    	return false;
    int lh = height(root->left);
    int rh = height(root->right);
    
    if(abs(lh-rh) <=1)
    	return true;
    else
    	return false;
}	

bool isOpBalanced(node *root, int *height){
    if(root == NULL)
    	return true;
    int lh = 0,rh = 0;	
    if(isOpBalanced(root->left,&lh)==false)
    	return false;
    if(isOpBalanced(root->right,&rh)==false)
    	return false;
    
    *height = max(lh,rh)+1;
    if(abs(lh-rh)<=1)
    	return true;
    else
    	return false;
    
    
}

void preorder(node *root){
    if(root == NULL){
    	return;
    }
    cout<<root->data<<", ";
    preorder(root->left);
    preorder(root->right);

}


int main(){
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    
    preorder(root);
    cout<<endl;
    
    struct node *root1 = new node(1);
    root1->left = new node(2);
    root1->right = new node(4);
    root1->left->left = new node(3);
    root1->left->left->left = new node(4);
    
    
    //Balanced Height Tree
    if(isBalanced(root)){
    	cout<<"Balanced Tree"<<endl;
    }
    else
    	cout<<"UnBalanced Tree"<<endl;
    
    //Optimised Height Tree
    int height = 0;
    if(isOpBalanced(root1,&height) == true){
        cout<<"Balanced tree"<<endl;
    }else
    	cout<<"Unbalanced Tree"<<endl;
    
    
    
}
