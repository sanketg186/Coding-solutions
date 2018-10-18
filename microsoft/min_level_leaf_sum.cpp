
//Sum of leaf nodes of a binary tree such that leaf should be on minimum level.
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

//User function Template for C++
/*
Structure of the Node of the tree is 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};*/
// Your task is to complete this function
// function shoudl return the required sum
int height(Node*root){
    if(root==NULL)
    return 0;
     int lh,rh;
     lh=height(root->left);
     rh=height(root->right);
    if(root->left&&root->right)
        return min(lh,rh)+1;
     if(root->left)
        return lh+1;
     if(root->right)
        return rh+1;
}
    
int f_sum(int h,Node* root){
        if(root==NULL)
            return 0;
        else if(h==0&&root->left==NULL&&root->right==NULL){
                return root->data;
        }
        else {
            if(root->left&&root->right)
                return f_sum(h-1,root->left)+f_sum(h-1,root->right);
            else if(root->left)
                return f_sum(h-1,root->left);
            else if(root->right)
                return f_sum(h-1,root->right);
            
        }
    
}
int minLeafSum(Node* root)
{   
    
    int min_h=height(root);
    int sum=f_sum(min_h,root);
	// Code here
}
