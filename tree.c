/*
Programmer====>Narayan Paul
Date: 17/03/23
Topic:Binary Search Tree
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
//Define a structure called bstnode with elements data(int) and two pointers(bstnode) called left and right.
typedef struct bstnode
{
    int data;
    struct bstnode *left;
    struct bstnode *right;
}bstnode;
//Create a function to create a  new node in the binary search tree
bstnode* getNode(int data){
    bstnode* node=malloc(sizeof(bstnode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;  
    return node;
}
//Function for inserting a node in the bst
bstnode* insert(bstnode *root,int x){
    //When root will be NULL  then we can add the new node directly into the root
    if(root==NULL){
        root=getNode(x);
    }
    //when data will be less than root's data then go to the left side of the tree
    //Then  again check whether the left is null or not if it is null then add the element there
    //Otherwise call the function again  by passing the left subtree as the root 
    //Do this recrsively
    else if(x <= root->data)
        root->left  = insert(root->left,x);
    else
        root->right = insert(root->right,x);
    return root;
}
//Function to search a specific element in BST
bool search(bstnode *root ,int key){
    //When the root will be NULL the we return false
    if(root == NULL)
        return false;
    //when the key is matched return true
    if(root->data == key )
        return true;
    //when key>=root->data  then move to the right child and call the function recursively
    if(root->data <key )
       return search(root->right,key);
    // //when key<root->data  then move to the left child and call the function recursively
    else  return search(root->left,key);
}
int max(int x,int y){
    if(x>y)
        return x;
    else
        return y;
}

int height(bstnode *root){
    if (root == NULL)
    	return -1;
    /* compute the height of each SubTree */
    return max(height(root->left), height(root->right)) + 1;
}
int main()
{
    bstnode *root = NULL;
    //insert nodes in binary tree
    root = insert(root,6);
    root = insert(root,51);
    root = insert(root,24);
    root = insert(root,58);
    root = insert(root,52);
    root = insert(root,72);
    root = insert(root,42);
    root = insert(root,82);
    
    int key = 52;
    if (search(root, key))
        printf("\n%d is present in BST\n" ,key);
    else
        printf("\n%d is not present in BST\n",key);
    printf("Height of the BST ->%d",height(root));
    return 0;
}
