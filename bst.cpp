#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *insertBST(Node *root, int val)
{

    if (root == NULL) //empty node
    {
        return new Node(val); // create new node
    }
    if (val < root->data)
    {
        root->left = insertBST(root->left, val);
    }
    else
    {
        // val > root->data
        root->right = insertBST(root->right, val);
    }
    return root;
}


Node* searchInBST(Node* root, int key){
    if(root==NULL){
        return NULL;
    }

    if(root->data == key){
        return root;
    }
    //root->data>key = search in left
    if(root->data > key){
        return searchInBST(root->left,key);
    }
    //data<key
    return searchInBST(root->right,key);
}

Node* inorderSucc(Node* root){
    Node* curr = root;
    while(curr && curr->left!=NULL){
        curr = curr->left;
    }
    return curr;
}


//delete in BST
Node* deleteInBST(Node* root,int key){
    if(key < root->data){
        root->left = deleteInBST(root->left,key);
    }
    else if(key > root->data){
        root->right = deleteInBST(root->right,key);
    }
    else{
        if(root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }
        //case 3
        Node* temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteInBST(root->right,temp->data);
    }
    return root;
}

void inorder(Node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}



int main()
{
    Node *root = NULL;
    root = insertBST(root,5);
    insertBST(root,1);
    insertBST(root,3);
    insertBST(root,4);
    insertBST(root,2);
    insertBST(root,7);

    //print inorder
    inorder(root);
    cout<<endl;
   if(searchInBST(root,20) == NULL){
        cout <<"Key does not exist"<<endl;
   } 
   else{
         cout <<"Key exists"<<endl;
   }

    return 0;
}