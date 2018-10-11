#include <iostream>
using namespace std;

struct node{
  int val;  
  node*left;
  node*right;
};
node*remove_outside_val(node*root,int min,int max){
    if(root==NULL)
        return root;
    root->left=remove_outside_val(root->left,min,max);
    root->right=remove_outside_val(root->right,min,max);
    
    if(root->val<min){
        node*rchild = root->right;
        delete root;
        return rchild;
    }
    if(root->val>max){
        node*lchild = root->left;
        delete root;
        return lchild;
    }
    return root;
    
}
node* newNode(int num) 
{ 
    node* temp = new node; 
    temp->val = num; 
    temp->left = temp->right = NULL; 
    return temp; 
}
node* insert(node* root, int key) 
{ 
    if (root == NULL) 
       return newNode(key); 
    if (root->val > key) 
       root->left = insert(root->left, key); 
    else
       root->right = insert(root->right, key); 
    return root; 
} 
void inorderTraversal(node* root) 
{ 
    if (root) 
    { 
        inorderTraversal( root->left ); 
        cout << root->val << " "; 
        inorderTraversal( root->right ); 
    } 
} 
int main() {
    node* root = NULL; 
    root = insert(root, 6); 
    root = insert(root, -13); 
    root = insert(root, 14); 
    root = insert(root, -8); 
    root = insert(root, 15); 
    root = insert(root, 13); 
    root = insert(root, 7); 
    cout << "Inorder traversal of the given tree is: "; 
    inorderTraversal(root); 
  
    root = remove_outside_val(root, -10, 13); 
  
    cout << "\nInorder traversal of the modified tree is: "; 
    inorderTraversal(root); 

	return 0;
}
