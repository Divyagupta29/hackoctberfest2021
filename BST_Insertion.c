#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};

void preOrder( struct node *root) {
  
	if( root == NULL ) 
      return;
	printf("%d ",root->data);
	preOrder(root->left);
	preOrder(root->right);
  
}


struct node* insert( struct node* root, int data ) {
	struct node *p=(struct node*)malloc(sizeof(struct node));
        struct node *current;
        struct node *parent;
        
  
    p->data=data;
    p->left=NULL;
    p->right=NULL;
    if(root==NULL)
    {
        root=p;
        return p;
    }
    else {
        current =root;
        parent=NULL;
    
    while(1)
    {
          parent=current;
        if(data<parent->data)
        {
            current = current->left;
            if(current==NULL){
              parent->left= p;
            break;
              }
        }
        else
        {
            current=current->right;
            if(current==NULL)
            {
            parent->right=p;
                        break;
            }
        }
    }     
    }
	return root;
}

int main() {
  
    struct node* root = NULL;
    
    int t;
    int data;

    scanf("%d", &t);

    while(t-- > 0) {
        scanf("%d", &data);
        root = insert(root, data);
    }
  
	preOrder(root);
    return 0;
}
