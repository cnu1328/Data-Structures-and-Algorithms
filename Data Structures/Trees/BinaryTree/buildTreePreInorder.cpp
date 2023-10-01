#include<iostream>

using namespace std;

struct node{
	
	int data;
	struct node *left,*right;
	node(int x){
	    data = x;
	    left = right = NULL;
	}
};

int search(int inorder[],int start,int end, int curr){
	for(int i=start;i<=end;i++){
		if(curr==inorder[i])
			return i;
	}
	return -1;
}

node *buildTree(int preorder[],int inorder[],int start,int end){
	
	if(start > end)
		return NULL;
	static int idx =0;
	int curr = preorder[idx];
	idx++;
	
	
	int pos = search(inorder,start,end,curr);
	if(pos == -1){
	    cout<<"It is unable to Build a Tree Due to preorder element not in inorder"<<endl;
	    return NULL;
	}
	node *nn = new node(curr);
	if(start == end){
	    return nn;
	}
	nn->left = buildTree(preorder,inorder,start,pos-1);
	nn->right = buildTree(preorder,inorder,pos+1,end);
	
	return nn;
	
}

void inorderPrint(node *root){
     if(root == NULL){
     	return;
     }	
     inorderPrint(root->left);
     cout<<root->data<<" ";
     inorderPrint(root->right);
}




int main(){
    
    int preorder[] = {1,2,4,5,3,6,7};
    int inorder[] = {4,2,5,1,6,3,7};
    
    node *root = buildTree(preorder,inorder,0,6);
    
    inorderPrint(root);
    cout<<endl;
}
