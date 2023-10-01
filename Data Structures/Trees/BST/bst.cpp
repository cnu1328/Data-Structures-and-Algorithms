#include<iostream>

using namespace std;


struct node{
	int data;
	node *left;
	node *right;

	node(int x){
		data = x;
		left = right = NULL;

	}

};

node *insert(node *root,int x){

	if(root == NULL)
		return new node(x);
	if(x<root->data)
		root->left = insert(root->left,x);
	else if(x>root->data)
		root->right = insert(root->right,x);
	return root;

}

void inorder(node *root){
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<", ";
	inorder(root->right);

}

void preorder(node *root){
	if(root==NULL)
		return;
	cout<<root->data<<", ";
	preorder(root->left);
	preorder(root->right);

}

void postorder(node *root){
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<", ";

}

node *search(node *root,int key){
	if(root == NULL || root->data == key)
		return root;
	if(key<root->data)
		return search(root->left,key);
	if(key>root->data)
		return search(root->right,key);
}

node *deletion(node *root,int key){
    if(root==NULL)
        return root;
    else if(key<root->data)
            root->left = deletion(root->left,key);
    else if(key>root->data)
            root->right = deletion(root->right,key);
    else{
        if(root->right && root->left){
            node *sucessor = root->right;
            while(sucessor->left!=NULL)
                sucessor = sucessor->left;
            root->data = sucessor->data;
            root->right = deletion(root->right,sucessor->data);
        }
        else{
            if(root->right)
                return root->right;
            else
                return root->left;
        }
    }
    return root;

}


int main(){

	node *root = NULL;
	/*int t,a;
	cin>>t;
	while(t--){
		cin>>a;
		root = insert(root,a);
	}*/
	root = insert(root,10);
	insert(root,2);
	insert(root,-1);
	insert(root,15);
	insert(root,20);
	insert(root,14);
	insert(root,3);


	//BST Search

	cout<<search(root,15)<<endl;

	inorder(root);
	cout<<endl;




    postorder(root);
	cout<<endl;

	preorder(root);
	cout<<endl;
	deletion(root,10);
}
