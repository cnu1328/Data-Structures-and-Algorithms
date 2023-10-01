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
    return max(calcHeight(root->left),calcHeight(root->right))+1;
}

int calcDiameter(node *root){
    if(root == NULL)
    	return 0;
    int lHeight = calcHeight(root->left);
    int rHeight = calcHeight(root->right);
    
    int currDiameter = lHeight+rHeight+1;
    
    int lDiameter = calcDiameter(root->left);
    int rDiameter = calcDiameter(root->right);
    
    return max(currDiameter,max(lDiameter,rDiameter));
}

int calcOPDiameter(node *root, int *height){
    if(root == NULL){
    	*height = 0;
    	return 0;
    }
    int lh = 0, rh =0;
    int lD = calcOPDiameter(root->left,&lh);
    int rD = calcOPDiameter(root->right,&rh);
    
    int currDiameter = lh + rh +1;
    
    *height = max(lh,rh)+1;
    
    return max(currDiameter,max(lD,rD));
	
}



int main(){
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->right->right->left = new node(10); 

    root->left->left->left = new node(8);
    root->left->left->left->right = new node(9);
    
    inorderprint(root);
    cout<<endl<<"Diameter of the Binary Tree : ";
    cout<<calcDiameter(root);
    
    cout<<endl<<"Optimised Code for Diameter of the Binary Code : ";
    int height = 0;
    cout<<calcOPDiameter(root,&height);
}
