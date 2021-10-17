#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	Node(int k)
	{
		data=k;
		left=right=NULL;
	}
};

void level_order(Node *root)
{
	queue<Node *> q;
	q.push(root);
	q.push(NULL);
	
	while(!q.empty())
	{
	    Node *curr=q.front();
		q.pop();
		if(curr!=NULL)
		{
		   cout<<curr->data<<" ";
		   if(curr->left!=NULL)
		      q.push(curr->left);
		   if(curr->right!=NULL)
		      q.push(curr->right);	
		}
		else
		{
			cout<<"\n";
			if(q.empty()==false)
			  q.push(NULL);
		}	
		
	}
}

int main()
{
	Node *root;
	root=new Node(2);
	root->left=new Node(7);
	root->left->left=new Node(3);
	root->left->right=new Node(6);
	root->left->right->right=new Node(11);
	root->left->right->left=new Node(5);
	root->right=new Node(8);
	root->right->right=new Node(9);
	root->right->right->left=new Node(4);
	
	cout<<"\n Level order Travarsal is \n";
	
	level_order(root);
	
	
   return 0;	
}
