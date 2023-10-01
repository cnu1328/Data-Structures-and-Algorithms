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

int sumatKthLevel(node *root,int k){
    if(root==NULL)
    	return -1;
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    int lvl = 0,sum=0;
    while(!q.empty()){
    	node *nn = q.front();
    	q.pop();
    	if(nn!=NULL){
    	    if(lvl==k)
    	    	sum = sum + nn->data;
    	    if(nn->left)
    	    	q.push(nn->left);
    	    if(nn->right)
    	    	q.push(nn->right);
    	    
    	}
    	else if(!q.empty()){
    	    q.push(NULL);
    	    lvl++;
    	}
    }
    return sum;
}


int countNodes(node *root){
    if(root==NULL)
    	return 0;
    return countNodes(root->left)+countNodes(root->right)+1;
}

int SumOfNodes(node *root){
    if(root == NULL)
    	return 0;
    return SumOfNodes(root->left)+SumOfNodes(root->right)+root->data;
}



int main(){
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    
    inorderprint(root);
    
    cout<<"Kth Node sum is : "<<endl;
    cout<<sumatKthLevel(root,1)<<endl;
    cout<<endl<<"Count of Nodes in a Binary Tree"<<endl;
    cout<<countNodes(root)<<endl;
    cout<<SumOfNodes(NULL)<<endl;
    
    
    
    
}
