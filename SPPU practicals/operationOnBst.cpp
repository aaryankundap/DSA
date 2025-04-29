#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        left=right=NULL;
    }
};

void traversal(Node* root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    traversal(root->left);
    traversal(root->right);
}

Node* insert(Node* &root,int x){
    if(root==NULL){
        root=new Node(x);
    }
    else if(root->data>x){
        root->left=insert(root->left,x);
    }
    else{
        root->right=insert(root->right,x);
    }
    return root;
}

void search(Node* root,int key,bool &present){
    if(root==NULL){
        return ;
    }
    if(root->data == key){
        present=true;
    }
    else if(root->data>key){
        search(root->left,key,present);
    }
    else if(root->data<key){
        search(root->right,key,present);
    }
}

int height(Node* root){
    if(root==NULL) return 0;
    int leftsubtree=height(root->left);
    int rightsubtree=height(root->right);
    return max(leftsubtree,rightsubtree)+1;
}

int Min(Node* root){
    if(root->left==NULL){
        return root->data;
    }
    return std::min(Min(root->left),root->data);
}


void mirror(Node* root){
    if(root==NULL) return ;
    mirror(root->left);
    mirror(root->right);
    swap(root->left,root->right);
}

int main(){
    Node* root=NULL;
    int n;
    cout<<"Enter the number of elements in the bst: ";
    cin>>n;
    for(int i=0;i<n;i++){
        int element;
        cout<<"The elements are: "<<endl;
        cin>>element;
        insert(root,element);
    }

    cout<<"The elements are: "<<endl;
    traversal(root);
    cout<<endl;

    cout<<"The minimum elements is"<<Min(root)<<endl;
    cout<<"The height of the tree is: "<<height(root)<<endl;

    bool ispresent=false;
    int key;
    cout<<"Enter the key you want to search: ";
    cin>>key;
    search(root,key,ispresent);
    if(ispresent==true){
        cout<<"The value you entered is present in the Bst"<<endl;
    }
    else{
        cout<<"the value entered is not present in the BST "<<endl;
    }
    return 0;

    mirror(root);
    cout<<"the tree after being mirrored is: ";
    traversal(root);
    return 0;
}
