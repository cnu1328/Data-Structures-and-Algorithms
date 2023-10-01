#include<iostream>

using namespace std;

struct node{
    int data;
    node *left;
    node *right;
    node(int x){
    	data = x;
    	right = left = NULL;
    }
};

int search(int inorder[],int start, int end, int curr){
    for(int i=start;i<=end;i++){
    	if(curr == inorder[i])
    		return i;
    }
    return -1;
}

node *buildTree(int postorder[],int inorder[],int start, int end){
    if(start>end)
    	return NULL;
    
    static int idx = 6;
    int curr = postorder[idx];
    idx--;
    node *nn = new node(curr);
    
    
    if(start == end){
    	return nn;
    }
    
    int pos = search(inorder,start,end,curr);
    if(pos == -1){
    	cout<<"It is unable to Build a Tree Due to postorder element not in inorder"<<endl;
    	return NULL;
    }
    
    
    nn->right = buildTree(postorder,inorder,pos+1,end);
    nn->left = buildTree(postorder,inorder,start,pos-1);
    
    return nn;
    
}	

void inorderprint(node *root){
    
    if(root == NULL)
    	return;
    inorderprint(root->left);
    cout<<root->data<<",";
    inorderprint(root->right);
    
}







int main(){
    int postorder[] = {4,5,2,6,7,3,1};
    int inorder[]   = {4,2,5,1,6,3,7};
    
    node *root = buildTree(postorder,inorder,0,6);
    
    inorderprint(root);
    
    cout<<endl;
    return 0;
}
