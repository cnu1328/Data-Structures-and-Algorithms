#include<iostream>
#include<queue>
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

node *lca(node *root, int n1,int n2){
	if(root==NULL)
    		return NULL;
    	if(root->data==n1 || root->data==n2)
    		return root;
    	node *left  = lca(root->left,n1,n2);
    	node *right  = lca(root->right,n1,n2);
    	if(left != NULL && right != NULL)
    		return root;
    	if(left == NULL && right == NULL)
		return NULL;
	if(left !=  NULL)
		return lca(root->left,n1,n2);
	return lca(root->right,n1,n2);
}

int findDist(node *root,int n1,int n2){
	


}

int distbn(node *root, int n1, int n2){
	node *lcA = lca(root,n1,n2);
	
	int d1 = findDist(lcA,n1,n2); 
	int d2 = findDist(lcA,n1,n2); 
	
	return d1+d2;
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
    
    
    inorderprint(root);
    cout<<endl;
   
}
