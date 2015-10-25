#include <iostream>

using namespace std;

class Node{
	int data;
	Node* left;
	Node* right;
	//Node* root;

public:
	Node(int d){
		left = NULL;
		right = NULL;
		data = d;
	}

	void setData(int d){
		data = d;
	}
	void setRight(Node* anext){
		right = anext;
	}
		void setLeft(Node* anext){
		left = anext;
	}
	int Data(){
		return data;
	}
	Node* Right(){
		return right;
	}
	Node* Left(){
		return left;
	}

};

class BinarySearchTree{

public:
	Node* root = NULL;

public:
	BinarySearchTree(){
	
	}
	Node* get_root();
	void set_root(Node*);
	void insert(int, Node*);
	void preorder(Node* root);
	void inorder(Node* root);
	void postorder(Node* root);
};

void BinarySearchTree::set_root(Node* p){
	root = p;
}

Node* BinarySearchTree::get_root(){ return root;}

void BinarySearchTree::insert(int data, Node* p){

	if(get_root() == NULL){
		Node* newnode = new Node(data);
		set_root(newnode);
	}
	else{

		if(data >= p->Data()){
			
			if(p->Right())insert(data,p->Right());
			else{
				Node* newnode = new Node(data);

				p->setRight(newnode);
			}
		}
	
		else if(data < p->Data()){
			if(p->Left()) insert(data, p->Left());
			else{
				Node* newnode = new Node(data);
				p->setLeft(newnode) ;
			}
		}
	}
}

void BinarySearchTree::preorder(Node* root){
	if(root != NULL){
		cout<<root->Data()<<"--";
		if(root->Left()) preorder(root->Left());
		if(root->Right()) preorder(root->Right());
	}
	else
		return;
}

void BinarySearchTree::inorder(Node* root){
	if(root != NULL){
		
		if(root->Left()) inorder(root->Left());
		cout<<root->Data()<<"--";
		if(root->Right()) {
			inorder(root->Right());
		}
	}
	else
		return;
}

void BinarySearchTree::postorder(Node* root){
	if(root != NULL){
		
		if(root->Left()) postorder(root->Left());
		if(root->Right()) postorder(root->Right());
		cout<<root->Data()<<"--";
	}
	else
		return;
}

int main(){

	int n=0,next,i=0;

	BinarySearchTree obj;
	//Node* root = NULL;
	cout<<"Enter the number of elements\n";
	cin>>n;
	
	while(i<n){
		cout<< "Enter the next element in the BST \n";
		cin>>next;
		obj.insert(next, obj.get_root());
		i++;
	}

	Node* root = obj.get_root();
		cout<<"\nPre order\n";
		obj.preorder(root);
		cout<<"NULL\nIn order \n";
		obj.inorder(root);
		cout<<"NULL\nPost order\n";
		obj.postorder(root);
		cout<<"NULL\n";

	return 0;
}
