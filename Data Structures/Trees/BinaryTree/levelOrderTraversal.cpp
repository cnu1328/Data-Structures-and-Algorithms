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
/*

This logic is not working in level ordering

void levelorder(node *root){
     if(root == NULL)
     	return;
     cout<<root->data<<" ";
     levelorder(root->left);
     cout<<root->data<<" ";
     levelorder(root->right);
}

*/

void levelorder(node *root){
    if(root == NULL)
    	return;
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
    	node *nn = q.front();
    	q.pop();
    	if(nn!=NULL){
    	    cout<<nn->data<<", ";
    	    if(nn->left){
    	    	q.push(nn->left);
    	    }
    	    if(nn->right){
    	    	q.push(nn->right);
    	    }
    	}
    	else if(!q.empty())
    	    q.push(NULL);
    	
    }
    return;
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

int main(){
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    
    inorderprint(root);
    cout<<endl<<"Level order Traversal"<<endl;
    levelorder(root);
    
    //cout<<sumatKthLevel(root,2)<<endl;
    //if(sum==-1)
    	//cout<<"Root is NULL"<<endl;
    //else
    	//cout<<sum<<endl;
    
}




